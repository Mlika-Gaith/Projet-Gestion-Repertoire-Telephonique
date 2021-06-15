#ifndef AJOUT_FENETRE_H_INCLUDED
#define AJOUT_FENETRE_H_INCLUDED

LRESULT CALLBACK AjoutFenetreProcedure (HWND hwnd, UINT msg, WPARAM wp , LPARAM lp);
void registerAjoutFenetreClass(HINSTANCE hInstance);
HWND displayAjoutFenetre(HWND hwnd);

char nom [35],prenom [35], numero [35],
date [30], email[35], rue [35], ville[35],
code [30];


#include "../fichiers_c/ajout_fenetre.c"

#endif // AJOUT_FENETRE_H_INCLUDED
