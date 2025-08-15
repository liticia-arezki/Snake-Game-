#include <stdlib.h>
#include <stdio.h>
#include <ncurses.h>
#include "Grille.h"
#include "Serpent.h"
#include "liste_Section.h"
#include "Fonction_Jeu.h"



int main(int argc, char **  argv) {
	int delai;	
	struct Grille * g;
	struct Serpent * serp;
	int l , c , d  ;
	printf ("donnez les lignes \n");
	scanf("%d",&l); 
	printf ("donnez les colonnes \n");
	scanf("%d",&c); 
	printf ("donnez le delai \n");
	scanf("%d",&d); 
	//initialiser la grille
	g = Grille_allouer(l, c);
	//creer le serpent
	serp = creer_serpent(g->ligne, g->colonne);
	delai = atoi(argv[3]);
	// initialiser la matrice pour savoir si le serpent touche lui meme 
	enum element **M = initialiser_mat(g->ligne, g->colonne); 
	
	// jouer avec un seul serpent
	Jouer_avec_Serpent(g, serp, d, M);
        // desallouer la grille 
      
	Grille_desallouer(&g);
	printf("\n\n C'est la fin de programme !\n");
        printf("\n\n game over !\n");
	return EXIT_SUCCESS;
	
}
