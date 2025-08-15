#include <stdlib.h>
#include <stdio.h>
#include "liste_Mouvement.h"


//la fonction qui cree la case avec les cordonnes nessecaires
struct Case * creer_case (int cordx, int cordy, enum Direction d) {
	
	struct Case * casxy = malloc(sizeof(struct Case));
	casxy->cordx = cordx;
	casxy->cordy = cordy;
	casxy->dir = d ;
	casxy->suivant = NULL;
	return casxy;
}

//la fonction qui desalloue la case
void desalouer_case(struct Case ** c) {
	
	if (*c != NULL) {	
		free(*c);
		*c = NULL;	
	}	
}

// la fonction qui creer la liste des mouvements
struct Liste_Mouvement * creer_liste_mouvement() {

	struct Liste_Mouvement * liste = malloc(sizeof(struct Liste_Mouvement));	
	liste->tete = NULL;
	liste->queue = NULL;
	liste->longueur = 0;
		
	return liste;
}

//la fonction qui dit si la liste  des mouvement est vide
int est_vide_liste_mouvement (struct Liste_Mouvement * liste) {
	return (liste->longueur == 0);
}


// la fonction qui ajoute au debut de la liste de mouvement une struct avec la case et la direction
void ajouter_debut_de_liste_mouvement(struct Liste_Mouvement * liste, struct Case * casxy ) {
	if (est_vide_liste_mouvement(liste)) {
           liste->queue = casxy ;
        }
	casxy->suivant = liste->tete;
	liste->longueur++;
	liste->tete = casxy ;
}


// la fonction qui ajoute a la fin de la liste de mouvement une struct avec la case et la dir
void ajouter_fin_de_liste_mouvement(struct Liste_Mouvement * liste , struct Case * casxy ) {

	casxy->suivant = NULL;
	
	if (est_vide_liste_mouvement(liste)) {
		liste->tete = casxy;
	}else {
		liste->queue->suivant = casxy;
	}
	liste->queue = casxy;
	liste->longueur++;

}


// la fonction qui extrait la premiere case dune une liste de mouvement 
struct Case * extrait_case_de_liste_mouvement ( struct Liste_Mouvement * liste ) {
	
	struct Case * cas = liste->tete;
	if (cas != NULL) {
	        // si la liste nest pas nulle on extrait lentete de case et on deminue la taille de la liste
   		liste->tete = cas->suivant;
    		liste->longueur--;
    		// si la liste est nulle on renvoie null
    		if (est_vide_liste_mouvement(liste)) 
    		{
    	        liste->queue = NULL; 
    	        }
    		cas->suivant = NULL;
	}
	return cas;
}


// desallouer la liste des mouvement
void desalouer_liste_mouvement(struct Liste_Mouvement ** liste ) {

	/*On Vérifie d'abord que l'argument entré correspond à une liste déja allouée dans le tas*/	
	if (*liste != NULL) {
		
		/* Création d'une section temporaire qui va servive à garder une trace de la section libérée*/
		struct Case * cas ;
		/* On libère toutes les sections de la liste une par une*/
		while(!est_vide_liste_mouvement(*liste)) {
			cas = extrait_case_de_liste_mouvement (*liste);
		}
		
		/* On libère la section temporaire */
		desalouer_case(&cas);
		/* On désaloue la liste qui est à présent vide */
		free(*liste);
		*liste = NULL;
	}
	
}

