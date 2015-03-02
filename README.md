# GL
Projet de Grammaire &amp; Langage

## Compilation

#### Installation des dépendances
- Tapez `sudo aptitude update` puis `sudo aptitude install libboost-all-dev` pour installer la librairie `Boost` nécessaire à la compilation

#### Construction
- Tapez `make` pour construire l'executable. Celui-ci se trouvera à la racine du projet sous le nom : `analyseur`
- Tapez `./analyseur` pour lancer le programme

#### Test
- Tapez `make tests` pour executer l'ensemble des tests du projet

#### Destruction
- Tapez `make clean` pour détruire l'executable et l'ensemble des fichiers objets du projet
