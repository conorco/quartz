---
tags : cours, SI1
author : Conor Cauty
date : 2022-10-24
title: Compte-rendu TP 1-2
listings-no-page-break: true
geometry: "left=2cm,right=2cm,top=2cm,bottom=2cm"
code-block-font-size: \scriptsize
output:
  pdf: 
    pandoc_args: ["--from=markdown+hard_line_breaks"]
    pdf-engine: xelatex
    output: Compte-rendu TP 1-2.pdf
    from: markdown
---
### Question 1 - Compréhension fonction de recherche
La fonction `recherche` est telle que :
```java
public static int recherche(int cherche,int[] t){
	for(i=0 ; i<t.length ; i++){
		if (t[i]==cherche) return i
	}
	return -1
}
```
La fonction `recherche` prend en entrée un entier `cherche`, un tableau d'entiers `t`, et renvoie le premier indice du tableau où la valeur de `cherche` se trouve. Si `cherche` n'est pas dans le tableau, la fonction renvoie -1.

### Question 2 - Compréhension fonction de recherche
La fonction `recherche` parcourt tout le tableau grâce à une boucle. A chaque itération `i` de la boucle, on compare la valeur correspondant à l'indice `i` dans le tableau à la valeur `cherche`. Si ces 2 valeurs sont égales, on retourne la valeur de `i`. Sinon, si on sort de la boucle, la fonction retourne -1.

### Question 3 - Amélioration algorithmique
En supposant qu'un tableau est trié par ordre croissant, on peut améliorer la recherche en comparant la valeur recherchée à la valeur du "milieu" (valeur de l'indice $i = \lfloor\frac{len(\text{tableau})}{2}\rfloor$ ). C'est ce que l'on fait dans l'algorithme de `recherche2` en ayant isolé des cas particuliers pour les tableaux vides, et les tableaux avec un nombre d'éléments impairs (source d'erreurs). En utilisant cette méthode, la vitesse de traitement ne dépend plus de la taille du tableau, puisqu'on le divise par 2 à chaque étape. Donc, le nombre d'itérations dans la boucle `while` correspond donc à une fonction logarithmique.

### Question 4 - Complexité expérimentale
![Courbe de complexité expérimentale](Obsidian/courbe_recherche2.png){width=300px}

La courbe de complexité montre que la fonction `recherche` est linéaire (son temps d'exécution dépend de la taille du tableau). Afin de trouver l'équation de droite : $y=x/4500$, on a pris un point sur la courbe de coordonnées $(7\cdot 10^{5} ; 155)$ donc : $155 = a\times7\cdot 10^5$, d'où $a = \frac{155}{7\cdot 10^{5}} = \frac{1}{4500}$  
La fonction `recherche2` est logarithmique (son temps d'exécution ne dépend **pas** de la taille du tableau).  En comparant `recherche2` à $\log{x}$, on observe que `recherche2` est 5 fois plus rapide que la fonction $\log{x}$, donc on peut définir la fonction de référence de `recherche2` par $y=\log(x/100000)$. 