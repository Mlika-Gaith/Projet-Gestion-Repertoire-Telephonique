#ifndef FONCTIONS_H_INCLUDED
#define FONCTIONS_H_INCLUDED

int taille_liste_rep (repertoire rt);

int recherche_tel (repertoire rt, char num[35]);

repertoire insere_tete_tel(repertoire rt, contact cont);

repertoire insere_queue_tel (repertoire rt, contact cont);

void insere_pos_tel (repertoire rt, contact cont, int position);

repertoire supprimer_tete_tel(repertoire rt);

repertoire supprimer_queue_tel (repertoire rt);

void supprimer_pos_tel (repertoire rt, int position);

repertoire supprimer_ville_donnee (repertoire rt, char ville [35], HWND hwnd);

repertoire suppression_tel_donne (repertoire rt, char numero [10]);

contact creation (char contact_info [500]);

int verifier_date (char date [20]);

int verifier_numero(char numero [20]);

void afficher (repertoire rt);

repertoire tri (repertoire rt);


#include "../fichiers_c/fonctions.c"

#endif // FONCTIONS_H_INCLUDED
