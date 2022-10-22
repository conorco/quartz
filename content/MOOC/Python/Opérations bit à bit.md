---
tags : code
date : 13/02/22
---

# Opérations *bit à bit* (*bitwise*)

## Compléments - niveau avancé

Les compléments ci-dessous expliquent des fonctions évoluées sur les entiers. 

### Opérations logiques : *ET* `&`, *OU* `|` et *OU* exclusif `^`

Il est possible aussi de faire des opérations *bit à bit* sur les nombres entiers. Le plus simple est de penser à l'écriture du nombre en base 2.

Considérons par exemple deux entiers constants dans cet exercice


```python
x49 = 49
y81 = 81
```

Ce qui nous donne comme [décomposition binaire](https://lehollandaisvolant.net/tuto/bin/) :

$$\begin{array}{rcccccc}
x49 & = & 49 & = & 32 + 16 + 1 & = 1\times2^{5}+1\times2^{4}+1\times2^{0} &\rightarrow &(0,1,1,0,0,0,1) \\
y81 & = & 81 & = & 64 + 16 + 1 & = 1\times2^{6}+1\times2^{4}+1\times2^{0} &\rightarrow &(1,0,1,0,0,0,1)
\end{array}$$

Pour comprendre comment passer de $32 + 16 + 1$ à $(0,1,1,0,0,0,1)$ il suffit d'observer que :

$$32 + 16 + 1 =
\textbf{0}*2^6 +
\textbf{1}*2^5 +
\textbf{1}*2^4 +
\textbf{0}*2^3 +
\textbf{0}*2^2 +
\textbf{0}*2^1 +
\textbf{1}*2^0$$

#### *ET* logique : opérateur `&`

L'opération logique `&` va faire un *et* logique bit à bit entre les opérandes, ainsi


```python
x49 & y81
```

Et en effet :

$\begin{array}{rcl}
x49          & \rightarrow & (0,1,1,0,0,0,1) \\
y81          & \rightarrow & (1,0,1,0,0,0,1) \\
x49\ \&\ y81 & \rightarrow & (0,0,1,0,0,0,1) \rightarrow 16 + 1 \rightarrow 17
\end{array}$

#### *OU* logique : opérateur `|`

De même, l'opérateur logique `|` fait simplement un *ou* logique, comme ceci :


```python
x49 | y81
```

On s'y retrouve parce que :

$$\begin{array}{rcl}
x49         & \rightarrow & (0,1,1,0,0,0,1) \\
y81         & \rightarrow & (1,0,1,0,0,0,1) \\
x49\ |\ y81 & \rightarrow & (1,1,1,0,0,0,1) \rightarrow 64 + 32 + 16 + 1 \rightarrow 113
\end{array}$$

#### *OU* exclusif : opérateur `^`

Enfin, on peut également faire la même opération à base de *ou* exclusif avec l'opérateur `^` :


```python
x49 ^ y81
```

$$\begin{array}{rcl}
x49         & \rightarrow & (0,1,1,0,0,0,1) \\
y81         & \rightarrow & (1,0,1,0,0,0,1) \\
x49\ ^\wedge\ y81 & \rightarrow & (1,1,0,0,0,0,0) \rightarrow 64 + 32  \rightarrow 96
\end{array}$$
Le *ou* exclusif de deux bits est vrai si et seulement si exactement une des deux entrées est vraie

### Décalages

Un décalage **à gauche** de, par exemple, 4 positions, revient à décaler tout le champ de bits de 4 cases à gauche (les 4 nouveaux bits insérés sont toujours des 0). C'est donc équivalent à une **multiplication** par $2^4 = 16$ :


```python
x49 << 4 
```

$$\begin{array}{rcl}
x49        & \rightarrow & (0,1,1,0,0,0,1) \\
x49\ <<\ 4 & \rightarrow & (0,1,1,0,0,0,1,0,0,0,0) \rightarrow 512 + 256 + 16 \rightarrow 784
\end{array}$$

De la même manière, le décalage à **droite** de $n$ revient à une **division** par $2^n$ (plus précisément, le quotient de la division) :


```python
x49 >> 4 # = x49 // 2**4
```

$$\begin{array}{rcl}
x49        & \rightarrow &         (0,1,1,0,0,0,1) \\
x49\ >>\ 4 & \rightarrow & (0,0,0,0,0,1,1) \rightarrow 2 + 1 \rightarrow 3
\end{array}$$

### Une astuce

On peut utiliser la fonction *built-in* `bin` pour calculer la représentation binaire d'un entier. Attention, la valeur de retour est une chaîne de caractères de type `str` :

```python
bin(x49) # pour passer en octect, on utilise oct(nombre)
```

Dans l'autre sens, on peut aussi entrer un entier directement en base 2 comme ceci :

```python
x49bis = 0b110001
x49bis == x49 # True
```

Ici, comme on le voit, `x49bis` est bien un entier.

### Pour en savoir plus

[Section de la documentation Python](https://docs.python.org/3/library/stdtypes.html#bitwise-operations-on-integer-types).
