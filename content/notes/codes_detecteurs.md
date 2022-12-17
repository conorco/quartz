---
title: "Codes détecteurs et correcteurs d'erreurs"
tags:
- info
- codage
---
# Principe et définitions
## Principe

Il y a des **altérations du message** dues au canal de transmission (câble, transmission sans fil...). Par exemple, pour un taux d'erreur de $10^{6}$ = 1 bit erroné sur $10^{6}$, donc pour une connexion à 1 Mo/s ↪ 8 bits erronés /seconde 

⇒ Altération des données stockées (DVD, disque-dur, mémoire flash)

Le **taux d'erreur** varie énormément → compris entre $10^{-9}$ et $10^{-4}$

Le **principe général** de détection et de correction des erreurs est donc :
- d'ajouter de la redondance au message à transmettre → différentes manières de le faire
- et à la réception d'effectuer l'opération inverse → les bits ajoutés sont contrôlés pour éviter les erreurs

> [!example] Transmettre un numéro de téléphone avec une erreur
> 
> 
> | Message transmis | Message reçu |
> | ---------------- | ------------ |
> | 0654122235       | 065412223<mark style="background: #FF5582A6;">6</mark>             |
> 
> **Solution** → redondance (un chiffre est remplacé par plusieurs lettres) :
> 
> ⇒ zero six cinquante-quatre douze deux deux trente-cilq (cilq $\approx$ cinq)

Donc : une information **concise** est **difficile à corriger** alors que dans une information **redondante**, on peut détecter et corriger les erreurs

> [!info] Différents codes
> 
> 1. **Code détecteur d'erreur** → Détecte un certains nombre d'erreurs mais ne les corrige pas
> 2. **Code détecteur et correcteur d'erreur** → Détecte et corrige un certain nombre d'erreurs.

## Définitions

**Taux d'erreur :** $T = \frac{\text{nombre de bits reçus erronés}}{\text{nombre des bits total émis}}$

**Débits :**
- Débit **binaire** (Db) = nombre de bits transmis/s
- Débit **symbole** (Ds) = nombre de symboles transmis/s *(en Baud)*

**code C(n,k)** :
- Nombre de bits du **message** : k bits
- Nombre de bits du **contrôle** : r bits
- Nombre de bits **transmis** : n = k+r bits

**Rendement d'un code C(n,k)** : $R=\frac{k}{N}<1$

> [!tip] Choix d'un code
> 
> Pour une bonne détection/correction d'erreurs → redondance importante donc **r grand**
> 
> Pour un code économique, avec une transmission rapide (débit élevé) → **r petit**
> 
> ⇒ Il existe donc un compromis entre l'efficacité de la détection/correction et l'efficacité de la transmission

### Codage en bloc C(n,k)

Dans la pratique des codes correcteurs → codages par blocs

![illustration](../images/Pasted%20image%2020221214160841.png)

### Codage systématique

Le mot à coder se trouve au début du mot codé

Il est nécessaire de rajouter $r = n-k$  bits de contrôle à la fin du mot à coder

- k premiers symboles du mot codé → **information**
- r derniers symboles du mot codé → **redondance**

Permet un **décodage immédiat**

![codage systématique](../images/Pasted%20image%2020221214161417.png)

### Poids et distance de Hamming

**Poids de Hamming :** $p_H$ est le nombre de bits à 1

**Distance de Hamming :** nombre de positions où les bits sont différents entre 2 mots

# Codes simples et usuels
## Code de parité
### Emission

> [!info] Principe
> 
> C'est un codage par bit de parité, qui est **détecteur d'erreur**, très simple et très utilisé
> 
> ⇒ ajout d'un **bit de parité** (bit de contrôle) qui correspond au nombre pair de "1"
> - nombre **pair** de 1 ⇒ bit de parité = 0
> - nombre **impair** de 1 ⇒ bit de parité = 1

![format du code de parité](../images/Pasted%20image%2020221217153915.png)

### Réception

Par exemple, pour le massage reçu suivant :
![](../images/Pasted%20image%2020221217154518.png)

Il y a 1 ou 3 erreurs commises car le nombre de bits est **impair**

Mais dans cet exemple :
![](../images/Pasted%20image%2020221217154600.png)
 Il peut y avoir 0, 2 ou 4 erreurs commises car le nombre de bits est **pair**


> [!check] Performances du code de parité
> 
> Le code de parité ne détecte qu'un nombre **impair** d'erreur et la correction est **impossible**
> 
> - Longueur des mots d'information : **k**
> - Redondance : **r=1**
> - Longueur des messages émis : **n=k+1**
> 
> Donc le rendement est tel que $R=\frac{k}{k+1}$ (assez fort)

## Code de répétition
### Emission

> [!info] Principe du codage par répétition
> 
> - Codage par répétition du bit à transmettre
> - Code **détecteur et correcteur** d'erreur, très simple et très utilisé
> - Code **systématique**
>   
> Ajout de **r bits** de contrôles → pour obtenir un nombre de bits impair
> 
> Noté tel que C(n,1) avec n = k+r

![schéma du codage par répétition](../images/Pasted%20image%2020221217155059.png)

### Réception

Par exemple :
![](../images/Pasted%20image%2020221217155234.png)

La correction se fait par la **distance de Hamming** minimale avec les mots possibles, donc le mot décodé est `1`.

Dans cet exemple, si il y a 2 ou 3 erreurs ⇒ mauvaise correction


> [!check] Performances
> 
> Détection des erreurs (*sauf si tous les bits sont **faux***), et correction de $\frac{r}{2}$ bits
> 
> Rendement de $R=\frac{k}{k+r}$


## Code double parité
### Emission

> [!info] Principe du code double parité
> 
> Permet un double contrôle par rapport au codage par rapport au [Code de parité](#Code%20de%20parité), c'est un code **détecteur** et **correcteur** d'erreur
> 
> Par rapport à la simple parité, on va **assembler plusieurs blocs de k bits** pour effectuer le double contrôle

![schéma du découpage en blocs de taille k](../images/Pasted%20image%2020221217160118.png)

Par exemple :

![](../images/Pasted%20image%2020221217160323.png)

### Réception

A la réception, on peut donc comparer les bits de parités pour chaque ligne et pour chaque colonne. Le croisement des informations permet de repérer l'erreur :

![illustration d'un tableau présentant une erreur au croisement de la deuxième ligne et troisième colonne](../images/Pasted%20image%2020221217160614.png)


> [!check] Performances
> 
> Détection de **beaucoup d'erreur**, mais correction **d'une seule erreur**
> 
> - Redondance : 1+k+M
> - Longueur des blocs émis : $n= (M+1)\times (k+1)$
> - Rendement $R=\frac{Mk}{k+Mk+M+1}$
>   
>  Donc **meilleur rendement** que le [Code de répétition](#Code%20de%20répétition)

# Code de Hamming
## Principe


## Codage


## Décodage