#ifndef AFFICHAGE_H_INCLUDED
#define AFFICHAGE_H_INCLUDED

LRESULT CALLBACK AffichageProcedure (HWND hwnd, UINT msg, WPARAM wp , LPARAM lp);
void registerAffichageClass(HINSTANCE hInstance);
HWND displayAffichage (HWND hwnd);


#include "../fichiers_c/affichage.c"


#endif // AFFICHAGE_H_INCLUDED
