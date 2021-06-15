#include<windows.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "../headers/variables.h"



 /****************************************************************************
*
*
*    FONCTION: taille_liste_rep
*
*    BUT: renvoie la taille du répaertoire téléphonique.
*
****************************************************************************/


int taille_liste_rep (repertoire rt){

    repertoire r = rt;
    int taille = 0;
    while( r != NULL){
        taille ++;
        r = r->suiv;
    }

    return taille;

}

 /****************************************************************************
*
*
*    FONCTION: recherche_tel
*
*    BUT: vérifie si un numero est déja existant.
*
****************************************************************************/

 int recherche_tel (repertoire rt, char num[35] ){

    repertoire r =rt;
    while (r != NULL){
        if (strcmp(r->cont.numero,num) == 0){
            return -1;
        }
        r=r->suiv;
    }
    return 1;

 }
  /****************************************************************************
*
*
*    FONCTION: insere_tete_tel
*
*    BUT: inserer un contact en tête du répertoire
*
****************************************************************************/

repertoire insere_tete_tel(repertoire rt, contact cont){

    repertoire r;
    r = (repertoire)malloc(sizeof(contact));
    r ->suiv = rt;
    r->cont = cont;
    rt = r;
    return rt;
}

 /****************************************************************************
*
*
*    FONCTION: insere_queue_tel
*
*    BUT: inserer un contact en queue du répertoire
*
****************************************************************************/

repertoire insere_queue_tel (repertoire rt, contact cont){

    repertoire r1, r2;
    r1 = (repertoire) malloc(sizeof(contact));
    r1->cont = cont;
    r1->suiv =  NULL;
    if (rt == NULL){
        rt = r1;
    }
    else{
        r2 = rt;
        while (r2->suiv != NULL){
            r2 = r2->suiv;
        }
        r2->suiv = r1;
    }

    return rt;

}
 /****************************************************************************
*
*
*    FONCTION: insere_pos_tel
*
*    BUT: inserer un contact dans une position précisée dans le répertoire.
*
****************************************************************************/
void insere_pos_tel (repertoire rt, contact cont, int position){

    repertoire r2, r1 = rt;
    int i = 1;
    while (i<position - 1){
        r1 = r1->suiv;
        i ++;
    }

    r2 = (repertoire) malloc (sizeof(contact));
    r2->cont = cont;
    r2->suiv = r1 -> suiv;
    r1->suiv = r2;



}
 /****************************************************************************
*
*
*    FONCTION: supprimer_tete_tel
*
*    BUT: supprimer un contact en tête du répertoire
*
****************************************************************************/

repertoire supprimer_tete_tel(repertoire rt){

    repertoire r = NULL;
    r = rt;
    rt = rt->suiv;
    free (r);
    return rt;


}

 /****************************************************************************
*
*
*    FONCTION: supprimer_queue_tel
*
*    BUT: supprimer un contact en queue du répertoire
*
****************************************************************************/

repertoire supprimer_queue_tel (repertoire rt){

    repertoire r1 = rt;

    while (r1->suiv->suiv != NULL){
        r1 = r1->suiv;
    }
    free(r1->suiv);
    r1->suiv = NULL;
    return rt;

}
 /****************************************************************************
*
*
*    FONCTION: supprimer_pos_tel
*
*    BUT: supprimer un contact dans une position donnée
*
****************************************************************************/

void supprimer_pos_tel (repertoire rt, int position){

    repertoire r1 = rt, r2;


    if (position == 1){
        free(r1->suiv);
        r1->suiv = NULL;
    }

    else{
        int i =1;
        while (i < position - 1){
            r1 = r1->suiv;
            i++;
        }

        r2 = r1->suiv->suiv;
        free(r1->suiv);
        r1 ->suiv = r2;
    }


}

 /****************************************************************************
*
*
*    FONCTION: suppression_tel_donne
*
*    BUT: suppression d'un contact à partir d'un numero de tel
*
****************************************************************************/


repertoire suppression_tel_donne (repertoire rt, char numero [10]){

    repertoire r1 = NULL, r2 = NULL;
    r1 = rt;
    int ok = 0;

    if (strcmp(r1->cont.numero,numero) == 0){
        rt = r1->suiv;
        free(r1);
    }
    else{
        while (r1->suiv != NULL){
            if (strcmp(r1->suiv->cont.numero,numero) == 0){
                ok = 1;
                break;
            }
            else{
                r1 = r1->suiv;
            }
        }

        if (ok == 1){
            r2 = r1->suiv;
            r1->suiv = r2->suiv;
            free(r2);

        }

    }

    return rt;

}


 /****************************************************************************
*
*
*    FONCTION: supprimer_ville_donnee
*
*    BUT: supprimer les contacts d'une ville donnee
*
****************************************************************************/


