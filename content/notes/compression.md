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

Développé dans les années 1960, norme ISO 646 en 1983

Codage qui utilise 7 bits pour représenter un caractère, donc permet de représenter $2^8=128$ caractères différents ce qui représente :
- 26 lettres latines miniscules
- 26 lettres majuscules
- 10 chiffres décimaux
- espace
- ponctuation
- parenthèses
- codes de formatage (retour à la ligne, DEL, ESC)

**Format :** 1 octet par caractère (8ème bits soit à 0, soit un bit de parité pour détecter les erreurs selon les systèmes de transmission)

## Autre codage de caractère (UTF-8)

# Compression
## Introduction

## Définitions

# Codages de compression statistique
## Introduction

## Codage de Shannon-Fano

## Codage de Huffman

# Codages par substitution