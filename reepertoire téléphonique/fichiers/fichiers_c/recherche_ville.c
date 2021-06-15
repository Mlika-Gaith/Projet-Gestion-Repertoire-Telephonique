#include <windows.h>
#include "../headers/variables.h"
#include "../headers/recherche_ville_affichage.h"



HWND recherche_ville_donne;
HWND box;
HWND hButton;
HWND hVilleDonnee;
char recherche_ville [35];
HBITMAP hRechercherVilleImage;

LRESULT CALLBACK RechercheVilleFenetreProcedure (HWND hwnd, UINT msg, WPARAM wp , LPARAM lp){


    switch (msg){
    case WM_COMMAND:
        switch (wp){


        case RECHERCHE_VILLE_BOUTTON :
            {


                // getting input field text

                GetWindowText(hVilleDonnee,recherche_ville,35);
                if (strcmp(recherche_ville,"") != 0){
                    displayRechercheVilleAffichageFenetre(hwnd,nouveau_repertoire,recherche_ville);
                }
                else{
                    MessageBoxW(hwnd,L" Champ Vide ",L" Attention !! ",MB_OK | MB_ICONERROR);
                }




            }
        break;


        }
        break;

    case WM_CREATE:
        loadImagesRechercheVilleFenetre();
        break;
    case WM_SIZE:
        {
        RECT MainRect;
        int MainWidth, MainHeight;
        GetWindowRect(recherche_ville_donne, &MainRect);
        MainWidth = MainRect.right - MainRect.left;
        MainHeight = MainRect.bottom - MainRect.top;
        SetWindowPos(box, hwnd, (MainWidth)/4,(MainHeight)/8, (MainWidth)/2, (MainHeight)-200, SWP_NOZORDER);
        SetWindowPos(hButton, hwnd,(MainWidth-170)/2,MainHeight-140,170,50, SWP_NOZORDER);
        }
        break;

    case WM_CLOSE:
        DestroyWindow(recherche_ville_donne);
        break;
    default:
        return DefWindowProcW(hwnd,msg,wp,lp);

    }


}


void registerRechercheVilleFenetre (HINSTANCE hInstance){

    WNDCLASSW rechNum = {0};
    rechNum.hbrBackground = (HBRUSH) COLOR_WINDOW;
    rechNum.hCursor = LoadCursor(NULL,IDC_ARROW);
    rechNum.hInstance = hInstance;
    rechNum.lpszClassName = L"RechercheVilleFenetre";
    rechNum.lpfnWndProc = RechercheVilleFenetreProcedure;

    RegisterClassW(&rechNum);

}


HWND displayRechercheVilleFenetre (HWND hwnd){

    recherche_ville_donne = CreateWindowW(L"RechercheVilleFenetre",L" Entrez une Ville ", WS_OVERLAPPEDWINDOW | WS_VISIBLE,
                  50,50,450,450,hwnd,NULL,NULL,NULL);

    RECT MainRect;
    int MainWidth, MainHeight;
    GetWindowRect(recherche_ville_donne, &MainRect);
    MainWidth = MainRect.right - MainRect.left;
    MainHeight = MainRect.bottom - MainRect.top;

    box = CreateWindowW(L"Button", L" Recherche ",WS_CHILD | WS_VISIBLE | BS_GROUPBOX,(MainWidth)/4,(MainHeight)/8, (MainWidth)/2, (MainHeight)-200,recherche_ville_donne,NULL,NULL, NULL);


    CreateWindowW(L"Static",L" Ville :",WS_VISIBLE | WS_CHILD | SS_CENTER, 2,80,120,40,box,NULL,NULL,NULL);

    hVilleDonnee = CreateWindowW (L"Edit",L"",WS_VISIBLE | WS_CHILD | WS_BORDER | ES_MULTILINE | ES_AUTOVSCROLL | ES_CENTER,100,70,90,40,box,NULL,NULL,NULL);
    hButton = CreateWindowW(L"Button",L"Rechercher",WS_VISIBLE|WS_CHILD| BS_BITMAP,(MainWidth-170)/2,MainHeight-130,170,50,recherche_ville_donne,(HMENU)RECHERCHE_VILLE_BOUTTON,NULL,NULL);
    SendMessageW(hButton,BM_SETIMAGE,IMAGE_BITMAP,(LPARAM)hRechercherVilleImage);

    return recherche_ville_donne;


}
void loadImagesRechercheVilleFenetre(){

    hRechercherVilleImage = (HBITMAP)LoadImageW(NULL,L"images/recherche.bmp",IMAGE_BITMAP,170,50,LR_LOADFROMFILE);

}
