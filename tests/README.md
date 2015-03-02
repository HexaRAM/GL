# Outil de test
Petit outil permettant de lancer automatiquement une série de tests.
>Vous devez vous trouver à la **racine du projet**

## Ajouter un test
Le programme parcourt le dossier `tests` et cherche des repertoires. Un repertoire correspond à un test.

Dans chaque repertoire de test, on doit trouver les fichiers suivant :

- `fichier.in` : commande à executer pour faire le test
- `fichier.out` : correspondant à la sortie attendue (à comparer avec la sortie de `fichier.in`)
- `fichier.lt` : correspondant au code **Lutin** à analyser

>Vous pouvez vous inspirer du test déjà existant

## Lancer les tests
- Tapez `./test.sh` pour lancer les tests. Vous pourrez observer les résultats sur la sortie standard.