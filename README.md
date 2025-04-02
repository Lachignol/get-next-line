# get_next_line

## Description
Le projet **get_next_line** de l'école 42 consiste à implémenter une fonction en C capable de lire une ligne à la fois depuis un descripteur de fichier. Cette fonction permet de gérer les entrées/sorties de manière efficace tout en respectant les contraintes de mémoire et les normes de codage.

## Fonctionnalités
La fonction `get_next_line` permet :
- De lire une ligne complète depuis un fichier ou l'entrée standard.
- De retourner `NULL` lorsque la fin du fichier est atteinte ou en cas d'erreur.
- De gérer des appels successifs pour lire tout le contenu du fichier ligne par ligne.

### Prototype
char *get_next_line(int fd);

### Comportement attendu
- Retourne la prochaine ligne lue, incluant le caractère de saut de ligne (`\n`).
- Utilise un **buffer** défini à la compilation pour optimiser les lectures.
- Gère les variables statiques pour conserver l'état entre plusieurs appels.

---

## Installation et Compilation
Clonez le projet depuis GitHub et compilez-le avec `make` :
git clone <URL_du_projet> cd get_next_line make

---

## Utilisation
Incluez le fichier d'en-tête dans votre projet :
#include “get_next_line.h”
Exemple d'utilisation :
#include <fcntl.h> #include <stdio.h> #include “get_next_line.h”
int main(void) { int fd = open(“example.txt”, O_RDONLY); char *line;
while ((line = get_next_line(fd)) != NULL) {
    printf("%s", line);
    free(line); // Libérer la mémoire allouée.
}
close(fd);
return 0;

---

## Structure du Projet
| Fichier          | Description                          | Responsabilité                   |
|------------------|--------------------------------------|----------------------------------|
| `get_next_line.c`| Implémentation principale            | Lecture et gestion des lignes   |
| `get_next_line_utils.c` | Fonctions utilitaires           | Manipulation de chaînes et mémoire |
| `Makefile`       | Automatisation de la compilation     | Génération de la bibliothèque   |

---

## Tests
Pour tester le projet, utilisez des fichiers contenant plusieurs lignes ou des entrées standard. Vous pouvez également ajuster la taille du buffer lors de la compilation :
gcc -D BUFFER_SIZE=32 -o test get_next_line.c get_next_line_utils.c

---

## Ressources Utiles
- [Documentation sur les file descriptors](https://man7.org/linux/man-pages/man2/open.2.html)
- Tutoriel vidéo : "Understanding Get Next Line" sur YouTube.
- Articles sur les variables statiques et gestion mémoire.

---

## Auteur
Projet réalisé dans le cadre du cursus 42. N'hésitez pas à poser vos questions ou à contribuer !
