---
tags : code
date : 14/02/22
---

# Outils de bases sur les str
### Découpage - assemblage : `split` et `join`

Les méthodes `split` et `join` permettent de découper une chaîne selon un séparateur pour obtenir une liste, et à l'inverse de reconstruire une chaîne à partir d'une liste.

`split` permet donc de découper :


```python
'abc=:=def=:=ghi=:=jkl'.split('=:=') # ['abc', 'def', 'ghi', 'jkl']
```

Et à l'inverse :


```python
"=:=".join(['abc', 'def', 'ghi', 'jkl']) # 'abc=:=def=:=ghi=:=jkl'
```

Attention toutefois si le séparateur est un terminateur, la liste résultat contient alors une dernière chaîne vide. En pratique, on utilisera la méthode `strip`, que nous allons voir ci-dessous, avant la méthode `split` pour éviter ce problème.

```python
'abc;def;ghi;jkl;'.split(';')
```

Qui s'inverse correctement cependant :

```python
";".join(['abc', 'def', 'ghi', 'jkl', ''])
```

### Remplacement : `replace`

`replace` est très pratique pour remplacer une sous-chaîne par une autre, avec une limite éventuelle sur le nombre de remplacements :

```python
"abcdefabcdefabcdef".replace("abc", "zoo") # 'zoodefzoodefzoodef'
```

En ajoutant une limite à 2 remplacements : 
```python
"abcdefabcdefabcdef".replace("abc", "zoo", 2) # 'zoodefzoodefabcdef'
```

Plusieurs appels à `replace` peuvent être chaînés comme ceci :

```python
"les [x] qui disent [y]".replace("[x]", "chevaliers").replace("[y]", "Ni") # 'les chevaliers qui disent Ni'
```

### Nettoyage : `strip`

On pourrait par exemple utiliser `replace` pour enlever les espaces dans une chaîne, ce qui peut être utile pour "nettoyer" comme ceci :

```python
" abc:def:ghi ".replace(" ", "") # 'abc:def:ghi'
```

Toutefois bien souvent on préfère utiliser `strip` qui ne s'occupe que du début et de la fin de la chaîne, et gère aussi les tabulations et autres retour à la ligne :

```python
" \tune chaîne avec des trucs qui dépassent \n".strip() # 'une chaîne avec des trucs qui dépassent'
```

On peut appliquer `strip` avant `split` pour éviter le problème du dernier élément vide :

```python
'abc;def;ghi;jkl;'.strip(';').split(';') # ['abc', 'def', 'ghi', 'jkl']
```

### Rechercher une sous-chaîne

Plusieurs outils permettent de chercher une sous-chaîne. Il existe `find` qui renvoie le plus petit index où on trouve la sous-chaîne :


```python
# l'indice du début de la première occurrence
"abcdefcdefghefghijk".find("def") # 3, on commence à 0
```


```python
# ou -1 si la chaîne n'est pas présente
"abcdefcdefghefghijk".find("zoo") # -1
```

`rfind` fonctionne comme `find` mais en partant de la fin de la chaîne :

```python
# en partant de la fin
"abcdefcdefghefghijk".rfind("fgh")
```

La méthode `index` se comporte comme `find`, mais en cas d'absence elle lève une **exception** (nous verrons ce concept plus tard) plutôt que de renvoyer `-1` :

```python
"abcdefcdefghefghijk".index("def")
```


```python
try:
    "abcdefcdefghefghijk".index("zoo")
except Exception as e:
    print("OOPS", type(e), e)
# OOPS <class 'ValueError'> substring not found
```

Mais le plus simple pour chercher si une sous-chaîne est dans une autre chaîne est d'utiliser l'instruction `in` sur laquelle nous reviendrons lorsque nous parlerons des séquences :


```python
"def" in "abcdefcdefghefghijk" # True
```

La méthode `count` compte le nombre d'occurrences d'une sous-chaîne :

```python
"abcdefcdefghefghijk".count("ef") # 3
```

Signalons enfin les méthodes de commodité suivantes :

```python
"abcdefcdefghefghijk".startswith("abcd") 
```

```python
"abcdefcdefghefghijk".endswith("ghijk")
```

S'agissant des deux dernières, remarquons que :

`chaine.startswith(sous_chaine)` $\Longleftrightarrow$ `chaine.find(sous_chaine) == 0`

`chaine.endswith(sous_chaine)` $\Longleftrightarrow$ `chaine.rfind(sous_chaine) == (len(chaine) - len(sous_chaine))`

On remarque ici la supériorité en terme d'expressivité des méthodes pythoniques `startswith` et `endswith`.

### Changement de casse

Voici pour conclure quelques méthodes utiles qui parlent d'elles-mêmes :


```python
"monty PYTHON".upper()
```


```python
"monty PYTHON".lower()
```


```python
"monty PYTHON".swapcase()
```


```python
"monty PYTHON".capitalize()
```


```python
"monty PYTHON".title()
```

### Pour en savoir plus

Tous ces outils sont [documentés en détail ici (en anglais)](https://docs.python.org/3/library/stdtypes.html#string-methods).
