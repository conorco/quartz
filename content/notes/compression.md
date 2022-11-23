---
title: "Codage et Compression"
tags:
- info
- codage
---

**Objectif de la compression** ↪ réduire la longueur d'une séquence numérique (en binaire) sans affecter son contenu informatif (= conservation de l'information)

➡ Transformer l'information délivrée par la source numérique ↪ on doit éliminer les redondances = représentation efficace

Le but est donc :
- de diminuer les tailles de fichiers et l'espace mémoire
- d'augmenter la capacité de transmission (en télécom, afin d'avoir un débit + important)

Il existe **2 types de compression** :
1. **Compression sans perte** ↪ on retrouve l'**intégralité** des données stockées sous forme comprimée *(par exemple : billets pour un concert, déclaration d'impôts, bulletins de votes)*
2. **Compression avec pertes** ↪ un peu de **distorsion** donc perte d'information mais plus complexe *(par exemple : émissions podcasts, musiques au format mp3, photos, vidéos...)*

Ici, on ne verra que la **compression sans perte**.

# Codage de caractères
## Introduction
Dans les exemples, nous verrons comment compresser du texte, donc il est important de voir comment on peut **coder** ce texte.

Les ordinateurs utilisent des [données binaires](Representation_num.md), donc chaque caractère de texte va être codé par 1 nombre, donc par une **suite de bits**.

Il existe différents codages de caractères (évolution avec le temps et différente selon les langues)

*codage Baudot (1874) : premier code binaire destiné à être utilisé par une machine*

## Code ASCII[^1]
[^1]: American Standard Code for Information Interchange

Développé dans les années 1960, **norme ISO 646** en 1983

Codage qui utilise 7 bits pour représenter un caractère, donc permet de représenter $2^8=128$ caractères différents ce qui représente :
- 26 lettres latines minuscules
- 26 lettres latines majuscules
- 10 chiffres décimaux
- espace
- ponctuation
- parenthèses
- codes de formatage (retour à la ligne, DEL, ESC)

