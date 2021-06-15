#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



#include "../headers/variables.h"
#include "../headers/fonctions.h"



HWND modifier_fenetre; //child window
HWND box;
HWND hBoutton_MODNumero, hBoutton_MODAdresse, hBoutton_Recherche;
HWND hNumero,hRecherche,hVille,hRue,hCode;

HBITMAP hModifierRechercheImage;
HBITMAP hModifierNumeroImage;
HBITMAP hModifierAdresseImage;

char  numero [35], rue [35], ville[35], code [30], rech [30];
repertoire r_rech = NULL;

int rech_bout = 0;
LRESULT CALLBACK ModifierFenetreProcedure (HWND hwnd, UINT msg, WPARAM wp , LPARAM lp){


    switch (msg){
    case WM_COMMAND:
        switch (wp){

        case MODIFIER_RECHERCHE_BOUTTON:
            {

                r_rech = nouveau_repertoire;
                strcpy(rech,"");
                int found = -1;
                rech_bout = 0;
                GetWindowText(hRecherche,rech,35);
                if (strcmp(rech,"") == 0){
                    MessageBoxW(hwnd,L" Champ Vide !! ",L" Erreur !!",MB_OK | MB_ICONERROR);
                }
                if (verifier_numero(rech) == -1){
                    MessageBoxW(hwnd,L" Numero non Valide !! ",L" Erreur !!",MB_OK | MB_ICONERROR);
                }
                if (recherche_tel(nouveau_repertoire,rech) == 1){
                    MessageBoxW(hwnd,L" Numero Non Trouve !! ",L" Attention !!",MB_OK | MB_ICONEXCLAMATION);
                }

                if ((strcmp(rech,"") != 0) && (verifier_numero(rech) == 1) && (recherche_tel(nouveau_repertoire,rech) == -1)){
                        printf("%d\n",1);
                    while (found != 0 && r_rech != NULL){
                        found = strcmp(r_rech->cont.numero,rech);

                        if (found == 0){
                            rech_bout = 1;
                            break;

                        }
                        if (found != -1)
                            r_rech= r_rech->suiv;

                    }


                    SetWindowText(hNumero,r_rech->cont.numero);
                    SetWindowText(hVille,r_rech->cont.adr.ville);
                    SetWindowText(hCode,r_rech->cont.adr.code);
                    SetWindowText(hRue,r_rech->cont.adr.rue);
                }
            }
            break;
        case MODIFIER_NUMERO_BOUTTON:
            {
                if (rech_bout == 0)
                    MessageBoxW(hwnd,L" Effectuez une Recherche D'abord !!",L" Attention !! ",MB_OK | MB_ICONEXCLAMATION);
                else{
                    GetWindowText(hNumero,numero,35);
                    if (strcmp(numero,"") == 0)
                        MessageBoxW(hwnd,L" Champ Vide !! ",L" Erreur !!",MB_OK | MB_ICONERROR);
                    if (recherche_tel(nouveau_repertoire,numero) == -1 && strcmp(numero,r_rech->cont.numero) != 0)
                        MessageBoxW(hwnd,L" Numero Deja Existant !! ",L" Attention !!",MB_OK | MB_ICONEXCLAMATION);
                    if (verifier_numero(numero) == -1)
                        MessageBoxW(hwnd,L" Numero non Valide !! ",L" Erreur !!",MB_OK | MB_ICONERROR);
                    if (((recherche_tel(nouveau_repertoire,numero) == 1 && strcmp(numero,r_rech->cont.numero) != 0) || (strcmp(numero,r_rech->cont.numero) == 0 && recherche_tel(nouveau_repertoire,numero) == -1)) &&
                        strcmp(numero,"") != 0 && verifier_numero(numero) == 1){
                            strcpy(r_rech->cont.numero,numero);
                            MessageBoxW(hwnd,L" Numero Modifie Avec Succes ",L" Succes ",MB_OK | MB_ICONINFORMATION);
                        }

                }
            }
            break;

        case MODIFIER_ADRESSE_BOUTTON:
            {
                if (rech_bout == 0)
                    MessageBoxW(hwnd,L" Effectuez une Recherche D'abord !!",L" Attention !! ",MB_OK | MB_ICONEXCLAMATION);
                else{
                    GetWindowText(hVille,ville,35);
                    GetWindowText(hRue,rue,35);
                    GetWindowText(hCode,code,35);
                    if (strcmp(ville,"") == 0 || strcmp(rue,"") == 0 || strcmp(code,"") == 0)
                        MessageBoxW(hwnd,L" Tous Les Champs Doivent Etre Non Vides !!",L" Erreur !! ",MB_OK | MB_ICONERROR);
                    else{
                        strcpy(r_rech->cont.adr.ville,ville);
                        strcpy(r_rech->cont.adr.code,code);
                        strcpy(r_rech->cont.adr.rue,rue);
                        MessageBoxW(hwnd,L" Adresse Modifie Avec Succes ",L" Succes ",MB_OK | MB_ICONINFORMATION);
                    }
                }
            }


        }
        break;

    case WM_CREATE:
        loadImagesModifierFenetre();
        break;
    case WM_SIZE:
        {
        RECT MainRect;
        int MainWidth, MainHeight;
        GetWindowRect(modifier_fenetre, &MainRect);
        MainWidth = MainRect.right - MainRect.left;
        MainHeight = MainRect.bottom - MainRect.top;
        SetWindowPos(box, hwnd, (MainWidth)/4,(MainHeight)/8, (MainWidth)/2, (MainHeight)-200, SWP_NOZORDER);
        SetWindowPos(hBoutton_Recherche,hwnd,MainWidth-210,179,160,50, SWP_NOZORDER);
        SetWindowPos(hBoutton_MODNumero,hwnd,MainWidth-210,281,160,50, SWP_NOZORDER);
        SetWindowPos(hBoutton_MODAdresse,hwnd,MainWidth-210,331,160,50, SWP_NOZORDER);

        }
        break;

    case WM_CLOSE:
        DestroyWindow(modifier_fenetre);
        break;
    default:
        return DefWindowProcW(hwnd,msg,wp,lp);

    }


}