repertoire supprimer_ville_donnee (repertoire rt, char ville [35], HWND hwnd){

        repertoire r1 = rt;
        repertoire r2 = NULL;

        int compteur = 0;


        // suppression du premier noeud s'il contient la ville correspondante

        while (r1 != NULL && strcmp(r1->cont.adr.ville,ville) == 0){

                rt = r1 ->suiv;
                free(r1);
                r1 = rt;
                compteur ++;

        }

        while (r1 != NULL){

            while (r1 != NULL && strcmp(r1->cont.adr.ville,ville) != 0){
                r2 = r1;
                r1 =r1->suiv;
            }

            if (r1 == NULL)
            {
                if (compteur == 0)
                    MessageBoxW(hwnd,L" Aucune Ville avec ce Nom ",L" Operation Echoue ",MB_OK | MB_ICONEXCLAMATION);
                else
                    MessageBoxW(hwnd,L" Suppression Avec Succes ",L" Succes ",MB_OK | MB_ICONINFORMATION);
                return rt;

            }

            compteur ++;
            r2->suiv = r1->suiv;
            free(r1);
            r1 =  r2->suiv;


        }

        if (compteur == 0)
            MessageBoxW(hwnd,L" Aucune Ville avec ce Nom ",L" Operation Echoue ",MB_OK | MB_ICONEXCLAMATION);
        else
            MessageBoxW(hwnd,L" Suppression Avec Succes ",L" Succes ",MB_OK | MB_ICONINFORMATION);

    return rt;
}


 /****************************************************************************
*
*
*    FONCTION: supprimer_indicatif_donne
*
*    BUT: supprimer les contacts d'un indicatif donne
*
****************************************************************************/



repertoire supprimer_indicatif_donne (repertoire rt, char indicatif_donne [10], HWND hwnd){

        repertoire r1 = rt;
        repertoire r2 = NULL;

        int compteur = 0;
        char indicatif [3];

        // suppression du premier noeud s'il contient l'indicatif correspondant

        while (r1 != NULL && strcmp(strncpy(indicatif,r1->cont.numero,2),indicatif_donne) == 0){

                rt = r1 ->suiv;
                free(r1);
                r1 = rt;
                compteur ++;

        }

        while (r1 != NULL){

            while (r1 != NULL && strcmp(strncpy(indicatif,r1->cont.numero,2),indicatif_donne) != 0){
                r2 = r1;
                r1 =r1->suiv;
            }

            if (r1 == NULL)
            {
                if (compteur == 0)
                    MessageBoxW(hwnd,L" Aucun Numero avec cet Indicatif ",L" Operation Echoue ",MB_OK | MB_ICONEXCLAMATION);
                else
                    MessageBoxW(hwnd,L" Suppression Avec Succes ",L" Succes ",MB_OK | MB_ICONINFORMATION);
                return rt;

            }

            compteur ++;
            r2->suiv = r1->suiv;
            free(r1);
            r1 =  r2->suiv;


        }

        if (compteur == 0)
            MessageBoxW(hwnd,L" Aucune Ville avec ce Nom ",L" Operation Echoue ",MB_OK | MB_ICONEXCLAMATION);
        else
            MessageBoxW(hwnd,L" Suppression Avec Succes ",L" Succes ",MB_OK | MB_ICONINFORMATION);


    return rt;
}





 /****************************************************************************
*
*
*    FONCTION: creation
*
*    BUT: creation d'un contact à partir d'un String
*    (à utiliser avec la fonction recuperation).
*
****************************************************************************/

contact creation (char contact_info [500]){

    char *ptr = strtok(contact_info,",");
    char *data [9]; // contient la date après séparation jour,mois,année
    int i =0;

    while (ptr != NULL){
        data[i++] = ptr;
        ptr = strtok(NULL,",");
    }

    contact cont ;
    strcpy(cont.numero,data[0]);
    strcpy(cont.nom,data[1]);
    strcpy(cont.prenom,data[2]);
    strcpy(cont.date_naissance,data[3]);
    strcpy(cont.email,data[4]);
    strcpy(cont.adr.ville,data[5]);
    strcpy(cont.adr.rue,data [6]);
    strcpy(cont.adr.code,data [7]);

    return cont;


}
 /****************************************************************************
*
*
*    FONCTION: verifier_date
*
*    BUT: vérifie si une date de naissance est légitime.
*
****************************************************************************/

