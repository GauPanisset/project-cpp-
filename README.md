# project-cpp-mines
C/C++ Project.

D'après la **Memory Box** de Fabien Olicard.

## Prérequis

Disponible sur Windows, MacOS, Linux.

#### Installation

- Qt 5.12
- *(Facultatif)* Qt Creator

#### Build

- Cloner le répertoire https://github.com/GauPanisset/project-cpp-mines
- A partir de Qt Creator : ouvrir le projet *MemoryCards.pro* puis compiler (flêche verte).

## Comment jouer ?

Lancer l'application. L'utilisateur arrive sur la fenêtre principale sur laquelle il a deux possibilités : 
1) Créer de nouvelles cartes.
2) Lancer une partie.

**1)** Créer une nouvelle carte, simplement remplir les trois champs présentés : recto, verso, collection.
Appuyer sur **RETURN** ou sur le bouton de confirmation pour valider. Si la carte est bien créée un message apparait.
Cliquer sur le bouton menu en haut à droite pour retourner sur la fenêtre principale .

**2)** Lancer une partie, deux choix s'offrent à l'utilisateur : 
2.1) A partir d'une nouvelle partie.
2.2) A partir d'une partie sauvegardée.

**2.1)** Activer l'onglet **Nouveau**. Choisir le mode de jeu (*Immédiat* ou *Durable*, voir plus bas pour les règles de sélection des cartes plus bas) à l'aide des radios boutons. Choisir la collection de cartes à utiliser pour le jeu à l'aide de la liste déroulante. Renseigner le nom de la partie, qui servira à sauvegarder puis retrouver la partie ultérieurement à l'aide du champ dédié. Appuyer sur le bouton **Jouer** pour lancer la partie avec les paramètres précédemment sélectionnés. 
**2.2)** Activer l'onglet **Charger**. Choisir le nom de la partie à charger à l'aide de la liste déroulante. Appuyer sur le bouton **Jouer** pour lancer la partie choisie.

Après avoir appuyé sur **Jouer** la fenêtre de jeu apparait. Sur celle-ci se trouve un côté de la carte et deux ou trois boutons (en fonction du mode sélectionné). Trouver la face cachée de la carte. Cliquer sur la carte pour révéler cette face cachée. Appuyer sur le bouton **Oui** si l'utilisateur avait la bonne réponse, **Bof** si l'utilisateur avait la bonne réponse mais des doutes ou **Non** si l'utilisateur n'avait pas la bonne réponse (le bouton **Bof** n'est disponible que dans le mode **Immédiat**).
Le jeu s'arrête automatiquement si les conditions d'arrets sont atteints (voir règles plus bas). Cliquer sur bouton menu en haut à gauche pour retourner sur la fenêtre principale. La sauvegarde de la partie en cours est fait à ce moment.

## Explication des règles

### Révisions durables :

Il existe 7 cases représentant les temporalités suivantes :

1. Tous les jours.
2. Tous les deux jours.
3. Tous les lundis.
4. Chaque premier du mois.
5. Tous les 3 mois.
6. Tous les 6 mois.
7. Tous les ans.

Chaque jours, se tester sur les cartes concernées. 

Pour chaque carte tirée dans la case *n* :

* si la réponse est correcte, la retourner et la placer dans la case *n+1*.
* sinon la retourner et la placer dans la case *n-1*.

Pour les cases *1* (respectivement *7*) retourner la carte et la laisser dans la case si la réponse est fausse (respectivement vraie).

Les cartes qui sont retournées dans la même case ne sont pas retirées le même jour.

### Apprentissage temps limité :

Ranger toutes les cartes dans la case *1*.

**Etape 1** : Pour chaque carte de la case *1* :  

* si la réponse est correcte et **sûre**, retourner la carte et la placer dans la case *3*.
* si la réponse est correcte avec un **doute**, retourner la carte et la placer dans la case *2*.
* si la réponse est fausse, retourner la carte et la placer dans la case *1*.

**Etape 2** : Pour chaque carte de la case *2* :

* si la réponse est correcte et **sûre**, retourner la carte et la placer dans la case *5*.
* si la réponse est correcte avec un **doute**, retourner la carte et la placer dans la case *4*.
* si la réponse est fausse, retourner la carte et la placer dans la case *3*.

**Etape 3** : Pour chaque carte de la case *3* :

* si la réponse est correcte (**sûre** ou **doute**), retourner la carte et la placer dans la case *5*.
* si la réponse est fausse, retourner la carte et la placer dans la case *4*.

**Etape 4** : Pour chaque carte de la case *4* :

* quelque soit la réponse, retourner la carte et la placer dans la case *5*.

**Etape 5** : Pour chaque carte de la case *5* :

* si la réponse est correcte et **sûre**, retourner la carte et la placer dans la case *7*.
* si la réponse est correcte avec un **doute**, retourner la carte et la placer dans la case *6*.
* si la réponse est fausse, retourner la carte et la placer dans la case *5*.

**Etape 6** : Pour chaque carte de la case *6* : 

* si la réponse est correcte et **sûre**, retourner la carte et la placer dans la case *7*.
* si la réponse est correcte avec un **doute** ou fausse, retourner la carte et la placer dans la case *1*.

**Etape 7** : Recommencer depuis l'**étape 1** avec les cartes qui se trouvent dans la case *1*.

**N.B.** Les cartes qui sont retournées dans la même case sont retirées jusqu'à ce qu'il n'y ait plus de cartes dans la case considérée. Fin d'une étape lorsqu'il n'y a plus de carte dans la case considérée. 

## Quelques améliorations à faire

- Développer l'esthétique de l'interface graphique. 
- Permettre la modification, suppression des cartes.
- Permettre une sélection plus flexible des cartes pour constituer un jeu.
- Permettre de personnaliser les textes (police de caractères, couleurs, etc...) des faces des cartes.
- Permettre de définir des faces des cartes avec des images.

