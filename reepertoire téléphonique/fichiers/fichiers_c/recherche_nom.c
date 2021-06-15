#include <windows.h>
#include "../headers/variables.h"
#include "../headers/recherche_nom_affichage.h"

HWND recherche_nom_donne;
HWND box;
HWND hButton;
HWND hNomDonne;
char recherche_nom [35];
HBITMAP hRechercherNomImage;

LRESULT CALLBACK RechercheNomFenetreProcedure (HWND hwnd, UINT msg, WPARAM wp , LPARAM lp){


    switch (msg){
    case WM_COMMAND:
        switch (wp){


        case RECHERCHE_NOM_BOUTTON :
            {


                // getting input field text

                GetWindowText(hNomDonne,recherche_nom,35);
                if (strcmp(recherche_nom,"") != 0){
                    displayRechercheNomAffichageFenetre(hwnd,nouveau_repertoire,recherche_nom);
                }
                else{
                    MessageBoxW(hwnd,L" Champ Vide ",L" Attention !! ",MB_OK | MB_ICONERROR);
                }




            }
        break;


        }
        break;

    case WM_CREATE:
        loadImagesRechercheNomFenetre();
        break;
    case WM_SIZE:
        {
        RECT MainRect;
        int MainWidth, MainHeight;
        GetWindowRect(recherche_nom_donne, &MainRect);
        MainWidth = MainRect.right - MainRect.left;
        MainHeight = MainRect.bottom - MainRect.top;
        SetWindowPos(box, hwnd, (MainWidth)/4,(MainHeight)/8, (MainWidth)/2, (MainHeight)-200, SWP_NOZORDER);
        SetWindowPos(hButton, hwnd,(MainWidth-170)/2,MainHeight-140,170,50, SWP_NOZORDER);
        }
        break;

    case WM_CLOSE:
        DestroyWindow(recherche_nom_donne);
        break;
    default:
        return DefWindowProcW(hwnd,msg,wp,lp);

    }


}


void registerRechercheNomFenetre (HINSTANCE hInstance){

    WNDCLASSW rechNom = {0};
    rechNom.hbrBackground = (HBRUSH) COLOR_WINDOW;
    rechNom.hCursor = LoadCursor(NULL,IDC_ARROW);
    rechNom.hInstance = hInstance;
    rechNom.lpszClassName = L"RechercheNomFenetre";
    rechNom.lpfnWndProc = RechercheNomFenetreProcedure;

    RegisterClassW(&rechNom);

}


HWND displayRechercheNomFenetre (HWND hwnd){

    recherche_nom_donne = CreateWindowW(L"RechercheNomFenetre",L" Recherchez Par Nom : ", WS_OVERLAPPEDWINDOW | WS_VISIBLE,
                  50,50,450,450,hwnd,NULL,NULL,NULL);

    RECT MainRect;
    int MainWidth, MainHeight;
    GetWindowRect(recherche_nom_donne, &MainRect);
    MainWidth = MainRect.right - MainRect.left;
    MainHeight = MainRect.bottom - MainRect.top;

    box = CreateWindowW(L"Button", L" Recherche ",WS_CHILD | WS_VISIBLE | BS_GROUPBOX,(MainWidth)/4,(MainHeight)/8, (MainWidth)/2, (MainHeight)-200,recherche_nom_donne,NULL,NULL, NULL);


    CreateWindowW(L"Static",L" Nom :",WS_VISIBLE | WS_CHILD | SS_CENTER, 2,80,120,40,box,NULL,NULL,NULL);

    hNomDonne = CreateWindowW (L"Edit",L"",WS_VISIBLE | WS_CHILD | WS_BORDER | ES_MULTILINE | ES_AUTOVSCROLL | ES_CENTER,100,70,90,40,box,NULL,NULL,NULL);
    hButton = CreateWindowW(L"Button",L"Rechercher",WS_VISIBLE|WS_CHILD| BS_BITMAP,(MainWidth-170)/2,MainHeight-130,170,50,recherche_nom_donne,(HMENU)RECHERCHE_NOM_BOUTTON,NULL,NULL);
    SendMessageW(hButton,BM_SETIMAGE,IMAGE_BITMAP,(LPARAM)hRechercherNomImage);

    return recherche_nom_donne;


}

void loadImagesRechercheNomFenetre(){

    hRechercherNomImage = (HBITMAP)LoadImageW(NULL,L"images/recherche.bmp",IMAGE_BITMAP,170,50,LR_LOADFROMFILE);

}

