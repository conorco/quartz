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
## Compléments à 2

## Opérations sur les entiers en machine avec les Compléments à 2

# Représentation des nomrbres réels ↪ nombres flottants
## Représentation en virgule flottante

## Représentation en norme IEEE754

## Opérations sur les flottants


