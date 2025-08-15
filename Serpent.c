#include <stdlib.h>
#include <stdio.h>
#include "Serpent.h"

struct Serpent * creer_serpent(int n, int m) {
	struct Serpent * serp = malloc(sizeof(struct Serpent)); 
	serp->cordx = (n/2);
	serp->cordy = (m/2);
    
	serp->chaine = creer_liste();
	ajouter_debut_de_liste(serp->chaine, creer_section(1, 41));
	
	serp->mouvement = creer_liste_mouvement();
	ajouter_debut_de_liste_mouvement(serp->mouvement, creer_case(serp->cordx, serp->cordy, NEUTRE));  

	return serp;
}

