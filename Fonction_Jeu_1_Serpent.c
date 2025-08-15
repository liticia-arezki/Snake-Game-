#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include<ncurses.h>
#include"Fonction_Jeu.h"
#include"Grille.h"
#include"Serpent.h"
#include"liste_Section.h"
#include"liste_Mouvement.h"


void Jouer_avec_Serpent(struct Grille *g, struct Serpent *serp, int delai, enum element **M){
        int ch , score=0 ;
        int couleur, longueur;  
	int t ; // si le serpent touche
	
        /* Initialisation de ncurses et du clavier */
        initscr();
        raw();
        keypad(stdscr, TRUE);
        noecho();
        halfdelay(delai);


        /* initialisation de la grille */
        Grille_tirage_fruit(g);
        Grille_vider(g);
        changer_matrice(M, g->ligne, g->colonne);
        Grille_remplir_rouge(g, g->cordx, g->cordy); 
        Grille_remplir_serp(g, serp, M);  
        Grille_redessiner(g);
        
    	printf("Votre score est : %d \033[1E", score);
    	
	printf("\033[0m\n");
        
        refresh();
         
        while ((ch = getch()) != '#') {
          // le switch pour ajouter une section de mouvement selon la direction
                switch (ch) {
                    case KEY_UP:
			if (serp->mouvement->tete->dir != BAS) 
				ajouter_debut_de_liste_mouvement(serp->mouvement, creer_case(serp->cordx, serp->cordy, HAUT));  
                        break;
                        
                    case KEY_DOWN:
                        if (serp->mouvement->tete->dir != HAUT) 
                        	ajouter_debut_de_liste_mouvement(serp->mouvement, creer_case(serp->cordx, serp->cordy, BAS));
                        break;
                        
                    case KEY_LEFT:
             		if (serp->mouvement->tete->dir != DROITE) 
             		        ajouter_debut_de_liste_mouvement(serp->mouvement, creer_case(serp->cordx, serp->cordy, GAUCHE)); 
                        break;
                        
                    case KEY_RIGHT:
			if (serp->mouvement->tete->dir != GAUCHE) 
                        	ajouter_debut_de_liste_mouvement(serp->mouvement, creer_case(serp->cordx, serp->cordy, DROITE)); 
                        break;
                }
		// le switch pour reinissialiser les cordonnes de la tete
		switch (serp->mouvement->tete->dir) {
                    	case HAUT:
				serp->cordy--;
                        	break;
                        case BAS:
				serp->cordy++;
                        	break;
                    	case DROITE:
				serp->cordx++;
                        	break;
                    	case GAUCHE:
				serp->cordx--;
                       		break;
		}
                
                /* Vérifier la collision avec le bord */
                if (serp->cordx < 0 || serp->cordx >= g->colonne || serp->cordy < 0 || serp->cordy >= g->ligne) {
                    break;  
                }

                /* Vérifier la collision avec le fruit */
                if (serp->cordx == g->cordx && serp->cordy == g->cordy) {
                	// on choisi la taille aleatoire pour montrer la taille des section
			longueur = (rand() % 2) + 1;
			// on choisi une couleur aleatoire pour montrer la taille des section
			couleur = (rand() % 6) + 41; 
                        // on ajoute une section
                    	ajouter_fin_de_liste(serp->chaine, creer_section(longueur, couleur));
                        // on donne dautre cordonnes pour le fruit 
                    	Grille_tirage_fruit(g);  
			// on incrimente le score
			score++;	
                }
                // on revide la grille pour remplir le serpent
                Grille_vider(g);
		changer_matrice(M, g->ligne, g->colonne);
                Grille_remplir_rouge(g, g->cordx, g->cordy);  
                t = Grille_remplir_serp(g, serp, M);
                
                if(t == 1){
                	break;	
                }
                
                Grille_redessiner(g);	
    		printf("\033[0m Votre score: %d \033[1E\033[0m\n", score);
                refresh();
        }
        /* Terminer la session ncurses */
        endwin(); 
        printf("Game over\n");
	printf("Votre score a la fin est : %d", score);

}

