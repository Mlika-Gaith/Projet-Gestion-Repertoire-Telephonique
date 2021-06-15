#ifndef RECHERCHE_NUMERO_AFFICHAGE_H_INCLUDED
#define RECHERCHE_NUMERO_AFFICHAGE_H_INCLUDED

LRESULT CALLBACK RechercheNumeroAffichageFenetreProcedure (HWND hwnd, UINT msg, WPARAM wp , LPARAM lp);
void registerRechercheNumeroAffichageFenetreClass(HINSTANCE hInstance);
HWND displayRechercheNumeroAffichagefenetre(HWND hwnd,repertoire rt);

#include "../fichiers_c/recherche_numero_affichage.c"

#endif // RECHERCHE_NUMERO_AFFICHAGE_H_INCLUDED
