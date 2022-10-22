---
tags : code
date : 14/02/22
---

# Formatage de chaînes de caractères

## Complément - niveau basique

On désigne par formatage les outils qui permettent d'obtenir une présentation fine des résultats, que ce soit pour améliorer la lisibilité lorsqu'on s'adresse à des humains, ou pour respecter la syntaxe d'un outil auquel on veut passer les données pour un traitement ultérieur.

### La fonction `print`

Nous avons jusqu'à maintenant presque toujours utilisé la fonction `print` pour afficher nos résultats. Comme on l'a vu, celle-ci réalise un formatage sommaire&nbsp;: elle insère un espace entre les valeurs qui lui sont passées.


```python
print(1, 'a', 12 + 4j) # 1 a (12+4j)
```

La seule subtilité notable concernant `print` est que, par défaut, elle ajoute un saut de ligne à la fin. Pour éviter ce comportement, on peut passer à la fonction un argument `end`, qui sera inséré *au lieu* du saut de ligne. Ainsi par exemple :

```python
# une première ligne
print("une", "seule", "ligne")
```


```python
# une deuxième ligne en deux appels à print
print("une", "autre", end=' ')
print("ligne")
```

Il faut remarquer aussi que `print` est capable d'imprimer **n'importe quel objet**. Nous l'avons déjà fait avec les listes et les tuples, voici par exemple un module :

```python
# on peut imprimer par exemple un objet 'module'
import math

print('le module math est', math)
```

En anticipant un peu, voici comment `print` présente les instances de classe (ne vous inquiétez pas, nous apprendrons dans une semaine ultérieure ce que sont les classes et les instances).


```python
# pour définir la classe Personne
class Personne:
    pass

# et pour créer une instance de cette classe
personne = Personne()
```


```python
# voilà comment s'affiche une instance de classe
print(personne) # <class '__main__.Personne'>
```

On rencontre assez vite les limites de `print` :

* d'une part, il peut être nécessaire de formater une chaîne de caractères sans nécessairement vouloir l'imprimer, ou en tout cas pas immédiatement ;
* d'autre part, les **espaces ajoutées** peuvent être plus néfastes qu'utiles ;
* enfin, on peut avoir besoin de préciser un nombre de chiffres significatifs, ou de choisir comment présenter une date.

C'est pourquoi il est plus courant de **formater** les chaînes - c'est-à-dire de calculer des chaînes en mémoire, sans forcément les imprimer de suite, et c'est ce que nous allons étudier dans ce complément.

### Les *f-strings*

Depuis la version 3.6 de Python, on peut utiliser les f-strings, le premier mécanisme de formatage que nous étudierons. C'est le mécanisme de formatage le plus simple et le plus agréable à utiliser.

Je vous recommande tout de même de lire les sections à propos de `format` et de `%`, qui sont encore massivement utilisées dans le code existant (surtout `%` d'ailleurs, bien qu'essentiellement obsolète).

Mais définissons d'abord quelques données à afficher :

```python
# donnons-nous quelques variables
prenom, nom, age = 'Jean', 'Dupont', 35
```


```python
# mon premier f-string
f"{prenom} {nom} a {age} ans"
```

Vous remarquez d'abord que la chaine commence par `f"`, c'est bien sûr pour cela qu'on l'appelle un *f-string*.

On peut bien entendu ajouter le `f` devant toutes les formes de strings, qu'ils commencent par `'` ou `"` ou `'''` ou `"""`.

Ensuite vous remarquez que les zones délimitées entre `{}` sont remplacées. La logique d'un *f-string*, c'est tout simplement de considérer l'intérieur d'un `{}` comme du code Python (une expression pour être précis), de l'évaluer, et d'utiliser le résultat pour remplir le `{}`.

Ça veut dire, en clair, que je peux faire des calculs à l'intérieur des `{}`.


```python
# toutes les expressions sont autorisées à l'intérieur d'un {}
f"dans 10 ans {prenom} aura {age + 10} ans"
```


```python
# on peut donc aussi mettre des appels de fonction
notes = [12, 15, 19]
f"nous avons pour l'instant {len(notes)} notes"
```

Nous allons en rester là pour la partie en niveau basique. Il nous reste à étudier comment chaque `{}` est formaté (par exemple comment choisir le nombre de chiffres significatifs sur un flottant), ce point est expliqué plus bas.

Comme vous le voyez, les *f-strings* fournissent une méthode très simple et expressive pour formater des données dans des chaînes de caractère. Redisons-le pour être bien clair : un *f-string* **ne réalise pas d'impression**, il faut donc le passer à `print` si l'impression est souhaitée.

*Si on affecte un f-string à une variable, celle-ci ne sera pas recalculée, la variable contient uniquement la chaîne de caractères mais pas les appels de fonction*

### La méthode `format`

Avant l'introduction des *f-strings*, la technique recommandée pour faire du formatage était d'utiliser la méthode `format` qui est définie sur les objets `str` et qui s'utilise comme ceci :


```python
"{} {} a {} ans".format(prenom, nom, age)
```

Dans cet exemple le plus simple, les données sont affichées en lieu et place des `{}`, dans l'ordre où elles sont fournies.

Cela convient bien lorsqu'on a peu de données. Si par la suite on veut changer l'ordre par exemple des nom et prénom, on peut bien sûr échanger l'ordre des arguments passés à format, ou encore utiliser la **liaison par position**, comme ceci :

```python
"{1} {0} a {2} ans".format(prenom, nom, age)
```

Dans la pratique toutefois, cette forme est assez peu utile, on lui préfère souvent la **liaison par nom** qui se présente comme ceci :


```python
("{le_prenom} {le_nom} a {l_age} ans"
   .format(le_nom=nom, le_prenom=prenom, l_age=age))
