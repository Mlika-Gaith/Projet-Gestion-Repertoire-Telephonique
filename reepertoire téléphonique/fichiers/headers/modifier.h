#ifndef MODIFIER_H_INCLUDED
#define MODIFIER_H_INCLUDED

HWND modifier_fenetre;


LRESULT CALLBACK ModifierFenetreProcedure (HWND hwnd, UINT msg, WPARAM wp , LPARAM lp);
void registerModifierFenetreClass (HINSTANCE hInstance);
HWND displayModifierFenetre (HWND hwnd);

#include "../fichiers_c/modifier.c"

#endif // MODIFIER_H_INCLUDED
