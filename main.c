#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "main.h"

int main(int argc, char *argv[])
{
    //      DECLARATION DES CONSTANTES
    const char e = '\x82' ; //é.

    //      DECLARATION DES VARIABLES
    Combinaison code ;
    int i, joueur[4], etat_joueur[4], tours, nb_chiffres_bons, nb_chiffres_mal ;
    char choix ;

    //      DEBUT DU JEU
    srand(time(NULL)) ;
    do
    {
          tours = 0 ;
          determiner(&code) ;
          do
          {
                tours++ ;
              /*for (i=0 ; i<4 ; i++)
              {
                  do
                  {
                       system("CLS") ;*/
                       printf("\t\t\tMASTERMIND\n\n\n") ;
                       /*for(j=0 ; j<4 ; j++) printf("\t%d", code.secret[j]) ;*/
                  /*} while (joueur[i]<1 && joueur[i]>9) ;
              }*/
              /*printf("\n\n") ;*/
              for (i=0 ; i<4 ; i++)
              {
                  printf("Entez le chiffre %d de la combinaison : ", i+1) ;
                  scanf("%d", &joueur[i]) ;
              }
              nb_chiffres_bons = bien_place(&code, joueur, etat_joueur) ;
              nb_chiffres_mal = mal_place(&code, joueur, etat_joueur) ;
              printf("\tVous avez %d chiffre(s) bien plac%c(s) et %d mal plac%c(s).", nb_chiffres_bons, e, nb_chiffres_mal, e) ;
              printf("\n\n\n") ;
              system("PAUSE") ;
          } while (nb_chiffres_bons != 4) ;
          printf("\n\n\n\tBien jou%c !! Vous avez d%ccouvert que le code %ctait ", e, e, e) ;
          for(i=0 ; i<4 ; i++)
          {
                printf("%d", code.secret[i]) ;
          }
          printf(" en %d coup(s) !!", tours) ;
          printf("\n\n\tVoulez-vous faire une nouvelle partie (o/n) ? ") ;
          while(getchar() != '\n') ;
          scanf("%c", &choix) ;
    } while (choix == 'o') ;
    printf("\n\n\n") ;
    system("PAUSE") ;
    return 0 ;
}

//Fonction qui détermine un code secret aléatoire (1..9) :
void determiner (Combinaison *code)
{
     int i ;
     for (i=0 ; i<4 ; i++)
     {
         code->secret[i] = rand()%9+1 ;
         code->etat[i] = 0 ;
     }
}

//Fonction qui détermine le nombre de chiffres bien placés :
int bien_place (Combinaison *code, int joueur[4], int etat_joueur[4])
{
    int res = 0, i ;
    for (i=0 ; i<4 ; i++)
    {
        if (joueur[i] == code->secret[i])
        {
            res++ ;
            code->etat[i] = 1 ;
            etat_joueur[i] = 1 ;
        }
        else
        {
            code->etat[i] = 0 ;
            etat_joueur[i] = 0 ;
        }
    }
    return res ;
}

//Fonction qui détermine le nombre de chiffres mal placés :
int mal_place (Combinaison *code, int joueur[4], int etat_joueur[4])
{
    int res = 0, i, j, ok ;
    for (i=0 ; i<4 ; i++)
    {
        j = 0 ;
        ok = 0 ;
        do
        {
            if ((i!=j) && (joueur[i] == code->secret[j]) && (code->etat[j] == 0) && (etat_joueur[i] == 0))
            {
                res++ ;
                ok = 1 ;
            }
            j++ ;
        } while ((j<4) && (ok!=1)) ;
    }
    return res ;
}
