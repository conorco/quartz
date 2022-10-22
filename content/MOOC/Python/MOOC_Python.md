---
tags : code
author : Conor Cauty
date : 2022-02-09 13:55
title: MOOC_Python
listings-no-page-break: true
disable-header-and-footer: true
geometry: "left=2cm,right=2cm,top=2cm,bottom=2cm"
output:
  pdf: 
    pandoc_args: ["--from=markdown+hard_line_breaks"]
    pdf-engine: xelatex
    output: MOOC_Python.pdf
    from: markdown
    template: eisvogel 
    listings: false
---

# Python 3 : des fondamentaux aux concepts avancés du langage
[TOC]

## Notions de cours
### Variable, objet et typage dynamique
En python tout est un **objet**, les **variables** référencent les objets.
**Objet** = morceau de code qui contient des données et ensemble de mécanismes qui permettent de manipuler ces données => **méthode**

Les objets ont un **type** = comportement par défaut ==**mais pas les variables**==
-> définit les données et méthodes associées à l'objet

Créer un objet chaîne de caractère : `'chaîne'`
![[Pasted image 20220212181426.png]]
Les méthodes viennent grâce à son type (chaîne de caractère)
Pour appeler une méthode : utiliser la notation `.`
Par exemple : `'chaîne'.upper()`

Pour affecter des variables : `note = 1`
Nom de variable :
- peut être défini par majuscules, minuscules, chiffres et `_`
- ne peut pas commencer par un chiffre
- prend en compte la casse $Identifiant \ne identifiant$
- donner des noms de variables explicites ! -> participe à la documentation automatique du code

En effectuant `a = 3`, on fait 3 opérations sous Python :
1. création de l'objet entier : 3
2. création de la variable a
3. référence entre la variable a et l'entier
En faisant `a='spam'`, on déréférence la variable a et on fait référence à `'spam'`

Le typage dynamique (voir [[Typages statiques et dynamiques]]) signifie que le type n'est pas lié à la variable qui référence l'objet mais **à l'objet** => langage à **typage fort**
La commande `del a` supprime a de l'espace des variables.

#### Conventions de nommages des variables 
- minuscules utilisées en général
- utiliser `_` pour une meilleure lisibilité mais **pas en début de variable**
- possibilité d'utiliser des caractères Unicode comme `éèθπ`

**Recommandations** 
- coder en anglais
- ne pas définir des variables avec des caractères non ASCII
- spécifier l'encodage si utilisation d'autre chose que UTF-8

Liste des *keywords* qui ne peuvent être utilisés pour nommer une variable (**nouveautés de Python3**)
![[Pasted image 20220212185910.png]]

### Les types numériques
4 types numériques :
- les entiers `int` => de précision illimitée (on peut faire de très grands nombres)
=> on peut ajouter des `_` qui seront ignorés pour la lisibilité
```python
tres_grand_nombre = 23_456_789_012_345
#tres_grand_nombre = 23456789012345
```
fonctionne aussi pour les `floats`
- les nombres décimaux `float` => précision limitée : codés sur 15 chiffres significatifs et encoder sur 63 bits [[Précision des calculs flottants]]
- les nombres complexes `complex`  => partie imaginaire avec un `j` : toujours précédé d'un nombre car sinon considéré comme une variable
`c = 4+5j` 
- les booléens `bool` -> sous-ensemble des entiers
=> représenté soit par `True` soit par `False`
	-> codé comme un entier `True` =1 `False`=0

=> on peut additionner un entier et un float/complexe mais on perd en précision

Conversion en entier `int(a)`, en float `float(b)`, en complexe `complex(c)`

| Opération            | Commande |
| -------------------- | -------- |
| addition             | `+`      |
| soustraction         | `-`      |
| multiplication       | `*`      |
| division             | `/`      |
| division euclidienne | `//`     |
| reste d'une division | `%`      |
| puissance            | `**`     |
| valeur absolue       | `abs()`  |

Pour des compléments, cf [[Affectations et opérations]] et [[Opérations bit à bit]]

- entrer un nombre sous forme binaire : `0b11001000` = 200
- entrer un nombre sous forme octale (base 8) : `0o310` = 200
- entrer un nombre sous forme hexadécimal (base 16) : `0xc8` = 200
- Pour d'autres bases, on peut utiliser la fonction de conversion `int` en lui passant un argument supplémentaire : `int('3020', 4)`

### Codage, jeux de caractères et Unicode
décodage : à partir d'une suite de lettres, identifier les mots
en informatique -> flux de bits => décodage
	=> définir une convention pour découper le flux de bits en blocs d'une certaine taille
	*Exemple : pour des blocs de 7 bits : codage ASCII*
![[Pasted image 20220213222820.png]]
Pour afficher un caractère -> utilisation d'une **police** (définit un glyphe = dessin qui correspond à chaque caractère)
Sur 7 bits : on ne peut coder que 128 caractères $\ne (=2^{7})$. 

-> utilisation de codages étendus (sur 8 bits : 256 caractères ASCII étendu)
	=> produit des erreurs d'encodage

pour résoudre ce problème : **projet Unicode** = coder l'intégralité des caractères dans le monde
	=> on peut coder et décoder tous les caractères
Unicode utilise $\ne$ types de codages : **UTF-8** (compatible avec ASCII standard), UTF-16, UTF-32 : compromis entre compacité et vitesse de codage

Complément sur les [[Caractères accentués]]

### Les chaînes de caractère
-> immuables [[objet mutable]] => toutes les fonctions sur une chaîne de caractère retournent une nouvelle chaîne de caractère
=> **une fois construite, on ne peut pas modifier une chaîne** -> on ne peut pas les **muter**

Une chaîne de caractères est entourée soit par deux `'` ou par deux `"`. Si la chaîne est entourée par deux `'` (respectivement `"`), alors le caractère `"` (respectivement `'`) pourra être utilisé comme un caractère normal dans la chaîne de caractères.
Attention de ne pas mettre d'apostrophes (sans caractère `\` devant) dans une chaîne délimitée par des apostrophes.
``` python
'le numéro d'appel {} est le {}'.format(text, numero)
# ne fonctionne pas
'le numéro d\'appel {} est le {}'.format(text, numero)
# fonctionne
```

