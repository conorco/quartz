---
tags:
- info
title: "Systèmes de numération utilisés en machine"
---

# Introduction
Dans [Représentation des nombres, numération](Représentation%20des%20nombres,%20numération.md), on a vu la représentation générale des nombres dans toutes les bases

On va voir ici comment les nombres sont codés dans un ordinateur : le **format** $\neq$ **nombres**.
- Limitations physiques (tailles des "mots" limités : 16, 32 ou 64 bits donc nombre d'octects fixes)
- Traiter les nombres négatifs (nombres signés) --> entiers **signés** (int) (les entiers non signés sont **uint**)
- Traiter les nombres réels (**float** ou **double**)

<mark style="background: #FFF3A3A6;">Le **format** donne le type des nombres</mark>

# Représentation DCB - Décimal Codé Binaire
## Définition
S'utilise principalement pour les systèmes d'affichages des valeurs numériques et dans les machines à calculer.

Chaque **chiffre** décimal (de 0 à 9) est codé sur 4 bits

| Poids | $2^3$ | $2^2$ | $2^1$ | $2^0$ |
| ----- | ----- | ----- | ----- | ----- |
| N     | $a_3$ | $a_2$ | $a_1$ | $a_0$ |
| 0     | 0     | 0     | 0     | 0     |
| 1     | 0     | 0     | 0     | 1     |
| 2     | 0     | 0     | 1     | 0     |
| 3     | 0     | 0     | 1     | 1     |
| 4     | 0     | 1     | 0     | 0     |
| 5     | 0     | 1     | 0     | 1     |
| 6     | 0     | 1     | 1     | 0     | 
| 7     | 0     | 1     | 1     | 1     |
| 8     | 1     | 0     | 0     | 0     |
| 9     | 1     | 0     | 0     | 1     |

> [!danger] Etats invalides
> 
> Comme on ne veut coder que des chiffres, il existe des états interdits (qui correspondraient aux valeurs de 10 à 15)
> 
> Les états interdits en DCB : **1010, 1011, 1100, 1101, 1110, 1111**

>[!example] Passer du décimal en DCB
>
> <mark style="background: #FFF3A3A6;">5</mark><mark style="background: #FF5582A6;">1</mark><mark style="background: #BBFABBA6;">8</mark> en DCB : <mark style="background: #FFF3A3A6;">0101</mark> <mark style="background: #FF5582A6;">0000</mark> <mark style="background: #BBFABBA6;">1000</mark>
> <mark style="background: #FFF3A3A6;">1</mark><mark style="background: #FF5582A6;">3</mark><mark style="background: #BBFABBA6;">9</mark> en DCB : <mark style="background: #FFF3A3A6;">0001</mark> <mark style="background: #FF5582A6;">0011</mark> <mark style="background: #BBFABBA6;">1001</mark>

**Toujours un multiple de 4 bits en DCB**

Conversion et lecture **très facile** mais **très gourmand en espace mémoire** (car consomme énormément de bits)

> [!hint] Consommation en mémoire
> 
> Pour 1024 états : **16 bits en DCB** alors que $1024=2^{10}$ donc seulement **10 bits en binaire**

## Opérations
### 1er cas : la somme est < 9
On ne se trouve pas sur un état interdit

> [!example] Exemple de calcul : opération facile
> 
> - 35 + 24 en DCB
>  - 35 = 0011 0101
> - 24 = 0010 0100
> - La somme est = 0101 1001 (DCB)
> - On peut vérifier car 0101 = 5 et 1001 = 9 donc on a bien 59

> [!attention] Ne pas confondre le format et la numération
> 
> Format = DCB
> 
> Numération = décimal
> 
> Les règles ne sont pas les mêmes !

### 2ème cas : la somme est > 9
**On passe par les états interdits**
- Le résultat est un état invalide ↪ passer les 6 états invalides (donc ajouter 6)
- Retenu sur le paquet de 4 bits suivants (+6) mais le résultat n'est **pas invalide**

> [!example] Premier cas : état invalide
> 
> - 6+7 en DCB 
> - 0110 + 0111 = **1101** = état invalide donc **faux**
> - On ajoute 6 pour passer les états interdits (pour passer de 9 à 10 = 1 et 0 = 0001 0000 (DCB))
> - 1101 + 0110 = 10011 donc le résultat est : 0001 0011 donc 13

> [!example] Deuxième cas : pas invalide
> 
> - 8+ 9 en DCB
> - 1000 + 1001 = <mark style="background: #FFF3A3A6;">1</mark>0001 = pas un état invalide --> <mark style="background: #FFF3A3A6;">retenue</mark>
> - Donc tous les états interdits ont été comptés : il faut donc rajouter 6 pour passer les états interdits
> - 10001 + 0110 = 10111 donc le résultat est 0001 0111 donc 17

# Représentation des nombres entiers signés ↪ complément à 2
Nombres entiers signés = nombres positifs et négatifs
## Compléments à 2
### Définition

**Format** pour représenter les nombres entiers
Ce format (cpt2) est à **nombre de bits fixé** (16, 32 ou 64 bits)

Méthodes différentes pour passer de la base 10 au cpt2 pour les nombres **positifs** et **négatifs**

- **Nombres positifs** : pareil que le binaire pour passer de base 10 à 2 (cf [Représentation des nombres, numération](Représentation%20des%20nombres,%20numération.md)
- **Nombres négatifs** : utilisation du complément à 2

> [!hint] Rappel : complément
> 
> Le complément à N d'un nombre est le nombre qui permet d'atteindre N.
> 
> *Par exemple : cpt10(3) = 10 - 3 = 7*

> [!info] Définition plus formelle
> 
> **Complément à 2 sur k (16, 32, 64) bits** mais en réalité on calcule le **complément à $2^{k}$**
> 
> Complement à 2 en base 10 de N ↪ cpt2(N) = $2^{k}- N$
>
> $N_{10}=-\alpha_{k-1}2^{k-1}+ \sum\limits_{i=0}^{k-2}\alpha_{i}2^{i}$
> 
> *Exemple :* cpt2(3) sur 4 bits ↪ cpt2(3) = $2^{4}-3$ = 16 - 3 = 13
> 
> *Donc en base 2 : $\text{cpt2(3)}=1101_{\text{(cpt2)}}$*

> [!warning] Utilisation du complément à 2
> 
> Un nombre **négatif** est le **complément 2** du même nombre positif, donc on utilise le complément à 2 **<mark style="background: #FFF3A3A6;">uniquement pour les nombres négatifs</mark>**
> 
> Donc si on a -3 en base 10 ↪ on cherche le complément à 2 de 3
> 
> cpt2(3) = 1101 donc $-3_{(10)}= 1101_{(cpt2)}$
> 
> Alors que $3_{(10)} = 0011_{(cpt2)}$

> [!summary] Récapitulatif complément à 2
> 
> Représentation utilisée pour les entiers par les ordinateurs
> 
> bit de signe, S=poids fort (situé à gauche) = MSB
> - S=0 : signe **poisitif**
> - S=1 : signe **négatif**
>   
>  Nombre de **bits fixé** (bits restants servent à la valeur de l'entier)

### Conversion Décimal vers Complément à 2

> [!info] Méthode 0 : calcul de $2^{k}-N$
> 
> Calcul de $2^{k}-N$ en décimal et conversion en binaire ↪ donne la valeur du nombre négatif en complément à 2

> [!example] Exemple méthode 0
> 
> $N_{10} = -11 = 1111 0101_{cpt2}$
> - Calcul de $2^{k}-N$ : $2^{8}-11 = 256 - 11 = 24$
> - Conversion en binaire : $24_{10}=1111 0101_{cpt2}$

> [!warning] Ne pas confondre format et calcul
> 
> Format cpt à 2 : binaire naturel pour les entiers positifs et **caclul** du complément à 2 pour les négatifs

> [!info] Méthode 1 (calculatoire)
> 
> - Pour les entiers positifs ↪ binaire naturel (et S=0)
> - Pour les entiers négatifs ↪ compléments à 2 (et S=1)
>  
>  Dans les 2 cas : **cpt2 = cpt1 + 1**
>  
>  *cpt1 = complète à 1 (1 ↪ 0 et 0 ↪ 1)*

> [!example] Exemple méthode 1
> 
> $N_{10}=11$ donc $N_{10}=0000 1011_{cpt2}$ (codé sur 1 octect donc 8 bits)
> 
> $N_{10} = -11 = 1111 0101_{cpt2}$
> - On part du nombre binaire de 10 : 0000 1011
> - Complément à 1 de ce nombre : 1111 0100
> - Ajout de 1 : 1111 0101

> [!info] Méthode 2 (manuelle)
> 
> Bits inchangés de droite à gauche (du LSB ↪ MSB) jusqu'au 1er "1" inclus puis **tous** les bits suivants sont inversés

> [!example] Exemple méthode 2
> 
> $N_{10}=-11$
> - Lecture de droite à gauche de <mark style="background: #FF5582A6;">0000101</mark><mark style="background: #BBFABBA6;">1</mark> $= 11_{2}$
> - Le LSB dans ce cas est déjà un 1, donc on le conserve et on inverse tous les autres : <mark style="background: #FF5582A6;">1111010</mark><mark style="background: #BBFABBA6;">1</mark> $= -11_{cpt2}$

Donc, **sur k bits**, on peut représenter les **entiers de $\bf{-2^{k-1}}$ à $\bf{2^{k-1}-1}$** avec le complément à 2

> [!question] Pourquoi $2^{k-1}-1$ ?
> 
> Car il y a 1 bit de réservé pour le bit de signe ! (S=0 si positif, 1 sinon)

Par exemple sur 3 bits, on va de $-2^{2} \text{ à }  2^2-1$ donc de $-4  \text{ à }  3$:

| -4  | -3  | -2  | -1  | 0   | 1   | 2   | 3   |
| --- | --- | --- | --- | --- | --- | --- | --- |
| 100 | 101 | 110 | 111 | 000 | 001 | 010 | 011 | 

> [!hint] Différence entre les positifs et négatifs en binaire
> 
> Contrairement aux positifs, plus les entiers négatifs sont grands, plus leur correspondance en binaire sera petite en complément à 2

### Conversion Complément à 2 vers Décimal

**Pour les entiers positifs (S=0)** : binaire naturel

> [!example] Exemple pour un nombre positif
> 
> $N_{cpt2}=\textcolor{red}{0}100\ 0111$ à convertir en décimal
> 
> - Le <mark style="background: #FF5582A6;">bit de signe</mark> est égal à 0 donc nombre positif
> - On convertit en décimal : $1 \times 2^{0}+ 1 \times 2^{1} + 1\times 2^{2} + 1 \times 2^{6} = 1+2+4+64 = 71_{10}$

**Pour les entiers négatifs (S=1)** : on reprend le complément à 2

> [!example] Exemple pour un nombre négatif
> 
> $N_{cpt2}= \textcolor{red}{1}100 \ 0111$ à convertir en décimal
> - Le <mark style="background: #FF5582A6;">bit de signe</mark> est égal à **1** donc nombre **négatif**
> - On a donc : cpt(N) + 1 = 1100 0111
> - On inverse tous les bits : 0011 1000
> - On rajoute 1 : **0011 1001**
> - On convertit en décimal : $1 \times 2^{0}+ 1 \times 2^{3}+1\times 2^{4}+1\times 2^{5} = 1+8+16+32 =\bf{\textcolor{yellow}{-}}57_{10}$
> 
><mark style="background: #FFF3A3A6;"> Ne pas oublier le signe car le nombre est négatif !</mark>

> [!warning] Attention à respecter le format de cpt2 sur $k$ bits
> 
> Lors d'une conversion à partir d'un format cpt2, le **nombre de bits doit être défini**, et il faut **absolument** respecter le nombre de bits lors de la conversion
> 
> **Le format complément à 2 n'est pas le même selon le nombre de bits utilisés**
> 
> *Par exemple : (<mark style="background: #BBFABBA6;">4 bits</mark>, <mark style="background: #FF5582A6;">8 bits</mark>, <mark style="background: #ADCCFFA6;">16 bits</mark>)*
> 
> 3<sub>10</sub> = <mark style="background: #BBFABBA6;">0111<sub>cpt2</sub></mark> = <mark style="background: #FF5582A6;">**0000** 0011<sub>cpt2</sub></mark> =<mark style="background: #ADCCFFA6;"> **0000 0000 0000** 0011<sub>cpt2</sub></mark>
> 
>  -3<sub>10</sub> = <mark style="background: #BBFABBA6;">1101<sub>cpt2</sub></mark> = <mark style="background: #FF5582A6;">**1111** 1101<sub>cpt2</sub></mark> =<mark style="background: #ADCCFFA6;"> **1111 1111 1111** 1101<sub>cpt2</sub></mark>
>  
>  On recopie le **bit de signe** devant pour respecter le format (donc 0 si positif et 1 si négatif)

Evidemment, **plus $k$ est grand, plus on pourra représenter un nombre d'entiers importants**. Donc, il est forcément possible de passer d'une représentation sur $k$ bits à une représentation sur $k'$ bits ($k' >k$) mais il n'est pas forcément possible de faire l'inverse.

## Opérations sur les entiers en machine avec les Compléments à 2

### Nombres de signes opposés
Si les 2 nombres sont de signes opposés ↪ résultat représentable (car on peut représenter de  $\bf{-2^{k-1}}$ à $\bf{2^{k-1}-1}$ )

> [!example] Exemple de calcul
> 
> 63 - 63 = 63 + (-63) à convertir en complément à 2
> 
> ![calcul posé de 63 - 63 en binaire| 200](../images/Pasted%20image%2020221101125420.png)
> 
> On ne s'occupe pas de la retenue car on représente sur 8 bits donc le résultat est bien 0000 0000
> 
> 63 - 18
> 
> ![calcul posé de 63-18 en binaire|200](../images/Pasted%20image%2020221101125849.png)
> 
> Le résultat est donc (en ignorant la retenue) : 0010 1101
> 
> On ignore la retenue car on effectue en fait le calcul $63 - \textcolor{blue}{2^{8}-18} -\textcolor{red}{2^{8}} = 63 - 18$ avec le <mark style="background: #ADCCFFA6;">complément à 2</mark> et la <mark style="background: #FF5582A6;">retenue ignorée</mark>

> [!warning] Retenue
> 
> La retenue est **toujours ignorée,** on n'en tient pas compte dans le résultat
> 
> Elle peut néanmoins être stockée pour effectuer des vérifications si besoin

###  Nombres de même signe

Si les 2 nombres ont le même signe, on risque de dépasser l'intervalle de nombres que l'on peut représenter : on doit donc **vérifier le dépassement = overflow**

Sur 3 bits par exemple, on ne peut pas représenter 3+3 car le nombre maximal représenté est **3** < **6**

> [!example] Exemples de calculs
> 
> Pour chaque calcul, on représente la <mark style="background: #FF5582A6;">retenue (carry = C)</mark> et le <mark style="background: #ADCCFFA6;">bit de signe S</mark>
> 
> On se trouve sur 8 bits dans ces exemples donc on peut représenter de **-128 à 127**
> 
> ![calcul de 18+65 |200](../images/Pasted%20image%2020221101130425.png)
> 
> Résultat : <mark style="background: #FF5582A6;">0</mark><mark style="background: #ADCCFFA6;">0</mark>1010011 donc C = S
> 
> On a un résultat de 83 donc le résultat est **représentable** : pas d'overflow
> 
> ![calcul de -18 - 65 |200](../images/Pasted%20image%2020221101130432.png)
> 
> Résultat : <mark style="background: #FF5582A6;">1</mark><mark style="background: #ADCCFFA6;">1</mark>0101101 donc C =S
> 
> On a un résultat de -83 donc le résultat est **représentable** : pas d'overflow
> 
> 101+65
>  ![calcul de 101 + 65 |200](../images/Pasted%20image%2020221101130445.png)
>  
>  Résultat : <mark style="background: #FF5582A6;">0</mark><mark style="background: #ADCCFFA6;">1</mark>0100110, donc C $\neq$ S 
>  
>  Le résultat est de 166 > 127 donc **overflow**
>  
>  -101-65
>  ![calcul de -101-65 |200](../images/Pasted%20image%2020221101130546.png)
>  
>  Résultat : <mark style="background: #FF5582A6;">1</mark><mark style="background: #ADCCFFA6;">0</mark>1011010, donc C $\neq$ S 
>  
>  Le résultat est de -166 > -128 donc **overflow**

Il est donc bien nécessaire d'<mark style="background: #FF5582A6;">afficher la retenue C</mark> pour pouvoir savoir si le résultat est représentable et donc s'il y a dépassement.

# Représentation des nomrbres réels ↪ nombres flottants
## Représentation en virgule flottante

## Représentation en norme IEEE754

## Opérations sur les flottants


