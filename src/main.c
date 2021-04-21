
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "../include/dico.h"


int main(int argc, char* argv[])
{
    char lettre = 0; // Stocke la lettre propos�e par l'utilisateur (retour du scanf)
    char motSecret[100] = {0}; // Ce sera le mot � trouver
    int *lettreTrouvee = NULL; // Un tableau de bool�ens. Chaque case correspond � une lettre du mot secret. 0 = lettre non trouv�e, 1 = lettre trouv�e
    long coupsRestants = 8; // Compteur de coups restants (0 = mort)
    long i = 0; // Une petite variable pour parcourir les tableaux
    long tailleMot = 0;
    char lettre_hint = 1;


    

    printf("Bienvenue dans le Pendu !\n\n");
    printf("Regles Du jeux\n\n");
    

    if (!piocherMot(motSecret))
        exit(0);

    tailleMot = strlen(motSecret);

    lettreTrouvee = malloc(tailleMot * sizeof(int)); // On alloue dynamiquement le tableau lettreTrouvee (dont on ne connaissait pas la taille au d�part)
    if (lettreTrouvee == NULL)
        exit(0);

    for (i = 0 ; i < tailleMot ; i++)
        lettreTrouvee[i] = 0;

    // On continue � jouer tant qu'il reste au moins un coup � jouer ou qu'on
    // n'a pas gagn�
    while (coupsRestants > 0 && !gagne(lettreTrouvee, tailleMot))
    {
        
        printf("\n\nIl vous reste %ld coups a jouer", coupsRestants);
        printf("\nQuel est le mot secret ? ");


        /* On affiche le mot secret en masquant les lettres non trouv�es
        Exemple : *A**ON */

        for (i = 0 ; i < tailleMot ; i++)
        {

            if (lettreTrouvee[i]) // Si on a trouv� la lettre n�i
                printf("%c", motSecret[i]); // On l'affiche

            
                
            else
                printf("_"); // Sinon, on affiche une �toile pour les lettres non trouv�es
        }


        printf("\nProposez une lettre : ");
        lettre = lireCaractere();

        char indice[10];
        
        //Section Hint
              if(coupsRestants <= 6)
               {

                    printf("\nVoudriez vous avoir un indice [oui/non]:\n");
                    scanf("%s",indice);

                    if(strcmp(indice,"oui") == 0)
                    {
                        char z = motSecret[rand()% tailleMot];
                        printf("Hint : %c \n", z);
                        
                        lettre = hint(z);//on revoie la valeur de la fonction z et on l'envoie a lettre
                        printf("%c\n", lettre);


                    }

                    else if(strcmp(indice,"non") == 0)
                    {
                        printf("\nProposez une lettre : ");
                        char y = lettre;

                    }

                  

               }
           

                
                            
                    
              
                        
                            
                   




             

                 //on revoie la valeur de z a lettre


        // Si ce n'�tait PAS la bonne lettre
        if (!rechercheLettre(lettre, motSecret, lettreTrouvee))
        {
            coupsRestants--; // On enl�ve un coup au joueur
        }

        
    }


    if (gagne(lettreTrouvee, tailleMot))
        printf("\n\nGagne ! Le mot secret etait bien : %s", motSecret);
    else
        printf("\n\nPerdu ! Le mot secret etait : %s", motSecret);

    free(lettreTrouvee); // On lib�re la m�moire allou�e manuellement (par malloc)
    
    printf("\n");

        return 0;
}


