#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



#include "../headers/variables.h"
#include "../headers/fonctions.h"



HWND supprimer_fenetre; //child window
HWND box;
HWND hBoutton_Supp_Tete, hBoutton_Supp_Queue, hBoutton_Supp_Position;
HWND hPosition;
HBITMAP hSupprimerTeteImage, hSupprimerQueueImage, hSupprimerPositionImage;


LRESULT CALLBACK SupprimerFenetreProcedure (HWND hwnd, UINT msg, WPARAM wp , LPARAM lp){


    switch (msg){
    case WM_COMMAND:
        switch (wp){

            case SUPPRESSION_TETE_BOUTTON:
                {
                    if (nouveau_repertoire != NULL){
                       int valeur;
                        valeur = MessageBox(hwnd," Voulez-Vous Supprimer Le Contact En Tete Du Repertoire ? "," Attention !! ",MB_YESNO | MB_ICONEXCLAMATION);
                        if (valeur == IDYES){
                            nouveau_repertoire = supprimer_tete_tel(nouveau_repertoire);
                            MessageBox(hwnd," Suppression Avec Succes "," Succes ",MB_OK | MB_ICONINFORMATION);
                        }
                    }
                    else{
                        MessageBox(hwnd," Repertoire Deja Vide"," Attention !! ",MB_OK | MB_ICONERROR);
                    }


                }
            break;

            case SUPPRESSION_QUEUE_BOUTTON:
                {

                      if (nouveau_repertoire != NULL){
                       int valeur;
                        valeur = MessageBox(hwnd," Voulez-Vous Supprimer Le Contact En Queue Du Repertoire ? "," Attention !! ",MB_YESNO | MB_ICONEXCLAMATION);
                        if (valeur == IDYES){
                            nouveau_repertoire = supprimer_queue_tel(nouveau_repertoire);
                            MessageBox(hwnd," Suppression Avec Succes "," Succes ",MB_OK | MB_ICONINFORMATION);
                        }
                    }
                    else{
                        MessageBox(hwnd," Repertoire Deja Vide"," Attention !! ",MB_OK | MB_ICONERROR);
                    }

                }
                break;

            case SUPPRESSION_POSITION_BOUTTON:
                {

                    char pos [35];
                    GetWindowText(hPosition,pos,35);
                    int position_suppression = atoi(pos);
                    int taille = taille_liste_rep(nouveau_repertoire);

                    if (nouveau_repertoire != NULL){

                        if(position_suppression< 1 || position_suppression > taille){
                            MessageBoxW(hwnd,L" Position Erronee (sup a la taille du repertoire ou inferieure a 0) ",L" Erreur ",MB_OK | MB_ICONERROR);
                            SetWindowText(hPosition,"");
                        }

                        if (position_suppression == 1 || position_suppression == taille){
                            MessageBoxW(hwnd,L" Position egale a la tete ou a la queue du repertoire. Utilisez supprimer tete ou supprimer queue ",L" Attention ",MB_OK | MB_ICONEXCLAMATION);
                            SetWindowText(hPosition,"");
                        }


                        if (position_suppression> 1 && position_suppression < taille){

                            int valeur = MessageBoxW(hwnd,L" Vous voulez supprimer ce contact ? ",L" Attention ",MB_YESNO| MB_ICONEXCLAMATION);

                            if (valeur == IDYES){
                                supprimer_pos_tel(nouveau_repertoire,position_suppression);
                                MessageBoxW(hwnd,L" Contact Supprime Avec succes ",L" Succes ",MB_OK| MB_ICONINFORMATION);

                            }

                        }


                    }
                    else{
                        MessageBox(hwnd," Repertoire Deja Vide"," Attention !! ",MB_OK | MB_ICONERROR);
                    }


                }
            break;

        }
        break;
    case WM_CREATE:
        loadImagesSupprimerFenetre();
        break;
    case WM_SIZE:
        {
        RECT MainRect;
        int MainWidth, MainHeight;
        GetWindowRect(supprimer_fenetre, &MainRect);
        MainWidth = MainRect.right - MainRect.left;
        MainHeight = MainRect.bottom - MainRect.top;
        SetWindowPos(box, hwnd, (MainWidth)/4,(MainHeight)/8, (MainWidth)/2, (MainHeight)-200, SWP_NOZORDER);
        SetWindowPos(hBoutton_Supp_Tete,hwnd,MainWidth-780,179,170,50, SWP_NOZORDER);
        SetWindowPos(hBoutton_Supp_Queue,hwnd,MainWidth-780,235,170,50, SWP_NOZORDER);
        SetWindowPos(hBoutton_Supp_Position,hwnd,MainWidth-780,290,170,50, SWP_NOZORDER);

        }
        break;

    case WM_CLOSE:
        DestroyWindow(supprimer_fenetre);
        break;
    default:
        return DefWindowProcW(hwnd,msg,wp,lp);

    }


}


