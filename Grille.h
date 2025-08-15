#ifndef GRILLE_H
#define GRILLE_H

#include "Serpent.h"
#include "liste_Mouvement.h"


struct Grille {
	int ligne;			
 	int colonne;			
	char *** tab;		
	int cordx;		
	int cordy;		
};



enum element {Rien, Fruit, Corp_serp};


//Déclarations des fonctions 


struct Grille * Grille_allouer(int n, int m);				

void Grille_vider(struct Grille * g);					

void Grille_tirage_fruit(struct Grille * g);				 

void Grille_remplir_rouge(struct Grille * g, int x, int y);		

void Grille_desallouer(struct Grille ** g);				

void Grille_redessiner(struct Grille *g);				

void Grille_remplir_couleur(struct Grille * g, int x, int y, int couleur);			

int Grille_remplir_serp(struct Grille * g, struct Serpent * serp, enum element **M);		

enum element **initialiser_mat(int n, int m);

void changer_matrice(enum element  **M, int n, int m);


#endif
