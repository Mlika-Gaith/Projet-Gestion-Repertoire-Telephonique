#include <windows.h>
#include "../headers/variables.h"



HWND suppression_indicatif_fenetre;
HWND box;
HWND hButton;
HWND hIndicatif;
HBITMAP hSupprimerIndicatifImage;

LRESULT CALLBACK SuppressionIndicatifFenetreProcedure (HWND hwnd, UINT msg, WPARAM wp , LPARAM lp){


    switch (msg){
    case WM_COMMAND:
        switch (wp){


        case SUPPRESSION_INDICATIF_BOUTTON :
            {
                // variables

                char indicatif [10];



                // getting input field text

                GetWindowText(hIndicatif,indicatif,10);
                printf("%s\n",indicatif);


                /*int taille = taille_liste_rep(nouveau_repertoire);
                printf("%d\n",taille);*/

                if (strlen(indicatif) != 2){
                    MessageBoxW(hwnd,L" Indicatif Errone ",L" Erreur ",MB_OK | MB_ICONERROR);
                }

                else{
                    nouveau_repertoire = supprimer_indicatif_donne(nouveau_repertoire,indicatif,hwnd);

                }



            }
        break;


        }
        break;

    case WM_CREATE:
        loadImagesSupprimerTelephoneFenetre();
        break;
    case WM_SIZE:
        {
        RECT MainRect;
        int MainWidth, MainHeight;
        GetWindowRect(suppression_indicatif_fenetre, &MainRect);
        MainWidth = MainRect.right - MainRect.left;
        MainHeight = MainRect.bottom - MainRect.top;
        SetWindowPos(box, hwnd, (MainWidth)/4,(MainHeight)/8, (MainWidth)/2, (MainHeight)-200, SWP_NOZORDER);
        SetWindowPos(hButton, hwnd,(MainWidth-170)/2,MainHeight-140,100,50, SWP_NOZORDER);
        }
        break;

    case WM_CLOSE:
        DestroyWindow(suppression_indicatif_fenetre);
        break;
    default:
        return DefWindowProcW(hwnd,msg,wp,lp);

    }


}


void registerSuppressionIndicatifFenetre (HINSTANCE hInstance){

    WNDCLASSW suppInd = {0};
    suppInd.hbrBackground = (HBRUSH) COLOR_WINDOW;
    suppInd.hCursor = LoadCursor(NULL,IDC_ARROW);
    suppInd.hInstance = hInstance;
    suppInd.lpszClassName = L"SuppressionIndicatifFenetre";
    suppInd.lpfnWndProc = SuppressionIndicatifFenetreProcedure;

    RegisterClassW(&suppInd);

}


HWND displaySuppressionIndicatifFenetre (HWND hwnd){

    suppression_indicatif_fenetre = CreateWindowW(L"SuppressionIndicatifFenetre",L" Entrez un Indicatif de Telephone ", WS_OVERLAPPEDWINDOW | WS_VISIBLE,
                  50,50,450,450,hwnd,NULL,NULL,NULL);

    RECT MainRect;
    int MainWidth, MainHeight;
    GetWindowRect(suppression_indicatif_fenetre, &MainRect);
    MainWidth = MainRect.right - MainRect.left;
    MainHeight = MainRect.bottom - MainRect.top;

    box = CreateWindowW(L"Button", L" Indicatif ",WS_CHILD | WS_VISIBLE | BS_GROUPBOX,(MainWidth)/4,(MainHeight)/8, (MainWidth)/2, (MainHeight)-200,suppression_indicatif_fenetre,NULL,NULL, NULL);


    CreateWindowW(L"Static",L" Indicatif :",WS_VISIBLE | WS_CHILD | SS_CENTER, 5,80,130,40,box,NULL,NULL,NULL);
    hIndicatif = CreateWindowW (L"Edit",L"",WS_VISIBLE | WS_CHILD | WS_BORDER | ES_MULTILINE | ES_AUTOVSCROLL,120,70,90,40,box,NULL,NULL,NULL);
    hButton = CreateWindowW(L"Button",L"Choisir",WS_VISIBLE|WS_CHILD| BS_BITMAP,(MainWidth-170)/2,MainHeight-130,170,50,suppression_indicatif_fenetre,(HMENU)SUPPRESSION_INDICATIF_BOUTTON,NULL,NULL);
    SendMessageW(hButton,BM_SETIMAGE,IMAGE_BITMAP,(LPARAM)hSupprimerIndicatifImage);
    return suppression_indicatif_fenetre;


}
void loadImagesSupprimerTelephoneFenetre(){

    hSupprimerIndicatifImage = (HBITMAP)LoadImageW(NULL,L"images/Supprimer.bmp",IMAGE_BITMAP,170,50,LR_LOADFROMFILE);

}
