# réalisé par le binôme : Yacine LARFI et Liticia AREZKI

## Nombre de fichiers utilisés
Le projet contient **12 fichiers** ainsi qu’un **Makefile**.  
Le programme est divisé de la manière suivante :

1. `Fonction_Jeu_1_Serpent.c` + `Fonction_Jeu.h`  
2. `Grille.c` + `Grille.h` (contient la structure de la grille, la matrice de l’exercice 5 et leurs fonctions)  
3. `liste_Mouvement.c` + `liste_Mouvement.h` (structure de la liste des mouvements du serpent et fonctions associées)  
4. `liste_Section.c` + `liste_Section.h` (structure des sections et fonctions associées)  
5. `Serpent.c` + `Serpent.h` (structure du serpent et fonctions pour créer le serpent)  
6. `main.c` (programme principal)  
7. `Makefile` (assure la compilation et l’exécution de tous les fichiers)

---

## Fonctionnement du programme

 créer un jeu Snake.  

### Étapes principales :

1. **Initialisation :**  
   - L’utilisateur saisit les données nécessaires : dimensions de la grille (lignes et colonnes) et délai de déplacement du serpent.  
   - La grille est initialisée (`grille.h` et `grille.c`).  
   - Les structures nécessaires de l’exercice 1 sont également initialisées.

2. **Structures de données :**  
   - `liste_Section` : contient la liste des sections du serpent et les fonctions pour créer la liste, ajouter une section au début ou à la fin, etc.  
   - `liste_Mouvement` : gère les mouvements du serpent et la structure `case` avec les coordonnées et la direction.  
   - `Serpent` : contient des pointeurs vers la liste de mouvements et la liste de sections.

3. **Boucle principale du jeu :**  
   - La grille est remplie et affichée.  
   - Le serpent est créé à partir des listes de sections et de mouvements.  
   - À chaque tour :  
     - Le programme lit le caractère entré par l’utilisateur et l’ajoute au début de la liste de mouvements.  
     - Si le serpent touche un mur ou lui-même, la boucle se termine.  
     - Si le serpent touche un fruit, une nouvelle section de taille et couleur aléatoire est ajoutée.  
     - Si aucun mouvement n’est effectué et que le délai est dépassé, le serpent continue selon le dernier mouvement.  
   - La grille est redessinée à chaque étape et la collision avec le serpent lui-même est vérifiée.

4. **Fin du jeu :**  
   - Le score final est affiché.  
   - Le programme se termine si le serpent touche un mur ou lui-même.

---

## Makefile

Le `Makefile` compile tous les fichiers et génère un exécutable nommé :  makefile

Pour compiler et exécuter :  
```bash
make
./snake_game

