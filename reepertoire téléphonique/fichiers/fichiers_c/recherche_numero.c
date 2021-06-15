#include <windows.h>
#include "../headers/variables.h"
#include "../headers/recherche_numero_affichage.h"



HWND recherche_numero_donne;
HWND box;
HWND hButton;
HWND hNumeroDonne;
char recherche_numero [35];

HBITMAP hRechercherNumeroImage;

LRESULT CALLBACK RechercheNumeroFenetreProcedure (HWND hwnd, UINT msg, WPARAM wp , LPARAM lp){


    switch (msg){
    case WM_COMMAND:
        switch (wp){


        case RECHERCHE_NUMERO_BOUTTON :
            {


                // getting input field text

                GetWindowText(hNumeroDonne,recherche_numero,35);
                if (strcmp(recherche_numero,"") != 0 && verifier_numero(recherche_numero) != -1)
                {
                    if (recherche_tel(nouveau_repertoire,recherche_numero) == -1){
                        repertoire r = nouveau_repertoire;
                        while (strcmp(r->cont.numero,recherche_numero) != 0){
                            r = r->suiv;
                        }
                        displayRechercheNumeroAffichagefenetre(hwnd,r);
                    }
                    else{
                        MessageBoxW(hwnd,L" Numero Non Trouve ",L" Resultat : ",MB_OK | MB_ICONEXCLAMATION);
                    }

                }

                else{

                    MessageBoxW(hwnd,L" Numero Errone ",L" Attention !! ",MB_OK | MB_ICONERROR);
                }




            }
        break;


        }
        break;

    case WM_CREATE:
        loadImagesRechercheNumeroFenetre();
        break;
    case WM_SIZE:
        {
        RECT MainRect;
        int MainWidth, MainHeight;
        GetWindowRect(recherche_numero_donne, &MainRect);
        MainWidth = MainRect.right - MainRect.left;
        MainHeight = MainRect.bottom - MainRect.top;
        SetWindowPos(box, hwnd, (MainWidth)/4,(MainHeight)/8, (MainWidth)/2, (MainHeight)-200, SWP_NOZORDER);
        SetWindowPos(hButton, hwnd,(MainWidth-170)/2,MainHeight-140,170,50, SWP_NOZORDER);
        }
        break;

    case WM_CLOSE:
        DestroyWindow(recherche_numero_donne);
        break;
    default:
        return DefWindowProcW(hwnd,msg,wp,lp);

    }


}


void registerRechercheNumeroFenetre (HINSTANCE hInstance){

    WNDCLASSW rechNum = {0};
    rechNum.hbrBackground = (HBRUSH) COLOR_WINDOW;
    rechNum.hCursor = LoadCursor(NULL,IDC_ARROW);
    rechNum.hInstance = hInstance;
    rechNum.lpszClassName = L"RechercheNumeroFenetre";
    rechNum.lpfnWndProc = RechercheNumeroFenetreProcedure;

    RegisterClassW(&rechNum);

}


HWND displayRechercheNumeroFenetre (HWND hwnd){

    recherche_numero_donne = CreateWindowW(L"RechercheNumeroFenetre",L" Entrez un Numero ", WS_OVERLAPPEDWINDOW | WS_VISIBLE,
                  50,50,450,450,hwnd,NULL,NULL,NULL);

    RECT MainRect;
    int MainWidth, MainHeight;
    GetWindowRect(recherche_numero_donne, &MainRect);
    MainWidth = MainRect.right - MainRect.left;
    MainHeight = MainRect.bottom - MainRect.top;

    box = CreateWindowW(L"Button", L" Recherche ",WS_CHILD | WS_VISIBLE | BS_GROUPBOX,(MainWidth)/4,(MainHeight)/8, (MainWidth)/2, (MainHeight)-200,recherche_numero_donne,NULL,NULL, NULL);


    CreateWindowW(L"Static",L" Numero :",WS_VISIBLE | WS_CHILD | SS_CENTER, 2,80,120,40,box,NULL,NULL,NULL);

    hNumeroDonne = CreateWindowW (L"Edit",L"",WS_VISIBLE | WS_CHILD | WS_BORDER | ES_MULTILINE | ES_AUTOVSCROLL | ES_CENTER,100,70,90,40,box,NULL,NULL,NULL);
    hButton = CreateWindowW(L"Button",L"Rechercher",WS_VISIBLE|WS_CHILD| BS_BITMAP,(MainWidth-170)/2,MainHeight-130,170,50,recherche_numero_donne,(HMENU)RECHERCHE_NUMERO_BOUTTON,NULL,NULL);
    SendMessageW(hButton,BM_SETIMAGE,IMAGE_BITMAP,(LPARAM)hRechercherNumeroImage);

    return recherche_numero_donne;


}
void loadImagesRechercheNumeroFenetre(){

    hRechercherNumeroImage = (HBITMAP)LoadImageW(NULL,L"images/recherche.bmp",IMAGE_BITMAP,170,50,LR_LOADFROMFILE);

}
