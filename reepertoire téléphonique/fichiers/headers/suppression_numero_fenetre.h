#ifndef SUPPRESSION_NUMERO_FENETRE_H_INCLUDED
#define SUPPRESSION_NUMERO_FENETRE_H_INCLUDED

LRESULT CALLBACK SuppressionNumeroFenetreProcedure (HWND hwnd, UINT msg, WPARAM wp , LPARAM lp);
void registerSuppressionNumeroFenetre (HINSTANCE hInstance);
HWND displaySuppressionNumeroFenetre (HWND hwnd);

#include "../fichiers_c/suppression_numero_fenetre.c"

#endif // SUPPRESSION_NUMERO_FENETRE_H_INCLUDED
