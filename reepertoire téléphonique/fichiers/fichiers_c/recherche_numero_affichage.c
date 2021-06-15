#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "../headers/variables.h"
#include "../headers/fonctions.h"
#include "../headers/recherche_numero.h"



HWND recherche_numero_affichage; //child window
HWND box;
HWND hNumeroAFF,hNomAFF,hPrenomAFF,hDateAFF,hEmailAFF,hVilleAFF,hRueAFF,hCodeAFF;



LRESULT CALLBACK RechercheNumeroAffichageFenetreProcedure (HWND hwnd, UINT msg, WPARAM wp , LPARAM lp){


    switch (msg){




    case WM_CREATE:
        EnableWindow(recherche_numero_donne,FALSE);
        break;
    case WM_SIZE:
        {
        RECT MainRect;
        int MainWidth, MainHeight;
        GetWindowRect(recherche_numero_affichage, &MainRect);
        MainWidth = MainRect.right - MainRect.left;
        MainHeight = MainRect.bottom - MainRect.top;
        SetWindowPos(box, hwnd, (MainWidth)/4,(MainHeight)/8, (MainWidth)/2, (MainHeight)-200, SWP_NOZORDER);
        SetWindowPos(hButton, hwnd,(MainWidth-100)/2,600,100,50, SWP_NOZORDER);
        }
        break;

    case WM_CLOSE:
        DestroyWindow(recherche_numero_affichage);
        DestroyWindow(recherche_numero_donne);
        break;
    default:
        return DefWindowProcW(hwnd,msg,wp,lp);

    }


}


void registerRechercheNumeroAffichageFenetreClass(HINSTANCE hInstance){

    WNDCLASSW rechNumAff = {0};
    rechNumAff.hbrBackground = (HBRUSH) COLOR_WINDOW;
    rechNumAff.hCursor = LoadCursor(NULL,IDC_ARROW);
    rechNumAff.hInstance = hInstance;
    rechNumAff.lpszClassName = L"rechercheNumeroAffichageFenetre";
    rechNumAff.lpfnWndProc = RechercheNumeroAffichageFenetreProcedure ;

    RegisterClassW(&rechNumAff);

}

HWND displayRechercheNumeroAffichagefenetre(HWND hwnd,repertoire rt){

    recherche_numero_affichage = CreateWindowW(L"rechercheNumeroAffichageFenetre",L" Resultat ", WS_OVERLAPPEDWINDOW | WS_VISIBLE,
                  50,50,800,800,hwnd,NULL,NULL,NULL);

    RECT MainRect;
    int MainWidth, MainHeight;
    GetWindowRect(recherche_numero_affichage, &MainRect);
    MainWidth = MainRect.right - MainRect.left;
    MainHeight = MainRect.bottom - MainRect.top;

    box = CreateWindowW(L"Button", L" Resultat ",WS_CHILD | WS_VISIBLE | BS_GROUPBOX,(MainWidth)/4,(MainHeight)/8, (MainWidth)/2, (MainHeight)-200,recherche_numero_affichage,NULL,NULL, NULL);


    CreateWindowW(L"Static",L" Numero :",WS_VISIBLE | WS_CHILD | SS_CENTER, 40,90,150,40,box,NULL,NULL,NULL);
    hNumeroAFF = CreateWindowW (L"Static",L"",WS_VISIBLE | WS_CHILD | SS_CENTER,190,90,100,40,box,NULL,NULL,NULL);
    SetWindowText(hNumeroAFF,rt->cont.numero);

    CreateWindowW(L"Static",L" Nom :",WS_VISIBLE | WS_CHILD | SS_CENTER, 40,140,150,40,box,NULL,NULL,NULL);
    hNomAFF = CreateWindowW (L"Static",L"",WS_VISIBLE | WS_CHILD | SS_CENTER,190,140,100,40,box,NULL,NULL,NULL);
    SetWindowText(hNomAFF,rt->cont.nom);

    CreateWindowW(L"Static",L" Prenom :",WS_VISIBLE | WS_CHILD | SS_CENTER, 40,190,150,40,box,NULL,NULL,NULL);
    hPrenomAFF = CreateWindowW (L"Static",L"",WS_VISIBLE | WS_CHILD | SS_CENTER,190,190,100,40,box,NULL,NULL,NULL);
    SetWindowText(hPrenomAFF,rt->cont.prenom);

    CreateWindowW(L"Static",L" Date de Naissance :",WS_VISIBLE | WS_CHILD | SS_CENTER, 40,240,150,40,box,NULL,NULL,NULL);
    hDateAFF = CreateWindowW (L"Static",L"",WS_VISIBLE | WS_CHILD | SS_CENTER,190,240,100,40,box,NULL,NULL,NULL);
    SetWindowText(hDateAFF,rt->cont.date_naissance);

    CreateWindowW(L"Static",L" Email :",WS_VISIBLE | WS_CHILD | SS_CENTER, 40,290,100,40,box,NULL,NULL,NULL);
    hEmailAFF = CreateWindowW (L"Static",L"",WS_VISIBLE | WS_CHILD | SS_CENTER,160,290,200,40,box,NULL,NULL,NULL);
    SetWindowText(hEmailAFF,rt->cont.email);

    CreateWindowW(L"Static",L" Ville :",WS_VISIBLE | WS_CHILD | SS_CENTER, 40,340,100,40,box,NULL,NULL,NULL);
    hVilleAFF = CreateWindowW (L"Static",L"",WS_VISIBLE | WS_CHILD | SS_CENTER,190,340,100,40,box,NULL,NULL,NULL);
    SetWindowText(hVilleAFF,rt->cont.adr.ville);

    CreateWindowW(L"Static",L" Rue :",WS_VISIBLE | WS_CHILD | SS_CENTER, 40,390,100,40,box,NULL,NULL,NULL);
    hRueAFF = CreateWindowW (L"Static",L"",WS_VISIBLE | WS_CHILD | SS_CENTER,190,390,100,40,box,NULL,NULL,NULL);
    SetWindowText(hRueAFF,rt->cont.adr.rue);

    CreateWindowW(L"Static",L" Code :",WS_VISIBLE | WS_CHILD | SS_CENTER, 40,440,100,40,box,NULL,NULL,NULL);
    hCodeAFF = CreateWindowW (L"Static",L"",WS_VISIBLE | WS_CHILD | SS_CENTER,190,440,100,40,box,NULL,NULL,NULL);
    SetWindowText(hCodeAFF,rt->cont.adr.code);



    return recherche_numero_affichage;


}