**Format :** 1 octet par caractère (8ème bits soit à 0, soit un bit de parité pour détecter les erreurs selon les systèmes de transmission : pour l'**uniformisation** des données)

![table ascii](../images/Pasted%20image%2020221119100811.png)

> [!example] Convertir "Je" en ASCII
> 
><mark style="background: #FF5582A6;"> J = 4A</mark> en Hexa
> 
> <mark style="background: #BBFABBA6;">e = 65</mark> en Hexa
> 
> Donc la suite de bits est : <mark style="background: #FF5582A6;">0100 1010</mark> <mark style="background: #BBFABBA6;">0110 0101</mark>

> [!attention] Limites du code ASCII
> 
> - **Nombre limité** de caractères
> - Manque de caractères importants : * au lieux de $\times$
> - code **américain** donc **pas de caractères accentués**
> - pour les autres alphabets (grecs, arabe, chinois) ↪ inadéquat

Donc développement d'autres codages de caractères

## Autre codage de caractère (UTF-8)
### ISO[^2] 8859
[^2]: International Organization for Standardization

- Versions ASCII étendues : Compatibilités ascendante et descendante (programme de lecture ISO8859 peut lire de l’ASCII et programme ASCII peut lire ISO8859)
- **Version la plus utilisée ISO8859-1** souvent dénommée Latin-1 (Europe Occidentale)
- **191 caractères codés sur un octet** (au lieu de 128) ;
- Versions ISO8859-2 (Europe de l’est), -3 (Europe du sud), -4 (Europe du nord), -5 (pour le russe), -6 (pour l’arabe) 
- Nombreuses **versions non compatibles** entre elles et **insuffisant pour les langues à idéogrammes**

### Unicode (1987)

- Créer un code universel
- Augmenter le nombre de bits pour coder un caractère ↪ **16 bits (65536 caractères)** 
- Inconvénients : **2 fois plus gros et non-compatible avec ASCII** 
- Est devenu une famille de codage 
- En 1991, consortium Unicode, la norme Unicode, en plus d’un standard de codage de caractère, un immense rapport sur les langues.
- La version 10.0,(8 518 nouveaux caractères) pour un total de 136 690 caractères est publiée le 20 juin 2017 
- Plusieurs encodage existent ↪ le **plus connu UTF**[^3] qui est **compatible avec ASCII**

[^3]: Universal Transformation Format

### UTF-8

**Codage de longueur variable :**

| Nombre d'octets           | Caractères codés                       |
| ------------------------- | -------------------------------------- |
| Sur 1 octet (0x00 à 0x7F) | tous les caractères du ASCII (MSB[^4] à 0) |
| Sur 2, 3 ou 4 octets      | les autres caractères (MSB à 1)                 | 

[^4]: bit de poids fort : non utilisé en ASCII

> [!info] Codage de l'UTF-8
> 
> - Un premier octet (**lead byte**) suivi d’un nombre variable d’octets (**trailing byte**)(maximum 4 octets au total) représentent conjointement la valeur à encoder.
> - Bit de poids fort du *<mark style="background: #BBFABBA6;">lead byte</mark>* à 1 et autant de bit à 1 que de <mark style="background: #FFB86CA6;">*trailing byte*</mark>. 
> - Un même caractère peut avoir plusieurs représentations choix du code le plus court
>   
>   
>   | Formats du code                     | Nombre d'octets utilisés | Nombre de bits disponibles pour coder |
| ----------------------------------- | ------------------------ | ------------------------------------- |
| 0xxxxxxx                            | 1                        | 7 bits                                |
| <mark style="background: #BBFABBA6;">110xxxxx</mark> <mark style="background: #FFB86CA6;">10xxxxxx</mark>                   | 2                        | 8 à 11 bits                           |
| <mark style="background: #BBFABBA6;">1110xxxx</mark><mark style="background: #FFB86CA6;"> 10xxxxxx 10xxxxxx</mark>          | 3                        | 12 à 16 bits                          |
| <mark style="background: #BBFABBA6;">11110xxx</mark><mark style="background: #FFB86CA6;"> 10xxxxxx 10xxxxxx 10xxxxxx</mark> | 4                        | 17 à 21 bits                                      |

**21 bits sont suffisants pour représenter l'ensemble des caractères définis par l'Unicode**

> [!example] Coder "<mark style="background: #ADCCFFA6;">é</mark><mark style="background: #D2B3FFA6;">t</mark><mark style="background: #FF5582A6;">é</mark>"
> 
> En UTF-8 : <mark style="background: #ADCCFFA6;">C3 A9</mark> <mark style="background: #D2B3FFA6;">74</mark> <mark style="background: #FF5582A6;">C3 A9</mark>
> 
> C3 A9 = <mark style="background: #BBFABBA6;">1100 0011</mark> <mark style="background: #FFB86CA6;">1010 1001</mark> avec le <mark style="background: #BBFABBA6;">lead byte</mark> et le <mark style="background: #FFB86CA6;">trailing byte</mark> (donc "é" codé sur 2 octets)

> [!tip] Taille des fichiers
> 
> Plus on utilise des caractères peu fréquents (comme les caractères accentués), plus le nombre d'octets utilisés est grand donc plus le fichier en sortie est volumineux

L'UTF-8 domine le web, c'est le codage le plus utilisé actuellement ([source](https://w3techs.com/technologies/overview/character_encoding))

![Percentages of websites using various character encoding, UTF-8 is leading with 98%](../images/Pasted%20image%2020221123094013.png)

![utilisation de l'UTF-8 au cours du temps | ](../images/Pasted%20image%2020221119102323.png)

# Compression
## Introduction

La distribution des lettres n'est pas équivalente en française (ou dans d'autres langues) :

[![distribution des lettres dans différentes langues](../images/Pasted%20image%2020221123094544.png)](https://fr.wikipedia.org/wiki/Fr%C3%A9quence_d'apparition_des_lettres)
Par exemple, la lettre e est utilisée 15 fois plus souvent que la lettre de b.

**Premières compressions** : Morse, avec les lettres les + utilisés : e, a, t (on voit qu'elles ont un plus court symbole)
![code morse international](../images/Pasted%20image%2020221123094824.png)

## Définitions

- La compression transforme l'information délivrée par la source numérique
- Elimine les redondances ↪ pour **minimiser la longueur binaire moyenne** d'un code $\overline{L}$

![schéma compression](../images/Pasted%20image%2020221123100502.png)

> [!tldr] Notations utilisées en compression
> 
> **Longueur binaire d'un symbole codé $l$** : nombre de **bits** d'un symbole codé (*le symbole "a" en ASCII est 01100001 donc $l_{"a"}=8$*)
> 
> **Probabilité pi de chaque symbole du code :** $p_{i}= \frac{\text{Nombre d'apparitions d'un symbole}}{\text{Nb total de symboles}}$
> 
> **Taille (longueur moyenne pondérée) du code de Q symboles :** $\overline{L} = \sum_{k=1}^{Q}p_{k}l_{k}$
> 
> Donc, pour réduire $\overline{L}$, on va chercher à réduire $l$ quand $p$ est élevé et inversement

> [!example] Code à 6 lettres
> 
> | Lettre      | A    | B    | C    | D    | E    | F   |
> | ----------- | ---- | ---- | ---- | ---- | ---- | --- |
> | Code        | 0    | 1    | 00   | 01   | 001  | 101 |
> | Apparition  | 5    | 4    | 3    | 2    | 1    | 1   |
> | Probabilité $p$ | 5/16 | 4/16 | 3/16 | 2/16 | 1/16 | 1/16 |
> | $l$ | 1 | 1 | 2 | 2 | 3 | 3 |
> 
> Calcul de  $\overline{L}=p_{1}l_{1}+p_{2}l_{2}+p_{3}l_{3}+p_{4}l_{4}+p_{5}l_{5}+p_{6}l_{6}$
> 
> $\overline{L}= \frac{5}{16}\cdot 1 +\frac{4}{16}\cdot 1 + \frac{3}{16}\cdot 2+\frac{2}{16}\cdot 2+\frac{1}{16}\cdot 3+\frac{1}{16}\cdot 3$
> 
> $\overline{L}= \frac{1}{16}(5+4+6+4+6)= \frac{25}{16} \approx$ 1,56 bits / symbole

> [!example] Différents codes et leurs caractéristiques
> 
>| Symboles | $p(S_{k})$ | Code A | Code B | Code C | Code D |
> | -------- | ---------- | ------ | ------ | ------ | ------ |
> | $S_0$    | 0,5        | 00     | 0      | 10     | 0      |
> | $S_1$    | 0,3        | 01     | 1      | 00     | 10     |
> | $S_2$    | 0,1        | 10     | 00     | 11     | 110    |
> | $S_3$    | 0,1        | 11     | 11     | 110    | 111    | 
> 
> Le code A a une longueur moyenne de 2 bits/symboles et est à **longueur fixe** et c'est un **code préfixe**
> 
> Le code B a une meilleure compression (1,2 bits/symbole) mais est **à longueur variable** et c'est un code **non préfixe** (S1 et S3 commencent par le même symbole)
> 
> Le code C a une longueur moyenne de 2,1 bits/symbole et est à longueur variable et non préfixe
> 
> Le code D a une longueur moyenne de 1,7 bits/symbole est à longueur variable et est **préfixe**

> [!info] Code à longueur fixe et variable
> 
> A **longueur fixe** : nombre de bits fixé (ASCII)
> 
> A **longueur variable** : nombre de bits variables (Morse)

> [!info] Code préfixe (ou code instantané)
> 
> Un code préfixe est un code où **aucun symbole n'est le préfixe d'un autre**, donc tous les mots du code peuvent être décodés sans erreur. **Tous les codes à longueur fixe sont des codes préfixes**
> 
> On préfère utiliser des codes préfixes pour la compression, comme **UTF-8**

### Information associée à un symbole

Soit A le symbole dont la probabilité d'occurrence est $p_{A}$. L'information liée à A est :
$$
I_{A}=\log_{2}\left( \frac{1}{p_{A}} \right ) = -\log_2p_{A}
$$

Donc, si A est peu probable, $I_{A} \rightarrow +\infty$, et si A quasi certain, $I_{A}\rightarrow 0$

Donc, plus $p$ est élevé, plus $I$ sera faible (donc **l'information est liée à la rareté d'un symbole**)

> [!example] Exemple de calcul d'information des symboles
> 
>| Symboles | $p(S_{k})$ | Code A | Code B | Code C | Code D |
> | -------- | ---------- | ------ | ------ | ------ | ------ |
> | $S_0$    | 0,5        | 00     | 0      | 10     | 0      |
> | $S_1$    | 0,3        | 01     | 1      | 00     | 10     |
> | $S_2$    | 0,1        | 10     | 00     | 11     | 110    |
> | $S_3$    | 0,1        | 11     | 11     | 110    | 111    | 
> 
> $I_{S_{0}}=-\log_{2}(0,5) = -\log_{2}(2^{-1})=1$
> 
> $I_{S_{1}}=-\log_{2}(0,3) = 1,74$
> 
>  $I_{S_{2}}=-\log_{2}(0,1) =3,32 = I_{S_{3}}$

### Entropie H : information moyenne liée au code

L'entropie représente la **moyenne pondérée** de l'information et est définie par :
$$
H = \sum\limits_{k=1}^{Q}p_{k}I_{k}=-\sum\limits_{k=1}^{Q}p_{k}\log_{2}p_{k}
$$
L'unité de H est en **bits d'information / symbole transmis**, ou en **Sh** (Shannon)

Les valeurs extrêmes de l'entropie sont : 
- $H_{min}=0$ pour $p_{k}=1$ (1 seul symbole présent)
- $H_{max}=\log_{2}Q$ pour Q symboles équiprobables, donc $p_{i}=\frac{1}{Q} \forall i$ 

> [!example] Exemples de calcul d'entropie (avec 16 lettres)
> 
> 1.  A A A A A A A A A A A A A A A A 
> 
> $p_{A}=1$ donc l'entropie est $H=-1 \times \log_{2}1 =-1\times 0 =0$
> 
> 2. A B C D E F G H I J K L M N O P
>    
>    $p_{i}=\frac{1}{16} \forall i$ donc $H=-16 \times \frac{1}{16} \times \log_{2} \frac{1}{16} = -\log_{2} \frac{1}{16} = \log_{2}2^{4} = 4$ donc entropie maximale

> [!quote] Origines de la notion d'entropie
> 
> En **physique** (Boltzmann[^5], 1872), l'entropie mesure le **désordre** dans un système.
> 
> En **théorie de l'information** (Shannon [^6], 1948), l'entropie mesure la "**quantité d'information**" contenue dans un signal
> 

[^5]: ardent défenseur de l’existence des atomes père de la physique statistique
[^6]: mathématicien, ingénieur électricien, cryptologue père de la théorie de l’information

> [!check] Bilan sur l'entropie
> 
> - <mark style="background: #FF5582A6;">A B C D E F G H I J K L M N O P ↪ H = 4 bits/symb</mark>
> - I L F A I T B E A U A I B I Z A ↪ H= 2,875 bits/symb
> - <mark style="background: #ADCCFFA6;">A A A A A A A A A A A A A A A A ↪ H = 0 bit/symb</mark>
>   
>   <mark style="background: #FF5582A6;">Entropie forte : </mark>Plus il y a de lettres différentes, plus il y a de désordre, plus il y a de nouveauté, plus il y a d’« information » dans le message
>   
>   <mark style="background: #ADCCFFA6;">Entropie faible :</mark> Plus il y a de lettres semblables, moins il y a de désordre plus il y a de redondance et donc moins d’« information » dans le message.

### Inégalité de Kraft

L'inégalité de Kraft est un **résultat fondamental en théorie des codes**, c'est une **condition <mark style="background: #FFF3A3A6;">nécessaire et suffisante</mark> d'existence d'un code déchiffrable et instantané**

Un code instantané doit satisfaire cette inégalité :
$$
\sum_{k=1}^{Q}2^{-l_{k}} \leq 1
$$

La réciproque est vraie, si une suite de $l_{k}$ vérifient cette relation, alors il existe un code instantané avec cette distribution des longueurs

![schéma compression 2](../images/Pasted%20image%2020221123111845.png)

### Autres définitions

> [!info] Taille du code
> 
> - Pour un code à **longueur fixe**, la taille du code est la taille des mots (ASCII = 8 bits)
> - Pour un code à **longueur variable**, la taille du code est $\overline{L}=l_{1}p_{1}+...+l_{n}p_{n}$

> [!danger] Théorème de Shannon code préfixe
> 
> $$H+1 \ge \overline{L}\ge H$$
> 
> Plus $\overline{L}$ (dépend de la compression utilisée) est proche de $H$ (qui ne dépend que des probabilités des symboles), meilleure seront les performances de la compression

> [!important] Efficacité et taux de compression
> 
> L'efficacité est définie par : $\eta = \frac{H}{\overline{L}}$
> 
> Le taux de compression est : $\tau = \frac{L_{fixe}}{\overline{L}} = \frac{\text{longueur avant compression}}{\text{longueur après compression}}$

> [!example] Exemples
> 
>| Symboles | $p(S_{k})$ | Code A | Code B | Code C | Code D |
> | -------- | ---------- | ------ | ------ | ------ | ------ |
> | $S_0$    | 0,5        | 00     | 0      | 10     | 0      |
> | $S_1$    | 0,3        | 01     | 1      | 00     | 10     |
> | $S_2$    | 0,1        | 10     | 00     | 11     | 110    |
> | $S_3$    | 0,1        | 11     | 11     | 110    | 111    | 
> 
> On a : $L_{A}= 2$ bits/sym, <mark style="background: #FFB86CA6;">$L_{B}=1,2$ bits/sym, $L_{C}=2,1$ bits/sym,</mark> $L_{D}=1,7$ bits/sym. <mark style="background: #FFB86CA6;">Codes non préfixes</mark> donc inutilisables pour appliquer l'inégalité de Kraft
> 
> On calcule l'entropie : $H = 1,69$ bits/symboles
> 
> Donc on a bien : $1,69+1 \ge \overline{L} \ge 1,69$, et on voit que $L_{D}$ est plus proche de $H$ que $L_{A}$, donc le code D apporte une meilleure compression


# Codages de compression statistique
## Introduction

## Codage de Shannon-Fano

## Codage de Huffman

# Codages par substitution