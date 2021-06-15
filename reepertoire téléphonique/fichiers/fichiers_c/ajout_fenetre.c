#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



#include "../headers/variables.h"
#include "../headers/fonctions.h"



HWND ajout_fenetre; //child window
HWND box;
HWND hBoutton_Tete, hBoutton_Queue, hBoutton_Position;
HWND hNumero,hNom,hPrenom,hDate,hEmail,hVille,hRue,hCode,hPosition;
HBITMAP hAjoutTeteImage, hAjoutQueueImage, hAjoutPositionImage;


char nom [35],prenom [35], numero [35],
date [30], email[35], rue [35], ville[35],
code [30], pos [30];


LRESULT CALLBACK AjoutFenetreProcedure (HWND hwnd, UINT msg, WPARAM wp , LPARAM lp){


    switch (msg){
    case WM_COMMAND:
        switch (wp){


        case AJOUTER_BOUTTON_TETE:
            {

                // getting input field text

                GetWindowText(hNom,nom,35);
                GetWindowText(hPrenom,prenom,35);
                GetWindowText(hNumero,numero,20);
                GetWindowText(hDate,date,35);
                GetWindowText(hEmail,email,90);
                GetWindowText(hVille,ville,35);
                GetWindowText(hRue,rue,35);
                GetWindowText(hCode,code,35);

                if (strcmp(nom,"") == 0 || strcmp(prenom,"") == 0 || strcmp(numero,"") == 0
                    || strcmp(email,"") == 0 || strcmp(date,"") == 0 || strcmp(ville,"") == 0
                    || strcmp(rue,"") == 0 || strcmp (code ,"") == 0){
                    MessageBoxW(hwnd,L" Tous les champs sont requis ",L" Attention !! ",MB_OK | MB_ICONERROR);
                }

                if (verifier_date(date) == -1){
                    MessageBoxW(hwnd,L" Date de Naissance Non Valide ",L" Attention !! ",MB_OK | MB_ICONERROR);
                    SetWindowText(hDate,"");
                }

                if (verifier_numero(numero) == -1){
                    MessageBoxW(hwnd,L" Numero Non Valide ",L" Attention !! ",MB_OK | MB_ICONERROR);
                    SetWindowText(hNumero,"");
                }

                if (recherche_tel(nouveau_repertoire,numero) == -1){

                    MessageBoxW(hwnd,L" Numero deja Existant ",L" Attention !! ",MB_OK | MB_ICONEXCLAMATION);
                    SetWindowText(hNumero,"");
                }

                if (strcmp(nom,"") != 0 && strcmp(prenom,"") != 0 && strcmp(numero,"") != 0
                    && strcmp(email,"") != 0 && strcmp(date,"") != 0 && strcmp(ville,"") != 0
                    && strcmp(rue,"") != 0 && strcmp (code ,"") != 0 && verifier_date(date) == 1
                    && verifier_numero(numero) == 1 && recherche_tel(nouveau_repertoire,numero) == 1 ){

                    contact cont;
                    cont = saisie_contact(numero,nom,prenom,date,email,ville,rue,code);
                    nouveau_repertoire = insere_tete_tel(nouveau_repertoire,cont);
                    creation_repertoire = 1;
                    int valeur;
                    valeur = MessageBoxW(hwnd,L" Contact Ajoute Avec Succes ",L" Succes ",MB_OK | MB_ICONINFORMATION);
                    if (valeur == IDOK){
                        SetWindowText(hNumero,"");
                        SetWindowText(hNom,"");
                        SetWindowText(hPrenom,"");
                        SetWindowText(hDate,"");
                        SetWindowText(hEmail,"");
                        SetWindowText(hVille,"");
                        SetWindowText(hRue,"");
                        SetWindowText(hCode,"");
                    }

                }

            }
        break;


        case AJOUTER_BOUTTON_QUEUE:

            {


                // getting input field text

                GetWindowText(hNom,nom,35);
                GetWindowText(hPrenom,prenom,35);
                GetWindowText(hNumero,numero,20);
                GetWindowText(hDate,date,35);
                GetWindowText(hEmail,email,90);
                GetWindowText(hVille,ville,35);
                GetWindowText(hRue,rue,35);
                GetWindowText(hCode,code,35);

                if (strcmp(nom,"") == 0 || strcmp(prenom,"") == 0 || strcmp(numero,"") == 0
                    || strcmp(email,"") == 0 || strcmp(date,"") == 0 || strcmp(ville,"") == 0
                    || strcmp(rue,"") == 0 || strcmp (code ,"") == 0){
                    MessageBoxW(hwnd,L" Tous les champs sont requis ",L" Attention !! ",MB_OK | MB_ICONERROR);
                }

                if (verifier_date(date) == -1){
                    MessageBoxW(hwnd,L" Date de Naissance Non Valide ",L" Attention !! ",MB_OK | MB_ICONERROR);
                    SetWindowText(hDate,"");
                }

                if (verifier_numero(numero) == -1){
                    MessageBoxW(hwnd,L" Numero Non Valide ",L" Attention !! ",MB_OK | MB_ICONERROR);
                    SetWindowText(hNumero,"");
                }

                if (recherche_tel(nouveau_repertoire,numero) == -1){

                    MessageBoxW(hwnd,L" Numero deja Existant ",L" Attention !! ",MB_OK | MB_ICONEXCLAMATION);
                    SetWindowText(hNumero,"");
                }

                if (strcmp(nom,"") != 0 && strcmp(prenom,"") != 0 && strcmp(numero,"") != 0
                    && strcmp(email,"") != 0 && strcmp(date,"") != 0 && strcmp(ville,"") != 0
                    && strcmp(rue,"") != 0 && strcmp (code ,"") != 0 && verifier_date(date) == 1
                    && verifier_numero(numero) == 1 && recherche_tel(nouveau_repertoire,numero) == 1 ){

                    contact cont;
                    cont = saisie_contact(numero,nom,prenom,date,email,ville,rue,code);
                    nouveau_repertoire = insere_queue_tel(nouveau_repertoire,cont);
                    creation_repertoire = 1;
                    int valeur;
                    valeur = MessageBoxW(hwnd,L" Contact Ajoute Avec Succes ",L" Succes ",MB_OK | MB_ICONINFORMATION);
                    if (valeur == IDOK){
                        SetWindowText(hNumero,"");
                        SetWindowText(hNom,"");
                        SetWindowText(hPrenom,"");
                        SetWindowText(hDate,"");
                        SetWindowText(hEmail,"");
                        SetWindowText(hVille,"");
                        SetWindowText(hRue,"");
                        SetWindowText(hCode,"");
                    }

                }

            }
        break;



        case AJOUTER_BOUTTON_POSITION:
            {

                // getting input field text

                GetWindowText(hNom,nom,35);
                GetWindowText(hPrenom,prenom,35);
                GetWindowText(hNumero,numero,20);
                GetWindowText(hDate,date,35);
                GetWindowText(hEmail,email,90);
                GetWindowText(hVille,ville,35);
                GetWindowText(hRue,rue,35);
                GetWindowText(hCode,code,35);
                GetWindowText(hPosition,pos,35);
                int position = atoi(pos);
                int taille = taille_liste_rep(nouveau_repertoire);


                 if (strcmp(nom,"") == 0 || strcmp(prenom,"") == 0 || strcmp(numero,"") == 0
                    || strcmp(email,"") == 0 || strcmp(date,"") == 0 || strcmp(ville,"") == 0
                    || strcmp(rue,"") == 0 || strcmp (code ,"") == 0){
                    MessageBoxW(hwnd,L" Tous les champs sont requis ",L" Attention !! ",MB_OK | MB_ICONERROR);
                }

                if (verifier_date(date) == -1){
                    MessageBoxW(hwnd,L" Date de Naissance Non Valide ",L" Attention !! ",MB_OK | MB_ICONERROR);
                    SetWindowText(hDate,"");
                }

                if (verifier_numero(numero) == -1){
                    MessageBoxW(hwnd,L" Numero Non Valide ",L" Attention !! ",MB_OK | MB_ICONERROR);
                    SetWindowText(hNumero,"");
                }

                if (recherche_tel(nouveau_repertoire,numero) == -1){

                    MessageBoxW(hwnd,L" Numero deja Existant ",L" Attention !! ",MB_OK | MB_ICONEXCLAMATION);
                    SetWindowText(hNumero,"");
                }

                if (strcmp(nom,"") != 0 && strcmp(prenom,"") != 0 && strcmp(numero,"") != 0
                    && strcmp(email,"") != 0 && strcmp(date,"") != 0 && strcmp(ville,"") != 0
                    && strcmp(rue,"") != 0 && strcmp (code ,"") != 0 && verifier_date(date) == 1
                    && verifier_numero(numero) == 1 && recherche_tel(nouveau_repertoire,numero) == 1 ){

                     if(position < 1 || position > taille + 1){
                        MessageBoxW(hwnd,L" Position Erronee (sup a la taille du repertoire ou inferieure a 0) ",L" Erreur ",MB_OK | MB_ICONERROR);
                        SetWindowText(hPosition,"");
                    }
                    if (position == 1 || position == taille + 1){
                        MessageBoxW(hwnd,L" Position egale a la tete ou a la queue du repertoire. Utilisez ajout tete ou ajout queue ",L" Attention ",MB_OK | MB_ICONEXCLAMATION);
                        SetWindowText(hPosition,"");
                    }
                    if (position > 1 && position == taille){

                        contact cont;
                        cont = saisie_contact(numero,nom,prenom,date,email,ville,rue,code);
                        insere_pos_tel(nouveau_repertoire,cont,position);
                        creation_repertoire = 1;
                        int valeur;
                        valeur = MessageBoxW(hwnd,L" Contact Ajoute Avec Succes ",L" Succes ",MB_OK | MB_ICONINFORMATION);
                        if (valeur == IDOK){
                            SetWindowText(hNumero,"");
                            SetWindowText(hNom,"");
                            SetWindowText(hPrenom,"");
                            SetWindowText(hDate,"");
                            SetWindowText(hEmail,"");
                            SetWindowText(hVille,"");
                            SetWindowText(hRue,"");
                            SetWindowText(hCode,"");
                        }
                    }


                }


            }
        break;


        }
        break;

    case WM_CREATE:
        loadImages();
        break;
    case WM_SIZE:
        {
        RECT MainRect;
        int MainWidth, MainHeight;
        GetWindowRect(ajout_fenetre, &MainRect);
        MainWidth = MainRect.right - MainRect.left;
        MainHeight = MainRect.bottom - MainRect.top;
        SetWindowPos(box, hwnd, (MainWidth)/4,(MainHeight)/8, (MainWidth)/2, (MainHeight)-200, SWP_NOZORDER);
        SetWindowPos(hBoutton_Tete,hwnd,MainWidth-210,179,160,50, SWP_NOZORDER);
        SetWindowPos(hBoutton_Position,hwnd,MainWidth-210,281,160,50, SWP_NOZORDER);
        SetWindowPos(hBoutton_Queue,hwnd,MainWidth-210,331,160,50, SWP_NOZORDER);

        }
        break;

    case WM_CLOSE:
        DestroyWindow(ajout_fenetre);
        break;
    default:
        return DefWindowProcW(hwnd,msg,wp,lp);

    }


}


