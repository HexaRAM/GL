# GL
Projet de Grammaire &amp; Langage

## Fonctionalités

#### Description
Ce programme va analyser votre programme **LUTIN** (fichier en *.lt*) et vous dire s'il est syntaxiquement et sémantiquement correct.
Celui-ci peut également vous fournir le résultat de l'exécution du programme (`option -e`) si celui-ci est correct. Une optimisation est également possible grâce à l'`option -o`

[...]

#### Utilisation
```shell
./analyseur fichier.lt -e # execute le programme
./analyseur fichier.lt -a # effectue une analyse statique du programme
./analyseur fichier.lt -p # affiche l'état du programme en mémoire
./analyseur fichier.lt -o # effectue des optimisations au niveau du programme
```

Il est possible de combiner les différentes options

```shell
./analyseur fichier.lt -o -p # affiche le programme avec les optimisations effectuées
```

## Compilation

#### Installation des dépendances
- Tapez `sudo aptitude update` puis `sudo aptitude install libboost-all-dev` pour installer la librairie `Boost` nécessaire à la compilation

#### Construction
- Tapez `make` pour construire l'executable. Celui-ci se trouvera à la racine du projet sous le nom : `analyseur`
- Tapez `./analyseur` pour lancer le programme

#### Test
- Tapez `make test` pour executer l'ensemble des tests du projet

#### Destruction
- Tapez `make clean` pour détruire l'executable et l'ensemble des fichiers objets du projet
