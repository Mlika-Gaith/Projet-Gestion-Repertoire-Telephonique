#ifndef RECHERCHE_NOM_H_INCLUDED
#define RECHERCHE_NOM_H_INCLUDED

LRESULT CALLBACK RechercheNomFenetreProcedure (HWND hwnd, UINT msg, WPARAM wp , LPARAM lp);
void registerRechercheNomFenetre (HINSTANCE hInstance);
HWND displayRechercheNomFenetre (HWND hwnd);

#include "../fichiers_c/recherche_nom.c"

#endif // RECHERCHE_NOM_H_INCLUDED
