#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include<commctrl.h>


#include "../headers/variables.h"
#include "../headers/fonctions.h"

HWND affichage_window;
HWND hListView;

LRESULT CALLBACK AffichageProcedure (HWND hwnd, UINT msg, WPARAM wp , LPARAM lp){


    switch (msg){
    case WM_COMMAND:



        break;

    case WM_CREATE:
        break;
    case WM_SIZE:
        {
        RECT MainRect;
        int MainWidth, MainHeight;
        GetWindowRect(affichage_window, &MainRect);
        MainWidth = MainRect.right - MainRect.left;
        MainHeight = MainRect.bottom - MainRect.top;
        SetWindowPos(hListView, hwnd,0,0,MainRect.right - MainRect.left,MainHeight = MainRect.bottom - MainRect.top, SWP_NOZORDER);
        }
        break;

    case WM_CLOSE:
        DestroyWindow(affichage_window);
        break;
    default:
        return DefWindowProcW(hwnd,msg,wp,lp);

    }


}

void registerAffichageClass(HINSTANCE hInstance){

    WNDCLASSW affichage = {0};
    affichage.hbrBackground = (HBRUSH) COLOR_WINDOW;
    affichage.hCursor = LoadCursor(NULL,IDC_ARROW);
    affichage.hInstance = hInstance;
    affichage.lpszClassName = L"Affichage";
    affichage.lpfnWndProc = AffichageProcedure;

    RegisterClassW(&affichage);

}


HWND displayAffichage (HWND hwnd){

    affichage_window = CreateWindowW(L"Affichage",L" Contenu du Repertoire Telephonique ", WS_OVERLAPPEDWINDOW | WS_VISIBLE | WS_VSCROLL | WS_HSCROLL,
                  50,50,1350,800,hwnd,NULL,NULL,NULL);

    RECT MainRect;
    int MainWidth, MainHeight;
    GetWindowRect(affichage_window, &MainRect);
    MainWidth = MainRect.right - MainRect.left;
    MainHeight = MainRect.bottom - MainRect.top;

    // adding columns
	TCHAR szText[256] = {0};
	TCHAR szString[9][20] = { TEXT("Index"),TEXT("Numero"),TEXT("Nom"),TEXT("Prenom"),TEXT("Date De Naissance"),TEXT("Email"),TEXT("Ville"),TEXT("RUE"),TEXT("Code") };

    hListView = CreateWindowEx(0, WC_LISTVIEW, 0, WS_CHILD |WS_VISIBLE | WS_BORDER | LVS_ALIGNLEFT | LVS_REPORT | LVS_EDITLABELS ,0,0,MainRect.right - MainRect.left,
                                     MainRect.bottom - MainRect.top,affichage_window,NULL, NULL, NULL);
    ListView_SetExtendedListViewStyleEx(hListView, LVS_EX_GRIDLINES, LVS_EX_GRIDLINES);


    LVCOLUMN lvc;
	ListView_DeleteAllItems(hListView);
    lvc.mask = LVCF_FMT | LVCF_WIDTH | LVCF_TEXT | LVCF_SUBITEM;

    for (int k = 0; k < 9; k++)
	{
		lvc.iSubItem = k;
		lvc.cx       = 150;
		lvc.pszText  = szString[k];
		lvc.fmt      = LVCFMT_LEFT;

		ListView_InsertColumn(hListView, k, &lvc);
	}


    // aading sub items


    LVITEM lvi;
    memset(&lvi,0,sizeof(LVITEM));
    lvi.mask      = LVIF_TEXT | LVIF_PARAM | LVIF_STATE;
    lvi.state     = 0;
    lvi.stateMask = 0;


    repertoire r2 = NULL;
    r2 = nouveau_repertoire;
    int taille = taille_liste_rep(r2);
    int valeur;


    //contact (liste à afficher)


    if (r2 == NULL){
        valeur = MessageBoxW(hwnd,L" Reprtoire Vide ",L" Attention !! ",MB_OK | MB_ICONEXCLAMATION);
        if (valeur == IDOK){
            DestroyWindow(affichage_window);
        }
    }

    int k = 0;
    int f =0;
    while (r2 != NULL){


        lvi.iItem    = k;
        lvi.iSubItem = 0;
        f = k +1;
        char index [50];

        int res = ListView_InsertItem(hListView, &lvi);
        ListView_SetItemText(hListView,k,0,itoa(f,index,10));
        ListView_SetItemText(hListView,k,1,r2->cont.numero);
        ListView_SetItemText(hListView,k,2,r2->cont.nom);
        ListView_SetItemText(hListView,k,3,r2->cont.prenom);
        ListView_SetItemText(hListView,k,4,r2->cont.date_naissance);
        ListView_SetItemText(hListView,k,5,r2->cont.email);
        ListView_SetItemText(hListView,k,6,r2->cont.adr.ville);
        ListView_SetItemText(hListView,k,7,r2->cont.adr.rue);
        ListView_SetItemText(hListView,k,8,r2->cont.adr.code);

        k ++;
        r2 = r2->suiv;

    }

    return affichage_window;


}
