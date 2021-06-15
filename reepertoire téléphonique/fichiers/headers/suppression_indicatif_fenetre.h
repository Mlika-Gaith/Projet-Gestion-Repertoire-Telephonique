#ifndef SUPPRESSION_INDICATIF_FENETRE_H_INCLUDED
#define SUPPRESSION_INDICATIF_FENETRE_H_INCLUDED

LRESULT CALLBACK SuppressionIndicatifFenetreProcedure (HWND hwnd, UINT msg, WPARAM wp , LPARAM lp);

void registerSuppressionIndicatifFenetre (HINSTANCE hInstance);

HWND displaySuppressionIndicatifFenetre (HWND hwnd);

#include "../fichiers_c/suppression_indicatif_donne.c"

#endif // SUPPRESSION_INDICATIF_FENETRE_H_INCLUDED
