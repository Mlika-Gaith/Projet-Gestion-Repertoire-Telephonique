#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

/** Inclure Les Fichiers Ici **/


#include "fichiers/headers/variables.h"
#include "fichiers/headers/menus.h"
#include "fichiers/headers/ajout_fenetre.h"
#include "fichiers/headers/affichage.h"
#include "fichiers/headers/supprimer_fenetre.h"
#include "fichiers/headers/enreg&recup.h"
#include "fichiers/headers/suppression_numero_fenetre.h"
#include "fichiers/headers/suppression_ville_donnee.h"
#include "fichiers/headers/suppression_indicatif_fenetre.h"
#include "fichiers/headers/recherche_numero.h"
#include "fichiers/headers/recherche_numero_affichage.h"
#include "fichiers/headers/recherche_ville.h"
#include "fichiers/headers/recherche_ville_affichage.h"
#include "fichiers/headers/recherche_nom.h"
#include "fichiers/headers/recherche_nom_affichage.h"
#include "fichiers/headers/recherche_indicatif.h"
#include "fichiers/headers/recherche_indicatif_affichage.h"
#include "fichiers/headers/modifier.h"




LRESULT CALLBACK WindowProcedure (HWND,UINT,WPARAM,LPARAM); // Gestion des messages système et utilisateur de la fenetre principale
HBITMAP hMainImage;
HDC hdc;

