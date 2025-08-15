#ifndef LISTE_MOUVEMENT_H
#define LISTE_MOUVEMENT_H

enum Direction { HAUT, BAS, GAUCHE, DROITE, NEUTRE};

struct Case {
	int cordx;
	int cordy;
	enum Direction dir;
	struct Case * suivant;
};

struct Liste_Mouvement {
	struct Case * tete;
	struct Case * queue;
	int longueur;		
};


struct Case * creer_case(int cordx, int cordy, enum Direction d );

void desalouer_case(struct Case ** c);

struct Liste_Mouvement * creer_liste_mouvement();

int est_vide_liste_mouvement (struct Liste_Mouvement * liste) ;

void ajouter_debut_de_liste_mouvement(struct Liste_Mouvement * liste, struct Case * casxy ) ;

void ajouter_fin_de_liste_mouvement(struct Liste_Mouvement * liste , struct Case * casxy );

struct Case * extrait_case_de_liste_mouvement ( struct Liste_Mouvement * liste ) ;

void desalouer_liste_mouvement(struct Liste_Mouvement ** liste ) ;


#endif
