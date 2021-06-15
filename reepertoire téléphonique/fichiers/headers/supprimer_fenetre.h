#ifndef SUPPRIMER_FENETRE_H_INCLUDED
#define SUPPRIMER_FENETRE_H_INCLUDED

LRESULT CALLBACK SupprimerFenetreProcedure (HWND hwnd, UINT msg, WPARAM wp , LPARAM lp);
void registerSupprimerFenetreClass(HINSTANCE hInstance);
HWND displaySupprimerFenetre(HWND hwnd);

#include "../fichiers_c/supprimer_fenetre.c"

#endif // SUPPRIMER_FENETRE_H_INCLUDED