`dir(str)` -> toutes les méthodes associées à `str`
Méthodes avec `_` => méthodes spéciales

Appeler une méthode : `'str'.methode()`

| Méthode          | Action                                                               |
| ---------------- | -------------------------------------------------------------------- |
| title()          | met sous forme de titre en changeant la casse (ex : **U**n **M**ooc) |
| replace('a','b') | remplace 'a' par 'b' dans la chaîne de caractère                     |
| isdecimal()      | indique si la chaîne de caractère contient un nombre décimal ou non  |
[[Outils de bases sur les str]]

Formater des chaînes de caractère avec `format`
```python
n = 'conor'
age = 21
"{} {}".format(n, age) # donne : 'conor 21'
"{} a {} ans".format(n, age) # donne : 'conor a 21 ans'
```

On peut aussi utiliser des f-string :
```python
f"{n} a {age} ans" # donne : 'conor a 21 ans'
```

On peut rentrer directement le code Unicode pour un caractère avec `\u`
*Exemple : `\u03a6` = Φ*
Tous les caractères sont supportés par Unicode, mais il peut y avoir une police sélectionnée qui ne comporte pas certains caractères Unicode.
Voir plus de choses sur le [[Formatage de chaine de caractères]]

Encodage en Python : 
- quand on utilise des chaînes de caractères `str`
- quand on utilise des flux de bits `bytes` -> contient uniquement des octets (mais peut les afficher sous forme de caractères)
-> on peut passer très facilement de l'un à l'autre (`utf8` à toujours privilégier)

```python
s = "un noël en été"
en = s.encode('utf8') 
en #  b'un no\xc3\xabl en \xc3\xa9t\xc3\xa9'
en.decode('utf8') # 'un noël en été' -> décodage
s.encode('latin1') # utilise un autre encodage : b'un no\xebl en \xe9t\xe9'
```

On peut vouloir des réponses de l'utilisateur. Pour cela, on peut utiliser la fonction `input`

```python
nom_ville = input("Entrez le nom de la ville : ")
```

Puis pour afficher ce qui a été saisi par l'utilisateur :
```python
print(f"nom_ville={nom_ville}")
```

**Attention à bien vérifier/convertir**  : `input` renvoie **toujours une chaîne de caractères** (`str`). C'est assez évident, mais il est très facile de l'oublier et de passer cette chaîne directement à une fonction qui s'attend à recevoir, par exemple, un nombre entier, auquel cas les choses se passent mal :

```python
>>> input("nombre de lignes ? ") + 3
nombre de lignes ? 12
Traceback (most recent call last):
  File "<stdin>", line 1, in <module>
TypeError: must be str, not int
```

Dans ce cas il faut appeler la fonction `int` pour convertir le résultat en un entier :

```python
int(input("Nombre de lignes ? ")) + 3
```

En pratique toutefois, on utilise assez peu cette fonction, car les applications "réelles" viennent avec leur propre interface utilisateur, souvent graphique, et disposent donc d'autres moyens que celui-ci pour interagir avec l'utilisateur.

Les applications destinées à fonctionner dans un terminal, quant à elles, reçoivent traditionnellement leurs données de la ligne de commande. C'est le propos du module [[#Argparse]] que nous avons déjà rencontré en première semaine.

Voir aussi le complément sur les [[Expressions régulières]]

 ### Les séquences
 -> les `list`, `tuple`, `str`, `bytes` 
	 => nombre fini d'éléments indicés de 0 à n-1 (si on a n éléments)

#### Opérations communes aux séquences
- accéder à un élément avec `s[x]` où `x` est l'indice
- longueur de la séquence `len(s)`
- test d'appartenance 
```python
'egg' in s
True # si s = 'egg, bacon'

'egg' not in s 
False
```
- concaténation de séquences `s + 'nouvelle séquence'` -> retourne un nouvel objet
- méthode `index` : `s.index('g')` -> retourne la première occurrence de g
- méthode `count` -> le nombre d'éléments dans la séquence
- fonctions `min` et `max`
- shallowcopies -> `'x'*30` retourne `'xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx'`

#### Slicing
On crée `s = 'egg, bacon'` tel que :
![[Pasted image 20220221102413.png]]
Opération de slicing :
```python
s[0:3] #retourne les éléments d'indice [0;3[
'egg' # est un nouvel objet
s[5:10]
'bacon'
s[:3] # parcourt tous les éléments du début jusqu'à 3 exclu
'egg'
s[5:] # de 5 jusqu'à la fin
'bacon'
s[:]
'egg, bacon' # est une copie 'shallocopy' de la chaîne de caractères
```

On peut ajouter un **pas** :
```python
s[0:10:2] # parcourt les éléments de 0 à 10 avec un pas de 2
'eg ao'
s[::2]
'eg ao'
s[:8:3]
'e,a'
```

Si on fait `s[100]` -> out of range **Erreur**
Mais si on fait :
```python
s[5:100] # on obtient tous les éléments de 5 jusqu'à la fin de la chaîne
'bacon'
```

Le slice est un objet, donc Python cherche l'intersection entre cet objet est les indices disponibles dans la chaîne de caractère -> **pas d'erreur**

```python
s[100:200]
'' # objet vide car pas d'intersection
```

##### Indices négatifs
![[Pasted image 20220221103354.png]]
-> numérotés à partir de la fin
```python
s[-10:-7] # renvoie les caractères des indices [-10;-7[
'egg'
s[::-1] # parcourt la séquence dans le sens inverse -> permet de retourner une séquence
'nocab ,gge'
```
On parcourt toujours la séquence dans le même sens, sauf si on change avec un pas négatif :
```python
s[2:0:-1]
'gg'
s[0:2:-1]
'' # car il n'y aucun caractère compris entre 0 et 2 si on parcourt la chaîne dans l'autre sens
```
Compléments sur [[Les slices]]

