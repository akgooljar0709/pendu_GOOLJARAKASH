# Titre du projet : Jeux Pendu

# But du projet
Le but de ce Projet est de réaliser le jeu du pendu où le but est de deviner un mot en proposant des lettres en un nombre limiter de coup.
## Commencer
Avant de commencer, nous alons cloné le travail du projet en local dans notre terminal.

```
mkdir jeux_pendu
cd jeux_pendu
git clone https://github.com/akgooljar0709/pendu_GOOLJARAKASH.git
cd pendu_GOOLJARAKASH
```
## Compiler Les Script
Pour compiler ce projet vous devez executez ces lines de code sur votre terminal 
Le dossier contient un CMakeLists.txt pour compiler pendu par exemple, si vous êtes dans à la racine du projet
```
cd bin
cmake ..
make
```

### Comment Executer le code 

##### Pendu
Deplacez vous dans là où se trouve le binaire pendu et sur le terminal :

```
./pendu
```
## Exécution des tests

Expliquer comment exécuter les tests automatisés pour ce système



## Construit avec

* [Langage C] (https://devdocs.io/c/) - Utilisé pour développer des applications système.




### Exemple Du Projet



```
Bienvenue dans le Pendu !

Chosissez votre mode de difficulte [facile,moyen,difficile]
facile


Il vous reste 8 coups a jouer
Quel est le mot secret ? ____
Proposez une lettre : j 


Il vous reste 7 coups a jouer
Quel est le mot secret ? ____
Proposez une lettre : k


Il vous reste 6 coups a jouer
Quel est le mot secret ? ____
Proposez une lettre : s
Voudriez vous avoir un indice [oui/non]:
oui
Hint : C 
C


Il vous reste 6 coups a jouer
Quel est le mot secret ? C_C_
Proposez une lettre : o
```
## Auteurs
* **GOOLJAR AKASH** - *Travail initial* - [GOOLJAR AKASH](https://github.com/akgooljar0709)



