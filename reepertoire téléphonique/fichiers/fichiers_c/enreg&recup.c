#include <string.h>
#include <math.h>


 /****************************************************************************
*
*
*    FONCTION: enregistrer
*
*    BUT: enregistrement de la Liste dans un fichier
*
****************************************************************************/

void enregistrer (repertoire rt, char * nomFichier){

    repertoire r = NULL;

    FILE *fp;
    FILE *tempFile;
    fp = fopen(nomFichier,"w");
    tempFile = fopen("tmpfile.txt","w");

    for (r = rt; r != NULL; r = r->suiv){

        fprintf(fp,"%s,%s,%s,%s,%s,%s,%s,%s\n",
                r->cont.numero,r->cont.nom,r->cont.prenom,r->cont.date_naissance,
                r->cont.email,r->cont.adr.ville,r->cont.adr.rue,r->cont.adr.code);


    }
    fclose(fp);
    fp = fopen(nomFichier,"r");
    removeEmptyLines(fp, tempFile);
    fclose(fp);
    fclose(tempFile);
    remove(nomFichier);
    rename("tmpfile.txt",nomFichier);


}

 /****************************************************************************
*
*
*    FONCTION: recuperation
*
*    BUT: recuperation et création d'une liste (répertoire) à partir d'un
*    fichier.txt
*
****************************************************************************/

repertoire recuperation (repertoire rt,char * nomFichier){


        FILE *fp;
        char line [1000];
        contact cont;
        repertoire r = NULL;
        r = rt;

        fp = fopen(nomFichier,"r");

        while (fgets(line, sizeof(line), fp)) {

            cont = creation(line);
            r = insere_queue_tel(r,cont);
        }

        fclose(fp);
        return r;


}

int isEmpty(const char *str)
{
    char ch;

    do
    {
        ch = *(str++);

        // Check non whitespace character
        if(ch != ' ' && ch != '\t' && ch != '\n' && ch != '\r' && ch != '\0')
            return 0;

    } while (ch != '\0');

    return 1;
}
void removeEmptyLines(FILE *srcFile, FILE *tempFile)
{
    char buffer[1000];

    while ((fgets(buffer, 1000, srcFile)) != NULL)
    {
        /* If current line is not empty then write to temporary file */
        if(!isEmpty(buffer))
            fputs(buffer, tempFile);
    }

}
