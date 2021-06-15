#ifndef RECHERCHE_INDICATIF_AFFICHAGE_H_INCLUDED
#define RECHERCHE_INDICATIF_AFFICHAGE_H_INCLUDED


LRESULT CALLBACK RechercheIndicatifAffichageProcedure (HWND hwnd, UINT msg, WPARAM wp , LPARAM lp);

void registerRechercheIndicatifAffichageFenetreClass(HINSTANCE hInstance);

HWND displayRechercheIndicatifAffichageFenetre (HWND hwnd, repertoire rt , char indicatif [35]);

#include "../fichiers_c/recherche_indicatif_affichage.c"

#endif // RECHERCHE_INDICATIF_AFFICHAGE_H_INCLUDED
