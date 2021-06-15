#ifndef RECHERCHE_NUMERO_H_INCLUDED
#define RECHERCHE_NUMERO_H_INCLUDED

LRESULT CALLBACK RechercheNumeroFenetreProcedure (HWND hwnd, UINT msg, WPARAM wp , LPARAM lp);
void registerRechercheNumeroFenetre (HINSTANCE hInstance);
HWND displayRechercheNumeroFenetre (HWND hwnd);

HWND recherche_numero_donne;

#include "../fichiers_c/recherche_numero.c"

#endif // RECHERCHE_NUMERO_H_INCLUDED