int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR args, int ncmdShow)
{

    /** Caractéristiques de La Fenetre principale **/

    WNDCLASS wc = {0};
    wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
    wc.hCursor = LoadCursor(NULL,IDC_ARROW);
    wc.hInstance = hInstance;
    wc.lpszClassName = L"mainWindow";
    wc.lpfnWndProc = WindowProcedure;

    if (!RegisterClassW(&wc)) //enregistrer la fenetre principale
        return -1;

    /** REGISTER CHILD WINDOWS HERE **/

    registerAjoutFenetreClass(hInstance);
    registerAffichageClass(hInstance);
    registerSupprimerFenetreClass(hInstance);
    registerSuppressionNumeroFenetre(hInstance);
    registerSuppressionVilleFenetre(hInstance);
    registerSuppressionIndicatifFenetre(hInstance);
    registerRechercheNumeroFenetre(hInstance);
    registerRechercheNumeroAffichageFenetreClass(hInstance);
    registerRechercheVilleFenetre(hInstance);
    registerRechercheVilleAffichageFenetreClass(hInstance);
    registerRechercheNomFenetre(hInstance);
    registerRechercheNomAffichageFenetreClass(hInstance);
    registerRechercheIndicatifFenetre(hInstance);
    registerRechercheIndicatifAffichageFenetreClass(hInstance);
    registerModifierFenetreClass(hInstance);



    /** CREATING MAIN WINDOW **/

    main_window = CreateWindowW(L"mainWindow",L"Repertoire telephonique",WS_OVERLAPPEDWINDOW | WS_VISIBLE,
                                100,100,900,500,NULL,NULL,NULL,NULL);



    /** Messages **/

    MSG msg = {0};

    while(GetMessage(&msg,NULL,NULL,NULL)){
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    free (nouveau_repertoire);
    return 0;

}

LRESULT CALLBACK WindowProcedure (HWND hwnd,UINT msg,WPARAM wp,LPARAM lp)
{

    switch(msg){

        case WM_CREATE:
            {

                hMainImage = (HBITMAP)LoadImageW(NULL,L"images/main_image.bmp",IMAGE_BITMAP,900,500,LR_LOADFROMFILE);
                addMenus(hwnd);

            }
            break;

        case WM_PAINT :
            {

            PAINTSTRUCT ps;
            hdc = BeginPaint(hwnd, &ps);
            DrawState(hdc,NULL,NULL,(long)hMainImage,0,0,0,0,0,DST_BITMAP);
            EndPaint(hwnd, &ps);

            }
        break;
        case WM_COMMAND:
            switch (wp){


                case CREATION:
                    {
                        if (chargement_repertoire == 0){
                            MessageBoxW(hwnd,L" Veuillez Charger le Repertoire D'abord ! ",L" Erreur !! ",MB_OK | MB_ICONERROR);
                        }
                        else {
                            if (nouveau_repertoire == NULL && creation_repertoire == 0){
                                displayAjoutFenetre(hwnd);

                            }
                            else if (nouveau_repertoire != NULL && creation_repertoire == 0){
                                MessageBoxW(hwnd,L" Repertoire Cree Avec Succes ",L" Succes ",MB_OK | MB_ICONINFORMATION);
                                creation_repertoire = 1;
                            }
                            else{
                                MessageBoxW(hwnd,L" Repertoire Deja Cree ",L" Succes ",MB_OK | MB_ICONINFORMATION);

                            }
                        }


                    }
                break;


                case AJOUT:
                    {

                       if (creation_repertoire == 1){
                            displayAjoutFenetre(hwnd);
                       }
                       else{
                            MessageBoxW(hwnd,L" Veuillez Creer Le reprtoire D'abord !! ",L" Attention !! ",MB_OK | MB_ICONEXCLAMATION);
                       }

                    }

                    break;


                case CONTENU_LISTE:
                    {
                        if (creation_repertoire == 1){
                            displayAffichage(hwnd);
                       }
                       else{
                            MessageBoxW(hwnd,L" Veuillez Creer Le reprtoire D'abord !! ",L" Attention !! ",MB_OK | MB_ICONEXCLAMATION);
                       }

                    }
                    break;


                case SUPPRESSION:
                    {
                        if (creation_repertoire == 1) {
                            displaySupprimerFenetre(hwnd);
                        }
                        else{
                            MessageBoxW(hwnd,L" Veuillez Creer Le reprtoire D'abord !! ",L" Attention !! ",MB_OK | MB_ICONEXCLAMATION);
                       }

                    }
                    break;

                case SUPPRESSION_TELEPHONE:
                    {
                        if (creation_repertoire == 1) {
                            displaySuppressionNumeroFenetre(hwnd);
                        }
                        else{
                            MessageBoxW(hwnd,L" Veuillez Creer Le reprtoire D'abord !! ",L" Attention !! ",MB_OK | MB_ICONEXCLAMATION);
                       }
                    }
                    break;

                case SUPPRESSION_VILLE:
                    {
                        if (creation_repertoire == 1){
                            displaySuppressionVilleFenetre(hwnd);
                        }
                        else{
                            MessageBoxW(hwnd,L" Veuillez Creer Le reprtoire D'abord !! ",L" Attention !! ",MB_OK | MB_ICONEXCLAMATION);
                        }
                    }
                    break;

                case SUPPRESSION_INDICATIF:
                    {

                        if (creation_repertoire == 1){
                            displaySuppressionIndicatifFenetre(hwnd);
                        }
                        else{
                            MessageBoxW(hwnd,L" Veuillez Creer Le reprtoire D'abord !! ",L" Attention !! ",MB_OK | MB_ICONEXCLAMATION);
                        }
                    }
                    break;

                case MODIFIER:
                    {
                        if (creation_repertoire == 1){
                            displayModifierFenetre(hwnd);
                        }
                        else{
                            MessageBoxW(hwnd,L" Veuillez Creer Le reprtoire D'abord !! ",L" Attention !! ",MB_OK | MB_ICONEXCLAMATION);
                        }
                    }
                    break;


                case RECHERCHE_NUMERO:
                    {
                        if (creation_repertoire == 1){
                            displayRechercheNumeroFenetre(hwnd);
                        }
                        else{
                            MessageBoxW(hwnd,L" Veuillez Creer Le reprtoire D'abord !! ",L" Attention !! ",MB_OK | MB_ICONEXCLAMATION);
                        }

                    }
                    break;

                case RECHERCHE_NOM:
                    {
                        if (creation_repertoire == 1){
                            displayRechercheNomFenetre(hwnd);
                        }
                        else{
                            MessageBoxW(hwnd,L" Veuillez Creer Le reprtoire D'abord !! ",L" Attention !! ",MB_OK | MB_ICONEXCLAMATION);
                        }
                    }
                    break;


                case RECHERCHE_INDICATIF:
                    {
                        if (creation_repertoire == 1){
                            displayRechercheIndicatifFenetre(hwnd);
                        }
                        else{
                            MessageBoxW(hwnd,L" Veuillez Creer Le reprtoire D'abord !! ",L" Attention !! ",MB_OK | MB_ICONEXCLAMATION);
                        }
                    }
                    break;


                case RECHERCHE_VILLE:
                    {

                         if (creation_repertoire == 1){
                            displayRechercheVilleFenetre(hwnd);
                        }
                        else{
                            MessageBoxW(hwnd,L" Veuillez Creer Le reprtoire D'abord !! ",L" Attention !! ",MB_OK | MB_ICONEXCLAMATION);
                        }
                    }
                    break;

                case TRI_LISTE:
                    {
                        if (creation_repertoire == 1){
                            int valeur = MessageBoxW(hwnd,L" Voulez-Vous Trier Le Repertoire Selon Les Numeros ? ",L" Trier ?? ", MB_YESNO | MB_ICONINFORMATION);
                            if (valeur == IDYES){
                                nouveau_repertoire = tri(nouveau_repertoire);
                            }
                        }
                        else{
                            MessageBoxW(hwnd,L" Veuillez Creer Le reprtoire D'abord !! ",L" Attention !! ",MB_OK | MB_ICONEXCLAMATION);
                        }

                    }
                    break;


                case ENREGISTREMENT_LISTE:
                    {
                        if (nouveau_repertoire == NULL){
                            int valeur = MessageBoxW(hwnd,L" Repertoire Vide Voulez-Vous L'enregistrer Quand Meme ? ",L" Attention !! ",MB_YESNO | MB_ICONEXCLAMATION);
                            if (valeur ==  IDYES){
                                enregistrer(nouveau_repertoire,"repertoire.txt");
                                MessageBoxW(hwnd,L" Repertoire Enregistre Avec Succes ", L" Succes ", MB_OK | MB_ICONINFORMATION);
                            }
                        }
                        else{
                            enregistrer(nouveau_repertoire,"repertoire.txt");
                            MessageBoxW(hwnd,L" Repertoire Enregistre Avec Succes ",L" Succes ", MB_OK | MB_ICONINFORMATION);
                        }


                    }
                    break;


                case CHARGEMENT_LISTE:
                    {
                        if (chargement_repertoire == 0){
                            nouveau_repertoire = recuperation(nouveau_repertoire,"repertoire.txt");
                            chargement_repertoire = 1;
                            MessageBoxW(hwnd,L"Repertoire Recupere Avec Succes ",L" Succes ",MB_OK | MB_ICONINFORMATION);
                        }
                        else{
                            MessageBoxW(hwnd,L"Repertoire deja Recupere ",L" Attention !! ",MB_OK | MB_ICONEXCLAMATION);
                        }
                    }
                    break;

                case OUVRIR_ENNONCE:
                    {
                        ShellExecute( NULL, "open", "projet.pdf", NULL, NULL, SW_SHOWNORMAL );
                    }
                    break;


                case OUVRIR_FICHIER_TXT:
                    {
                        ShellExecute( NULL, "open", "repertoire.txt", NULL, NULL, SW_SHOWNORMAL );
                    }
                    break;

                case QUITTER:
                    {
                        int valeur = MessageBoxW(hwnd,L" Voulez-Vous Vraiment Quitter ? ",L" Attention !! ", MB_YESNO |MB_ICONINFORMATION);
                        if (valeur == IDYES){
                            DestroyWindow(main_window);
                        }
                    }
                    break;


            }
            break;
        case WM_DESTROY :
            PostQuitMessage(0);
            break;
        default:
            return DefWindowProcW(hwnd,msg,wp,lp);


    }

}










