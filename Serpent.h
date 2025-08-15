#ifndef SERPENT_H
#define SERPENT_H

#include "liste_Section.h"
#include "liste_Mouvement.h"


struct Serpent {
	int cordx; // la tete de serpent 
	int cordy;
	struct Liste * chaine;	
	struct Liste_Mouvement * mouvement;
	
};


struct Serpent * creer_serpent(int n, int m);

#endif
