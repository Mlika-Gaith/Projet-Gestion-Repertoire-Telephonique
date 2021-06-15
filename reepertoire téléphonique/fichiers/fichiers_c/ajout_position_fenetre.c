#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../headers/variables.h"
#include "../headers/fonctions.h"
#include "../headers/ajout_fenetre.h"



HWND ajout_position_nombre;
HWND hBoxAjout;
HWND hButton;
HWND hPosition;
int position;

LRESULT CALLBACK AjoutPositionFenetreProcedure (HWND hwnd, UINT msg, WPARAM wp , LPARAM lp){


    switch (msg){
    case WM_COMMAND:
        switch (wp){


        case AJOUTER_POSITION_NOMBRE :
            {
                // variables

                char pos [35];



                // getting input field text

                GetWindowText(hPosition,pos,35);
                //printf("%s\n",pos);
                position = atoi(pos);
                //printf("%d\n",position);
                int taille = taille_liste_rep(nouveau_repertoire);
                printf("%d\n",taille);
                if(position < 1 || position > taille + 1){
                    MessageBoxW(hwnd,L" Position Erronee (sup a la taille du repertoire ou inferieure a 0) ",L" Erreur ",MB_OK | MB_ICONERROR);
                    SetWindowText(hPosition,"");
                }
                if (position == 1 || position == taille + 1){
                    MessageBoxW(hwnd,L" Position egale a la tete ou a la queue du repertoire. Utilisez ajout tete ou ajout queue ",L" Attention ",MB_OK | MB_ICONEXCLAMATION);
                    SetWindowText(hPosition,"");
                }
                if (position > 1 && position < (taille+1)){

                    contact cont;
                    cont = saisie_contact(numero,nom,prenom,date,email,ville,rue,code);
                    insere_pos_tel(nouveau_repertoire,cont,pos);
                }

            }
        break;


        }
        break;

    case WM_CREATE:
        break;
    case WM_SIZE:
        {
        RECT MainRect;
        int MainWidth, MainHeight;
        GetWindowRect(ajout_position_nombre, &MainRect);
        MainWidth = MainRect.right - MainRect.left;
        MainHeight = MainRect.bottom - MainRect.top;
        SetWindowPos(hBoxAjout, hwnd, (MainWidth)/4,(MainHeight)/8, (MainWidth)/2, (MainHeight)-200, SWP_NOZORDER);
        SetWindowPos(hButton, hwnd,(MainWidth-100)/2,MainHeight-140,100,50, SWP_NOZORDER);
        }
        break;

    case WM_CLOSE:
        DestroyWindow(ajout_position_nombre);
        break;
    default:
        return DefWindowProcW(hwnd,msg,wp,lp);

    }


}


void registerAjoutPositionFenetreClass (HINSTANCE hInstance){

    WNDCLASSW ajoutPosNom = {0};
    ajoutPosNom.hbrBackground = (HBRUSH) COLOR_WINDOW;
    ajoutPosNom.hCursor = LoadCursor(NULL,IDC_ARROW);
    ajoutPosNom.hInstance = hInstance;
    ajoutPosNom.lpszClassName = L"AjouterPositionNombreFenetre";
    ajoutPosNom.lpfnWndProc = AjoutPositionFenetreProcedure;

    RegisterClassW(&ajoutPosNom);

}


HWND displayAjoutPositionFenetre (HWND hwnd){

    ajout_position_nombre = CreateWindowW(L"AjouterPositionNombreFenetre",L" Entrez une Position ", WS_OVERLAPPEDWINDOW | WS_VISIBLE,
                  50,50,400,400,hwnd,NULL,NULL,NULL);

    RECT MainRect;
    int MainWidth, MainHeight;
    GetWindowRect(ajout_position_nombre, &MainRect);
    MainWidth = MainRect.right - MainRect.left;
    MainHeight = MainRect.bottom - MainRect.top;

    hBoxAjout = CreateWindowW(L"Button", L" Position ",WS_CHILD | WS_VISIBLE | BS_GROUPBOX,(MainWidth)/4,(MainHeight)/8, (MainWidth)/2, (MainHeight)-200,ajout_position_nombre,NULL,NULL, NULL);


    CreateWindowW(L"Static",L" Position :",WS_VISIBLE | WS_CHILD | SS_CENTER, 10,80,120,40,hBoxAjout,NULL,NULL,NULL);
    hPosition = CreateWindowW (L"Edit",L"",WS_VISIBLE | WS_CHILD | WS_BORDER | ES_MULTILINE | ES_AUTOVSCROLL,110,70,50,40,hBoxAjout,NULL,NULL,NULL);
    hButton = CreateWindowW(L"Button",L"Choisir",WS_VISIBLE|WS_CHILD,(MainWidth-100)/2,MainHeight-140,100,50,ajout_position_nombre,(HMENU)AJOUTER_POSITION_NOMBRE,NULL,NULL);

    return ajout_position_nombre;


}
