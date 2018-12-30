# project-cpp-mines
C/C++ Project.

D'après la **Memory Box** de Fabien Olicard.

## Deux modes de jeu

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
* si la réponse est fausse, retourner la carte et la placer dans la case *1*


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
* si la réponse est fausse, retourner la carte et la placer dans la case *5*

**Etape 6** : Pour chaque carte de la case *6* : 

* si la réponse est correcte et **sûre**, retourner la carte et la placer dans la case *7*.
* si la réponse est correcte avec un **doute** ou fausse, retourner la carte et la placer dans la case *1*.

**Etape 7** : *Facultatif* : Recommencer depuis l'**étape 1** avec les cartes qui se trouvent dans la case *1*.

**N.B.** Les cartes qui sont retournées dans la même case sont retirées jusqu'à ce qu'il n'y ait plus de cartes dans la case considérée. Fin d'une étape lorsqu'il n'y a plus de carte dans la case considérée. 

