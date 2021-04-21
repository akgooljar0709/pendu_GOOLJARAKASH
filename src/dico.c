
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include "../include/dico.h"


int piocherMot(char *motPioche)
{
    FILE* dico = NULL; // Le pointeur de fichier qui va contenir notre fichier
    int nombreMots = 0, numMotChoisi = 0, i = 0;
    int caractereLu = 0;
    char ans[10];

    printf("Chosissez votre mode de difficulte [facile,moyen,difficile]\n"); 
    scanf("%s", ans);   


    if(strcmp(ans,"facile") == 0){

        dico = fopen("../ressource/word_4.txt", "r"); // On ouvre le dictionnaire en lecture seule
    }

    else if (strcmp(ans,"moyen") == 0) {
        dico = fopen("../ressource/word_5.txt", "r"); // On ouvre le dictionnaire en lecture seule 
    }

    else if (strcmp(ans,"difficile") == 0) {
        dico = fopen("../ressource/word_6.txt", "r"); // On ouvre le dictionnaire en lecture seule 
    }

    else {printf("Erreur\n");}



    // On v�rifie si on a r�ussi � ouvrir le dictionnaire
    if (dico == NULL) // Si on n'a PAS r�ussi � ouvrir le fichier
    {
        printf("\nImpossible de charger le dictionnaire de mots");
        return 0; // On retourne 0 pour indiquer que la fonction a �chou�
        // A la lecture du return, la fonction s'arr�te imm�diatement.
    }

    // On compte le nombre de mots dans le fichier (il suffit de compter les
    // entr�es \n
    do
    {
        caractereLu = fgetc(dico);
        if (caractereLu == '\n')
            nombreMots++;
    } while(caractereLu != EOF);


    numMotChoisi = nombreAleatoire(nombreMots); // On pioche un mot au hasard
    // On recommence � lire le fichier depuis le d�but. On s'arr�te lorsqu'on est arriv�s au bon mot
    rewind(dico);
    while (numMotChoisi > 0)
    {
        caractereLu = fgetc(dico);
        if (caractereLu == '\n')
            numMotChoisi--;
    }

    /* Le curseur du fichier est positionn� au bon endroit.
    On n'a plus qu'� faire un fgets qui lira la ligne */
    fgets(motPioche, 100, dico);

    // On vire l'\n � la fin
    motPioche[strlen(motPioche) - 1] = '\0';
    fclose(dico);

    return 1; // Tout s'est bien pass�, on retourne 1
}

int nombreAleatoire(int nombreMax)
{
    srand(time(NULL));
    return (rand() % nombreMax);
}


char lireCaractere()
{
    char caractere = 0;


     // On lit les autres caract�res m�moris�s un � un jusqu'� l'\n
    while (getchar() != '\n') ;
    caractere = getchar(); // On lit le premier caract�re
    caractere = toupper(caractere); // On met la lettre en majuscule si elle ne l'est pas d�j�
    
   
   

    return caractere; // On retourne le premier caract�re qu'on a lu
}


int gagne(int lettreTrouvee[], long tailleMot)
{
    long i = 0;
    int joueurGagne = 1;

    for (i = 0 ; i < tailleMot ; i++)
    {
        if (lettreTrouvee[i] == 0)
            joueurGagne = 0;
    }

    return joueurGagne;
}

int rechercheLettre(char lettre, char motSecret[], int lettreTrouvee[])
{
    long i = 0;
    int bonneLettre = 0;
   

    // On parcourt motSecret pour v�rifier si la lettre propos�e y est
    for (i = 0 ; motSecret[i] != '\0' ; i++)
    {
        if (lettre == motSecret[i]) // Si la lettre y est
        {
            bonneLettre = 1; // On m�morise que c'�tait une bonne lettre
            lettreTrouvee[i] = 1; // On met � 1 le case du tableau de bool�ens correspondant � la lettre actuelle
        }

        /*else if(lettre == 4)
        {

                printf("%c\n",motSecret[1]);
    
            }*/

    }



    

    return bonneLettre;
}


char hint(char z)
{
    char caractere = 0;

    caractere = z; // On lit le premier caract�re
    caractere = toupper(caractere); // On met la lettre en majuscule si elle ne l'est pas d�j�

    // On lit les autres caract�res m�moris�s un � un jusqu'� l'\n
    while (getchar() != '\n') ;

    return caractere; // On retourne le premier caract�re qu'on a lu
}