#include <windows.h>
#include "../headers/variables.h"

HMENU hMenu; //handler for our menu

void addMenus (HWND hwnd){

    /** Mother Menu **/

    hMenu = CreateMenu();

    /** Les Menus Principales **/

    //HMENU hCreation = CreateMenu();
    HMENU hMiseAjour = CreateMenu();
    HMENU hRechAffTri = CreateMenu();
    HMENU hEnregCharg = CreateMenu();
    HMENU quitter = CreateMenu ();
    HMENU hFichiers = CreateMenu();

    /** Les subMenus **/

    // Menu mise à Jour

    HMENU hAjout = CreateMenu ();
    HMENU hSupprimer = CreateMenu();

    // Ajout des subMenus du menu mise à jour

    AppendMenu(hMiseAjour,MF_POPUP,AJOUT,"Ajouter un nouvel contact");
    AppendMenu(hMiseAjour,MF_SEPARATOR,NULL,NULL);
    AppendMenu(hMiseAjour,MF_POPUP,(UINT_PTR) hSupprimer,"Supprimer un contact ");
    AppendMenu(hMiseAjour,MF_SEPARATOR,NULL,NULL);
    AppendMenu(hMiseAjour,MF_POPUP,MODIFIER,"Modifier les données d'un contact");

    // Les subMenus des subMenus du menu mise à jour


    AppendMenu(hSupprimer,MF_STRING,SUPPRESSION,"Supprimer un numero");
    AppendMenu(hSupprimer,MF_SEPARATOR,NULL,NULL);
    AppendMenu(hSupprimer,MF_STRING,SUPPRESSION_TELEPHONE,"Suppression d'un téléphone donné");
    AppendMenu(hSupprimer,MF_SEPARATOR,NULL,NULL);
    AppendMenu(hSupprimer,MF_STRING,SUPPRESSION_VILLE,"Suppression des téléphones d'une ville donnée");
    AppendMenu(hSupprimer,MF_SEPARATOR,NULL,NULL);
    AppendMenu(hSupprimer,MF_STRING,SUPPRESSION_INDICATIF,"Suppression des téléphones d'un indicatif donné");





    // Menu Recherche & Affichage

    AppendMenu(hRechAffTri,MF_STRING,CONTENU_LISTE,"Contenu de la liste des téléphones");
    AppendMenu(hRechAffTri,MF_SEPARATOR,NULL,NULL);
    AppendMenu(hRechAffTri,MF_STRING,RECHERCHE_NUMERO,"Recherche par numéro téléphone");
    AppendMenu(hRechAffTri,MF_SEPARATOR,NULL,NULL);
    AppendMenu(hRechAffTri,MF_STRING,RECHERCHE_NOM,"Recherche par nom");
    AppendMenu(hRechAffTri,MF_SEPARATOR,NULL,NULL);
    AppendMenu(hRechAffTri,MF_STRING,RECHERCHE_INDICATIF,"Recherche par indicatif téléphone");
    AppendMenu(hRechAffTri,MF_SEPARATOR,NULL,NULL);
    AppendMenu(hRechAffTri,MF_STRING,RECHERCHE_VILLE,"Recherche par ville");
    AppendMenu(hRechAffTri,MF_SEPARATOR,NULL,NULL);
    AppendMenu(hRechAffTri,MF_STRING,TRI_LISTE,"Tri 1");


    // Menu Enregistrement & chargement

    AppendMenu(hEnregCharg,MF_STRING,ENREGISTREMENT_LISTE,"Enregistrement");
    AppendMenu(hEnregCharg,MF_SEPARATOR,NULL,NULL);
    AppendMenu(hEnregCharg,MF_STRING,CHARGEMENT_LISTE,"Chargement");

    // MENU FICHIERS

    AppendMenu(hFichiers,MF_STRING,OUVRIR_ENNONCE,"Ouvrir Ennoncé");
    AppendMenu(hFichiers,MF_SEPARATOR,NULL,NULL);
    AppendMenu(hFichiers,MF_STRING,OUVRIR_FICHIER_TXT,"Ouvrir Repertoire.txt");

    /** Ajout Des Menus Générales **/

    AppendMenu(hMenu,MF_STRING,CREATION, "Création");
    AppendMenu(hMenu,MF_SEPARATOR,NULL,NULL);
    AppendMenu(hMenu,MF_POPUP,(UINT_PTR) hMiseAjour, "Mise à Jour");
    AppendMenu(hMenu,MF_SEPARATOR,NULL,NULL);
    AppendMenu(hMenu,MF_POPUP,(UINT_PTR) hRechAffTri, "Recherche, Affichage & Tri");
    AppendMenu(hMenu,MF_SEPARATOR,NULL,NULL);
    AppendMenu(hMenu,MF_POPUP,(UINT_PTR) hEnregCharg, "Enregistrement & Chargement");
    AppendMenu(hMenu,MF_SEPARATOR,NULL,NULL);
    AppendMenu(hMenu,MF_POPUP,(UINT_PTR) hFichiers, "Fichiers");
    AppendMenu(hMenu,MF_SEPARATOR,NULL,NULL);
    AppendMenu(hMenu,MF_STRING,QUITTER, "Quitter");
    SetMenu(hwnd,hMenu);



}
