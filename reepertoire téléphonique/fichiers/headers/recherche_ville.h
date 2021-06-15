#ifndef RECHERCHE_VILLE_H_INCLUDED
#define RECHERCHE_VILLE_H_INCLUDED

LRESULT CALLBACK RechercheVilleFenetreProcedure (HWND hwnd, UINT msg, WPARAM wp , LPARAM lp);
void registerRechercheVilleFenetre (HINSTANCE hInstance);
HWND displayRechercheVilleFenetre (HWND hwnd);

HWND recherche_ville_donne;

#include "../fichiers_c/recherche_ville.c"

#endif // RECHERCHE_VILLE_H_INCLUDED
