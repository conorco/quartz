---
tags : cours, INF1
author : Conor Cauty
date : 2022-09-19 16:17
title: CM1
listings-no-page-break: true
disable-header-and-footer: true
geometry: "left=2cm,right=2cm,top=2cm,bottom=2cm"
output:
  pdf: 
    pandoc_args: ["--from=markdown+hard_line_breaks"]
    pdf-engine: xelatex
    output: CM1.pdf
    from: markdown
    template: eisvogel 
    listings: true
---

# CM1
## Présentation de l'UE
**Objectifs :**
- Enseigner les principes fondamentaux de la programmation impérative
- En Java mais sans l'aspect orienté objet (car Java est bcp utilisé et similaire à d'autres langages de programmation)
- Avoir acquis les notions sur lesquelles repose le reste du cursus

```ad-hint
title: Différence programmation impérative et programmation orientée objet

programmation impérative : suite d'instructions avec des types itératifs et des types + compliqués (chaînes, tableaux etc)
la façon dont les types + compliqués sont élaborés est assez simple et pas forcément optimisée
	=> petit nombre d'outils à disposition dans la programmation impérative --> limites

programmation orientée objet : pour des programmes qui manipulent + de choses, fournit un cadre qui permet d'automatiser des contraintes
=> + compliqué à mettre en oeuvre mais pour des projets d'une ampleur un peu plus grande
```

**Finalité de l'UE INF1**
➡ assimiler les principes de la programmation impérative

**Comment ❓**
- programme syntaxiquement correct
- qui fait ce qu'on attend
- d'une manière raisonnable (optimisation)

**Outils pour faire un programme qui fonctionne :**
- feuille pour réfléchir avant
- éditeur / IDE : *Exemples : [vscodium](https://www.eclipse.org/), [eclipse](https://www.eclipse.org/) (+ compliqué)*

## Qu'est-ce que l'informatique ?
L'informatique est la **""science** du traitement de **l'information"**
- science : principes, pas un art, progrès, on ne connaît pas tout

## Représentation de l'information en mémoire
On ne peut agir qu'en jouant avec du courant électrique : on distingue 2 états = courant/pas de courant = **binaire**

(dans les années 70 : ordinateurs à 3 états : pas, un peu, beaucoup)

Le + **petit élément d'information** = binary unit (unité d'information binaire) = **bit** qui vaut soit 0 soit 1

A partir des bits, on peut faire des paquets de bits => **8 bits (octet)** = 1 **byte**

Mémoire d'un ordinateur peut être représentée comme :
![](Obsidian/Pasted%20image%2020220919172959.png)

On peut ensuite faire des paquets :
![](Obsidian/Pasted%20image%2020220919173106.png)

