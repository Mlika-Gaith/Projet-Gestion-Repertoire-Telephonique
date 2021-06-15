#ifndef RECHERCHE_INDICATIF_H_INCLUDED
#define RECHERCHE_INDICATIF_H_INCLUDED

HWND recherche_indicatif_donne;

LRESULT CALLBACK RechercheIndicatifFenetreProcedure (HWND hwnd, UINT msg, WPARAM wp , LPARAM lp);
void registerRechercheIndicatifFenetre (HINSTANCE hInstance);
HWND displayRechercheIndicatifFenetre (HWND hwnd);

#include "../fichiers_c/recherche_indicatif.c"


#endif // RECHERCHE_INDICATIF_H_INCLUDED
