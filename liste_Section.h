#ifndef LISTE_SECTION_H
#define LISTE_SECTION_H



struct Section {
	int taille;				
	int couleur;				
	struct Section * suivant;		
};


struct Liste {
	struct Section * tete;		
	struct Section * queue ;		
	int longueur; 				
};


struct Section * creer_section(int taille, int couleur);

void desalouer_section(struct Section ** s);

struct Liste * creer_liste();

int est_vide(struct Liste * liste);

void ajouter_debut_de_liste(struct Liste * liste , struct Section * section );

void ajouter_fin_de_liste(struct Liste * liste, struct Section * section);

struct Section * extrait_section(struct Liste * liste);

void desalouer_liste(struct Liste ** liste ) ;

#endif