void registerSupprimerFenetreClass(HINSTANCE hInstance){

    WNDCLASSW suppFen = {0};
    suppFen.hbrBackground = (HBRUSH) COLOR_WINDOW;
    suppFen.hCursor = LoadCursor(NULL,IDC_ARROW);
    suppFen.hInstance = hInstance;
    suppFen.lpszClassName = L"SupprimerTelephone";
    suppFen.lpfnWndProc = SupprimerFenetreProcedure;

    RegisterClassW(&suppFen);

}

HWND displaySupprimerFenetre(HWND hwnd){

    supprimer_fenetre = CreateWindowW(L"SupprimerTelephone",L" Supprimer un Contact ", WS_OVERLAPPEDWINDOW | WS_VISIBLE,
                  50,50,800,700,hwnd,NULL,NULL,NULL);

    RECT MainRect;
    int MainWidth, MainHeight;
    GetWindowRect(supprimer_fenetre, &MainRect);
    MainWidth = MainRect.right - MainRect.left;
    MainHeight = MainRect.bottom - MainRect.top;

    box = CreateWindowW(L"Button", L" Supprimer un Contact ",WS_CHILD | WS_VISIBLE | BS_GROUPBOX,(MainWidth)/4,(MainHeight)/8, (MainWidth)/2, (MainHeight)-200,supprimer_fenetre,NULL,NULL, NULL);
    hBoutton_Supp_Tete = CreateWindowW(L"Button",L"Supprimer en Tete",WS_VISIBLE|WS_CHILD| BS_BITMAP,MainWidth-480,179,170,50,supprimer_fenetre,(HMENU)SUPPRESSION_TETE_BOUTTON,NULL,NULL);
    SendMessageW(hBoutton_Supp_Tete,BM_SETIMAGE,IMAGE_BITMAP,(LPARAM)hSupprimerTeteImage);
    hBoutton_Supp_Queue = CreateWindowW(L"Button",L"Supprimer en Queue",WS_VISIBLE|WS_CHILD| BS_BITMAP,MainWidth-480,239,170,50,supprimer_fenetre,(HMENU)SUPPRESSION_QUEUE_BOUTTON ,NULL,NULL);
    SendMessageW(hBoutton_Supp_Queue,BM_SETIMAGE,IMAGE_BITMAP,(LPARAM)hSupprimerQueueImage);

    CreateWindowW(L"Static",L" Position :",WS_VISIBLE | WS_CHILD | SS_CENTER, 100,310,100,40,box,NULL,NULL,NULL);
    hPosition = CreateWindowW (L"Edit",L"",WS_VISIBLE | WS_CHILD | WS_BORDER | ES_MULTILINE | ES_AUTOVSCROLL | ES_CENTER,200,300,90,40,box,NULL,NULL,NULL);


    hBoutton_Supp_Position = CreateWindowW(L"Button",L"Supprimer avec Position",WS_VISIBLE|WS_CHILD| BS_BITMAP,MainWidth-480,300,170,50,supprimer_fenetre,(HMENU)SUPPRESSION_POSITION_BOUTTON,NULL,NULL);
    SendMessageW(hBoutton_Supp_Position,BM_SETIMAGE,IMAGE_BITMAP,(LPARAM)hSupprimerPositionImage);

    return supprimer_fenetre;


}
void loadImagesSupprimerFenetre(){

    hSupprimerTeteImage = (HBITMAP)LoadImageW(NULL,L"images/Supprimer_tete.bmp",IMAGE_BITMAP,170,50,LR_LOADFROMFILE);
    hSupprimerQueueImage = (HBITMAP)LoadImageW(NULL,L"images/supprimer_queue.bmp",IMAGE_BITMAP,170,50,LR_LOADFROMFILE);
    hSupprimerPositionImage = (HBITMAP)LoadImageW(NULL,L"images/supprimer_position.bmp",IMAGE_BITMAP,170,50,LR_LOADFROMFILE);
}

