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

    // Menu mise � Jour

    HMENU hAjout = CreateMenu ();
    HMENU hSupprimer = CreateMenu();

    // Ajout des subMenus du menu mise � jour

    AppendMenu(hMiseAjour,MF_POPUP,AJOUT,"Ajouter un nouvel contact");
    AppendMenu(hMiseAjour,MF_SEPARATOR,NULL,NULL);
    AppendMenu(hMiseAjour,MF_POPUP,(UINT_PTR) hSupprimer,"Supprimer un contact ");
    AppendMenu(hMiseAjour,MF_SEPARATOR,NULL,NULL);
    AppendMenu(hMiseAjour,MF_POPUP,MODIFIER,"Modifier les donn�es d'un contact");

    // Les subMenus des subMenus du menu mise � jour


    AppendMenu(hSupprimer,MF_STRING,SUPPRESSION,"Supprimer un numero");
    AppendMenu(hSupprimer,MF_SEPARATOR,NULL,NULL);
    AppendMenu(hSupprimer,MF_STRING,SUPPRESSION_TELEPHONE,"Suppression d'un t�l�phone donn�");
    AppendMenu(hSupprimer,MF_SEPARATOR,NULL,NULL);
    AppendMenu(hSupprimer,MF_STRING,SUPPRESSION_VILLE,"Suppression des t�l�phones d'une ville donn�e");
    AppendMenu(hSupprimer,MF_SEPARATOR,NULL,NULL);
    AppendMenu(hSupprimer,MF_STRING,SUPPRESSION_INDICATIF,"Suppression des t�l�phones d'un indicatif donn�");





    // Menu Recherche & Affichage

    AppendMenu(hRechAffTri,MF_STRING,CONTENU_LISTE,"Contenu de la liste des t�l�phones");
    AppendMenu(hRechAffTri,MF_SEPARATOR,NULL,NULL);
    AppendMenu(hRechAffTri,MF_STRING,RECHERCHE_NUMERO,"Recherche par num�ro t�l�phone");
    AppendMenu(hRechAffTri,MF_SEPARATOR,NULL,NULL);
    AppendMenu(hRechAffTri,MF_STRING,RECHERCHE_NOM,"Recherche par nom");
    AppendMenu(hRechAffTri,MF_SEPARATOR,NULL,NULL);
    AppendMenu(hRechAffTri,MF_STRING,RECHERCHE_INDICATIF,"Recherche par indicatif t�l�phone");
    AppendMenu(hRechAffTri,MF_SEPARATOR,NULL,NULL);
    AppendMenu(hRechAffTri,MF_STRING,RECHERCHE_VILLE,"Recherche par ville");
    AppendMenu(hRechAffTri,MF_SEPARATOR,NULL,NULL);
    AppendMenu(hRechAffTri,MF_STRING,TRI_LISTE,"Tri 1");


    // Menu Enregistrement & chargement

    AppendMenu(hEnregCharg,MF_STRING,ENREGISTREMENT_LISTE,"Enregistrement");
    AppendMenu(hEnregCharg,MF_SEPARATOR,NULL,NULL);
    AppendMenu(hEnregCharg,MF_STRING,CHARGEMENT_LISTE,"Chargement");

    // MENU FICHIERS

    AppendMenu(hFichiers,MF_STRING,OUVRIR_ENNONCE,"Ouvrir Ennonc�");
    AppendMenu(hFichiers,MF_SEPARATOR,NULL,NULL);
    AppendMenu(hFichiers,MF_STRING,OUVRIR_FICHIER_TXT,"Ouvrir Repertoire.txt");

    /** Ajout Des Menus G�n�rales **/

    AppendMenu(hMenu,MF_STRING,CREATION, "Cr�ation");
    AppendMenu(hMenu,MF_SEPARATOR,NULL,NULL);
    AppendMenu(hMenu,MF_POPUP,(UINT_PTR) hMiseAjour, "Mise � Jour");
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
