#ifndef RECHERCHE_VILLE_AFFICHAGE_H_INCLUDED
#define RECHERCHE_VILLE_AFFICHAGE_H_INCLUDED


HWND recherche_ville_affichage_fenetre;

LRESULT CALLBACK RechercheVilleAffichageProcedure (HWND hwnd, UINT msg, WPARAM wp , LPARAM lp);
void registerRechercheVilleAffichageFenetreClass(HINSTANCE hInstance);
HWND displayRechercheVilleAffichageFenetre (HWND hwnd, repertoire rt , char ville [35]);

#include "../fichiers_c/recherche_ville_affichage.c"

#endif // RECHERCHE_VILLE_AFFICHAGE_H_INCLUDED
