---
tags : code
date : 12/02/22
---

# Gestion de la mémoire
## Langages de bas niveau
Dans un langage traditionnel de bas niveau comme C ou C++, le programmeur est en charge de l'allocation - et donc de la libération - de la mémoire.
Ce qui signifie que, sauf pour les valeurs stockées dans la pile, le programmeur est amené :
 * à réclamer de la mémoire au système d'exploitation en appelant explicitement `malloc` (C) ou `new` (C++) ;
 * et réciproquement à rendre cette mémoire au système d'exploitation lorsqu'elle n'est plus utilisée, en appelant `free` (C) ou `delete` (C++).

Avec ce genre de langage, la gestion de la mémoire est un aspect important de la programmation. Ce modèle offre une **grande flexibilité**, mais au prix d'un **coût élevé en matière de vitesse de développement**.

En effet, il est assez facile d'oublier de libérer la mémoire après usage, ce qui peut conduire à épuiser les ressources disponibles. À l'inverse, utiliser une zone mémoire non allouée peut conduire à des bugs très difficiles à localiser et à des problèmes de sécurité majeurs. Notons qu'une grande partie des attaques en informatique reposent sur l'exploitation d'erreurs de gestion de la mémoire.

## Langages de haut niveau

Pour toutes ces raisons, avec un langage de plus haut niveau comme Python, le programmeur est libéré de cet aspect de la programmation.

Pour anticiper un peu sur le cours des semaines suivantes, voici ce que vous pouvez garder en tête s'agissant de la gestion mémoire en Python :
* vous créez vos objets au fur et à mesure de vos besoins ;
* vous n'avez pas besoin de les libérer explicitement, le "*Garbage Collector*" de Python va s'en charger pour recycler la mémoire lorsque c'est possible 
* Python a tendance à être assez gourmand en mémoire, comparé à un langage de bas niveau, car tout est objet et chaque objet est assorti de *méta-informations* qui occupent une place non négligeable. Par exemple, chaque objet possède au minimum :
  * une référence vers son type - c'est le prix du **typage dynamique** ;
  * un compteur de références - le nombre d'autres valeurs (variables ou objets) qui pointent vers l'objet, cette information est notamment utilisée, précisément, par le *Garbage Collector* pour déterminer si la mémoire utilisée par un objet peut être libérée ou non.
* un certain nombre de types prédéfinis et non mutables sont implémentés en Python comme des *singletons*, c'est-à-dire qu'un seul objet est créé et partagé, c'est le cas par exemple pour les petits entiers et les chaînes de caractères
* lorsqu'on implémente une classe, il est possible de lui conférer cette caractéristique de singleton, de manière à optimiser la mémoire nécessaire pour exécuter un programme.