#ifndef AJOUT_POSITION_FENETRE_H_INCLUDED
#define AJOUT_POSITION_FENETRE_H_INCLUDED

LRESULT CALLBACK AjoutPositionFenetreProcedure (HWND hwnd, UINT msg, WPARAM wp , LPARAM lp);
void registerAjoutPositionFenetreClass (HINSTANCE hInstance);
HWND displayAjoutPositionFenetre (HWND hwnd);

#include "../fichiers_c/ajout_position_fenetre.c"
#endif // AJOUT_POSITION_FENETRE_H_INCLUDED
