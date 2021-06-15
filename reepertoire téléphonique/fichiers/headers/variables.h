#ifndef VARIABLES_H_INCLUDED
#define VARIABLES_H_INCLUDED

#define AJOUT 1
#define SUPPRESSION 2
#define SUPPRESSION_TELEPHONE 3
#define SUPPRESSION_VILLE 4
#define SUPPRESSION_INDICATIF 5
#define MODIFIER 6

#define CONTENU_LISTE 8
#define RECHERCHE_NUMERO 9
#define RECHERCHE_NOM 10
#define RECHERCHE_INDICATIF 11
#define RECHERCHE_VILLE 12
#define TRI_LISTE 13
#define QUITTER 14
#define ENREGISTREMENT_LISTE 15
#define CHARGEMENT_LISTE 16
#define CREATION 17


#define AJOUTER_BOUTTON_TETE 19
#define AJOUTER_BOUTTON_QUEUE 18
#define AJOUTER_BOUTTON_POSITION 20


#define SUPPRESSION_VILLE_BOUTTON 21
#define AJOUTER_POSITION_NOMBRE 22
#define RECHERCHE_NUMERO_BOUTTON 23
#define SUPPRESSION_NUMERO_BOUTTON 24
#define SUPPRESSION_INDICATIF_BOUTTON 25
#define RECHERCHE_VILLE_BOUTTON 29
#define RECHERCHE_NOM_BOUTTON 30
#define RECHERCHE_INDICATIF_BOUTTON 31

#define SUPPRESSION_TETE_BOUTTON 26
#define SUPPRESSION_QUEUE_BOUTTON 27
#define SUPPRESSION_POSITION_BOUTTON 28
#define MODIFIER_RECHERCHE_BOUTTON 32
#define MODIFIER_NUMERO_BOUTTON 33
#define MODIFIER_ADRESSE_BOUTTON 34
#define OUVRIR_ENNONCE 40
#define OUVRIR_FICHIER_TXT 41




/** ====== LES VARIABLES ===== **/
typedef struct adresse{
        char rue [35];
        char ville[35];
        char code [10];


} adresse;



typedef struct contact{
        char numero [20];
        char nom[35];
        char prenom [35];
        adresse adr;
        char date_naissance [18];
        char email [100];


}contact;

typedef struct cellule {
        contact cont;
        struct cellule *suiv;

}cellule;

typedef struct cellule* repertoire;

/** ====== LES VARIABLES ===== **/



repertoire nouveau_repertoire = NULL; // repertoire principale
HWND main_window; // fenetre principale

int chargement_repertoire = 0; // verification du chargement
int creation_repertoire = 0; // verification de la création



#endif // VARIABLES_H_INCLUDED