void registerModifierFenetreClass(HINSTANCE hInstance){

    WNDCLASSW ajoutFen = {0};
    ajoutFen.hbrBackground = (HBRUSH) COLOR_WINDOW;
    ajoutFen.hCursor = LoadCursor(NULL,IDC_ARROW);
    ajoutFen.hInstance = hInstance;
    ajoutFen.lpszClassName = L"ModifierTelephone";
    ajoutFen.lpfnWndProc = ModifierFenetreProcedure;

    RegisterClassW(&ajoutFen);

}

HWND displayModifierFenetre(HWND hwnd){

    modifier_fenetre = CreateWindowW(L"ModifierTelephone",L" Modifier un Contact ", WS_OVERLAPPEDWINDOW | WS_VISIBLE,
                  50,50,1400,700,hwnd,NULL,NULL,NULL);

    RECT MainRect;
    int MainWidth, MainHeight;
    GetWindowRect(modifier_fenetre, &MainRect);
    MainWidth = MainRect.right - MainRect.left;
    MainHeight = MainRect.bottom - MainRect.top;

    box = CreateWindowW(L"Button", L" Modifier un Contact ",WS_CHILD | WS_VISIBLE | BS_GROUPBOX,(MainWidth)/4,(MainHeight)/8, (MainWidth)/2, (MainHeight)-200,modifier_fenetre,NULL,NULL, NULL);


    CreateWindowW(L"Static",L" Rechercher Par Numero :",WS_VISIBLE | WS_CHILD | SS_CENTER, 40,90,220,40,box,NULL,NULL,NULL);
    hRecherche = CreateWindowW (L"Edit",L"8 chiffres ",WS_VISIBLE | WS_CHILD | WS_BORDER | ES_MULTILINE | ES_AUTOVSCROLL | ES_CENTER,280,79,100,40,box,NULL,NULL,NULL);

    CreateWindowW(L"Static",L" Numero :",WS_VISIBLE | WS_CHILD | SS_CENTER, 40,200,150,40,box,NULL,NULL,NULL);
    hNumero = CreateWindowW (L"Edit",L"8 chiffres ",WS_VISIBLE | WS_CHILD | WS_BORDER | ES_MULTILINE | ES_AUTOVSCROLL | ES_CENTER,190,189,100,40,box,NULL,NULL,NULL);

    CreateWindowW(L"Static",L" Ville :",WS_VISIBLE | WS_CHILD | SS_CENTER, 40,240,150,40,box,NULL,NULL,NULL);
    hVille = CreateWindowW (L"Edit",L"",WS_VISIBLE | WS_CHILD | WS_BORDER | ES_MULTILINE | ES_AUTOVSCROLL | ES_CENTER,190,229,100,40,box,NULL,NULL,NULL);

    CreateWindowW(L"Static",L" Rue :",WS_VISIBLE | WS_CHILD | SS_CENTER, 40,280,150,40,box,NULL,NULL,NULL);
    hRue = CreateWindowW (L"Edit",L"",WS_VISIBLE | WS_CHILD | WS_BORDER | ES_MULTILINE | ES_AUTOVSCROLL | ES_CENTER,190,269,100,40,box,NULL,NULL,NULL);

    CreateWindowW(L"Static",L" Code :",WS_VISIBLE | WS_CHILD | SS_CENTER, 40,320,150,40,box,NULL,NULL,NULL);
    hCode = CreateWindowW (L"Edit",L"",WS_VISIBLE | WS_CHILD | WS_BORDER | ES_MULTILINE | ES_AUTOVSCROLL | ES_CENTER,190,309,100,40,box,NULL,NULL,NULL);

    hBoutton_Recherche = CreateWindowW(L"Button",L"Rechercher",WS_VISIBLE|WS_CHILD| BS_BITMAP,MainWidth-580,160,170,50,modifier_fenetre,(HMENU)MODIFIER_RECHERCHE_BOUTTON,NULL,NULL);
    SendMessageW(hBoutton_Recherche,BM_SETIMAGE,IMAGE_BITMAP,(LPARAM)hModifierRechercheImage);


    hBoutton_MODNumero = CreateWindowW(L"Button",L"Modifier Numero",WS_VISIBLE|WS_CHILD| BS_BITMAP,MainWidth-580,279,170,50,modifier_fenetre,(HMENU)MODIFIER_NUMERO_BOUTTON,NULL,NULL);
    SendMessageW(hBoutton_MODNumero,BM_SETIMAGE,IMAGE_BITMAP,(LPARAM)hModifierNumeroImage);
    hBoutton_MODAdresse = CreateWindowW(L"Button",L"Modifier Adresse",WS_VISIBLE|WS_CHILD| BS_BITMAP,MainWidth-580,350,170,50,modifier_fenetre,(HMENU)MODIFIER_ADRESSE_BOUTTON,NULL,NULL);
    SendMessageW(hBoutton_MODAdresse,BM_SETIMAGE,IMAGE_BITMAP,(LPARAM)hModifierAdresseImage);

    return modifier_fenetre;
}

void loadImagesModifierFenetre(){

    hModifierRechercheImage = (HBITMAP)LoadImageW(NULL,L"images/recherche.bmp",IMAGE_BITMAP,170,50,LR_LOADFROMFILE);
    hModifierNumeroImage = (HBITMAP)LoadImageW(NULL,L"images/modifier_numero.bmp",IMAGE_BITMAP,170,50,LR_LOADFROMFILE);
    hModifierAdresseImage = (HBITMAP)LoadImageW(NULL,L"images/modifier_adresse.bmp",IMAGE_BITMAP,170,50,LR_LOADFROMFILE);

}