int verifier_date (char date [20]){


        char date_naissance [20];
        strcpy(date_naissance,date);
        int i =0;


       char *ptr = strtok(date_naissance,"/");
       char *data [3]; // contient la date après séparation jour,mois,année

       while (ptr != NULL){
        data[i++] = ptr;
        ptr = strtok(NULL,"/");
       }


        if (strlen(date) != 10 || strlen(data[0]) != 2 || // vérifier si la date est sous la forme jj/mm/aaaa
            strlen(data[1]) != 2 || strlen(data[2]) != 4 || i != 3 ){
                return -1;
            }

        int jour = atoi(data[0]); // convertir jour , mois annee en intger
        int mois = atoi(data[1]);
        int annee = atoi(data[2]);

        int bissextile = 0;
        int mois_max = 12;
        int jour_max = 0;
        if (annee < 1930)
            return -1;

        // verifier si l'année est bissextile
        if (((annee%4 == 0) && (annee%100 != 0)) || annee%400 == 0){

            bissextile = 1;
        }
        else{
            bissextile = 0;
        }

        // verifier si mois>0 && mois<=12
        if (mois <0 || mois > mois_max){
            return -1;
        }

        switch(mois){
        case 4:
        case 6:
        case 9:
        case 11:
            jour_max = 30;
            break;
        case 2:
            if (bissextile == 1){
                jour_max = 29;
            }
            else{
                jour_max = 28;
            }
            break;
        default:
            jour_max = 31;


        }

        if (jour<0 || jour>jour_max){
            return -1;
        }



        return 1;




}

 /****************************************************************************
*
*
*    FONCTION: verifier_numero
*
*    BUT: vérifie si un numéro est légitime (composé de 8 numero)
*
****************************************************************************/

int verifier_numero(char numero [30]){

    int num_telephone;

    int len = strlen(numero);


    num_telephone = atoi(numero);


    int longueur = floor(log10(num_telephone))+1; // longeur du numero doit être composé de 8 numéros.



    if ((longueur < 8) || num_telephone < 0 || len != 8 || (longueur>8))
        return -1;

    return 1; // numero valide

}

/****************************************************************************
*
*
*    FONCTION: tri
*
*    BUT: trier tout les contacts selon les numeros de tel
*
****************************************************************************/

repertoire tri (repertoire rt){


    repertoire r1 = NULL, r2 = NULL;
    r1 = rt;

    while(r1->suiv != NULL){
        r2 = r1->suiv;

        while (r2 != NULL){

            if (strcmp(r1->cont.numero, r2->cont.numero) > 0){


                contact cont = r1->cont;
                r1->cont = r2->cont;
                r2->cont = cont;


            }
            r2 = r2->suiv;
        }

        r1 = r1->suiv;
    }


    return rt;


}





 /****************************************************************************
*
*
*    FONCTION: afficher
*
*    BUT: afficher tout les contacts
*
****************************************************************************/

void afficher (repertoire rt){

    repertoire r = rt;
    if (r == NULL)
        printf("Liste vide");
    else {
        while (r != NULL){
           printf("%s\n",r->cont.numero);
           printf("%s\n",r->cont.nom);
           printf("%s\n",r->cont.prenom);
           printf("%s\n",r->cont.date_naissance);
           printf("%s\n",r->cont.email);
           printf("%s\n",r->cont.adr.code);
           printf("%s\n",r->cont.adr.ville);
           printf("%s\n",r->cont.adr.rue);
            r = r->suiv;
        }
    }

}

 /****************************************************************************
*
*
*    FONCTION: saisie_contact
*
*    BUT: saisie des données d'un contact
*
****************************************************************************/

contact saisie_contact(char numero [30],char nom [30], char prenom [30], char date [30],
                       char email [35], char ville [35], char rue [35], char code [35] ){

            contact cont;

            strcpy(cont.numero,numero);
            strcpy(cont.nom,nom);
            strcpy(cont.prenom,prenom);
            strcpy(cont.date_naissance,date);
            strcpy(cont.email,email);
            strcpy(cont.adr.ville,ville);
            strcpy(cont.adr.rue,rue);
            strcpy(cont.adr.code,code);

            return cont;
}