### Les listes
[[#Les séquences]] d'objets hétérogènes -> n'importe quel type d'objets
	=> la liste ne stocke pas les objets mais des références vers les objets => taille de la liste indépendant du type d'objet

liste = [[objet mutable]] : que l'on peut modifier en place (là où il est stocké)
	-> pas besoin de faire une copie de l'objet pour le modifier

**Opération de slicing :**
```python
a = [6, 'spam', 3.2, True]
a[1:3] = [1, 2, 3]
a 
[6, 1, 2, 3, True]
```
1. enlève les éléments de $[1;3[$  
2. insertion de $[1,2,3]$ à la place des éléments effacés

Pour enlever des éléments :
```python
a[1:3]=[]
del a[1:3]
```

**Méthode sur les listes :**
`'append',  'clear',  'copy',  'count', 'extend', 'index', 'insert', 'pop', 'remove', 'reverse', 'sort'`

- `append` : ajoute un élément à la fin d'une liste
- `expend` : pareil que `append` mais avec tous les éléments de la liste passée en argument
```python
a = ['spam','egg','beans']
liste2 = ["mot1", "mot2"]
a.append(liste2) # retourne ['spam','egg','beans', ["mot1", "mot2"]]
a = ['spam','egg','beans']
a.extend(liste2) # retourne a = ['spam','egg','beans','mot1', 'mot2']
```
- `sort` : trie la liste, en place (sans copie) => **ne pas faire d'affectation avec sort car ne retourne rien**
Pour faire un tri décroissant : `liste.sort(reverse=True)`
Fonctionne aussi pour les chaînes de caractères, avec l'ordre alphabétique mais où : $Z > a$ 
- `sorted` : trie la liste **avec copie**
- la méthode `insert` permet d'insérer des éléments `liste.insert(2, '1 bis')` insère à l'indice 2
	=> équilvalent à un slice tel que `liste[2:2] = ['1bis']`
- `remove` permet d'enlever la première occurrence d'un objet dans une liste
- `pop` enlève un élément à un indice donné, si aucun indice donné -> dernier élément de la liste
- `reverse` permet de renverser la liste $\ne$ du slicing `liste[::-1]`qui retourne une copie
- passer d'une chaîne de caractères à une liste : `split` -> découpe une chaîne de caractère en utilisant l'espace par défaut (utiliser `s.split(sep=','` pour séparer avec les virgules)
```python
s = "spam egg beans"
a = s.split()
a
['spam', 'egg', 'beans']
```

On peut utiliser des méthodes sur les chaînes de caractères :
```python
a[0] = a[0].upper() # a = ['SPAM', 'egg', 'beans']
```
**ATTENTION à ne pas oublier les `()`**

Pour retransformer en chaîne de caractères (avec un espace comme séparateur), on utilise la méthode `join` :
```python
" ".join(a) # 'SPAM egg beans'
```
#### Différence entre append/extend et +
Ces deux méthodes `append` et `extend` sont donc assez voisines ; avant de voir d'autres méthodes de `list`, prenons un peu le temps de comparer leur comportement avec l'addition `+` de liste. L'élément clé ici, on l'a déjà vu dans la vidéo, est que la liste est un objet **mutable**. `append` et `extend` **modifient** la liste sur laquelle elles travaillent, alors que l'addition **crée un nouvel objet**.
```python
a1 = list(range(3))
print(a1) # [0,1,2]
```

```python
a2 = list(range(10, 13))
print(a2) # [10,11,12]
```

```python
# le fait d'utiliser + crée une nouvelle liste
a3 = a1 + a2 
```

Comme on le voit, après une addition, les deux termes de l'addition sont inchangés. 

Ici on tire profit du fait que la liste est un objet mutable : `extend` **modifie** l'objet sur lequel on l'appelle (ici `e1`). Dans ce scénario on ne crée en tout que deux objets, et du coup il est inutile pour extend de renvoyer quoi que ce soit, et c'est pourquoi `e3` ici vaut None.

C'est pour cette raison que :

* l'addition est disponible sur tous les types séquences - on peut toujours réaliser l'addition puisqu'on crée un nouvel objet pour stocker le résultat de l'addition ;
* mais `append` et `extend` ne sont par exemple **pas disponibles** sur les chaînes de caractères, qui sont **immuables** - si `e1` était une chaîne, on ne pourrait pas la modifier pour lui ajouter des éléments.

### Tests if et syntaxe
Permet de faire des exécutions **conditionnelles** : `a>b ; a>=b ; a<b ; a<=b ; a==b ; a !=b ; a in s ; a not in s`

Blocs d'instruction définis par le `:` et la tabulation de 4 caractères -> 1 seule manière de présenter son code
Différent dans d'autres codages où les conventions de codages ne font pas partie de la syntaxe

Vérifier l'indentation en faisant des copier-coller 

On recommande de ne pas dépasser 79 caractères sur une seule ligne -> pour pouvoir mettre plusieurs éditeurs l'un à côté de l'autre

Tout ce qui est `[]`, `()`, `{}` supporte ⏎ 

#### L'instruction `pass`
Nous avons vu qu'en Python les blocs de code sont définis par leur indentation.

##### Une fonction vide

Cette convention a une limitation lorsqu'on essaie de définir un bloc vide. Voyons par exemple comment on définirait en C une fonction qui ne fait rien :

```C
/* une fonction C qui ne fait rien */
void foo() {}
```

Comme en Python on n'a pas d'accolade pour délimiter les blocs de code, il existe une instruction `pass`, qui ne fait rien. À l'aide de cette instruction on peut à présent définir une fonction vide comme ceci :


```python
# une fonction Python qui ne fait rien
def foo():
    pass
```

##### Une boucle vide

Pour prendre un second exemple un peu plus pratique, et pour anticiper un peu sur l'instruction `while` que nous verrons très bientôt, voici un exemple d'une boucle vide, c'est à dire sans corps, qui permet de "dépiler" dans une liste jusqu'à l'obtention d'une certaine valeur :


```python
liste = list(range(10))
print('avant', liste)
while liste.pop() != 5:
    pass
print('après', liste)
```

On voit qu'ici encore l'instruction `pass` a toute son utilité.

##### Un `if` sans `then`


```python
# on utilise dans ces exemples une condition fausse
condition = False
```

Imaginons qu'on parte d'un code hypothétique qui fasse ceci :


```python
# la version initiale
if condition:
    print("non")
else:
    print("bingo")
```

Et que l'on veuille modifier ce code pour simplement supprimer l'impression de `non`. La syntaxe du langage **ne permet pas** de simplement commenter le premier `print` :
```python
# si on commente le premier print
# la syntaxe devient incorrecte
if condition:
#    print "non"
else:
    print "bingo"
```

Évidemment ceci pourrait être récrit autrement en inversant la condition, mais parfois on s'efforce de limiter au maximum l'impact d'une modification sur le code. Dans ce genre de situation on préférera écrire plutôt :


```python
# on peut s'en sortir en ajoutant une instruction pass
if condition:
#    print "non"
    pass
else:
    print("bingo")
```

#### if/elif/else et opérateurs booléens
On peut avoir plusieurs `elif` avec des blocs d'instructions
	-> passe par tous les elif au fur et à mesure
	
![](Obsidian/Pasted%20image%2020220303161331.png)

Dans un test `if`, on peut avoir :
- n'importe quelle expression 
	on appelle la fonction `bool(objet)` qui appelle soit :
		`objet.__bool__()` : méthode spéciale qui retourne Vrai ou Faux
		`objet.__len__()` : 0 -> Faux, sinon Vrai => un objet vide de longueur vide est considéré comme faux
- un type built-in : si `False 0 None [] {} () ''` -> Faux, Vrai pour le reste
- une comparaison `> >= < <= == !=`
- un test d'appartenance avec `in`
- un retour de fonction
```python
s = '123'
if s.isdecimal():
	print(int(s) + 10)
```
- un opérateur de test booléen : 
![](Obsidian/Pasted%20image%2020220303162406.png)
`and` et `or` -> opérateurs short-circuits : on peut savoir au premier élément si le test est validé donc on ne va pas plus loin


### Boucles for et fonctions
**factorisation du code** : permet de ne pas réécrire plusieurs fois un code qui fait la même chose
Boucles for et fonctions -> 2 techniques de factorisation de code

```python
for i in range(10):
    print(i**2)
```

Fonction : morceau de code que l'on peut appeler n'importe quand
```python
def carre(a):
    for i in a:
        print(i**2)
```
la fonction n'est pas une copie, simplement une référence

```python
def carre(a):
    L = []
    for i in a:
        L.append(i**2)
    return L
```

`return` permet de retourner le résultat de la fonction (ici une liste qui contient les carrés de la liste entrée)

#### Le style procédural
Une procédure est une fonction qui se contente de dérouler des instructions. Voici un exemple d'une telle fonction :
Une procédure est une fonction qui se contente de dérouler des instructions. Voici un exemple d'une telle fonction :


```python
def affiche_carre(n):
    print("le carre de", n, "vaut", n*n)
```

qui s'utiliserait comme ceci :

```python
affiche_carre(12) # le carre de 12 vaut 144
```
#### Le style fonctionnel
Utilise la fonction `return` pour pouvoir écrire quelque chose comme :
```python
surface = carre(15)
```

Si on ne définit pas de `return` pour une fonction, celle-ci retourne `None`

#### Portée de variables
Si on définit :
```python
def f(a, b, c):
    print(a, b, c)
```

`f` est une variable qui fait référence à une fonction. Donc, on peut faire une référence partagée en faisant `g = f` qui référence le même objet fonction

Python ne copie jamais d'objets sauf si demandé de manière explicite, les objets sont toujours passés par référence :
```python
L = []
def add_1(a):
	a.append(1)
add_1(L) # L = [1]
```
La liste est modifiée par **effet de bord** -> on a une référence partagée d'un objet mutable
Comportement économe en mémoire mais inconvénient -> fait de manière implicite

```python
add_1(L[:]) # L[:] fait une shallow copie de L
```
Donc L n'est pas modifié, on peut donc modifier la fonction tel que pour ne pas modifier L :
```python
def add_1(a):
	a = a[:]
	a.append(1)
	return a
```

Le bloc de code d'une fonction n'est évalué que lors de l'appel de la fonction
```python
def f(a):
	func(a)
```
`f` est bien défini mais pas `func` -> erreur

**polymorphisme** des fonctions -> la fonction peut s'exécuter avec n'importe quel type compatible
```python
def my_add(a,b):
	print(f"{a} et {b}")
	return a + b
```
=> réduit le code : fonction unique qui peut se comporter correctement pour tous les types (si les opérations sont possibles pour tous les types)

### Boucle while
```python
a = list(range(1, 10))
while a: # vrai tant que la liste n'est PAS vide
    a.pop()
    print(a)
```

Les instructions `break` et `continue` permettent d'interrompre ou de continuer les instructions :
``` python
a = list(range(1,10))
b=2
while a:
    a.pop()
    if len(a) ==5 :
        continue # permet de remonter en haut du while
    print(a)
```
Nous donne :
> [1, 2, 3, 4, 5, 6, 7, 8]
[1, 2, 3, 4, 5, 6, 7]
[1, 2, 3, 4, 5, 6]
[1, 2, 3, 4]
[1, 2, 3]
[1, 2]
[1]
[]

Avec `break` à la place de `continue` :
> [1, 2, 3, 4, 5, 6, 7, 8]
[1, 2, 3, 4, 5, 6, 7]
[1, 2, 3, 4, 5, 6] # on a exactement 5 éléments après cette occurence et donc on sort de la boucle ensuite

Exemple d'utilisation, dans une **boucle infinie**  :
```python
while True:
    s = input('Quelle est votre question ?\n')
    if 'aucune' in s:
        break
```

La boucle infinie `while True` peut être utile !
On a tendance à privilégier `for` pour les boucles finies et déterministes.

### Compréhension de listes
Boucle for pour parcourir les listes
-> la compréhension de liste permet d'appliquer une opération à chaque élément d'une liste

```python
# pour obtenir les logarithmes d'une liste a
b = [math.log(i) for i in a]
# au lieu de :
for i in a:
	b.append(math.log(i))
```

On peut rajouter un test :
```python
b = [math.log(i) for i in a if i > 0]
```

Fonctionne aussi sur des string :
```python
prenom = ['Alice', 'evE', 'sonia', 'BOB']
prenom = [p.lower() for p in prenom]
['alice', 'eve', 'sonia', 'bob']
```

### Les fichiers
Pour désactiver les backslashs (dans le chemin d'un fichier) :

```python
f = open(r'c:\chemin\du\fichier') # raw-string
# ou bien
f = open('c:\\chemin\\du\\fichier')
```

Pour écrire dans un fichier :
```python
f.write("chose à écrire")
f.close()
```
On peut ensuite visualiser avec :

```python
!type fichier.txt # ou !cat sous linux
```

En Python, les fichiers sont des **itérateurs**, on peut les mettre dans une boucle for. Un fichier est son propre itérateur -> on ne peut le parcourir qu'une fois dans la boucle for. Pour le reparcourir, il faut le fermet et l'ouvrir à nouveau.
Donc, écrire 2 boucles for imbriquée sur le **même objet fichier** ne fonctionne pas.

Pour ouvrir en mode binaire :

```python
with open(r'C:\temp\spam.bin', 'bw') as f:
    for i in range(100):
        f.write(b'\x3d')
```

Les modes d'ouverture les plus utilisés sont :

-   `'r'` (la chaîne contenant l'unique caractère `r`) pour ouvrir un fichier en lecture seulement -> mode par défaut quand non précisé ;
-   `'w'` en écriture seulement ; le contenu précédent du fichier, s'il existait, est perdu ;
-   `'a'` en écriture seulement ; mais pour ajouter du contenu en fin de fichier.
- ouvrir en mode lecture et écriture : mode `+`


#### Context manager
Protocole pour ne pas avoir à fermer le fichier avec `.close()`
On utilise :
```python
with open("fichier") as f:
	for line in f :
		print(line) # le fichier va automatiquement se fermer après l'éxécution du bloc de code
```

Compléments : [[Fichiers et utilitaires]], [[Format JSON et autres]], [[Fichiers systeme]]

### Les tuples
très similaires à une liste -> accès aux éléments avec un crochet, slicing etc.
$\ne$ fondamentale entre le tuple et la liste : le tuple est un **objet immuable**

Création d'un tuple : `t = ()` => tuple vide
Pour créer un tuple d'un seul élément : `t = (4,)` sinon sans la `,` Python considère que c'est un entier
Les parenthèses sont facultatives pour les tuples mais il est préférable de les utiliser. Par exemple :

```python
# ceci provoque une SyntaxError
1, == x
```

On écrit généralement les tuples avec une virgule à la fin pour faciliter la syntaxe :

```python
mon_tuple = ([1, 2, 3],
             [4, 5, 6],
             [7, 8, 9],
            )
```

Le tuple est une séquence donc on peut faire toutes les opérations faisables sur les séquences

Conversion d'un tuple en liste : `l = list(t)` et inversement `t = tuple(l)`
	-> peut être utilisé pour modifier les tuples, car ils sont immuables

#### *Sequence unpacking*

Très utilisés pour le **tuple unpacking** :

```python
(a,b) = (3,4) # peut aussi être écrit sans parenthèses
# a = 3 et b = 4
```

Cette technique, aussi appelée **sequence unpacking** fonctionne aussi avec d'autres types, qui sont itérables, comme les listes, les string etc. Les seules contraintes sont que : 
* le terme à droite du signe `=` soit un *itérable* (tuple, liste, string, etc.) ;
* le terme à gauche soit écrit comme un tuple ou une liste - notons tout de même que l'utilisation d'une liste à gauche est rare et peu pythonique ;
* les deux termes aient la même longueur - en tout cas avec les concepts que l'on a vus jusqu'ici, mais voir aussi plus bas l'utilisation de `*arg` avec le *extended unpacking*.

Pour échanger 2 variables, on utilise donc la méthode suivante :
```python
a = 1
b = 2
a, b = b, a
print('a', a, 'b', b)
```

**Extended tuple unpacking** :

```python
a = list(range(10))
x, *y = a #x est égal au premier élément et y référence tous les autres éléments de a
```
On ne peut mentionner qu'**une seule fois** une variable précédée de `*`
Exemple d'utilisation :
```python
# si on sait que data contient prenom, nom, 
# et un nombre inconnu d'autres informations
data = [ 'Jean', 'Dupont', '061234567', '12', 'rue du four', '57000', 'METZ', ]

# on peut utiliser la variable _
# ce n'est pas une variable spéciale dans le langage,
# mais cela indique au lecteur que l'on ne va pas s'en servir
prenom, nom, *_ = data
print(f"prenom={prenom} nom={nom}")
```

Si on utilise plusieurs fois la même variable :
```python
entree = [1, 2, 3]
a, a, a = entree
# a vaut 3, comme si on avait effectué plusieurs fois l'affectation de gauche à droite
```

Cette technique n'est utilisée en pratique que pour les parties de la structure dont on n'a que faire dans le contexte. Dans ces cas-là, il arrive qu'on utilise le nom de variable `_`, dont on rappelle qu'il est légal, ou tout autre nom comme `ignored` pour manifester le fait que cette partie de la structure ne sera pas utilisée, par exemple :


```python
entree = [1, 2, 3]

_, milieu, _ = entree
print('milieu', milieu)

ignored, ignored, right = entree
print('right', right)
```

On peut aussi utiliser le *sequence unpacking* pour des niveaux plus imbriqués : 

```python
structure = ['abc', [(1, 2), ([3], 4)], 5]
#Si on souhaite extraire la valeur qui se trouve à l'emplacement du `3`, on peut écrire :
(a, (b, ((trois,), c)), d) = structure
print('trois', trois)
#Ou encore, sans doute un peu plus lisible :
(a, (b, ([trois], c)), d) = structure
print('trois', trois)
#on aurait aussi bien pu écrire :
trois = structure[1][1][0][0]
# structure[1] = [(1, 2), ([3], 4)]
# structure[1][1] = ([3], 4)
# structure[1][1][0] = [3]
```

On peut écrire pour des structures encore plus imbriquées :
```python
tree = [1, 2, [(3, 33, 'three', 'thirty-three')],
        ( [4, 44, ('forty', 'forty-four')])]
# unpacking avec plusieurs variables *extended
*_,  ((_, *x3, _),), (*_, x4) = tree
print(f"x3={x3}, x4={x4}")
# x3 vaut [33, 'three'] et x4 vaut ('forty', 'forty-four')
```
La limitation d'avoir une seule variable de la forme `*extended` s'applique toujours, naturellement, mais à chaque niveau dans l'imbrication, comme on le voit sur cet exemple.

Il est possible de faire une boucle `for` qui itère sur **une seule** liste mais qui *agit* sur **plusieurs variables**, comme ceci :

```python
entrees = [(1, 2), (3, 4), (5, 6)]
for a, b in entrees:
    print(f"a={a} b={b}")
```
Retourne :
> a=1 b=2
a=3 b=4
a=5 b=6

#### La fonction `zip`
Imaginons qu'on dispose de deux listes de longueurs égales, dont on sait que les entrées correspondent une à une, comme par exemple :


```python
villes = ["Paris", "Nice", "Lyon"]
populations = [2*10**6, 4*10**5, 10**6]
```

Afin d'écrire facilement un code qui "associe" les deux listes entre elles, Python fournit une fonction *built-in* baptisée `zip` ; voyons ce qu'elle peut nous apporter sur cet exemple :


```python
list(zip(villes, populations))
```

Retourne :
> [('Paris', 2000000), ('Nice', 400000), ('Lyon', 1000000)]

**Remarque** : lorsqu'on passe à `zip` des listes de tailles différentes, le résultat est tronqué, c'est l'entrée **de plus petite taille** qui détermine la fin du parcours.

```python
# on n'itère que deux fois
# car le premier argument de zip est de taille 2
for units, tens in zip([1, 2], [10, 20, 30, 40]):
    print(units, tens)
```

Une autre fonction très utile permet d'itérer sur une liste avec l'indice dans la liste, il s'agit de `enumerate` :


```python
for i, ville in enumerate(villes):
    print(i, ville)
```
Retourne :
> 0 Paris
1 Nice
2 Lyon

Cette forme est **plus simple** et **plus lisible** que les formes suivantes qui sont équivalentes, mais qui ne sont pas pythoniques :

```python
for i in range(len(villes)):
    print(i, villes[i])
# ou
for i, ville in zip(range(len(villes)), villes):
    print(i, ville)
```

### Tables de hash 
Strucuture de données qui permet de répondre à certaines limitations des types séquences -> optimés pour l'accès avec un numéro de séquence mais pas pour le test d'appartenance
```python
%timeit 'x' in range(100)
2.86 µs ± 38.2 ns per loop (mean ± std. dev. of 7 runs, 100,000 loops each)
%timeit 'x' in range(10_000) # underscore pour faciliter la lecture
366 µs ± 9.72 µs per loop (mean ± std. dev. of 7 runs, 1,000 loops each)
```

L'opération de test d'appartenance est 100 fois plus lente entre 100 et 10000 éléments -> linéaire en terme de nombre d'éléments

On ne peut pas indicer des séquences avec des chaînes de caractères 

La structure de données table de hash permet de répondre à ces limitations.

Table de hash constituée d'un tableau et d'une fonction
![](Obsidian/Pasted%20image%2020220302163911.png)

Pour ajouter une correspondance entre 'eve' et 34 : 
1. On passe une clef (ce qui est spécifié entre crochets -> eve)
2. On associe cette clef à une valeur (34) : `T[eve] = 34`
3. On passe 'eve' à la fonction de hash
4. La fonction de hash retourne une case dans le tableau : par exemple 2 
5. On a alors :
![](Obsidian/Pasted%20image%2020220303090058.png)
Donc dans une fonction de hash, l'insertion l'effacement etc est conditionné par la vitesse de la fonction de hash et est donc indépendante du nombre d'éléments

On peut associer plusieurs valeurs à un même nombre : ![](Obsidian/Pasted%20image%2020220303090333.png)
Si on cherche `T[jo]` :
1. on va dans la case 2 correspondant à la clé de jo
2. On regarde si la clé 'jo' correspond au premier couple
3. On retourne 46 car 'jo' est la clé du second couple

Python gère automatiquement la fonction de hash et la taille du tableau => temps d'action qui peut être indépendant du nombre d'éléments
les tables de hash permettent de faire des tests d'appartenance avc une complexité nommée **O(1)** = indépendant du nombre d'éléments dans la table de hash

Il existe 2 implémentations des tables de hash : les sets et les dictionnaires

### Les dictionnaires
-> objets mutables : bonne efficacité mémoire
On peut avoir comme clé n'importe quel objet hashable = objet sur lequel on peut calculer une fonction de hash
En Python, tous les objets immuables sont hashables mais pas tous les objets mutables => si la clé change en cours d'exécution -> pb

Pour créer un dictionnaire : `age = {}`
Par exemple :
```python
age = {'ana' :35, 'eve':30, 'bob':38} # pas ordonné dans un dictionnaire
age['ana'] # 35
```

On peut aussi construire un dictionnaire tel que (avec des tuples) :
```python
a = [('ana', 35), ('eve', 30), ('bob', 38)]
age = dict(a)
```

On peut réaffecter des valeurs car le dictionnaire est mutable : `age['bob'] = 48` ou effacer un couple de valeurs avec `del age['bob']`

Les dictionnaires ont des opérations très proches de séquences :
- `len(age)` retourne le nombre de couples clés valeurs
- tests d'appartenance avec `in` (pour voir si une clé est présente)

couple clé-valeurs = **item**

- accéder aux clés : `age.keys()`
- accéder aux valeurs : `age.values()`
- accéder aux items : `age.items()`

Ces méthodes retournent un objet particulier : une 'vue'
	=> objet sur lequel on peut itérer et faire un test d'appartenance
la 'vue' est mise à jour en même temps que le dictionnaire
```python
k = age.keys() # vue sur les clés : dict_keys(['ana', 'eve'])
age['bob'] = 25
k # dict_keys(['ana', 'eve', 'bob'])
'ana' in k # True
'bill' in k # False
```

On peut aussi faire une boucle for sur la vue pour parcourir le dictionnaire en utilisant la notation de tuple unpacking :
```python
for k, v in age.items():
    print(f"{k} {v}") # affiche ana 35 \n eve 30 \n bob 35 
# k = la clé, v = la valeur
for k in age:
    print(k) # affiche uniquement les clés
```

### Les ensembles / sets
Très proches des dictionnaires, objets mutables également
Les sets ne stockent qu'une clé contrairement aux dicitonnaires
-> optimisé pour garder uniquement le nombre d'éléments uniques d'une séquence
-> pour faire des tests d'appartenance pour les éléments d'une séquence

On crée un set par : `s = set()`
Pour ajouter des valeurs à un set :
```python
s = {1, 2, 3, 'a', True} # différence avec le dictionnaire : pas de ":" qui sépare la clé de la valeur
a = [1, 2, 4, 1, 18, 30, 4, 1]
set(a) # retourne uniquement les éléments uniques : {1, 2, 4, 18, 30}
```

- `len(s)` retourne le nombre d'éléments
- test d'appartenance avec `in`
- ajout d'éléments : `s.add('truc')`
- ajout de séquence d'éléments : `s.update([1,2,3,4,5,6,7])` -> n'ajoute que les éléments qui n'étaient pas déjà présents
- `s.clear` vide `s`
- `s.discard(5)` enlève l'élément `5` => fonctionne même si l'élément n'est pas présent
- `s.remove(5)` enlève l'élément `5` => **ne fonctionne pas si l'élément n'est pas présent**
```python
try:
    ensemble.remove('foo')
except KeyError as e:
    print("remove a levé l'exception", e)
# permet de capturer une erreur d'exécution pour continuer le programme
```
- `s.pop()` comme dans les listes sauf qu'il n'y a pas d'ordre dans les ensemble
- Opérations classiques :
```python
s1 = {1, 2, 3}
s2 = {3, 4, 5}
s1 - s2 # différence entre les 2 ensembles : enlève les éléments de s2 dans s1
s1 | s2 # union des ensembles
s1 & s2 # intersection des ensembles
s1 ^ s2 # différence symétrique : (s1 - s2) u (s2 - s1)
s1.isdisjoint(s2) # ensembles disjoints : retourne False
```

Faire un test d'appartenance pour une liste : comparer tous les éléments 1 à 1
Alors que pour un set : calcul sur une fonction de hash, et 1 seule comparaison -> le calcul est extrêmement rapide (de l'ordre de grandeur de l'accès à un élément dans une liste)
```python
a = [0]
s = set(a)

%timeit -n 50 0 in a #  -n 50 : boucles 
%timeit -n 50 0 in s
```
Les deux sont de l'ordre de 40 ns 
Convertir une séquence en set est toujours rentable pour faire un test d'appartenance

Pour créer un ensemble vide, on ne peut pas utiliser `{}` qui renvoie un objet de type dictionnaire (car les sets sont apparus plus tardivement). On peut par contre utiliser `set()` ou `set([])`

Les éléments d'un set doivent être globalement immuables : pas de listes par exemple, ou de sets de sets

Par contre, on peut utiliser le type `frozenset` -> ensemble immuable, qui peut servir de clé dans un dictionnaire ou être inclus dans un autre ensemble
Créé avec `frozenset`. Certaines fonctions sont exclues dans les frozensets : `update`, `pop`, `clear`, `remove` ou `discard`.

### Les exceptions 
3 choses à savoir sur les exceptions :
1. Les exceptions ne sont pas une fatalité -> mécanisme de communication d'erreurs : on peut les capturer et de réagir
2. Fournissent de l'information sur l'erreur qui se produit
3. mécanisme utilisé dans un fonctionnement normal d'un programme

Par exemple :
```python
div(1, 0)
---------------------------------------------------------------------------
ZeroDivisionError                         Traceback (most recent call last)
Input In [100], in <module>
----> 1 div(1, 0)

Input In [98], in div(a, b)
      1 def div(a, b):
----> 2     print(a / b)

ZeroDivisionError: division by zero
```
-> donne la raison et situe l'erreur dans le programme

La clause `except` permet de capturer l'exception :
```python
def div(a,b):
    try:
        print(a/b)
    except ZeroDivisionError:
        print("attention, division par 0")
    print("continuons")

div(1,0) 
attention, division par 0
continuons
```

Autre exception possible
```python
div(1, "0")

Input In [102], in div(a, b)
      1 def div(a, b):
      2     try:

----> 3         print(a / b)
      4     except ZeroDivisionError:
      5         print("attention, division par 0")

TypeError: unsupported operand type(s) for /: 'int' and 'str'
```

On peut alors ajouter un except :
```python
except TypeError:
	print("il faut des int !")
```

On peut avoir une clause except sans préciser le type d'erreur
-> mauvaise pratique car cache les exceptions produites par le code !

Si on fait seulement
```python
def div(a,b):
    try:
        print(a/b)
    except:
        print("attention, division par 0")
    print("continuons")
```
On aura des erreurs qui ne correspondent pas vraiment aux erreurs qui se produisent (par exemple avec un string)

Les exceptions ont un mécanisme de **bubbling**

```python
def div(a,b):
    print(a/b)

def f(x):
    div(1,x)
```
En faisant `f(0)`, on a une erreur due au programme div mais qui remonte (qui *bubble*) jusqu'au programme f pour l'arrêter

2 avantages :
- on peut capturer l'exception n'importe où le long de la pile d'exécution (dans div ou dans f par exemple)
- la trace d'éxecution montre par où est passée l'exception et permet donc d'identifier le problème

Pour connaître les exceptions : lire la documentation des modules ou de sobjets utilisés !

### Les classes

En Python, on peut définir ses propres objets qui vont se comporter comme des types built-in -> classes (=type)
liste : type qui créé les objets listes, et les objets listes sont des instances du type liste

Création d'une classe 
```python
class C:
    pass

c1 = C() # créé une instance de C
```

```python
class Phrase:
      def __init__(self, phrase):
	      self.mots = phrase.split()
```
`self` correspond à l'instance créée par la classe
 En faisant :
```python
p = Phrase("je fais un mooc sur python")
```
On attribue à p la classe Phrase. On voit dans le code précédent qu'on attribue `phrase.split()` à  `self.mots` où `self` est donc `p` ici. Donc en faisant :
`p.mots`, on a comme retour : `['je', 'fais', 'un', 'mooc', 'sur', 'python']`

Pour définir une méthode, par exemple une méthode qui mets tous les mots en majuscules :
```python
def upper(self):
    self.mots = [m.upper() for m in self.mots]

p.upper()
p.mots # retourne la liste avec les mots en majuscules
```

Si on fait `print(p)`, on a l'adresse de l'objet et non le contenu de la liste. Pour changer cela, on ajoute à la classe :
```python
def __str__(self):
    return "\n".join(self.mots)
```
Affiche :
> je
fais
un
mooc
sur
python

Tous les comportements des types built-in peuvent être implémentés dans les classes.



---

## Commandes
### print
```python
print("a =", a, "et b =", b)
# ou encore, équivalente mais avec un f-string
print(f"a = {a} et b = {b}")
a = 100; print(a) #affiche la valeur de a
```
### Argparse
module ``argparse`` permet d'interpréter des arguments passés sous lignes de commande

```bash
# Exemple
$ python3 fibonacci.py 12
```

`````` python
# importation
from argparse import ArgumentParser
``````
## shebang
uniquement sous Unix
```python
#!/usr/bin/env python3
```
pour ajouter le fichier en exécutable
```bash
chmod +x fibonacci.py
```
=> le fichier peut être exécuté sans mentionner ``python``

```bash
export PATH=/le/chemin/jusqu/a:$PATH
```
=> pas besoin d'être dans le répertoire du fichier
## type 
permet de référencer le type d'une variable
```python
x = 1
type(x) # Out = int
x = [1, 2, 3]
type(x) # Out = list

```

## isinstance
permet de savoir si un objet est d'un type donné
```python
isinstance(23, int) # True
```

## Programmes
### Suite de fibonacci
```python
## Version sans terminal
def fibonacci(n):
    "retourne le nombre de fibonacci pour l'entier n"
    # pour les deux petites valeurs de n, on peut retourner n
    if n <= 1:
        return n
    # sinon on initialise f2 pour n-2 et f1 pour n-1
    f2, f1 = 0, 1
    # et on itère n-1 fois pour additionner
    for i in range(2, n + 1):
        f2, f1 = f1, f1 + f2
#        print(i, f2, f1)
    # le résultat est dans f1
    return f1
``````
Pour mettre dans le terminal [[#Argparse]]
``````python
from argparse import ArgumentParser
def fibonacci(n):
    "retourne le nombre de fibonacci pour l'entier n"
    # pour les deux petites valeurs de n, on peut retourner n
    if n <= 1:
        return n
    # sinon on initialise f2 pour n-2 et f1 pour n-1
    f2, f1 = 0, 1
    # et on itère n-1 fois pour additionner
    for i in range(2, n + 1):
        f2, f1 = f1, f1 + f2
#        print(i, f2, f1)
    # le résultat est dans f1
    return f1
parser = ArgumentParser()
parser.add_argument(dest="entier", type=int,
                    help="entier d'entrée")
input_args = parser.parse_args()
entier = input_args.entier
print(f"fibonacci({entier}) = {fibonacci(entier)}")
``````

### Dessiner un carré
#module
``````python
def square(length):
    "have the turtle draw a square of side <length>"
    for side in range(4):
        turtle.forward(length)
        turtle.left(90)

#initialise la tortrue
turtle.reset()
#dessine le carré
square(200)
#termine quand l'utilisateur clique
turtle.exitonclick()
``````
documentation du module [`turtle`](https://docs.python.org/3/library/turtle.html).

Vous trouverez quelques exemples pour commencer ici :

-   [turtle_multi_squares.py](https://nbhosting.inria.fr/35571/notebooks/w1/media/turtle_multi_squares.py) pour dessiner des carrés à l'emplacement de la souris en utilisant plusieurs tortues ;
-   [turtle_fractal.py](https://nbhosting.inria.fr/35571/notebooks/w1/media/turtle_fractal.py) pour dessiner une fractale simple ;
``````python
from turtle import *
color('red', 'yellow')
begin_fill()
while True:
    forward(200)
    left(250)
    if abs(pos()) < 1:
        break
end_fill()
done()
``````
-   [turtle_fractal_reglable.py](https://nbhosting.inria.fr/35571/notebooks/w1/media/turtle_fractal_reglable.py) une variation sur la fractale, plus paramétrable.
```python
import turtle

def left_triangle(length):
    for i in range(3):
        turtle.forward(length)
        turtle.left(120)

def fractal_side(length, fractal, proportions):
    if fractal == 0:
        turtle.forward(length)
    else:
        [l1, l2, l3]= [p*length for p in proportions]
        fractal_side(l1, fractal-1, proportions)
        turtle.right(60)
        fractal_side(l2, fractal-1, proportions)
        turtle.left(120)
        fractal_side(l2,fractal-1, proportions)
        turtle.right(60)
        fractal_side(l3, fractal-1, proportions)

def fractal_triangle(length, fractal, proportions):
    for i in range(3):
        fractal_side(length,fractal, proportions)
        turtle.left(120)

turtle.reset()
turtle.speed('fastest')
fractal_triangle(300, 4, (.1, .5, .4,))
left_triangle(300)
turtle.exitonclick()
```

### Compter des lignes, mots, caractères

```python
# permet de compter les lignes, le nombre de mots et le nombre de caractères en les retournant sous la forme : [lignes, mots, caractères]
def wc(string):
    res = [string.count('\n'),len(string.split()),len(string)]
    return res 
```