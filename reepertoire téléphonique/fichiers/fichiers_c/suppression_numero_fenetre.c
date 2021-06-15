#include <windows.h>
#include "../headers/variables.h"

HWND suppression_numero_fenetre;

HWND box;
HWND hButton;
HWND hTelephone;
HBITMAP hSupprimerTelephoneImage;

LRESULT CALLBACK SuppressionNumeroFenetreProcedure (HWND hwnd, UINT msg, WPARAM wp , LPARAM lp){


    switch (msg){
    case WM_COMMAND:
        switch (wp){


        case SUPPRESSION_NUMERO_BOUTTON :
            {
                // variables

                char telephone [35];



                // getting input field text

                GetWindowText(hTelephone,telephone,20);



                if (verifier_numero(telephone) == -1){
                    MessageBoxW(hwnd,L" Numero Errone ",L" Erreur ",MB_OK | MB_ICONERROR);
                }
                if (recherche_tel(nouveau_repertoire,telephone) == 1){
                    MessageBoxW(hwnd,L" Numero Non Existant ",L" Operation a Echoue ",MB_OK | MB_ICONEXCLAMATION);
                }
                else{
                    nouveau_repertoire = suppression_tel_donne(nouveau_repertoire,telephone);
                    MessageBoxW(hwnd,L" Contact Supprime Avec Succes ",L" Succes ",MB_OK | MB_ICONINFORMATION);

                }



            }
        break;


        }
        break;

    case WM_CREATE:
        loadImagesSupprimerIndicatifFenetre();
        break;
    case WM_SIZE:
        {
        RECT MainRect;
        int MainWidth, MainHeight;
        GetWindowRect(suppression_numero_fenetre, &MainRect);
        MainWidth = MainRect.right - MainRect.left;
        MainHeight = MainRect.bottom - MainRect.top;
        SetWindowPos(box, hwnd, (MainWidth)/4,(MainHeight)/8, (MainWidth)/2, (MainHeight)-200, SWP_NOZORDER);
        SetWindowPos(hButton, hwnd,(MainWidth-170)/2,MainHeight-140,100,50, SWP_NOZORDER);
        }
        break;

    case WM_CLOSE:
        DestroyWindow(suppression_numero_fenetre);
        break;
    default:
        return DefWindowProcW(hwnd,msg,wp,lp);

    }


}


void registerSuppressionNumeroFenetre (HINSTANCE hInstance){

    WNDCLASSW suppNum = {0};
    suppNum.hbrBackground = (HBRUSH) COLOR_WINDOW;
    suppNum.hCursor = LoadCursor(NULL,IDC_ARROW);
    suppNum.hInstance = hInstance;
    suppNum.lpszClassName = L"SuppressionTelephoneFenetre";
    suppNum.lpfnWndProc = SuppressionNumeroFenetreProcedure;

    RegisterClassW(&suppNum);

}


HWND displaySuppressionNumeroFenetre (HWND hwnd){

    suppression_numero_fenetre = CreateWindowW(L"SuppressionTelephoneFenetre",L" Entrez un Numero de Telephone ", WS_OVERLAPPEDWINDOW | WS_VISIBLE,
                  50,50,450,450,hwnd,NULL,NULL,NULL);

    RECT MainRect;
    int MainWidth, MainHeight;
    GetWindowRect(suppression_numero_fenetre, &MainRect);
    MainWidth = MainRect.right - MainRect.left;
    MainHeight = MainRect.bottom - MainRect.top;

    box = CreateWindowW(L"Button", L" Numero ",WS_CHILD | WS_VISIBLE | BS_GROUPBOX,(MainWidth)/4,(MainHeight)/8, (MainWidth)/2, (MainHeight)-200,suppression_numero_fenetre,NULL,NULL, NULL);


    CreateWindowW(L"Static",L" Telephone :",WS_VISIBLE | WS_CHILD | SS_CENTER, 5,80,130,40,box,NULL,NULL,NULL);
    hTelephone = CreateWindowW (L"Edit",L"",WS_VISIBLE | WS_CHILD | WS_BORDER | ES_MULTILINE | ES_AUTOVSCROLL | ES_CENTER,120,70,90,40,box,NULL,NULL,NULL);
    hButton = CreateWindowW(L"Button",L"Choisir",WS_VISIBLE|WS_CHILD| BS_BITMAP,(MainWidth-170)/2,MainHeight-130,170,50,suppression_numero_fenetre,(HMENU)SUPPRESSION_NUMERO_BOUTTON,NULL,NULL);
    SendMessageW(hButton,BM_SETIMAGE,IMAGE_BITMAP,(LPARAM)hSupprimerTelephoneImage);

    return suppression_numero_fenetre;


}

void loadImagesSupprimerIndicatifFenetre(){

    hSupprimerTelephoneImage = (HBITMAP)LoadImageW(NULL,L"images/Supprimer.bmp",IMAGE_BITMAP,170,50,LR_LOADFROMFILE);

}
