#include <windows.h>
#include "../headers/variables.h"
#include "../headers/recherche_indicatif_affichage.h"

HWND recherche_indicatif_donne;
HWND box;
HWND hButton;
HWND hIndicatifDonne;
char recherche_indicatif [35];
HBITMAP hRechercherIndicatifImage;

LRESULT CALLBACK RechercheIndicatifFenetreProcedure (HWND hwnd, UINT msg, WPARAM wp , LPARAM lp){


    switch (msg){
    case WM_COMMAND:
        switch (wp){


        case RECHERCHE_INDICATIF_BOUTTON :
            {


                // getting input field text

                GetWindowText(hNomDonne,recherche_indicatif,35);
                int indicatif = atoi(recherche_indicatif);
                int longueur = floor(log10(indicatif))+1;
                if (strlen(recherche_indicatif) != 2 || longueur != 2 ){

                    MessageBoxW(hwnd,L" Indicatif Errone ",L" Erreur ",MB_OK | MB_ICONERROR);
                }
                else{
                    displayRechercheIndicatifAffichageFenetre(hwnd,nouveau_repertoire,recherche_indicatif);
                }




            }
        break;


        }
        break;

    case WM_CREATE:
        loadImagesRechercheIndicatifFenetre();
        break;
    case WM_SIZE:
        {
        RECT MainRect;
        int MainWidth, MainHeight;
        GetWindowRect(recherche_indicatif_donne, &MainRect);
        MainWidth = MainRect.right - MainRect.left;
        MainHeight = MainRect.bottom - MainRect.top;
        SetWindowPos(box, hwnd, (MainWidth)/4,(MainHeight)/8, (MainWidth)/2, (MainHeight)-200, SWP_NOZORDER);
        SetWindowPos(hButton, hwnd,(MainWidth-170)/2,MainHeight-140,170,50, SWP_NOZORDER);
        }
        break;

    case WM_CLOSE:
        DestroyWindow(recherche_indicatif_donne);
        break;
    default:
        return DefWindowProcW(hwnd,msg,wp,lp);

    }


}


void registerRechercheIndicatifFenetre (HINSTANCE hInstance){

    WNDCLASSW rechInd = {0};
    rechInd.hbrBackground = (HBRUSH) COLOR_WINDOW;
    rechInd.hCursor = LoadCursor(NULL,IDC_ARROW);
    rechInd.hInstance = hInstance;
    rechInd.lpszClassName = L"RechercheIndicatifFenetre";
    rechInd.lpfnWndProc = RechercheIndicatifFenetreProcedure;

    RegisterClassW(&rechInd);

}


HWND displayRechercheIndicatifFenetre (HWND hwnd){

    recherche_indicatif_donne = CreateWindowW(L"RechercheIndicatifFenetre",L" Recherchez Par Indicatif : ", WS_OVERLAPPEDWINDOW | WS_VISIBLE,
                  50,50,450,450,hwnd,NULL,NULL,NULL);

    RECT MainRect;
    int MainWidth, MainHeight;
    GetWindowRect(recherche_indicatif_donne, &MainRect);
    MainWidth = MainRect.right - MainRect.left;
    MainHeight = MainRect.bottom - MainRect.top;

    box = CreateWindowW(L"Button", L" Recherche ",WS_CHILD | WS_VISIBLE | BS_GROUPBOX,(MainWidth)/4,(MainHeight)/8, (MainWidth)/2, (MainHeight)-200,recherche_indicatif_donne,NULL,NULL, NULL);


    CreateWindowW(L"Static",L" Nom :",WS_VISIBLE | WS_CHILD | SS_CENTER, 2,80,120,40,box,NULL,NULL,NULL);

    hNomDonne = CreateWindowW (L"Edit",L"",WS_VISIBLE | WS_CHILD | WS_BORDER | ES_MULTILINE | ES_AUTOVSCROLL | ES_CENTER,100,70,90,40,box,NULL,NULL,NULL);
    hButton = CreateWindowW(L"Button",L"Rechercher",WS_VISIBLE|WS_CHILD| BS_BITMAP,(MainWidth-170)/2,MainHeight-130,170,50,recherche_indicatif_donne,(HMENU)RECHERCHE_INDICATIF_BOUTTON,NULL,NULL);
    SendMessageW(hButton,BM_SETIMAGE,IMAGE_BITMAP,(LPARAM)hRechercherIndicatifImage);


    return recherche_indicatif_donne;


}

void loadImagesRechercheIndicatifFenetre(){

    hRechercherIndicatifImage = (HBITMAP)LoadImageW(NULL,L"images/recherche.bmp",IMAGE_BITMAP,170,50,LR_LOADFROMFILE);

}
