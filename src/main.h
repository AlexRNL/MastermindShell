#ifndef DEF_MAINH
#define DEF_MAINH

typedef struct
{
        int secret[4] ; //Ici, on stocke le code à découvrir.
        int etat[4] ; //Ce tableau indique si le chiffre a été découvert.
} Combinaison ;

//Prototypes des fonctions :
void determiner (Combinaison *code) ;
int bien_place (Combinaison *code, int joueur[4], int etat_joueur[4]) ;
int mal_place (Combinaison *code, int joueur[4], int etat_joueur[4]) ;

#endif