(on attribue une adresse à l'octet pour savoir où il se situe dans la mémoire)

1024 octet = 1 Ko (Kilo-octet : K $\neq$ k = kilo = 10<sup>3</sup>) 
2<sup>10</sup> = 1024
1024<sup>2</sup> = 1 Mo
1024<sup>3</sup> = 1 Go
1024<sup>4</sup> = 1 To (ordre de grandeur des disques durs actuels)

| En base 10 | En base 2 |
| ---------- | --------- |
| 0          | 0         |
| 1          | 1         |
| 2          | 10        |
| 3          | 11        |
| 4          | 100       |
| ...        |           |
| 9          | 1001      |
| 10         | 1010      |
| 11         | 1011      |
| ...        |           |
| 21         | 10101     |
| ...        |           |
| 99         | 1100011   |
| 100        | 1100100   |
| ...        |           |
| 255        | 11111111  | 

Avec 8 chiffres, on peut stocker 255 valeurs (ce qui est assez pour stocker des chiffres, des minuscules, majuscules etc.) donc historiquement on a gardé 2<sup>3</sup> = 8 bits
*Pour convertir de la base 10 à 2 : [site](https://wims.univ-cotedazur.fr/wims/wims.cgi)*


Mémoire stocke l'information, microprocesseur agit pour calculer dans la mémoire --> on arrive à la notion de programme pour que la mémoire et le microprocesseur interagissent ensemble

## Notion de programme
**code =** suite d'instruction qui fait quelque chose
**algorithme =** suite d'actions pour résoudre correctement un problème => général

=> pas de code buggé (juste une suite d'instruction) mais il y a des algorithmes buggés (qui ne résolvent pas correctement un problème)

l'algorithme est ensuite décliné en **programme =** suite d'instructions (dans un langage particulier) conformes à un algorithme

Ce qui est compliqué --> faire un algorithme 
Passer d'un algorithme à un programme --> + technique (connaître le langage de programmation etc)

En fonction de l'algorithme => 1 langage de programmation peut être favorisé par rapport à un autre

## Executer un programme

Prendre une suite d'action sous forme de 0 et de 1 et exécuter la fonction du programme

Le **langage de programmation** permet de fournir des instructions de haut niveau (pas des 0 et des 1 directement)

![](Obsidian/Pasted%20image%2020220919175626.png)

Le résultat de la traduction (**compilateur**) dépend de l'ordinateur, et notamment du système d'exploitation
Donc => le même programme doit être compilé 1 fois pour Windows, 1 fois pour MacOS

Pour **l'interpréteur**, à chaque nouvelle exécution du programme on relance la traduction, alors que ce n'est pas le cas avec le compilateur

Les langages avec un interpréteur sont beaucoup plus portables (dépend moins de l'OS) qu'avec compilateur

Java fait la **compilation et l'interprétation**
![](Obsidian/Pasted%20image%2020220919180359.png)

Le fichier `.class` est compris par l'ordinateur, mais on n'y touche jamais

Noms de programmes en Java commencent toujours par une majuscule
Fonction `Main` : fonction exécutée par le programme, tout ce qui se trouve dans les accolades est exécuté de manière séquentielle (d'abord une instruction, puis l'autre etc.)

# Variable
variable = zone en mémoire qui contient une valeur et a un nom
Caractérisé par :
- son **nom** : `longueur_cote` ou `Longueur_Cote` par exemple
- son **type** (entier, nombre décimal, booléen)
- sa **valeur**

3 étapes pour une variable :
1. **Déclaration**
   On donne nom et type
   L'ordinateur trouve une zone mémoire et met à jour la liste des variables qu'il connaît
   *Exemple : déclarer une variable 'riri' qui est un entier* : `int riri;`

2. **Affectation** : mettre une valeur dans la variable
   On utilise un opérateur d'affectation `=` qui fait 2 vérifications : 
	   - est-ce que la variable existe ?
	   - est-ce que le type de la variable est le même que le type de l'affectation ?
   Par exemple : `riri = 23` (asymétrique)
   *La première fois qu'une affectation est effectuée : initialisation*

3. **Utilisation** : remplace le nom de la variable par sa valeur

## Variables booléennes
**Peut prendre 2 valeurs :**
- True (T, qu'on note 1)
- False (F, qu'on note 0)

Le 0/1 est purement conventionnel

**Pour obtenir un booléen :**
- directement
- en comparant 2 valeurs 
	- vrai : même valeurs `==`
	- faux : valeurs différentes `!=`
- en comparant 2 nombres
	- mêmes comparaisons que tout à l'heure et comparaisons < > $\leq$ $\geq$
	- Pour $\leq$ , on utilise `<=`
	- Pour $\geq$, on utilise `>=`

**Opérations entre booléens**
- `NOT`

| a   | not(a) |
| --- | ------ |
| F   | T      |
| T   | F      | 

- `AND`

| a   | b   | a AND b |
| --- | --- | ------- |
| F   | F   | F       |
| F   | T   | F       |
| T   | F   | F       |
| T   | T   | T       | 

- `OR`

| a   | b   | a OR b |
| --- | --- | ------ |
| F   | F   | F      | 
| F   | T   | T      |
| T   | F   | T      |
| T   | T   | T      |

Raccourci du `AND` : `&&`
Raccourci du `OR` : `||`

## Opérateurs conditionnels

si `condition Booléenne` (sous-entendu : est **vrai**)
alors `{`
	`bloc d'instruction`
	`}`
sinon`{`
	`bloc d'instruction`
	`}`

## Boucles
- Pour : `for`
- Tant que : `while`
- Faire tant que : `do while`

Exemple de boucle `for` :
```java
for(int i = 0 ;     i<12 ;    i = i + 1)
/*  début de    fin de     incrémentation
	la boucle   la boucle */
```