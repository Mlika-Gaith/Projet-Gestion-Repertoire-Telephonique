#ifndef RECHERCHE_NOM_AFFICHAGE_H_INCLUDED
#define RECHERCHE_NOM_AFFICHAGE_H_INCLUDED

HWND recherche_nom_affichage_fenetre;

LRESULT CALLBACK RechercheNomAffichageProcedure (HWND hwnd, UINT msg, WPARAM wp , LPARAM lp);

void registerRechercheNomAffichageFenetreClass(HINSTANCE hInstance);

HWND displayRechercheNomAffichageFenetre (HWND hwnd, repertoire rt , char nom [35]);

#include "../fichiers_c/recherche_nom_affichage.c"

#endif // RECHERCHE_NOM_AFFICHAGE_H_INCLUDED
