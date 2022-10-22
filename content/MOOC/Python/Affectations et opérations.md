---
tags : code
date : 13/02/22
---

# Affectations et opérations
Il existe en Python toute une famille d'opérateurs dérivés de l'affectation qui permettent de faire en une fois une opération et une affectation. En voici quelques exemples.

## Incrémentation

On peut facilement augmenter la valeur d'une variable numérique comme ceci :

```python
entier = 10

entier += 2
print('entier', entier)
```

Comme on le devine peut-être, ceci est équivalent à :
```python
entier = 10

entier = entier + 2
print('entier', entier)
```

## Autres opérateurs courants

Cette forme, qui combine opération sur une variable et réaffectation du résultat à la même variable, est disponible avec tous les opérateurs courants :

```python
entier -= 4
print('après décrément', entier)
entier *= 2
print('après doublement', entier)
entier /= 2
print('mis à moitié', entier)
entier //= 2
print('divisé euclidien', entier)
```

## Types non numériques

En réalité cette construction est disponible sur tous les types qui supportent l'opérateur en question. Par exemple, les listes (que nous verrons bientôt) peuvent être additionnées entre elles :

```python
liste = [0, 3, 5]
print('liste', liste) # liste [0, 3, 5]

liste += ['a', 'b']
print('après ajout', liste) # après ajout [0, 3, 5, 'a', 'b']
```

Beaucoup de types supportent l'opérateur `+`, qui est sans doute de loin celui qui est le plus utilisé avec cette construction.

## Opérateurs plus abscons

Signalons enfin que l'on trouve aussi cette construction avec d'autres opérateurs moins fréquents, par exemple :

```python
entier = 2
print('entier:', entier)
entier **= 10
print('à la puissance dix:', entier) #1024
entier %= 5
print('modulo 5:', entier) #4
```

Et pour ceux qui connaissent déjà un peu Python, on peut même le faire avec des opérateurs de décalage, que nous verrons très bientôt :

```python
entier <<= 2
print('double décalage gauche:', entier) #16
```
