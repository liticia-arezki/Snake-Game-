#include <stdlib.h>
#include <stdio.h>
#include "liste_Section.h"


// Fonction pour créer une nouvelle section 
struct Section * creer_section(int taille, int couleur) {

	// Allocation de mémoire pour la nouvelle section 
	struct Section * section = malloc(sizeof(struct Section)) ;
	section->taille = taille;
	section->couleur = couleur;
	section->suivant = NULL;
	return section;

}


// Fonction pour désallouer une section 
void desalouer_section( struct Section ** section ) {
	
	if (*section != NULL) {
		// libere la section	
		free(*section);
		*section = NULL;
	}
}


// la fonction qui cree une liste 
struct Liste * creer_liste() {

	struct Liste * liste = malloc(sizeof(struct Liste));	
	liste->tete = NULL;
	liste->queue = NULL;
	liste->longueur = 0;
	return liste;
}

//la fonction qui dit si la liste est vide
int est_vide(struct Liste * liste) {
	return (liste->longueur == 0);
}

// la fonction qui ajoute l'entete de la liste 
void ajouter_debut_de_liste(struct Liste * liste , struct Section * section ) {
		
	if (est_vide(liste)) 
		liste->queue = section;
	section->suivant = liste->tete;
		
	liste->tete = section;

	liste->longueur++;
}


// la fonction qui ajoute la queue de la liste 
void ajouter_fin_de_liste(struct Liste * liste, struct Section * section) {
	section->suivant = NULL;
	if (est_vide(liste)) {
		liste->tete = section;
	}else {
		liste->queue->suivant = section ;
	}	
	liste->queue = section ;
	liste->longueur++;

}


struct Section * extrait_section(struct Liste * liste) {
	
	struct Section * section  = liste->tete;
	if (section != NULL) {
   		liste->tete = section->suivant;
    	
    		liste->longueur--;
    		
    		if (est_vide(liste)) 
    	        liste->queue = NULL; 
    		section->suivant = NULL;
	}
	return section;
}




void desalouer_liste(struct Liste ** liste ) {

	if (*liste != NULL) {
		struct Section * section;
		while(!est_vide(*liste)) {
			section = extrait_section(*liste);
		}
		desalouer_section(&section);
		free(*liste);
		*liste = NULL;
	}
}
