#include <windows.h>
#include "../headers/variables.h"


HWND suppression_ville_donnee;
HWND box;
HWND hButton;
HWND hVilleDonnee;
HBITMAP hSupprimerVilleImage;

LRESULT CALLBACK SuppressionVilleFenetreProcedure (HWND hwnd, UINT msg, WPARAM wp , LPARAM lp){


    switch (msg){
    case WM_COMMAND:
        switch (wp){


        case SUPPRESSION_VILLE_BOUTTON :
            {
                // variables

                char ville [35];



                // getting input field text

                GetWindowText(hVilleDonnee,ville,35);
                nouveau_repertoire = supprimer_ville_donnee(nouveau_repertoire,ville,hwnd);

            }
        break;


        }
        break;

    case WM_CREATE:
        loadImagesSupprimerVilleFenetre();
        break;
    case WM_SIZE:
        {
        RECT MainRect;
        int MainWidth, MainHeight;
        GetWindowRect(suppression_ville_donnee, &MainRect);
        MainWidth = MainRect.right - MainRect.left;
        MainHeight = MainRect.bottom - MainRect.top;
        SetWindowPos(box, hwnd, (MainWidth)/4,(MainHeight)/8, (MainWidth)/2, (MainHeight)-200, SWP_NOZORDER);
        SetWindowPos(hButton, hwnd,(MainWidth-170)/2,MainHeight-140,100,50, SWP_NOZORDER);
        }
        break;

    case WM_CLOSE:
        DestroyWindow(suppression_ville_donnee);
        break;
    default:
        return DefWindowProcW(hwnd,msg,wp,lp);

    }


}


void registerSuppressionVilleFenetre (HINSTANCE hInstance){

    WNDCLASSW suppVille = {0};
    suppVille.hbrBackground = (HBRUSH) COLOR_WINDOW;
    suppVille.hCursor = LoadCursor(NULL,IDC_ARROW);
    suppVille.hInstance = hInstance;
    suppVille.lpszClassName = L"SuppressionVilleFenetre";
    suppVille.lpfnWndProc = SuppressionVilleFenetreProcedure;

    RegisterClassW(&suppVille);

}


HWND displaySuppressionVilleFenetre (HWND hwnd){

    suppression_ville_donnee = CreateWindowW(L"SuppressionVilleFenetre",L" Entrez uune Ville ", WS_OVERLAPPEDWINDOW | WS_VISIBLE,
                  50,50,450,450,hwnd,NULL,NULL,NULL);

    RECT MainRect;
    int MainWidth, MainHeight;
    GetWindowRect(suppression_ville_donnee, &MainRect);
    MainWidth = MainRect.right - MainRect.left;
    MainHeight = MainRect.bottom - MainRect.top;

    box = CreateWindowW(L"Button", L" Ville ",WS_CHILD | WS_VISIBLE | BS_GROUPBOX,(MainWidth)/4,(MainHeight)/8, (MainWidth)/2, (MainHeight)-200,suppression_ville_donnee,NULL,NULL, NULL);


    CreateWindowW(L"Static",L" Ville :",WS_VISIBLE | WS_CHILD | SS_CENTER, 5,80,130,40,box,NULL,NULL,NULL);
    hVilleDonnee = CreateWindowW (L"Edit",L"",WS_VISIBLE | WS_CHILD | WS_BORDER | ES_MULTILINE | ES_AUTOVSCROLL | ES_CENTER,100,70,90,40,box,NULL,NULL,NULL);
    hButton = CreateWindowW(L"Button",L"Choisir",WS_VISIBLE|WS_CHILD| BS_BITMAP,(MainWidth-170)/2,MainHeight-130,170,50,suppression_ville_donnee,(HMENU)SUPPRESSION_VILLE_BOUTTON,NULL,NULL);
    SendMessageW(hButton,BM_SETIMAGE,IMAGE_BITMAP,(LPARAM)hSupprimerVilleImage);

    return suppression_ville_donnee;


}
void loadImagesSupprimerVilleFenetre(){

    hSupprimerVilleImage = (HBITMAP)LoadImageW(NULL,L"images/Supprimer.bmp",IMAGE_BITMAP,170,50,LR_LOADFROMFILE);

}