```

*Petite digression* : remarquez l'usage des parenthèses, qui me permettent de couper ma ligne en deux, car sinon ce code serait trop long pour la PEP8; on s'efforce toujours de ne pas dépasser 80 caractères de large, dans notre cas c'est utile notamment pour l'édition du cours au format PDF.

Reprenons : dans ce premier exemple de liaison par nom, nous avons délibérément utilisé des noms différents pour les données externes et pour les noms apparaissant dans le format, pour bien illustrer comment la liaison est résolue, mais on peut aussi bien faire tout simplement :

```python
"{prenom} {nom} a {age} ans".format(nom=nom, prenom=prenom, age=age)
```

Voici qui conclut notre courte introduction à la méthode `format`.

## Complément - niveau intermédiaire

### La toute première version du formatage : l'opérateur `%`

`format` a été en fait introduite assez tard dans Python, pour remplacer la technique que nous allons présenter maintenant.

Étant donné le volume de code qui a été écrit avec l'opérateur `%`, il nous a semblé important d'introduire brièvement cette construction ici. Vous ne devez cependant pas utiliser cet opérateur dans du code moderne, la manière pythonique de formater les chaînes de caractères est le f-string.

Le principe de l'opérateur `%` est le suivant. On élabore comme ci-dessus un "format" c'est-à-dire le patron de ce qui doit être rendu, auquel on passe des arguments pour "remplir" les trous. Voyons les exemples de tout à l'heure avec l'opérateur `%` :


```python
# l'ancienne façon de formater les chaînes avec %
# est souvent moins lisible
"%s %s a %s ans" % (prenom, nom, age)
```

On pouvait également avec cet opérateur recourir à un mécanisme de liaison par nommage, en passant par un dictionnaire. Pour anticiper un tout petit peu sur cette notion que nous verrons très bientôt, voici comment


```python
variables = {'le_nom': nom, 'le_prenom': prenom, 'l_age': age}
"%(le_nom)s, %(le_prenom)s, %(l_age)s ans" % variables
```

## Complément - niveau avancé

De retour aux *f-strings* et à la fonction `format`, il arrive qu'on ait besoin de spécifier plus finement la façon dont une valeur doit être affichée; cela se fait en précisant un **format** à l'intérieur des `{}` comme ceci :

![[Pasted image 20220214213700.png]]

* à gauche du `:` vous pouvez mettre **n'importe quelle expression** (opérations arithmétiques, appels de fonctions, …); bien sûr s'il n'y a pas de `:` tout ce qui est entre les `{}` constitue l'expression à évaluer;
* à droite du `:` vous pouvez préciser **un format**, nous allons en voir quelques exemples.

### Précision des arrondis

C'est typiquement le cas avec les valeurs flottantes pour lesquelles la précision de l'affichage vient au détriment de la lisibilité. 

Voici comment on obtient une valeur de pi arrondie :


```python
from math import pi
```


```python
# un f-string
f"2pi avec seulement 2 chiffres apres la virgule {2*pi:.2f}" # 6.28
```

Vous remarquez que la façon de construire un *format* est la même pour les *f-strings* et pour `format`.

### `0` en début de nombre

Pour forcer un petit entier à s'afficher sur 4 caractères, avec des `0` ajoutés au début si nécessaire :


```python
x = 15

f"{x:04d}" # 0015
```

Ici on utilise le format `d` (toutes ces lettres `d`, `f`, `g` viennent des formats ancestraux de la libc comme `printf`). Ici avec `04d` on précise qu'on veut une sortie sur 4 caractères et qu'il faut remplir à gauche si nécessaire avec des `0`.

### Largeur fixe

Dans certains cas, on a besoin d'afficher des données en colonnes de largeur fixe, on utilise pour cela les formats `<` `^` et `>` pour afficher à gauche, au centre, ou à droite d'une zone de largeur fixe :


```python
# les données à afficher
comptes = [
 ('Apollin', 'Dupont', 127),
 ('Myrtille', 'Lamartine', 25432),
 ('Prune', 'Soc', 827465),
]

for prenom, nom, solde in comptes:
    print(f"{prenom:<15} -- {nom:^12} -- {solde:>8} €")
# Apollin             Dupont          127 €
# Myrtille          Lamartine       25432 €
# Prune                Soc         827465 €
# 15, 12 et 8 -> largeur de colonne
```

### Voir aussi

Nous vous invitons à vous reporter à la documentation de `format` pour plus de détails [sur les formats disponibles](https://docs.python.org/3/library/string.html#formatstrings), et notamment aux [nombreux exemples](https://docs.python.org/3/library/string.html#format-examples) qui y figurent.