void registerAjoutFenetreClass(HINSTANCE hInstance){

    WNDCLASSW ajoutFen = {0};
    ajoutFen.hbrBackground = (HBRUSH) COLOR_WINDOW;
    ajoutFen.hCursor = LoadCursor(NULL,IDC_ARROW);
    ajoutFen.hInstance = hInstance;
    ajoutFen.lpszClassName = L"AjouterTelephone";
    ajoutFen.lpfnWndProc = AjoutFenetreProcedure;

    RegisterClassW(&ajoutFen);

}

HWND displayAjoutFenetre(HWND hwnd){

    ajout_fenetre = CreateWindowW(L"AjouterTelephone",L" Ajouter Nouveau Contact ", WS_OVERLAPPEDWINDOW | WS_VISIBLE,
                  50,50,1400,700,hwnd,NULL,NULL,NULL);

    RECT MainRect;
    int MainWidth, MainHeight;
    GetWindowRect(ajout_fenetre, &MainRect);
    MainWidth = MainRect.right - MainRect.left;
    MainHeight = MainRect.bottom - MainRect.top;

    box = CreateWindowW(L"Button", L" Ajouter Nouveau Contact ",WS_CHILD | WS_VISIBLE | BS_GROUPBOX,(MainWidth)/4,(MainHeight)/8, (MainWidth)/2, (MainHeight)-200,ajout_fenetre,NULL,NULL, NULL);


    CreateWindowW(L"Static",L" Numero :",WS_VISIBLE | WS_CHILD | SS_CENTER, 40,90,150,40,box,NULL,NULL,NULL);
    hNumero = CreateWindowW (L"Edit",L"8 chiffres ",WS_VISIBLE | WS_CHILD | WS_BORDER | ES_MULTILINE | ES_AUTOVSCROLL | ES_CENTER,190,79,100,40,box,NULL,NULL,NULL);

    CreateWindowW(L"Static",L" Nom :",WS_VISIBLE | WS_CHILD | SS_CENTER, 40,140,150,40,box,NULL,NULL,NULL);
    hNom = CreateWindowW (L"Edit",L"",WS_VISIBLE | WS_CHILD | WS_BORDER | ES_MULTILINE | ES_AUTOVSCROLL | ES_CENTER,190,129,100,40,box,NULL,NULL,NULL);

    CreateWindowW(L"Static",L" Prenom :",WS_VISIBLE | WS_CHILD | SS_CENTER, 40,190,150,40,box,NULL,NULL,NULL);
    hPrenom = CreateWindowW (L"Edit",L"",WS_VISIBLE | WS_CHILD | WS_BORDER | ES_MULTILINE | ES_AUTOVSCROLL | ES_CENTER,190,179,100,40,box,NULL,NULL,NULL);

    CreateWindowW(L"Static",L" Date de Naissance :",WS_VISIBLE | WS_CHILD | SS_CENTER, 40,240,150,40,box,NULL,NULL,NULL);
    hDate = CreateWindowW (L"Edit",L"",WS_VISIBLE | WS_CHILD | WS_BORDER | ES_MULTILINE | ES_AUTOVSCROLL | ES_CENTER,190,229,100,40,box,NULL,NULL,NULL);

    CreateWindowW(L"Static",L" Email :",WS_VISIBLE | WS_CHILD | SS_CENTER, 40,290,100,40,box,NULL,NULL,NULL);
    hEmail = CreateWindowW (L"Edit",L"",WS_VISIBLE | WS_CHILD | WS_BORDER | ES_MULTILINE | ES_AUTOVSCROLL | ES_CENTER,190,279,100,40,box,NULL,NULL,NULL);

    CreateWindowW(L"Static",L" Ville :",WS_VISIBLE | WS_CHILD | SS_CENTER, 40,340,100,40,box,NULL,NULL,NULL);
    hVille = CreateWindowW (L"Edit",L"",WS_VISIBLE | WS_CHILD | WS_BORDER | ES_MULTILINE | ES_AUTOVSCROLL | ES_CENTER,190,329,100,40,box,NULL,NULL,NULL);

    CreateWindowW(L"Static",L" Rue :",WS_VISIBLE | WS_CHILD | SS_CENTER, 40,390,100,40,box,NULL,NULL,NULL);
    hRue = CreateWindowW (L"Edit",L"",WS_VISIBLE | WS_CHILD | WS_BORDER | ES_MULTILINE | ES_AUTOVSCROLL | ES_CENTER,190,379,100,40,box,NULL,NULL,NULL);

    CreateWindowW(L"Static",L" Code :",WS_VISIBLE | WS_CHILD | SS_CENTER, 40,440,100,40,box,NULL,NULL,NULL);
    hCode = CreateWindowW (L"Edit",L"",WS_VISIBLE | WS_CHILD | WS_BORDER | ES_MULTILINE | ES_AUTOVSCROLL | ES_CENTER,190,429,100,40,box,NULL,NULL,NULL);

    hBoutton_Tete = CreateWindowW(L"Button",L"Ajouter en Tete",WS_VISIBLE|WS_CHILD| BS_BITMAP,MainWidth-580,179,170,50,ajout_fenetre,(HMENU)AJOUTER_BOUTTON_TETE,NULL,NULL);
    SendMessageW(hBoutton_Tete,BM_SETIMAGE,IMAGE_BITMAP,(LPARAM)hAjoutTeteImage);

    hBoutton_Queue = CreateWindowW(L"Button",L"Ajouter en Queue",WS_VISIBLE|WS_CHILD| BS_BITMAP,MainWidth-580,239,170,50,ajout_fenetre,(HMENU)AJOUTER_BOUTTON_QUEUE,NULL,NULL);
    SendMessageW(hBoutton_Queue,BM_SETIMAGE,IMAGE_BITMAP,(LPARAM)hAjoutQueueImage);

    CreateWindowW(L"Static",L" Position :",WS_VISIBLE | WS_CHILD | SS_CENTER, 460,400,100,40,box,NULL,NULL,NULL);
    hPosition = CreateWindowW (L"Edit",L"",WS_VISIBLE | WS_CHILD | WS_BORDER | ES_MULTILINE | ES_AUTOVSCROLL | ES_CENTER,550,387,70,40,box,NULL,NULL,NULL);

    hBoutton_Position = CreateWindowW(L"Button",L"Ajouter avec Position",WS_VISIBLE|WS_CHILD| BS_BITMAP,MainWidth-580,300,170,50,ajout_fenetre,(HMENU)AJOUTER_BOUTTON_POSITION,NULL,NULL);
    SendMessageW(hBoutton_Position,BM_SETIMAGE,IMAGE_BITMAP,(LPARAM)hAjoutPositionImage);

    return ajout_fenetre;


}

void loadImages (){

    hAjoutTeteImage = (HBITMAP)LoadImageW(NULL,L"images/ajout_tete.bmp",IMAGE_BITMAP,170,50,LR_LOADFROMFILE);
    hAjoutQueueImage = (HBITMAP)LoadImageW(NULL,L"images/ajout_queue.bmp",IMAGE_BITMAP,170,50,LR_LOADFROMFILE);
    hAjoutPositionImage = (HBITMAP)LoadImageW(NULL,L"images/ajout_position.bmp",IMAGE_BITMAP,170,50,LR_LOADFROMFILE);
}

