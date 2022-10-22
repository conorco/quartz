---
tags : code
author : Conor Cauty
date : 2022-03-21 08:51
title: Créer un site (HML5 CSS3)
listings-no-page-break: true
disable-header-and-footer: true
geometry: "left=2cm,right=2cm,top=2cm,bottom=2cm"
output:
  pdf: 
    pandoc_args: ["--from=markdown+hard_line_breaks"]
    pdf-engine: xelatex
    output: Créer un site (HML5 CSS3).pdf
    from: markdown
    template: eisvogel 
    listings: true
---
# Mémento
## Des balises HTML
###  Balises de premier niveau

Les balises de premier niveau sont les principales balises qui structurent une page HTML. Elles sont indispensables pour réaliser le « code minimal » d'une page web.

| Balise   | Description        |
| -------- | ------------------ |
| `<html>` | Balise principale  | 
| `<head>` | En-tête de la page |
| `<body>` | Corps de  la page  |

Code minimal HTML :
```html
<!DOCTYPE html>
<html lang="en" dir="ltr">
  <head>
    <meta charset="utf-8">
    <title></title>
  </head>
  <body>
    
  </body>
</html>
```

### Balises d'en-tête

Ces balises sont toutes situées dans l'en-tête de la page web, c'est-à-dire entre `<head>` et `</head>` :

| Balise | Description |
| --- | --- |
| `<link />` | Liaison avec une feuille de style |
| `<meta />` | Métadonnées de la page web (charset, mots-clés, etc.) |
| `<script>` | Code JavaScript |
| `<style>` | Code CSS |
| `<title>` | Titre de la page |

### Balises de structuration du texte

| Balise | Description |
| --- | --- |
| `<abbr>` | Abréviation |
| `<blockquote>` | Citation (longue) |
| `<cite>` | Citation du titre d'une œuvre ou d'un évènement |
| `<q>` | Citation (courte) |
| `<sup>` | Exposant |
| `<sub>` | Indice |
| `<strong>` | Mise en valeur forte |
| `<em>` | Mise en valeur normale |
| `<mark>` | Mise en valeur visuelle |
| `<h1>` | Titre de niveau 1 |
| `<h2>` | Titre de niveau 2 |
| `<h3>` | Titre de niveau 3 |
| `<h4>` | Titre de niveau 4 |
| `<h5>` | Titre de niveau 5 |
| `<h6>` | Titre de niveau 6 |
| `<img />` | Image |
| `<figure>` | Figure (image, code, etc.) |
| `<figcaption>` | Description de la figure |
| `<audio>` | Son |
| `<video>` | Vidéo |
| `<source>` | Format source pour les balises `<audio>` et `<video>` |
| `<a>` | Lien hypertexte |
| `<br />` | Retour à la ligne |
| `<p>` | Paragraphe |
| `<hr />` | Ligne de séparation horizontale |
| `<address>` | Adresse de contact |
| `<del>` | Texte supprimé |
| `<ins>` | Texte inséré |
| `<dfn>` | Définition |
| `<kbd>` | Saisie clavier |
| `<pre>` | Affichage formaté (pour les codes sources) |
| `<progress>` | Barre de progression |
| `<time>` | Date ou heure |

### Balises de listes

Cette section énumère toutes les balises HTML permettant de créer des listes (listes à puces, listes numérotées, listes de définitions…)

| Balise | Description |
| --- | --- |
| `<ul>` | Liste à puces, non numérotée |
| `<ol>` | Liste numérotée |
| `<li>` | Élément de la liste à puces |
| `<dl>` | Liste de définitions |
| `<dt>` | Terme à définir |
| `<dd>` | Définition du terme |

### Balises de tableau

| Balise | Description |
| --- | --- |
| `<table>` | Tableau |
| `<caption>` | Titre du tableau |
| `<tr>` | Ligne de tableau |
| `<th>` | Cellule d'en-tête |
| `<td>` | Cellule |
| `<thead>` | Section de l'en-tête du tableau |
| `<tbody>` | Section du corps du tableau |
| `<tfoot>` | Section du pied du tableau |

### Balises de formulaire

| Balise | Description |
| --- | --- |
| `<form>` | Formulaire |
| `<fieldset>` | Groupe de champs |
| `<legend>` | Titre d'un groupe de champs |
| `<label>` | Libellé d'un champ |
| `<input />` | Champ de formulaire (texte, mot de passe, case à cocher, bouton, etc.) |
| `<textarea>` | Zone de saisie multiligne |
| `<select>` | Liste déroulante |
| `<option>` | Élément d'une liste déroulante |
| `<optgroup>` | Groupe d'éléments d'une liste déroulante |

### Balises sectionnantes

Ces balises permettent de construire le squelette de notre site web.

| Balise | Description |
| --- | --- |
| `<header>` | En-tête |
| `<nav>` | Liens principaux de navigation |
| `<footer>` | Pied de page |
| `<section>` | Section de page |
| `<article>` | Article (contenu autonome) |
| `<aside>` | Informations complémentaires |

### Balises génériques

Les balises génériques sont des balises qui n'ont pas de sens sémantique.

En effet, toutes les autres balises HTML ont un _sens_ : `<p>` signifie « paragraphe », `<h2>` signifie « sous-titre », etc.  
Parfois, on a besoin d'utiliser des balises génériques (aussi appelées **_balises universelles_**) car aucune des autres balises ne convient. On utilise le plus souvent des balises génériques pour construire son design.

Il y a deux balises génériques : l'une est inline, l'autre est block.

| Balise | Description |
| --- | --- |
| `<span>` | Balise générique de type inline |
| `<div>` | Balise générique de type block |

Ces balises ont un intérêt uniquement si vous leur associez un attribut `class` , `id` ou `style` :

* `**class**` : indique le nom de la classe CSS à utiliser.
    
* `**id**` : donne un nom à la balise. Ce nom doit être unique sur toute la page car il permet d'identifier la balise. Vous pouvez vous servir de l'ID pour de nombreuses choses, par exemple pour créer un lien vers une ancre, pour un style CSS de type ID, pour des manipulations en JavaScript, etc.
    
* **`style`** : cet attribut vous permet d'indiquer directement le code CSS à appliquer. Vous n'êtes donc pas obligé d'avoir une feuille de style à part, vous pouvez mettre directement les attributs CSS. Notez qu'il est préférable de ne pas utiliser cet attribut et de passer à la place par une feuille de style externe, car cela rend votre site plus facile à mettre à jour par la suite.
    

Ces trois attributs ne sont pas réservés aux balises génériques : vous pouvez aussi les utiliser sans aucun problème dans la plupart des autres balises.

## Des propriétés CSS
### Propriétés de mise en forme du texte

Je résume ici la plupart des propriétés de **mise en forme du texte**.

Qu'est-ce que la mise en forme de texte ? C'est tout ce qui touche à la présentation du texte proprement dit : le gras, l'italique, le souligné, la police, l'alignement, etc.

| Propriété | Valeurs (exemples) | Description |
| --- | --- | --- |
| `font-family` | _police1, police2, police3_, serif, sans-serif, monospace | Nom de police |
| `@font-face` | _Nom et source de la police_ | Police personnalisée |
| `font-size` | 1.3em, 16px, 120%... | Taille du texte |
| `font-weight` | bold, normal | Gras |
| `font-style` | italic, oblique, normal | Italique |
| `text-decoration` | underline, overline, line-through, blink, none | Soulignement, ligne au-dessus, barré ou clignotant |
| `font-variant` | small-caps, normal | Petites capitales |
| `text-transform` | capitalize, lowercase, uppercase | Capitales |
| `font` | -   | Super propriété de police. Combine : `font-weight` , `font-style` , `font-size` , `font-variant` , `font-family` . |
| `text-align` | left, center, right, justify | Alignement horizontal |
| `vertical-align` | baseline, middle, sub, super, top, bottom | Alignement vertical (cellules de tableau ou éléments `inline-block` uniquement) |
| `line-height` | 18px, 120%, normal... | Hauteur de ligne |
| `text-indent` | 25px | Alinéa |
| `white-space` | pre, nowrap, normal | Césure |
| `word-wrap` | break-word, normal | Césure forcée |
| `text-shadow` | 5px 5px 2px blue  <br>_(horizontale, verticale, fondu, couleur)_ | Ombre de texte |

### Propriétés de couleur et de fond

| Propriété | Valeurs (exemples) | Description |
| --- | --- | --- |
| `color` | _nom_, rgb(rouge,vert,bleu), rgba(rouge,vert,bleu,transparence), #CF1A20... | Couleur du texte |
| `background-color` | _Identique à color_ | Couleur de fond |
| `background-image` | url('image.png') | Image de fond |
| `background-attachment` | fixed, scroll | Fond fixe |
| `background-repeat` | repeat-x, repeat-y, no-repeat, repeat | Répétition du fond |
| `background-position` | _(x y)_, top, center, bottom, left, right | Position du fond |
| `background` | -   | Super propriété du fond. Combine : `background-image` , `background-repeat` , `background-attachment` , `background-position` |
| `opacity` | 0.5 | Transparence |

### Propriétés des boîtes

| Propriété | Valeurs (exemples) | Description |
| --- | --- | --- |
| `width` | 150px, 80%... | Largeur |
| `height` | 150px, 80%... | Hauteur |
| `min-width` | 150px, 80%... | Largeur minimale |
| `max-width` | 150px, 80%... | Largeur maximale |
| `min-height` | 150px, 80%... | Hauteur minimale |
| `max-height` | 150px, 80%... | Hauteur maximale |
| `margin-top` | 23px | Marge en haut |
| `margin-left` | 23px | Marge à gauche |
| `margin-right` | 23px | Marge à droite |
| `margin-bottom` | 23px | Marge en bas |
| `margin` | 23px 5px 23px 5px  <br>_(haut, droite, bas, gauche)_ | Super-propriété de marge.  <br>Combine : `margin-top` , `margin-right` , `margin-bottom` , `margin-left` . |
| `padding-left` | 23px | Marge intérieure à gauche |
| `padding-right` | 23px | Marge intérieure à droite |
| `padding-bottom` | 23px | Marge intérieure en bas |
| `padding-top` | 23px | Marge intérieure en haut |
| `padding` | 23px 5px 23px 5px  <br>_(haut, droite, bas, gauche)_ | Super-propriété de marge intérieure.  <br>Combine : `padding-top` , `padding-right` , `padding-bottom` , `padding-left` . |
| `border-width` | 3px | Épaisseur de bordure |
| `border-color` | _nom_, rgb(rouge,vert,bleu), rgba(rouge,vert,bleu,transparence), #CF1A20... | Couleur de bordure |
| `border-style` | solid, dotted, dashed, double, groove, ridge, inset, outset | Type de bordure |
| `border` | 3px solid black | Super-propriété de bordure. Combine ,`border-width` , `border-color` , `border-style` .  <br>Existe aussi en version`border-top` , `border-right` , `border-bottom` , `border-left` . |
| `border-radius` | 5px | Bordure arrondie |
| `box-shadow` | 6px 6px 0px black  <br>_(horizontale, verticale, fondu, couleur)_ | Ombre de boîte |

### Propriétés de positionnement et d'affichage

| Propriété | Valeurs (exemples) | Description |
| --- | --- | --- |
| `display` | block, inline, inline-block, table, table-cell, none... | Type d'élément ( `block` , `inline` , `inline-block` , `none` …) |
| `visibility` | visible, hidden | Visibilité |
| `clip` | rect (0px, 60px, 30px, 0px)  <br>_rect (haut, droite, bas, gauche)_ | Affichage d'une partie de l'élément |
| `overflow` | auto, scroll, visible, hidden | Comportement en cas de dépassement |
| `float` | left, right, none | Flottant |
| `clear` | left, right, both, none | Arrêt d'un flottant |
| `position` | relative, absolute, static | Positionnement |
| `top` | 20px | Position par rapport au haut |
| `bottom` | 20px | Position par rapport au bas |
| `left` | 20px | Position par rapport à la gauche |
| `right` | 20px | Position par rapport à la droite |
| `z-index` | 10  | Ordre d'affichage en cas de superposition.  <br>La plus grande valeur est affichée par-dessus les autres. |

### Propriétés des listes

| Propriété | Valeurs (exemples) | Description |
| --- | --- | --- |
| `list-style-type` | disc, circle, square, decimal, lower-roman, upper-roman, lower-alpha, upper-alpha, none | Type de liste |
| `list-style-position` | inside, outside | Position en retrait |
| `list-style-image` | url('puce.png') | Puce personnalisée |
| `list-style` | -   | Super-propriété de liste. Combine `list-style-type` , ,`list-style-position` , `list-style-image` . |

### Propriétés des tableaux

| Propriété | Valeurs (exemples) | Description |
| --- | --- | --- |
| `border-collapse` | collapse, separate | Fusion des bordures |
| `empty-cells` | hide, show | Affichage des cellules vides |
| `caption-side` | bottom, top | Position du titre du tableau |

### Autres propriétés

| Propriété | Valeurs (exemple) | Description |
| --- | --- | --- |
| `cursor` | crosshair, default, help, move, pointer, progress, text, wait, e-resize, ne-resize, auto... | Curseur de souris |

---

[source](https://openclassrooms.com/fr/courses/1603881-apprenez-a-creer-votre-site-web-avec-html5-et-css3/1604192-decouvrez-le-fonctionnement-des-sites-web)
# Créer un site (HML5 CSS3)
Le site [**caniuse.com**](https://caniuse.com/) tient à jour une liste des fonctionnalités prises en charge par les différentes versions de chaque navigateur -> permet de vérifier la compatibilité des versions d'un navigateur
=> il vaut mieux avoir au moins 2 navigateurs pour tester le site

## Les balises
- Balises **paires** :
```html
<titre>Ceci est un titre </titre>
```
- Balises **orphelines** :
```html
<image />
<!-- ou bien -->
<image>
<!-- mais cela permet de ne pas les confondre -->
```
- attributs :
```html
<balise attribut="valeur">
<!-- par exemple -->
<image nom="photo.jpg" />
```

## Structure de base d'une page HTML
```html
<!DOCTYPE html>
<html>
  <head>
    <meta charset="utf-8">
    <title></title>
  </head>
  <body>
    
  </body>
</html>
```

### doctype

-> permet d'indiquer qu'il s'agit bien d'une page web HTML
Quand on voit `<!DOCTYPE html>` cela veut dire que la page est écrite en HTML5

Sinon, beaucoup + complexe : `<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">`

### HTML

englobe tout le contenu de la page rédigée en HTML

### en-tête `<head>`  et le corps `<body>`
Une page web est constituée de deux parties :

-   L'en-tête `<head>`  : cette section donne quelques informations générales sur la page, comme son titre, l'encodage (pour la gestion des caractères spéciaux), etc. Cette section est généralement assez courte. Les informations que contient l'en-tête ne sont pas affichées sur la page, ce sont simplement des informations générales à destination de l'ordinateur. Elles sont cependant très importantes !
    
-   Le corps `<body>`  : c'est là que se trouve la partie principale de la page. Tout ce que nous écrirons ici sera affiché à l'écran. C'est à l'intérieur du corps que nous écrirons la majeure partie de notre code.

#### L'encodage ( `charset`  )

```html
<meta charset="utf-8" />
```

Il faut aussi que le fichier soit **enregistré** en UTF-8.

#### Le titre `<title>`
Titre qui est affiché au niveau du titre de l'onglet, et qui apparaît dans les résultats de recherche sur un moteur de recherche

### Les commentaires

Les commentaires en HTML s'écrivent sous la forme :

```html
<!-- Ceci est un commentaire -->
```

-> permettent à n'importe qui de comprendre le code écrit.

### Les paragraphes

La balise `<p>` est utilisée pour indiquer le début d'un paragraphe et `</p>` pour indiquer la fin d'un paragraphe.

#### Sauter une ligne
- Utiliser différents paragraphes avec les balises `<p></p>` : permet de **sauter** une ligne
- Utiliser la balise orpheline `<br />` : permet d'aller à la ligne sans sauter de ligne

### Les titres
-   `<h1> </h1>`  : signifie « titre très important ». En général, on s'en sert pour afficher le titre de la page au début de celle-ci ;
    
-   `<h2> </h2>`  : signifie « titre important » ;
    
-   `<h3> </h3>`  : pareil, c'est un titre un peu moins important (on peut dire un « sous-titre », si vous voulez) ;
    
-   `<h4> </h4>`  : titre encore moins important ;
    
-   `<h5> </h5>`  : titre pas important ;
    
-   `<h6> </h6>`  : titre vraiment, mais alors là vraiment pas important du tout.

==à ne pas confondre avec la balise `<title>` !==

### La mise en valeur

- `<em>` : met en <em>italique</em> généralement
- `<strong>` : met en <strong>gras</strong> généralement (mais signifie : important)
- `<mark>` : fait <mark>ressortir visuellement</mark> le texte (surligne par défaut)

On peut modifier les valeurs par défaut en mettant en page avec le **CSS**

### Les listes

#### Listes non ordonnées

```html
<ul>
    <li>Fraises</li>
    <li>Framboises</li>
    <li>Cerises</li>
</ul>
```

Donne :
<ul>
    <li>Fraises</li>
    <li>Framboises</li>
    <li>Cerises</li>
</ul>

-   `<ul></ul>`  délimite toute la liste ;
    
-   `<li></li>`  délimite un élément de la liste (une puce).

#### Liste ordonnée
exemple : 
```html
<ol>
    <li>Je me lève.</li>
    <li>Je mange et je bois.</li>
    <li>Je retourne me coucher.</li>
</ol>

```
Donne :
<ol>
    <li>Je me lève.</li>
    <li>Je mange et je bois.</li>
    <li>Je retourne me coucher.</li>
</ol>


#### Autre liste 
il existe un troisième type de liste, beaucoup plus rare : la liste de définitions. Elle fait intervenir les balises `<dl>` (pour délimiter la liste), `<dt>` (pour délimiter un terme) et `<dd>` (pour délimiter la définition de ce terme).

```html
<dl>
<dt>HTML</dt>
<dd>C'est un langage de programmation pour le développement web. Il permet de structurer la page.</dd>
</dl>
```

Donne : 
<dl>
<dt>HTML</dt>
<dd>C'est un langage de programmation pour le développement web. Il permet de structurer la page.</dd>
</dl>

### Créer des liens
On utilise la balise `<a>` :
Exemple :
```html
<a href="https://openclassrooms.com">OpenClassrooms</a>
```
Donne : <a href="https://openclassrooms.com">OpenClassrooms</a>
Ici, c'est un exemple de lien **absolu**

On peut aussi utiliser des liens **relatifs**, par exemple vers une autre page de son site :
```html
<p>Bonjour. Souhaitez-vous consulter <a href="page2.html">la page 2</a> ?</p>
```
Si la `page2.html` est située dans le même dossier que la page dans laquelle on écrit cette ligne de code.

Résumé :
![schéma explicatif des liens relatifs](Obsidian/Pasted%20image%2020220321094748.png)

#### Lien vers une ancre
Une **ancre** et un point de repère que l'on peut mettre dans les pages HTML lorsqu'elles sont très longues. On utilise pour cela l'attribut `id` :
```html
<h2 id="mon_ancre">Titre</h2>
```
Et pour référencer ce titre, on utilise un lien, qui commence par un `#` :
```html
<a href="#mon_ancre">Aller vers l'ancre</a>
```

On peut aussi référencer des ancres situées dans une autre page avec : `<a href="ancres.html#rollers">`

#### Outils sur les liens
##### Info-bulle au survol

Pour avoir quelque chose comme ça : 
<p>Bonjour. Souhaitez-vous visiter <a href="https://openclassrooms.com" title="Vous ne le regretterez pas !">OpenClassrooms</a> ?</p>
On a utilisé l'attribut `title` dans un lien :

```html
<p>Bonjour. Souhaitez-vous visiter <a href="https://openclassrooms.com" title="Vous ne le regretterez pas !">OpenClassrooms</a> ?</p>
```

##### Lien qui ouvre une nouvelle fenêtre/onglet
Avec `target="_blank"` :
```html
<p>Bonjour. Souhaitez-vous visiter <a href="https://openclassrooms.com" title="Vous ne le regretterez pas !" target="_blank">OpenClassrooms</a> ?</p>
```

##### Lien pour envoyer un mail
Avec l'attribut `mailto`
```html
<p><a href="mailto:votrenom@bidule.com">Envoyez-moi un e-mail !</a></p>
```

##### Lien pour télécharger un fichier
Même principe que pour les liens vers une autre page, mais en référençant le fichier

```html
<p><a href="monfichier.zip">Télécharger le fichier</a></p>
```

### Les images
#### Les différents formats d'image
Toutes les images sur le web sont compressées, pour réduire leur taille

- **JPEG** : conçu pour réduire le poids des photos, jusqu'à 16 millions de couleurs différentes => compression **avec perte**
- **PNG** : peut être rendu transparent, n'altère pas la qualité (**sans perte**), existe en 2 versions :
	- 8 bits : 256 couleurs
	- 24 bits : 16 millions de couleurs (= JPEG)
- **GIF** : limité à 256 couleurs, peut être animé

 On préfère les formats suivants pour chaque type d'image :
-   **Une photo** : utilisez un JPEG.
    
-   **N'importe quel graphique avec peu de couleurs** (moins de 256) : utilisez un PNG 8 bits, ou éventuellement un GIF.
    
-   **N'importe quel graphique avec beaucoup de couleurs** : utilisez un PNG 24 bits.
    
-   **Une image animée** : utilisez un GIF animé.

==ATTENTION==
- il faut bannir les autres formats comme BITMAP `.bmp`
- bien choisir le nom de son image en évitant :
	- les majuscules
	- les espaces -> remplacer par `_`
	- les accents

#### Insérer une image

On insère les images avec `<img />` accompagnée de 2 attributs :
-   `src`  : il permet d'indiquer où se trouve l'image que l'on veut insérer. Vous pouvez soit mettre un chemin absolu (ex. :  `http://www.site.com/fleur.png`  ), soit mettre le chemin en relatif (ce qu'on fait le plus souvent). Ainsi, si votre image est dans un sous-dossier  `images`  , vous devrez taper :  `src="images/fleur.png"`
    
-   `alt`  : cela signifie « texte alternatif ». On doit _toujours_ indiquer un texte alternatif à l'image, c'est-à-dire un court texte qui décrit ce que contient l'image. Ce texte sera affiché à la place de l'image si celle-ci ne peut pas être téléchargée (cela arrive), ou dans les navigateurs de personnes handicapées (non-voyants) qui ne peuvent malheureusement pas « voir » l'image. Cela aide aussi les robots des moteurs de recherche pour les recherches d'images. Pour la fleur, on mettrait par exemple :  `alt="Une fleur"`

Les images doivent se trouver à l'intérieur d'un paragraphe.
On peut également, comme pour les liens, afficher une info-bulle avec l'attribut `title`

Pour avoir une image cliquable (par exemple une miniature), on insère l'image à l'intérieur d'un lien. Exemple :
```html
<p>
    Vous souhaitez voir l'image dans sa taille d'origine ? Cliquez dessus !<br />
    <a href="img/montagne.jpg"><img src="img/montagne_mini.jpg" alt="Photo de montagne" title="Cliquez pour agrandir" /></a>
</p>
```

### Les figures
Les figures peuvent être de différents types :

-   images ;
    
-   codes source ;
    
-   citations ;
    
-   etc. -> tout ce qui va illustrer le texte

En HTML5, on dispose de la balise  `<figure>`  . Voici comment on pourrait l'utiliser :

```html
<figure>
    <img src="images/blocnotes.png" alt="Bloc-Notes" />
</figure>
```

Une figure est le plus souvent accompagnée d'une légende. Pour ajouter une légende, utilisez la balise  `<figcaption>`  à l'intérieur de la balise  `<figure>`  , comme ceci :

```html
<figure>
    <img src="images/blocnotes.png" alt="Bloc-Notes" />
    <figcaption>Le logiciel Bloc-Notes</figcaption>
</figure>
```

La figure peut permettre d'éviter d'avoir à insérer une image dans un paragraphe.

-   Si l'image n'apporte aucune information (c'est juste une illustration pour décorer) : placez l'image dans un paragraphe.
    
-   Si elle apporte une information : placez l'image dans une figure.

## Le CSS
Il peut être écrit dans 3 endroits différents :
-   dans un fichier `.css`  (_méthode la plus recommandée_) ;
    
-   dans l'en-tête `<head>`  du fichier HTML ;
    
-   directement dans les balises du fichier HTML _via_ un attribut `style`  (_méthode la moins recommandée_).

**Insertion dans un fichier :**
On utilise la balise : `<link rel="stylesheet" href="style.css" />` pour référencer notre page en `.css` 

**Dans l'en-tête :**
On peut directement faire :
```html
<!DOCTYPE html>
<html>
    <head>
        <meta charset="utf-8" />
        <style>
            p
            {
                color: blue;
            }
        </style>
        <title>Premiers tests du CSS</title>
    </head>

    <body>

    </body>
</html>
```

**Directement dans les balises :** 
```html
<p style="color: blue;">Bonjour et bienvenue sur mon site !</p>
```

### Commentaires en CSS

On utilise `/* commentaire */`. Les commentaires peuvent prendre plusieurs lignes :

```css
/*
style.css
---------
 
Par Conor
*/
 
p
{
    color: blue; /* Les paragraphes seront en bleu */
}
```

### Sélectionner une balise
Dans un code CSS comme celui-ci, on trouve trois éléments différents :

-   **des noms de balises** : on écrit les noms des balises dont on veut modifier l'apparence. Par exemple, si je veux modifier l'apparence de tous les paragraphes `<p>`  , je dois écrire `p`  ;
    
-   **des propriétés CSS** : les « effets de style » de la page sont rangés dans des propriétés. Il y a par exemple la propriété `color`  qui permet d'indiquer la couleur du texte, `font-size`  qui permet d'indiquer la taille du texte, etc. Il y a beaucoup de propriétés CSS et, comme je vous l'ai dit, je ne vous obligerai pas à les connaître toutes par cœur ;
    
-   **les valeurs** : pour chaque propriété CSS, on doit indiquer une valeur. Par exemple, pour la propriété `color`  , il faut indiquer le nom de la couleur. Pour `font-size`  , il faut indiquer quelle taille on veut, etc.

Schématiquement, on a donc :
```css
balise1
{
    propriete1: valeur1;
    propriete2: valeur2;
    propriete3: valeur3;
}
```

Pour appliquer un style à plusieurs balises, on les sépare par une `,` :
```css
h1, em
{
    color: blue;
}
```

### `class` et `id`
On peut utiliser des attributs spéciaux qui fonctionnent sur toutes les balises : 
-   l'attribut `class`  ;
    
-   l'attribut `id`  .

Par exemple, on écrira :
```html
<p class="introduction">Bonjour et bienvenue sur mon site !</p>
```

Et dans notre CSS :

```css
.introduction
{
color: blue;
}
```

L'attribut `id` fonctionne comme `class` sauf qu'il ne peut être utilisé **qu'une seule fois** dans le code. On le référence dans le fichier CSS précédé de `#`

#### Balises universelles
Elles permettent de sélectionner plus finement des éléments dans notre page. Par exemple dans :
```html
<p>Bonjour et bienvenue sur mon site !</p>
```

Si on voulait appliquer un style seulement à `bienvenue`, on pourrait utiliser les balises universelles :
-   `<span> </span>`  : c'est une balise de type **inline**, c'est-à-dire une balise que l'on place au sein d'un paragraphe de texte pour sélectionner certains mots uniquement. Les balises `<strong>`  et `<em>`  sont de la même famille. Cette balise s'utilise donc au milieu d'un paragraphe et c'est celle dont nous allons nous servir pour colorer « bienvenue » ;
    
-   `<div> </div>`  : c'est une balise de type **block**, qui entoure un bloc de texte. Les balises `<p>`  ,  `<h1>`  , etc., sont de la même famille. Ces balises ont quelque chose en commun : elles créent un nouveau « bloc » dans la page et provoquent donc obligatoirement un retour à la ligne. `<div>`  est une balise fréquemment utilisée dans la construction d'un design, comme nous le verrons plus tard.

### Les sélecteurs avancés
On a vu qu'on pouvait sélectionner un paragraphe (avec `p`), des titres (avec `h1`) ou des mises en valeurs (avec `em` ou `span`) ainsi que des classes (`.classe1`) et des id (`#id1`)

Mais on peut aussi utiliser d'autres sélecteurs, par exemple :

- `*` : sélecteur universel -> sélectionne toutes les balises
- `A B` -> sélectionne la balise B contenue dans A, exemple :
```css
h3 em
{

}
```
Sélectionne toutes les balises `<em>`  situées à l'intérieur d'une balise `<h3>`

- `A + B` -> sélectionne une balise qui suit une autre
- `A[attribut]` -> sélectionne une balise qui possède un attribut
```css
a[title]
{

}
```

Va sélectionner des choses comme :
```html
<a href="http://site.com" title="Infobulle">
```

- `A[attribut="valeur"]` -> sélectionne les balises ayant "valeur" comme attribut
- `A[attribut*="Valeur"]` : une balise, un attribut et une valeur

```css
a[title*="ici"]
{

}
```

Idem, l'attribut doit cette fois contenir dans sa valeur le mot « ici » (peu importe sa position).

### Formater du texte
#### Taille
On utilise la propriété CSS `font-size`

On peut :
-   indiquer une **taille absolue** : en pixels, en centimètres ou millimètres. Cette méthode est très précise, mais il est conseillé de ne l'utiliser que si c'est absolument nécessaire, car on risque d'indiquer une taille trop petite pour certains lecteurs ;
    
-   indiquer une **taille relative** : en pourcentage, « em » ou « ex », cette technique a l'avantage d'être plus souple. Elle s'adapte plus facilement aux préférences de taille des visiteurs.

 Il y a plusieurs moyens d'indiquer une valeur relative. Vous pouvez par exemple écrire la taille avec des mots en anglais comme ceux-ci :

-   `xx-small`  : minuscule ;
    
-   `x-small`  : très petit ;
    
-   `small`  : petit ;
    
-   `medium`  : moyen ;
    
-   `large`  : grand ;
    
-   `x-large`  : très grand ;
    
-   `xx-large`  : euh… gigantesque.

Mais on peut aussi utiliser `em` :
-   Si vous écrivez `1em`  , le texte a une taille normale.
    
-   Si vous voulez grossir le texte, vous pouvez inscrire une valeur supérieure à 1, comme `1.3em`  .
    
-   Si vous voulez réduire le texte, inscrivez une valeur inférieure à 1, comme `0.8em`  .

#### La police

On utilise la propriété CSS `font-family`
Seulement, pour éviter les problèmes si l'internaute n'a pas la même police que vous, on précise en général _plusieurs_ noms de police, séparés par des virgules :

```css
balise
{
    font-family: police1, police2, police3, police4;
}
```

En général, on indique en tout dernier `serif` -> police par défaut

Liste de polices qui fonctionnent bien sur la plupart des navigateurs :

-   Arial ;
    
-   Arial Black ;
    
-   Comic Sans MS ;
    
-   Courier New ;
    
-   Georgia ;
    
-   Impact ;
    
-   Times New Roman ;
    
-   Trebuchet MS ;
    
-   Verdana.

Si le nom de la police contient des espaces, on peut l'entourer de guillemets dans le CSS :

```css
p
{
    font-family: Impact, "Arial Black", Arial, Verdana, sans-serif;
}
```

#### Utiliser une police personnalisée
On peut importer n'importe quelle police dans le navigateur, mais attention :
-   il faudra que le navigateur de vos visiteurs _télécharge_ automatiquement le fichier de la police, dont le poids peut atteindre, voire dépasser 1 Mo… ;
    
-   la plupart des polices sont soumises au droit d'auteur, il n'est donc _pas légal_ de les utiliser sur son site. (utiliser [fontsquirrel.com](http://www.fontsquirrel.com/), car il permet de télécharger des packs prêts à l'emploi pour CSS 3) ;
    
-   il existe _plusieurs formats_ de fichiers de polices, et ceux-ci ne fonctionnent pas sur tous les navigateurs.

les différents formats de fichiers de polices qui existent et qu'il faut connaître :

-   `.ttf`  : _TrueType Font_. Fonctionne sur IE9 et tous les autres navigateurs ;
    
-   `.eot`  : _Embedded OpenType_. Fonctionne sur Internet Explorer uniquement, toutes versions. Ce format est propriétaire, produit par Microsoft ;
    
-   `.otf`  : _OpenType Font_. Ne fonctionne pas sur Internet Explorer ;
    
-   `.svg`  : _SVG Font_. Le seul format reconnu sur les iPhone et iPad pour le moment ;
    
-   `.woff`  : _Web Open Font Format_. Nouveau format conçu pour le Web, qui fonctionne sur IE9 et tous les autres navigateurs.

Pour déclarer une nouvelle police, on utilise `@font-face`, comme ceci, pour avoir les différents formats de police : 
```css
@font-face {
    font-family: 'MaSuperPolice';
    src: url('MaSuperPolice.eot') format('eot'),
         url('MaSuperPolice.woff') format('woff'),
         url('MaSuperPolice.ttf') format('truetype'),
         url('MaSuperPolice.svg') format('svg');
}
```

#### Italique, gras, souligné
##### Italique
On utilise `font-style` qui peut prendre 3 valeurs :
-   `italic`  : le texte sera mis en italique ;
    
-   `oblique`  : le texte sera passé en oblique (les lettres sont penchées, le résultat est légèrement différent de l'italique proprement dit) ;
    
-   `normal`  : le texte sera normal (par défaut). Cela vous permet d'annuler une mise en italique.

##### Gras
On utilise `font-weight` :
-   `bold`  : le texte sera en gras ;
    
-   `normal`  : le texte sera écrit normalement (par défaut).

##### Soulignement et autre
On utilise `text-decoration` :
-   `underline`  : souligné ;
    
-   `line-through`  : barré ;
    
-   `overline`  : ligne au-dessus ;
    
-   `none`  : normal (par défaut).

#### Alignement
On utilise la propriété `text-align` :
-   `left`  : le texte sera aligné à gauche (c'est le réglage par défaut) ;
    
-   `center`  : le texte sera centré ;
    
-   `right`  : le texte sera aligné à droite ;
    
-   `justify`  : le texte sera « justifié ». Justifier le texte permet de faire en sorte qu'il prenne toute la largeur possible sans laisser d'espace blanc à la fin des lignes. 

L'alignement ne fonctionne que sur les balises de type **block** comme `<p>` , `<div>` , `<h1>` , `<h2>` ... 

#### Les flottants

Illustration d'un flottant :
![illustration |200](Obsidian/Pasted%20image%2020220321104214.png)

On utilise `float` :
-   `left`  : l'élément flottera à gauche ;
    
-   `right`  : l'élément flottera… à droite

Pour stopper un flottant, comme dans cet exemple :
![exemple avec 2 lignes](Obsidian/Pasted%20image%2020220321104336.png)

On utilise la propriété `clear` qui peut prendre comme valeurs :
-   `left`  : le texte se poursuit en dessous après un `float: left;`
    
-   `right`  : le texte se poursuit en dessous après un `float: right;`
    
-   `both`  : le texte se poursuit en dessous, que ce soit après un `float: left;`  ou après un `float: right;`  .

#### Couleur du texte
Propriété : `color`, on peut utiliser les 16 noms de couleurs suivants :
![!= couleurs](Obsidian/Pasted%20image%2020220321105936.png)

On peut également utiliser des hexadecimaux `#FFFFFF` donne du blanc (= `#FFF`) ou la méthode RGB `rgb(160,86,204)` donne du <p style="color:rgb(160,86,204)">violet</p> 
### Fond de la page
#### Couleur de fond
Utiliser la propriété : `background-color`, qui a les mêmes fonctionnalités que `color`

Si on applique :
```css
body {
	background-color: black;
	color:white;
}
```

Alors tout le fond de notre page sera noir (et le texte sera blanc ! cf [Héritage en CSS](#Héritage%20en%20CSS). Mais on peut également appliquer cette propriété à :

- du texte

<p style="background-color: navy">ceci est un texte</p>
- un bloc 

#### Image de fond

Pour appliquer une image de fond, on utilise `background-image` tel que :
```css
body
{
    background-image: url("neige.png");
}
```

Différentes options sont disponibles :
- `background-attachment` permet de "fixer" le fond (on voit le texte glisser sur le fond), valeurs possibles :
	- `fixed`
	- `scroll`
- `background-repeat` : fond répétée en mosaïque, valeurs possibles :
	-  `no-repeat`  : le fond ne sera pas répété. L'image sera donc unique sur la page ;
    
	-   `repeat-x`  : le fond sera répété uniquement sur la première ligne, horizontalement ;
    
	-   `repeat-y`  : le fond sera répété uniquement sur la première colonne, verticalement ;
    
	-   `repeat`  : le fond sera répété en mosaïque (par défaut).
- `background-position` prend des valeurs
	- en pixels
	- avec `top`, `bottom`, `left`, `center`, `right` (peuvent être combinés)
- `background` -> combine plusieurs propriétés précédentes (**super-propriété**):

```css
body
{
    background: url("soleil.png") fixed no-repeat top right;
}
```

Concernant les **super-propriétés** :
- l'ordre des valeurs n'a pas d'importance.
- vous n'êtes pas obligé de mettre toutes les valeurs. Ainsi, si vous ne voulez pas écrire `fixed`  , vous pouvez l'enlever sans problème.

On peut mettre plusieurs images de fond en les séparant par une virgule :

```css
body
{
    background: url("soleil.png") fixed no-repeat top right, url("neige.png") fixed;
}
```

#### Transparence

On peut jouer avec les niveaux de transparences des éléments avec la propriété `opacity` :
-   Avec une valeur de 1, l'élément sera totalement opaque : c'est le comportement par défaut.
    
-   Avec une valeur de 0, l'élément sera totalement transparent.

Si vous appliquez la propriété `opacity` à un élément de la page, _tout_ le contenu de cet élément sera rendu transparent (même les images, les autres blocs à l'intérieur, etc.). Si vous voulez juste rendre la couleur de fond transparente, utilisez plutôt la notation RGBa que nous allons découvrir.

##### Notation RGBa
a = canal alpha

```css
p
{
    background-color: rgba(255, 0, 0, 0.5); /* Fond rouge à moitié transparent */
}
```

### Héritage en CSS
En CSS, si vous appliquez un style à une balise, toutes les balises qui se trouvent à l'intérieur prendront le même style.

CSS signifie d'ailleurs *Cascading Style Sheets* donc les propriétés sont héritées en cascade.

On peut "annuler" l'héritage en redéfinissant de manière plus précise une balise :

```css
body
{
    background-color: black;
    color: white;
}

mark
{
    /* La couleur de fond prend le pas sur celle de toute la page */
    background-color: red;
    color: black;
}
```


### Créer des bordures, des ombres
#### Bordures standard
 De nombreuses propriétés CSS vous permettent de modifier l'apparence de vos bordures : `border-width`  , `border-color`  , `border-style`  …

Pour aller à l'essentiel, je vous propose ici d'utiliser directement la super-propriété `border`  qui regroupe l'ensemble de ces propriétés.

Pour `border`  , on peut utiliser jusqu'à trois valeurs pour modifier l'apparence de la bordure :

-   **la largeur** : indiquez la largeur de votre bordure. Mettez une valeur en pixels (comme `2px`  ) ;
    
-   **la couleur** : c'est la couleur de votre bordure. Utilisez, comme on l'a appris, soit un nom de couleur ( `black`  , `red`  …), soit une valeur hexadécimale ( `#FF0000`  ), soit une valeur RGB ( `rgb(198, 212, 37)`  ) ;
    
-   **le type de bordure** : là, vous avez le choix. Votre bordure peut être un simple trait, ou des pointillés, ou encore des tirets, etc. Voici les différentes valeurs disponibles :
    
    -   `none`  : pas de bordure (par défaut) ;
        
    -   `solid`  : un trait simple ;
        
    -   `dotted`  : pointillés ;
        
    -   `dashed`  : tirets ;
        
    -   `double`  : bordure double ;
        
    -   `groove`  : en relief ;
        
    -   `ridge`  : autre effet relief ;
        
    -   `inset`  : effet 3D global enfoncé ;
        
    -   `outset`  : effet 3D global surélevé.

![les différents types de bordures](Obsidian/Pasted%20image%2020220321112119.png)

Si on veut mettre des bordures différentes en fonction du côté :

-   `border-top`  : bordure du haut ;
    
-   `border-bottom`  : bordure du bas ;
    
-   `border-left`  : bordure de gauche ;
    
-   `border-right`  : bordure de droite.

#### Bordures arrondies
La propriété `broder-radius` permet d'arrondir facilement les angles de n'importe quel élément :

```css
p
{
    border-radius: 10px;
}

/* On peut également préciser un arrondi différent pour chaque coin */

p
{
    border-radius: 10px 5px 10px 5px;
}

/* Ou créer des courbes ellipitiques */
p
{
    border-radius: 20px / 10px;
}
```

#### Les ombres
La propriété `box-shadow`  s'applique à tout le bloc et prend quatre valeurs dans l'ordre suivant :

1.  Le décalage horizontal de l'ombre.
    
2.  Le décalage vertical de l'ombre.
    
3.  L'adoucissement du dégradé.
    
4.  La couleur de l'ombre.
```css
p
{
    box-shadow: 6px 6px 6px black;
}
```

Pour un texte, on utilise `text-shadow` et le fonctionnement est le même que pour `box-shadow`

### Apparences dynamiques
Pour modifier l'apparence des éléments de façon dynamique, on utilise des **pseudo-formats**
#### Au survol
On utilise le pseudo format `:hover` utilisé comme ceci (pour souligner les liens au survol) :
```css
a:hover
{
   text-decoration: underline;
}
```

On peut modifier l'apparence de n'importe quel élément de cette manière, pas seulement les liens !

#### Au clic et lors de la sélection
**Au moment du clic** : `:active`
Il n'est utilisé que sur les liens, ce n'est pas forcément très visible

**Quand l'élément est sélectionné** : `:focus`
(Se voit si on appuie sur la touche `Tab`)

#### Lorsque le lien a déjà été consulté
Avec `:visited`, on ne peut pas changer beaucoup de choses hormis la couleur (violet par défaut)

## Structurer la page
En général, une page web est constituée d'un en-tête (tout en haut), de menus de navigation (en haut ou sur les côtés), de différentes sections au centre… et d'un pied de page (tout en bas). Des balises HTML introduites en HTML5 vont permettre de dire : « Ceci est mon en-tête », « Ceci est mon menu de navigation », etc.

### Les balises structurantes 
#### `<header>` : l'en-tête
 On y trouve le plus souvent un logo, une bannière, le slogan de votre site…
 Il peut y avoir plusieurs en-têtes dans votre page. Si celle-ci est découpée en plusieurs sections, chaque section peut en effet avoir son propre `<header>` .

#### `<footer>` : le pied de page

On y trouve des informations comme des liens de contact, le nom de l'auteur, les mentions légales, etc.

#### `<nav>` : principaux liens de navigation
Cette balise doit regrouper tous les principaux liens de navigation du site (par exemple le menu principal du site). On trouve généralement ce menu sous forme de liste à puces à l'intérieur de la balise `<nav>`

```html
<nav>
    <ul>
        <li><a href="index.html">Accueil</a></li>
        <li><a href="forum.html">Forum</a></li>
        <li><a href="contact.html">Contact</a></li>
    </ul>
</nav>
```

#### `<section>` : une section de page
La balise `<section>`  sert à regrouper des contenus en fonction de leur thématique. Elle englobe généralement une portion du contenu au centre de la page.

```html
<section>
    <h1>Ma section de page</h1>
    <p>Bla bla bla bla</p>
</section>
```

Sur la page d'accueil du portail Free.fr, on trouve plusieurs blocs qui pourraient être considérés comme des sections de page (figure suivante).

![illustration des sections](Obsidian/Pasted%20image%2020220321212803.png)

#### `<aside>` : des informations complémentaires
La balise `<aside>`  est conçue pour contenir des informations complémentaires au document que l'on visualise. Ces informations sont généralement placées sur le côté (bien que ce ne soit pas une obligation).

```html
<aside>
    <!-- Placez ici des informations complémentaires -->
</aside>
```

Il peut y avoir plusieurs blocs `<aside>`  dans la page.

Sur Wikipédia, par exemple, il est courant de voir à droite un bloc d'informations complémentaires à l'article que l'on visualise.

#### `<article>`  : un article indépendant

La balise `<article>`  sert à englober une portion généralement autonome de la page. C'est une partie de la page qui pourrait ainsi être reprise sur un autre site. C'est le cas par exemple des actualités (articles de journaux ou de blogs).

```html
<article>
    <h1>Mon article</h1>
    <p>Bla bla bla bla</p>
</article>
```

#### Résumé
On a donc la configuration suivante avec les balises ci-dessus :

![schéma balises](Obsidian/Pasted%20image%2020220321213023.png)

### Les boites
#### Dimensions
Un bloc a des dimensions précises, il a donc 2 ptés CSS :
-   `width`  : c'est la largeur du bloc. À exprimer en pixels (px) ou en pourcentage (%) ;
    
-   `height`  : c'est la hauteur du bloc. Là encore, on l'exprime soit en pixels (px), soit en pourcentage (%).

Par défaut, un bloc prend 100% de la largeur dispo

On peut demander à ce qu'un bloc ait des dimensions minimales et maximales. C'est très pratique, car cela nous permet de définir des dimensions « limites » pour que notre site s'adapte aux différentes résolutions d'écran de nos visiteurs :

-   `min-width`  : largeur minimale ;
    
-   `min-height`  : hauteur minimale ;
    
-   `max-width`  : largeur maximale ;
    
-   `max-height`  : hauteur maximale.

#### Les marges

Il faut savoir que tous les blocs possèdent des marges. Il existe _deux types de marges_ :

-   les marges intérieures : avec `padding` (en général en pixels) ;
    
-   les marges extérieures : avec `margin` (en général en pixels)

![schéma marges](Obsidian/Pasted%20image%2020220321214157.png)

Pour affecter des tailles de marges != selon le côté, on utilise `margin-top`, `margin-bottom`, `margin-left`, `margin-right` etc.
De même pour `padding`

Il y a d'autres façons de spécifier les marges avec les propriétés `margin` et `padding` . Par exemple :  
`margin: 2px 0 3px 1px;` signifie « 2 px de marge en haut, 0 px à droite (le px est facultatif dans ce cas), 3 px en bas, 1 px à gauche ».  
Autre notation raccourcie : `margin: 2px 1px;` signifie « 2 px de marge en haut et en bas, 1 px de marge à gauche et à droite ».

#### Centrer des blocs
-   donnez une largeur au bloc (avec la propriété `width`  ) ;
    
-   indiquez que vous voulez des marges extérieures automatiques, comme ceci : `margin: auto;`  .

#### Gérer un bloc qui dépasse

Si on a un texte dans un bloc par exemple, et qu'on ne veut pas que le texte dépasse du bloc :

![exemple qui dépasse](Obsidian/Pasted%20image%2020220322165131.png)

On utilise `overflow` :

-   `visible`  (par défaut) : si le texte dépasse les limites de taille, il reste visible et sort volontairement du bloc ;
    
-   `hidden`  : si le texte dépasse les limites, il sera tout simplement coupé. On ne pourra pas voir tout le texte ;
    
-   `scroll`  : là encore, le texte sera coupé s'il dépasse les limites. Sauf que cette fois, le navigateur mettra en place des barres de défilement pour qu'on puisse lire l'ensemble du texte. C'est un peu comme un cadre à l'intérieur de la page.
    
-   `auto`  : c'est le mode « pilote automatique ». En gros, c'est le navigateur qui décide de mettre ou non des barres de défilement (il n'en mettra que si c'est nécessaire). C'est la valeur que je conseille d'utiliser le plus souvent.

#### `word-wrap` : couper les textes trop larges

Pour éviter ce genre de choses :
![texte qui dépasse](Obsidian/Pasted%20image%2020220322165420.png)

On peut utiliser :
```css
p
{
    word-wrap: break-word;
}
```

### Mise en page avec Flexbox
l y a plusieurs façons de mettre en page un site. Au fil du temps, plusieurs techniques ont existé :

1.  Au début, les webmasters utilisaient des tableaux HTML pour faire la mise en page (berk).
    
2.  Puis, CSS est apparu et on a commencé à faire une mise en page à l'aide de la propriété `float` (bof).
    
3.  Cette technique avait des inconvénients. Une autre, plus pratique, a consisté à créer des éléments de type `inline-block`  sur la page (mouais).
    
4.  Aujourd'hui, une bien meilleure technique encore existe : **Flexbox** ! Elle permet toutes les folies (ou presque😉)

**Principe de mise en page avec Flexbox :** définir un conteneur, et placer des éléments à l'intérieur de ce conteneur :

![schéma du principe de Flexbox](Obsidian/Pasted%20image%2020220322170050.png)

Le conteneur est une balise HTML, et les éléments sont d'autres balises HTML à l'intérieur :

```html
<div id="conteneur">
    <div class="element 1">Element </div>
    <div class="element 2">Element </div>
    <div class="element 3">Element </div>
</div>
```

Par défaut, les blocs se placent les uns en dessous des autres

![éléments par défaut](Obsidian/Pasted%20image%2020220322170222.png)

Si je mets une propriété CSS, tout change. Cette propriété, c'est `flex`  , et je l'applique au conteneur :

```css
#conteneur
{
    display: flex;
}
```

... alors les blocs se placent par défaut côte à côte.

![flex](Obsidian/Pasted%20image%2020220322170236.png)

#### Changer la direction

Avec `flex-direction` , on peut les positionner verticalement ou encore les inverser. Il peut prendre les valeurs suivantes :

-   row : organisés sur une ligne (par défaut) ;
    
-   column : organisés sur une colonne ;
    
-   row-reverse : organisés sur une ligne, mais en ordre inversé ;
    
-   column-reverse : organisés sur une colonne, mais en ordre inversé.

#### Retour à la ligne
  
Par défaut, les blocs essaient de rester sur la même ligne s'ils n'ont pas la place (ce qui peut provoquer des bugs de design, parfois). Si vous voulez, vous pouvez demander à ce que les blocs aillent à la ligne lorsqu'ils n'ont plus la place, avec `flex-wrap`  qui peut prendre ces valeurs :

-   nowrap : pas de retour à la ligne (par défaut) ;
    
-   wrap : les éléments vont à la ligne lorsqu'il n'y a plus la place ;
    
-   wrap-reverse : les éléments vont à la ligne, lorsqu'il n'y a plus la place, en sens inverse.

![image d'illustration](Obsidian/Pasted%20image%2020220323182705.png)

#### Aligner les blocs
Les éléments sont donc alignés soit horizontalement (par défaut), soit verticalement. Cet alignement définit **l'axe principal**. Il y a aussi un axe secondaire (= *cross axis*)

- si les éléments sont organisés horizontalement => cross axis vertical
- et inversement

##### Sur l'axe principal
On utilise `justify-content` qui peut prendre les valeurs :
-   flex-start : alignés au début (par défaut) ;
    
-   flex-end : alignés à la fin ;
    
-   center : alignés au centre ;
    
-   space-between : les éléments sont étirés sur tout l'axe (il y a de l'espace entre eux) ;
    
-   space-around : idem, les éléments sont étirés sur tout l'axe, mais ils laissent aussi de l'espace sur les extrémités.

![illustration](Obsidian/Pasted%20image%2020220323183549.png)

Cela fonctionne aussi si les éléments sont alignés verticalement

##### Sur l'axe secondaire
On utilise `align-items` qui peut prendre les valeurs :

-   stretch : les éléments sont étirés sur tout l'axe (valeur par défaut) ;
    
-   flex-start : alignés au début ;
    
-   flex-end : alignés à la fin ;
    
-   center : alignés au centre ;
    
-   baseline : alignés sur la ligne de base (semblable à flex-start).

Par exemple, avec :

```css
#conteneur
{
	display: flex;
	justify-content: center;
	align-items: center;
}
```

On obtient des éléments complétements centrés, horizontalement et verticalement :

![illustration](Obsidian/Pasted%20image%2020220323183919.png)

On peut aussi utiliser le code suivant pour centrer horizontalement et verticalement les éléments :

```css
#conteneur
{
    display: flex;
}

.element
{
    margin: auto;
}
```

##### Aligner un seul élément
Il est possible de faire une exception pour un seul des éléments sur l'axe secondaire avec `align-self`  :

```css
#conteneur
{
    display: flex;
    flex-direction: row;
    justify-content: center;
    align-items: center;
}

.element:nth-child(2) /* On prend le deuxième bloc élément */
{
    background-color: blue;
    align-self: flex-end; /* Seul ce bloc sera aligné à la fin */
}

/* ... */
```

Résultat :

![résultat illustré](Obsidian/Pasted%20image%2020220323184157.png)

#### Répartir plusieurs lignes
Si vous avez plusieurs lignes dans votre Flexbox, vous pouvez choisir comment celles-ci seront réparties avec `align-content`

En autorisant les éléments à aller à la ligne avec `flex-wrap`, on obtient :
![](Obsidian/Pasted%20image%2020220323184524.png)

Avec la propriété `align-content` qui peut prendre les valeurs :

-   flex-start : les éléments sont placés au début ;
    
-   flex-end : les éléments sont placés à la fin ;
    
-   center : les éléments sont placés au centre ;
    
-   space-between : les éléments sont séparés avec de l'espace entre eux ;
    
-   space-around : idem, mais il y a aussi de l'espace au début et à la fin ;
    
-   stretch (par défaut) : les éléments s'étirent pour occuper tout l'espace.

![illustration | 800](Obsidian/Pasted%20image%2020220323184608.png)

#### Changer l'ordre
Avec la propriété `order`, on peut changer l'ordre des éléments en CSS. Par exemple avec 3 éléments, on peut faire :
```css
.element:nth-child(1)
{
    order: 3;
}
.element:nth-child(2)
{
    order: 1;
}
.element:nth-child(3)
{
    order: 2;
}
```

Et on passe alors de :
![début](Obsidian/Pasted%20image%2020220323184828.png)

à :
![fin](Obsidian/Pasted%20image%2020220323184839.png)

#### Faire grossir ou maigrir les éléments
Avec la propriété `flex` , nous pouvons permettre à un élément de grossir pour occuper tout l'espace restant. Par exemple :

```css
.element:nth-child(2)
{
	flex: 1;
}
```

Donne : 
![](Obsidian/Pasted%20image%2020220323185023.png)

Le nombre indiqué est un rapport de "grossissement" par rapport aux autres éléments :

```css
.element:nth-child(1)
{
    flex: 2;
}
.element:nth-child(2)
{
    flex: 1;
}
```

![](Obsidian/Pasted%20image%2020220323185111.png)

`flex` est en fait une super-propriété qui combine `flex-grow` (capacité à grossir), `flex-shrink` (capacité à maigrir) et `flex-basis` (taille par défaut)

#### En pratique
Voir [exercice](https://codepen.io/nicolaspatschkowski/pen/yLNXQaO?editors=1100)

Pour faire :
1.  Retirez les puces de la liste à puces 
    
2.  Placez le header et le menu côte à côte. (ils sont dans la même `div` avec pour id `topsection`)
    
3.  Affichez les paragraphes en justifié, sur 80 % de largeur, et centrez leurs blocs sur la page.

On a le code CSS :

```css
ul {
  list-style-type: none;
}

#topsection
{
  display:flex;
  
}

p
{
  text-align: justify;
  width: 80%;
  margin:auto;
}
```

#### Autres techniques de mise en page
Voir les autres techniques [ici](https://openclassrooms.com/fr/courses/1603881-apprenez-a-creer-votre-site-web-avec-html5-et-css3/1606402-decouvrez-dautres-techniques-de-mise-en-page) avec le positionnement flottant, le positionnement inline-block, les positionnements absolu, fixe et relatif

Par exemple, la propriété `display` peut prendre (entre autres) ces valeurs :

| Valeur         | Exemples                       | Description                                                                                                                |
| -------------- | ------------------------------ | -------------------------------------------------------------------------------------------------------------------------- |
| `inline`       | `<a>  , <em>  , <span>  …`     | Eléments d'une ligne. Se placent les uns à côté des autres.                                                                |
| `block`        | `<p>  , <div>  , <section>`  … | Eléments en forme de blocs. Se placent les uns en dessous des autres et peuvent être redimensionnés.                       |
| `inline-block` | `<select>  , <input>`          | Eléments positionnés les uns à côté des autres (comme les inlines) mais qui peuvent être redimensionnés (comme les blocs). |
| `none`         | `<head>`                       | Eléments non affichés.                                                                                                     |

Le type `inline-block` est une combinaison des `inline` et des blocs. les éléments s'affichent côte à côte et peuvent être redimensionnés

On peut leur appliquer la propriété `vertical-align` :
-   `baseline`  : aligne la base de l'élément avec celle de l'élément parent (par défaut) ;
    
-   `top`  : aligne en haut ;
    
-   `middle`  : centre verticalement ;
    
-   `bottom`  : aligne en bas ;
    
-   (valeur en px ou %) : aligne à une certaine distance de la ligne de base (baseline).

##### Positionnement absolu

On utilise la propriété : `position : absolute` avec les valeurs :
-   `left`  : position par rapport à la gauche de la page ;
    
-   `right`  : position par rapport à la droite de la page ;
    
-   `top`  : position par rapport au haut de la page ;
    
-   `bottom`  : position par rapport au bas de la page.

On peut donner une valeur en pixels, ou en pourcentage

![](Obsidian/Pasted%20image%2020220324110705.png)

Par exemple, le code suivant place l'élément tout en bas à droite de l'écran : 

```css
element
{
    position: absolute;
    right: 0px;
    bottom: 0px;
}
```

Les éléments positionnés en absolu sont placés par-dessus le reste des éléments de la page ! Par ailleurs, si vous placez deux éléments en absolu vers le même endroit, ils risquent de se chevaucher. Dans ce cas, utilisez la propriété `z-index` pour indiquer quel élément doit apparaître au-dessus des autres. On aura la répartition suivante :

![](Obsidian/Pasted%20image%2020220324110926.png)

 le positionnement absolu ne se fait pas forcément toujours par rapport au coin en haut à gauche de la fenêtre ! Si vous positionnez en absolu un bloc A qui se trouve dans un autre bloc B, lui-même positionné en absolu (ou fixe ou relatif), alors votre bloc A se positionnera par rapport au coin supérieur gauche du bloc B.

##### Le positionnement fixe

Le bloc reste fixe à sa position, même si on descend plus bas dans la page

##### Le positionnement relatif
![](Obsidian/Pasted%20image%2020220324111334.png)

Si on fait :

```css
strong
{
   background-color: red;
   color: yellow;
   
   position: relative;
   left: 55px;
   top: 10px;
}
```

Alors, on aura :
![](Obsidian/Pasted%20image%2020220324111402.png)
## Vérifier la validité du site
W3C propose sur son site web un outil appelé le « validateur » (« Validator » en anglais).  
Le validateur est une sorte de programme qui va analyser votre code source et vous dire s'il est correctement écrit, ou s'il comporte des erreurs que vous devez corriger.

Souvenez-vous : le W3C a établi des normes. Il est nécessaire de les respecter, pour qu'on soit sûr que tous les sites web parlent la même « langue ».

Il existe un validateur pour HTML et un validateur pour CSS (à mettre dans vos favoris !). Celui pour CSS comportant quelques bugs (il signale comme invalides des feuilles CSS qui sont tout à fait valides), nous ne nous y attarderons pas. Par contre, le validateur HTML va être très intéressant pour nous ; voici son adresse : [http://validator.w3.org](https://validator.w3.org/).

Vous pouvez valider votre page web de trois façons différentes, c'est pour cela qu'il y a trois onglets :

-   adresse (URL) ;
    
-   envoi du fichier `.html`  ;
    
-   copier-coller du code HTML.
    

Pour le moment, notre site web n'est pas encore disponible sur le Web, ce qui fait qu'il n'a pas d'adresse URL. Le mieux est donc d'envoyer le fichier `.html`  que l'on a fait, ou encore de copier-coller directement le code HTML.

Si vous envoyez votre code HTML et que tout se passe bien, le validateur va vous répondre avec le message représenté à la figure suivante.

![Le validateur du W3C nous informe que notre page ne comporte pas d'erreur](https://user.oc-static.com/files/345001_346000/345202.png)

Le validateur du W3C nous informe que notre page ne comporte pas d'erreur

Dans ce cas, cela signifie que tout va bien et que vous avez bien construit votre page !

Il faut savoir que les navigateurs « essaient » de ne pas afficher les erreurs, lorsqu'ils en rencontrent, pour ne pas perturber l'internaute. Mais rien ne vous dit que d'autres navigateurs ne vont pas se comporter bizarrement !

Avoir une page web valide, c'est donc avoir la possibilité de dormir tranquille en sachant que l'on a bien fait les choses comme il faut. Cela simplifie le travail des programmes qui lisent les pages web.  
De plus, et c'est vérifié, une page web correctement construite aura plus de chances d'être mieux positionnée dans les résultats de recherche de Google, ce qui vous amènera… plus de visiteurs !

Voici une liste de conseils qui peuvent vous aider à résoudre les erreurs qui risquent de vous être signalées tôt ou tard :

-   tous vos textes doivent en général être dans des balises de paragraphes. Il est interdit de mettre du texte directement entre les balises `<body></body>`  sans l'avoir entouré des fameux `<p></p>`  . Ceci est aussi valable pour les retours à la ligne `<br />`  , qui doivent être à l'intérieur de paragraphes. C'est une erreur ultra-courante chez les débutants ;
    

```html
<p>Ceci est un texte correctement placé dans un paragraphe.
<br />
Les balises <br /> doivent se trouver à l'intérieur d'un paragraphe, ne l'oubliez pas</p>

Ceci est un texte en-dehors d'un paragraphe. C'est interdit.
<br />
```

-   _toutes vos images doivent comporter un attribut_ `alt`  qui indique ce que contient l'image. Si, par hasard, votre image est purement décorative (vous ne pouvez pas lui trouver une description), vous êtes autorisé à ne rien mettre comme valeur pour l'attribut `alt`  .
    

```html
<!-- L'image comporte une description -->
<img src="photo.jpg" alt="Une photo de moi" />

<!-- L'image ne comporte pas de description mais a quand même un attribut alt -->
<img src="deco.png" alt="" />
```

-   vos balises doivent être _fermées dans l'ordre_.
    

```html
<!-- Les balises ne sont pas fermées dans leur ordre d'ouverture -->
<p>Texte <em>important</p></em>

<!-- Les balises sont fermées dans leur ordre d'ouverture -->
<p>Texte <em>important</em></p>
```

Gardez bien ce schéma en tête, beaucoup de débutants font cette erreur ;

-   si vos liens comportent des `&`  , vous devez les remplacer par le code `&amp;`  pour éviter toute confusion au navigateur ;
    

```html
<!-- Exemple d'un mauvais lien en HTML -->
<a href="http://www.site.com/?jour=15&mois=10&an=2000">

<!-- Exemple d'un bon lien en HTML -->
<a href="http://www.site.com/?jour=15&amp;mois=10&amp;an=2000">
```

-   vérifiez enfin que vous n'avez pas utilisé des balises anciennes et désormais obsolètes en HTML5 (comme le vieux `<frame>`  , la balise `<marquee>`  …).

## Ajouter d'autres éléments
### Tableaux
Pour indiquer le début et la fin d'un tableau, on utilise `<table>` qui est une balise de type bloc, il faut donc la placer en dehors d'un paragraphe

-   `<tr> </tr>`  : indique le début et la fin d'une ligne du tableau ;
    
-   `<td> </td>`  : indique le début et la fin du contenu d'une cellule.

En HTML, un tableau se construit ligne par ligne.  Dans chaque ligne ( `<tr>` ), on indique le contenu des différentes cellules ( `<td>` ).  
Schématiquement, un tableau se construit comme à la figure suivante.

![](Obsidian/Pasted%20image%2020220325195847.png)

Par exemple pour 2 lignes de ce tableau, on aurait :

```html
<table>
   <tr>
       <td>Carmen</td>
       <td>33 ans</td>
       <td>Espagne</td>
   </tr>
   <tr>
       <td>Michelle</td>
       <td>26 ans</td>
       <td>États-Unis</td>
   </tr>
</table>
```

En ajoutant du CSS :
```css
td /* Toutes les cellules des tableaux... */
{
    border: 1px solid black; /* auront une bordure de 1px */
}
```

![](Obsidian/Pasted%20image%2020220325200305.png)

Pour n'avoir qu'une seule bordure entre 2 cellules, on va utiliser `broder-collapse` qui peut peut prendre deux valeurs :

-   `collapse`  : les bordures seront collées entre elles, c'est l'effet qu'on recherche ici ;
    
-   `separate`  : les bordures seront dissociées (valeur par défaut).

![](Obsidian/Pasted%20image%2020220325202150.png)

#### Ligne d'en-tête

La ligne d'en-tête se crée avec un `<tr>` comme on l'a fait jusqu'ici, mais les cellules qu'elle contient sont, cette fois, encadrées par des balises `<th>` et non pas `<td>` ! Et bien sûr, cette ligne est la première du tableau

Il faut donc mettre à jour le CSS

```css
table
{
    border-collapse: collapse;
}
td, th /* Mettre une bordure sur les td ET les th */
{
    border: 1px solid black;
}
```

#### Titre du tableau
On utilise la balise `caption` pour indiquer le titre du tableau, qui se place juste avant l'en-tête du tableau

Par exemple :

![](Obsidian/Pasted%20image%2020220325202458.png)

La position du titre peut être changée avec la propriété `caption-side` (options `top` et `bottom`)

#### Tableau structuré
-   pour les gros tableaux, il est possible de les **diviser** en trois parties :
    
    -   en-tête,
        
    -   corps du tableau,
        
    -   pied de tableau ;
        
-   pour certains tableaux, il se peut que vous ayez besoin de **fusionner** des cellules entre elles.

##### Diviser un gros tableau 
 il existe des balises HTML qui permettent de définir les trois « zones » du tableau :

-   **l'en-tête (en haut)** : il se définit avec les balises `<thead></thead>`  ;
    
-   **le corps (au centre)** : il se définit avec les balises `<tbody></tbody>`  ;
    
-   **le pied du tableau (en bas)** : il se définit avec les balises `<tfoot></tfoot>`  .

![](Obsidian/Pasted%20image%2020220325211727.png)

 Il est conseillé d'écrire dans les balises l'ordre suivant :
 1.  `<thead>`
    
2.  `<tfoot>`
    
3.  `<tbody>`

##### Fusion de cellules
  
Pour effectuer une fusion, on rajoute un attribut à la balise `<td>`  . Il faut savoir qu'il existe deux types de fusion :

-   **la fusion de colonnes** : La fusion s'effectue horizontalement. On utilisera l'attribut `colspan`  ;

*Exemple :*
![](Obsidian/Pasted%20image%2020220325213147.png)
    
-   **la fusion de lignes** : là, deux lignes seront groupées entre elles. La fusion s'effectuera verticalement. On utilisera l'attribut `rowspan`  .

Pour les 2 attributs, il faut indiquer le nombre de cellules à fusionner :
```html
<td colspan="2">
```

Par exemple pour `colspan` :

```html
<table>
   <tr>
       <th>Titre du film</th>
       <th>Pour enfants ?</th>
       <th>Pour adolescents ?</th>
   </tr>
   <tr>
       <td>Les bisounours font du ski</td>
       <td>Oui, adapté</td>
       <td>Pas assez violent...</td>
   </tr>
   <tr>
       <td>Lucky Luke, seul contre tous</td>
       <td colspan="2">Pour toute la famille !</td>
   </tr>
</table>
```

<table>
   <tr>
       <th>Titre du film</th>
       <th>Pour enfants ?</th>
       <th>Pour adolescents ?</th>
   </tr>
   <tr>
       <td>Les bisounours font du ski</td>
       <td>Oui, adapté</td>
       <td>Pas assez violent...</td>
   </tr>
   <tr>
       <td>Lucky Luke, seul contre tous</td>
       <td colspan="2"  style="text-align: center">Pour toute la famille !</td>
   </tr>
</table>


Et pour `rowspan`, on construit le tableau en longueur au lieu de le construire en haut :

```html
<table>
   <tr>
       <th>Titre du film</th>
       <td>Les bisounours font du ski</td>
       <td>Lucky Luke, seul contre tous</td>
   </tr>
   <tr>
       <th>Pour enfants ?</th>
       <td>Oui, adapté</td>
       <td rowspan="2">Pour toute la famille !</td>
   </tr>
   <tr>
       <th>Pour adolescents ?</th>
       <td>Pas assez violent...</td>
   </tr>
</table>
```
<table>
   <tr>
       <th>Titre du film</th>
       <td>Les bisounours font du ski</td>
       <td>Lucky Luke, seul contre tous</td>
   </tr>
   <tr>
       <th>Pour enfants ?</th>
       <td>Oui, adapté</td>
       <td rowspan="2">Pour toute la famille !</td>
   </tr>
   <tr>
       <th>Pour adolescents ?</th>
       <td>Pas assez violent...</td>
   </tr>
</table>

On peut modifier l'alignement vertical du texte des cellules de tableaux avec la propriété `vertical-align`

### Créer des formulaires
Le traitement des résultats doit s'effectuer dans un autre exemple, par exemple le PHP.

On utilise la balise `form` pour indiquer le début et la fin du formulaire. C'est aussi une balise de type bloc, donc à insérer après un `<p></p>`

On a 2 problèmes en créant un formulaire :
-   **Problème n° 1** : comment envoyer le texte saisi par le visiteur ? Par quel moyen ?
    
-   **Problème n° 2** : une fois que les données ont été envoyées, comment les traiter ? Souhaitez-vous recevoir le message automatiquement par mail ou préférez-vous qu'un programme se charge de l'enregistrer quelque part, puis de l'afficher sur une page visible par tout le monde ?

On utilise 2 attributs à la balise `<form>` pour pallier à ces 2 problèmes :
-   `method`  : cet attribut indique par quel moyen les données vont être envoyées (réponse au **problème n° 1**). Il existe deux solutions pour envoyer des données sur le Web :
    
    -   `method="get"`  : c'est une méthode en général assez peu adaptée car elle est limitée à 255 caractères. La particularité vient du fait que les informations seront envoyées dans l'adresse de la page ( `http://…`  ), mais ce détail ne nous intéresse pas vraiment pour le moment. La plupart du temps, je vous recommande d'utiliser l'autre méthode : `post`  ,
        
    -   `method="post"`  : c'est la méthode la plus utilisée pour les formulaires car elle permet d'envoyer un grand nombre d'informations. Les données saisies dans le formulaire ne transitent pas par la barre d'adresse ;
        
-   `action`  : c'est l'adresse de la page ou du programme qui va _traiter_ les informations (réponse au **problème n° 2**). Cette page se chargera de vous envoyer un e-mail avec le message si c'est ce que vous voulez, ou bien d'enregistrer le message avec tous les autres dans une base de données.  
    Cela ne peut pas se faire en HTML et CSS ; on utilisera en général un autre langage : PHP.

Donc par exemple, on écrit :

```html
<p>Texte avant le formulaire</p>

<form method="post" action="traitement.php">

<p>Texte à l'intérieur du formulaire</p>

</form>

<p>Texte après le formulaire</p>
```

#### Zones de saisies basiques

il y a deux zones de texte différentes :

-   **la zone de texte monoligne** : comme son nom l'indique, on ne peut y écrire qu'une seule ligne. Elle sert à saisir des textes courts, par exemple un pseudo => balise `<input />`
    
-   **la zone de texte multiligne** : cette zone de texte permet d'écrire une quantité importante de texte sur plusieurs lignes

Pour créer une zone de texte à une ligne, on doit écrire :

```html
<input type="text" />
```

Ce n'est pas encore suffisant : il faut donner un nom à votre zone de texte. Ce nom n'apparaît pas sur la page, mais il vous sera indispensable par la suite. En effet, cela vous permettra (en PHP par exemple) de reconnaître d'où viennent les informations : vous saurez que tel texte est le pseudo du visiteur, tel texte est le mot de passe qu'il a choisi, etc.

Pour donner un nom à un élément de formulaire, on utilise l'attribut `name`  . Ici, on va supposer qu'on demande au visiteur de rentrer son pseudo :

```html
<input type="text" name="pseudo" />
```

On utilise la balise `<label>` pour indiquer à quoi correspond la zone de texte :
```html
<form method="post" action="traitement.php">
	<p>
		<label>Votre pseudo</label> : <input type="text" name="pseudo" />
	</p>
</form>
```

Il faut lier le label à la zone de texte.  
Pour ce faire, on doit donner un nom à la zone de texte, non pas avec l'attribut `name`  mais avec l'attribut `id`  (que l'on peut utiliser sur toutes les balises).

En fait, l'id est utilisé pour **identifier** l'élément HTML pour pouvoir y accéder et le manipuler. Il est donc unique pour cet élément. 

Le `name` , lui, réfère à la variable du formulaire que l’élément concerne. Ici, il n’y a qu’un seul élément qui pourra référer à la variable _pseudo_ ; `name` et `id` auront donc la même valeur. Mais lorsque nous utiliserons des `checkbox` ou des `radio` , plusieurs éléments correspondront à la même variable. Par exemple, la variable _couleur_ avec un élément pour _rouge_, un pour _bleu_ et un pour _vert_. Ils auront donc le même `name` , mais pas le même `id`  . 

Pour lier le label au champ, il faut lui donner un attribut `for`  qui a la même valeur que l' `id`  du champ… Le mieux est de le voir sur un exemple :

```html
<form method="post" action="traitement.php">
   <p>
       <label for="pseudo">Votre pseudo</label> : <input type="text" name="pseudo" id="pseudo" />
   </p>
</form>
```

<form method="post" action="traitement.php">
   <p>
       <label for="pseudo">Votre pseudo</label> : <input type="text" name="pseudo" id="pseudo" />
   </p>
</form>

#### Attributs supplémentaires
  
On peut ajouter un certain nombre d'autres attributs à la balise `<input />`  pour personnaliser son fonctionnement :

-   on peut agrandir le champ avec `size`  ;
    
-   on peut limiter le nombre de caractères que l'on peut saisir avec `maxlength`  ;
    
-   on peut préremplir le champ avec une valeur par défaut à l'aide de `value`  ;
    
-   on peut donner une indication sur le contenu du champ avec `placeholder`  . Cette indication disparaîtra dès que le visiteur aura cliqué à l'intérieur du champ.
    

Dans l'exemple suivant, la zone de texte contient une indication permettant de comprendre ce qu'il faut saisir ; le champ fait 30 caractères de long mais on ne peut écrire que 10 caractères maximum à l'intérieur :

```html
<form method="post" action="traitement.php">
    <p>
        <label for="pseudo">Votre pseudo :</label>
        <input type="text" name="pseudo" id="pseudo" placeholder="Ex : Zozor" size="30" maxlength="10" />
    </p>
</form>
```

<form method="post" action="traitement.php">
    <p>
        <label for="pseudo">Votre pseudo :</label>
        <input type="text" name="pseudo" id="pseudo" placeholder="Ex : Zozor" size="30" maxlength="10" />
    </p>
</form>

#### Zone de mot de passe

Pour créer une zone de mot de passe, on utilise l'attribut `type="password"`

<form method="post" action="traitement.php">
   <p>
       <label for="pseudo">Votre pseudo :</label>
       <input type="text" name="pseudo" id="pseudo" />
       
       <br />
       <label for="pass">Votre mot de passe :</label>
       <input type="password" name="pass" id="pass" />
       
   </p>
</form>

```html
<form method="post" action="traitement.php">
   <p>
       <label for="pseudo">Votre pseudo :</label>
       <input type="text" name="pseudo" id="pseudo" />
       
       <br />
       <label for="pass">Votre mot de passe :</label>
       <input type="password" name="pass" id="pass" />
       
   </p>
</form>
```

#### Zone de texte multiligne
On utilise la balise `<textarea></textarea>`, à laquelle il faut ajouter un `name` et un `label`

On peut modifier la taille du `textarea` de 2 manière différentes :
-   **En CSS** : il suffit d'appliquer les propriétés CSS `width`  et `height`  au `<textarea>`  .
    
-   **Avec des attributs** : on peut ajouter les attributs `rows`  et `cols`  à la balise `<textarea>`  . Le premier indique le nombre de lignes de texte qui peuvent être affichées simultanément, et le second le nombre de colonnes.

Entre la balise ouvrante et fermante, on peut afficher un texte prérempli.

#### Zones de saisie enrichies
Tous les navigateurs ne connaissent pas encore ces zones de saisie enrichies. À leur place, les anciennes versions des navigateurs afficheront une simple zone de saisie monoligne (comme si on avait écrit `type="text"` ).

- **e-mail** : le champ semble identique mais le navigateur *sait* qu'une adresse mail doit être saisie (il peut entourer le champ en rouge)
```html
<input type="email" />
```

- **URL** 
```html
<input type="url" />
```

- **numéro de téléphone**
```html
<input type="tel" />
```

- **nombre** : en général affiché avec des petites flèches pour changer la valeur
```html
<input type="number" />
```
On peut personnaliser le fonctionnement du champ avec les attributs suivants :
-   `min`  : valeur minimale autorisée ;
    
-   `max`  : valeur maximale autorisée ;
    
-   `step`  : c'est le « pas » de déplacement. Si vous indiquez un pas de 2, le champ n'acceptera que des valeurs de 2 en 2 (par exemple 0, 2, 4, 6…).

- **curseur** : permet de sélectionner un nombre avec un curseur (= *slider*) <input type="range" />
```html
<input type="range" />
```

On peut aussi utiliser les attributs `min` , `max` et `step` pour restreindre les valeurs disponibles.

- **couleur** : permet de saisir une couleur
<input type="color" />
```html
<input type="color" />
```

*[Non pris en charge par tous les navigateurs](https://caniuse.com/#feat=input-color)*

- **date** : différents champs de sélection de date existent :
	-   `date`  : pour la date (05/08/1985 par exemple) ;
    
	-   `time`  : pour l'heure (13:37 par exemple) ;
    
	-   `week`  : pour la semaine ;
    
	-   `month`  : pour le mois ;
    
	-   `datetime`  : pour la date et l'heure (avec gestion du décalage horaire) ;
    
	-   `datetime-local`  pour la date et l'heure (sans gestion du décalage horaire).

*Exemple :*
```html
<input type="date" />
```

*[Vérifier la compatibilité](https://caniuse.com/#feat=input-datetime)*

- **recherche** : le navigateur décide comment afficher le champ de recherche (il peut ajouter une loupe ou mémoriser les dernières recherches effectuées) <input type="search" />

```html
<input type="search" />
```

#### Eléments d'options
##### Cases à cocher
On utilise : 
```html
<input type="checkbox" name="choix" />
```
En ajoutant un `label`, on peut obtenir :

<form method="post" action="traitement.php">
   <p>
       Cochez les aliments que vous aimez manger :<br />
       <input type="checkbox" name="frites" id="frites" checked /> <label for="frites">Frites</label><br />
       <input type="checkbox" name="steak" id="steak" /> <label for="steak">Steak haché</label><br />
       <input type="checkbox" name="epinards" id="epinards" /> <label for="epinards">Epinards</label><br />
       <input type="checkbox" name="huitres" id="huitres" /> <label for="huitres">Huitres</label>
   </p>
</form>
```html
<form method="post" action="traitement.php">
   <p>
       Cochez les aliments que vous aimez manger :<br />
       <input type="checkbox" name="frites" id="frites" /> <label for="frites">Frites</label><br />
       <input type="checkbox" name="steak" id="steak" /> <label for="steak">Steak haché</label><br />
       <input type="checkbox" name="epinards" id="epinards" /> <label for="epinards">Epinards</label><br />
       <input type="checkbox" name="huitres" id="huitres" /> <label for="huitres">Huitres</label>
   </p>
</form>
```

**Il faut donner un nom différent à chaque case à cocher, ce qui permet d'identifier quelles cases ont été cochées par le visiteur**

Une case peut être cochée par défaut avec `checked` :
```html
<input type="checkbox" name="choix" checked />
```

##### Zones d'options

Permettent un choix **unique** parmi une liste d'options. Elles doivent être organisées en groupes. Les options d'un même groupe possèdent le même nom ( `name` ), mais chaque option doit avoir une valeur ( `value` ) différente.

On utilise `<input />` avec : `type="radio"`

```html
<form method="post" action="traitement.php">
   <p>
       Veuillez indiquer la tranche d'âge dans laquelle vous vous situez :<br />
       <input type="radio" name="age" value="moins15" id="moins15" /> <label for="moins15">Moins de 15 ans</label><br />
       <input type="radio" name="age" value="medium15-25" id="medium15-25" /> <label for="medium15-25">15-25 ans</label><br />
       <input type="radio" name="age" value="medium25-40" id="medium25-40" /> <label for="medium25-40">25-40 ans</label><br />
       <input type="radio" name="age" value="plus40" id="plus40" /> <label for="plus40">Encore plus vieux que ça ?!</label>
   </p>
</form>
```

<form method="post" action="traitement.php">
   <p>
       Veuillez indiquer la tranche d'âge dans laquelle vous vous situez :<br />
       <input type="radio" name="age" value="moins15" id="moins15" /> <label for="moins15">Moins de 15 ans</label><br />
       <input type="radio" name="age" value="medium15-25" id="medium15-25" checked/> <label for="medium15-25">15-25 ans</label><br />
       <input type="radio" name="age" value="medium25-40" id="medium25-40" /> <label for="medium25-40">25-40 ans</label><br />
       <input type="radio" name="age" value="plus40" id="plus40" /> <label for="plus40">Encore plus vieux que ça ?!</label>
   </p>
</form>

##### Les listes déroulantes

La balise `<select> </select>` indique le début et la fin de la liste déroulante.
A l'intérieur de cette balise, on place des balises `<option></option>` avec un attribut `value` 

```html
<form method="post" action="traitement.php">
   <p>
       <label for="pays">Dans quel pays habitez-vous ?</label><br />
       <select name="pays" id="pays">
           <option value="france">France</option>
           <option value="espagne">Espagne</option>
           <option value="italie">Italie</option>
           <option value="royaume-uni">Royaume-Uni</option>
           <option value="canada">Canada</option>
           <option value="etats-unis">États-Unis</option>
           <option value="chine">Chine</option>
           <option value="japon">Japon</option>
       </select>
   </p>
</form>
```

<form method="post" action="traitement.php">
   <p>
       <label for="pays">Dans quel pays habitez-vous ?</label><br />
       <select name="pays" id="pays">
           <option value="france">France</option>
           <option value="espagne">Espagne</option>
           <option value="italie">Italie</option>
           <option value="royaume-uni">Royaume-Uni</option>
           <option value="canada">Canada</option>
           <option value="etats-unis">États-Unis</option>
           <option value="chine">Chine</option>
           <option value="japon">Japon</option>
       </select>
   </p>
</form>
Pour que cette option soit sélectionnée par défaut, on utilise `selected`

On peut aussi grouper vos options avec la balise `<optgroup> </optgroup>`  . Dans notre exemple, pourquoi ne pas séparer les pays en fonction de leur continent ?

```html
<form method="post" action="traitement.php">
   <p>
       <label for="pays">Dans quel pays habitez-vous ?</label><br />
       <select name="pays" id="pays">
           <optgroup label="Europe">
               <option value="france">France</option>
               <option value="espagne">Espagne</option>
               <option value="italie">Italie</option>
               <option value="royaume-uni">Royaume-Uni</option>
           </optgroup>
           <optgroup label="Amérique">
               <option value="canada">Canada</option>
               <option value="etats-unis">Etats-Unis</option>
           </optgroup>
           <optgroup label="Asie">
               <option value="chine">Chine</option>
               <option value="japon">Japon</option>
           </optgroup>
       </select>
   </p>
</form>
```

<form method="post" action="traitement.php">
   <p>
       <label for="pays">Dans quel pays habitez-vous ?</label><br />
       <select name="pays" id="pays">
           <optgroup label="Europe">
               <option value="france">France</option>
               <option value="espagne">Espagne</option>
               <option value="italie">Italie</option>
               <option value="royaume-uni">Royaume-Uni</option>
           </optgroup>
           <optgroup label="Amérique">
               <option value="canada">Canada</option>
               <option value="etats-unis">Etats-Unis</option>
           </optgroup>
           <optgroup label="Asie">
               <option value="chine">Chine</option>
               <option value="japon">Japon</option>
           </optgroup>
       </select>
   </p>
</form>

#### Finaliser et envoyer les formulaires
##### Regrouper les champs
  
Si votre formulaire grossit et comporte beaucoup de champs, il peut être utile de les regrouper au sein de plusieurs balises `<fieldset>` . Chaque `<fieldset>` peut contenir une légende avec la balise `<legend>`

```html
<form method="post" action="traitement.php">
 
   <fieldset>
       <legend>Vos coordonnées</legend> <!-- Titre du fieldset --> 

       <label for="nom">Quel est votre nom ?</label>
       <input type="text" name="nom" id="nom" /><br>

       <label for="prenom">Quel est votre prénom ?</label>
       <input type="text" name="prenom" id="prenom" /><br>
 
       <label for="email">Quel est votre e-mail ?</label>
       <input type="email" name="email" id="email" /><br>

   </fieldset>
 
   <fieldset>
       <legend>Votre souhait</legend> <!-- Titre du fieldset -->
 
       <p>
           Faites un souhait que vous voudriez voir exaucé :

           <input type="radio" name="souhait" value="riche" id="riche" /> <label for="riche">Etre riche</label><br>
           <input type="radio" name="souhait" value="celebre" id="celebre" /> <label for="celebre">Etre célèbre</label><br>
           <input type="radio" name="souhait" value="intelligent" id="intelligent" /> <label for="intelligent">Etre <strong>encore</strong> plus intelligent</label><br>
           <input type="radio" name="souhait" value="autre" id="autre" /> <label for="autre">Autre...</label>
       </p>
 
       <p>
           <label for="precisions">Si "Autre", veuillez préciser :</label>
           <textarea name="precisions" id="precisions" cols="40" rows="4"></textarea>
       </p>
   </fieldset>
</form>
```

<form method="post" action="traitement.php">
 
   <fieldset>
       <legend>Vos coordonnées</legend> <!-- Titre du fieldset --> 

       <label for="nom">Quel est votre nom ?</label>
       <input type="text" name="nom" id="nom" /><br>

       <label for="prenom">Quel est votre prénom ?</label>
       <input type="text" name="prenom" id="prenom" /><br>
 
       <label for="email">Quel est votre e-mail ?</label>
       <input type="email" name="email" id="email" /><br>

   </fieldset>
 
   <fieldset>
       <legend>Votre souhait</legend> <!-- Titre du fieldset -->
 
       <p>
           Faites un souhait que vous voudriez voir exaucé :

           <input type="radio" name="souhait" value="riche" id="riche" /> <label for="riche">Etre riche</label><br>
           <input type="radio" name="souhait" value="celebre" id="celebre" /> <label for="celebre">Etre célèbre</label><br>
           <input type="radio" name="souhait" value="intelligent" id="intelligent" /> <label for="intelligent">Etre <strong>encore</strong> plus intelligent</label><br>
           <input type="radio" name="souhait" value="autre" id="autre" /> <label for="autre">Autre...</label>
       </p>
 
       <p>
           <label for="precisions">Si "Autre", veuillez préciser :</label>
           <textarea name="precisions" id="precisions" cols="40" rows="4"></textarea>
       </p>
   </fieldset>
</form>

##### Sélectionner automatiquement un champ
  
Vous pouvez placer automatiquement le curseur dans l'un des champs de votre formulaire avec l'attribut `autofocus`  . Dès que le visiteur chargera la page, le curseur se placera dans ce champ.

Par exemple, pour que le curseur soit par défaut dans le champ `prenom`  :

```html
<input type="text" name="prenom" id="prenom" autofocus />
```

##### Rendre un champ obligatoire
  
Vous pouvez faire en sorte qu'un champ soit obligatoire en lui donnant l'attribut `required`  .

```html
<input type="text" name="prenom" id="prenom" required />
```

Le navigateur indiquera alors au visiteur, si le champ est vide au moment de l'envoi, qu'il doit impérativement être rempli.

> Les anciens navigateurs, qui ne reconnaissent pas cet attribut, enverront le contenu du formulaire sans vérification. Pour ces navigateurs, il sera nécessaire de compléter les tests avec, par exemple, des scripts JavaScript.

**On dispose de pseudo-formats en CSS pour changer le style des éléments requis ( `:required` ) et invalides ( `:invalid` ). N'oubliez pas non plus que vous disposez du pseudo-format `:focus` pour changer l'apparence d'un champ lorsque le curseur se trouve à l'intérieur.**

```css
:required
{
	background-color: red;
}
```

##### Le bouton d'envoi
On utilise encore la balise `<input />` en 4 versions :

-   `type="submit"`  : le principal bouton d'envoi de formulaire. C'est celui que vous utiliserez le plus souvent. Le visiteur sera conduit à la page indiquée dans l'attribut `action`  du formulaire ;
    
-   `type="reset"`  : remise à zéro du formulaire ;
    
-   `type="image"`  : équivalent du bouton `submit`  , présenté cette fois sous forme d'image. Rajoutez l'attribut `src`  pour indiquer l'URL de l'image ;
    
-   `type="button"`  : bouton générique, qui n'aura (par défaut) aucun effet. En général, ce bouton est géré en JavaScript pour exécuter des actions sur la page. Nous ne l'utiliserons pas ici.

**On peut changer le texte affiché à l'intérieur des boutons avec l'attribut `value`**

Par exemple, pour créer : <input type="submit" value="Envoyer" />
```html
<input type="submit" value="Envoyer" />
```

### Ajouter de l'audio et des vidéos

On utilise 2 balises `<video>` et `<audio>`

#### Formats audio et vidéo

**Formats audio :**
-   **MP3** : vous ne pouvez _pas_ ne pas en avoir entendu parler ! C'est l'un des plus vieux, mais aussi l'un des plus compatibles (tous les appareils savent lire des MP3), ce qui fait qu'il est toujours très utilisé aujourd'hui ;
    
-   **AAC** : utilisé majoritairement par Apple sur iTunes, c'est un format de bonne qualité. Les iPod, iPhone et autres iPad savent les lire sans problème ;
    
-   **Ogg** : le format Ogg Vorbis est très répandu dans le monde du logiciel libre, notamment sous Linux. Ce format a l'avantage d'être libre, c'est-à-dire qu'il n'est protégé par aucun brevet ;
    
-   **WAV** (**format non compressé**) : évitez autant que possible de l'utiliser car le fichier est très volumineux avec ce format. C'est un peu l'équivalent du Bitmap (BMP) pour l'audio.

Consulter [caniuse](https://caniuse.com) pour connaître la compatibilité

**Formats vidéo :**

Pour stocker la vidéo, on a besoin de 3 éléments :
-   **un format conteneur** : c'est un peu comme une boîte qui va servir à contenir les deux éléments ci-dessous. On reconnaît en général le type de conteneur à l'extension du fichier : AVI, MP4, MKV… ;
    
-   **un codec audio** : c'est le format du son de la vidéo, généralement compressé. Nous venons de les voir, on utilise les mêmes : MP3, AAC, OGG… ;
    
-   **un codec vidéo** : c'est le format qui va compresser les images. C'est là que les choses se corsent, car ces formats sont complexes et on ne peut pas toujours les utiliser gratuitement. Les principaux à connaître pour le Web sont :
    
    -   **H.264** : l'un des plus puissants et des plus utilisés aujourd'hui… mais il n'est pas 100 % gratuit. En fait, on peut l'utiliser gratuitement dans certains cas (comme la diffusion de vidéos sur un site web personnel), mais il y a un flou juridique qui fait qu'il est risqué de l'utiliser à tout va,
        
    -   **Ogg Theora** : un codec gratuit et libre de droits, mais moins puissant que H.264. Il est bien reconnu sous Linux mais, sous Windows, il faut installer des programmes pour pouvoir le lire,
        
    -   **WebM** : un autre codec gratuit et libre de droits, plus récent. Proposé par Google, c'est le concurrent le plus sérieux de H.264 à l'heure actuelle.

Consulter [caniuse](https://caniuse.com) pour connaître la compatibilité : le format H.264 est le + compatible.  Il est quand même conseillé de proposer si possible chaque vidéo dans plusieurs formats, pour qu'elle soit lisible sur un maximum de navigateurs.

Pour convertir une vidéo dans différents formats, on peut utiliser le logiciel [Miro Video Converter](http://www.mirovideoconverter.com/)

#### Insérer un élément audio
On ne peut pas faire simplement :
```html
<audio src="musique.mp3"></audio>
```

Il faut compléter la balise des attributs suivants :
-   `controls`  : pour ajouter les boutons « Lecture », « Pause » et la barre de défilement. Cela peut sembler indispensable, et vous vous demandez peut-être pourquoi cela n'y figure pas par défaut, mais certains sites web préfèrent créer eux-mêmes leurs propres boutons et commander la lecture avec du JavaScript ;
    
-   `width`  : pour modifier la largeur de l'outil de lecture audio ;
    
-   `loop`  :   la musique sera jouée en boucle ;
    
-   `autoplay`  : la musique sera jouée dès le chargement de la page (évitez d'en abuser, c'est en général irritant d'arriver sur un site qui joue de la musique tout seul !) ;
    
-   `preload`  : indique si la musique peut être préchargée dès le chargement de la page ou non. Cet attribut peut prendre les valeurs :
    
    -   `auto`  (par défaut) : le navigateur décide s'il doit précharger toute la musique, uniquement les métadonnées ou rien du tout,
        
    -   `metadata`  : charge uniquement les métadonnées (durée, etc.),
        
    -   `none`  : pas de préchargement. Utile si vous ne voulez pas gaspiller de bande passante sur votre site.

> On ne peut pas forcer le préchargement de la musique, c'est toujours le navigateur qui décide.  
Les navigateurs mobiles, par exemple, ne préchargent jamais la musique, pour économiser la bande passante (le temps de chargement étant long sur un portable).

```html
<audio src="audio.mp3" controls></audio>
```

<audio src="audio.mp3" controls></audio>

On peut mettre un message en cas d'erreur entre les 2 balises : 
```html
<audio src="hype_home.mp3" controls>Veuillez mettre à jour votre navigateur !</audio>
```

On peut aussi proposer plusieurs versions du fichier audio avec (le navigateur prendra le format qu'il reconnait) :

```html
<audio controls>
    <source src="hype_home.mp3">
    <source src="hype_home.ogg">
</audio>
```

#### Insertion d'une vidéo

De même, il faut utiliser des attributs supplémentaires en plus de la balise :
-   `poster`  : image à afficher à la place de la vidéo tant que celle-ci n'est pas lancée. Par défaut, le navigateur prend la première image de la vidéo mais, comme il s'agit souvent d'une image noire ou d'une image peu représentative de la vidéo, je vous conseille d'en créer une ! Vous pouvez tout simplement faire une capture d'écran d'un moment de la vidéo.
    
-   `controls`  : pour ajouter les boutons « Lecture », « Pause » et la barre de défilement. Cela peut sembler indispensable, mais certains sites web préfèrent créer eux-mêmes leurs propres boutons et commander la lecture avec du JavaScript. En ce qui nous concerne, ce sera largement suffisant !
    
-   `width`  : pour modifier la largeur de la vidéo.
    
-   `height`  : pour modifier la hauteur de la vidéo.
    
-   `loop`  : la vidéo sera jouée en boucle.
    
-   `autoplay`  : la vidéo sera jouée dès le chargement de la page. Là encore, évitez d'en abuser, c'est en général irritant d'arriver sur un site qui lance quelque chose tout seul !
    
-   `preload`  : indique si la vidéo peut être préchargée dès le chargement de la page ou non. Cet attribut peut prendre les valeurs :
    
    -   `auto`  (par défaut) : le navigateur décide s'il doit précharger toute la vidéo, uniquement les métadonnées ou rien du tout ;
        
    -   `metadata`  : charge uniquement les métadonnées (durée, dimensions, etc.) ;
        
    -   `none`  : pas de préchargement. Utile si vous souhaitez éviter le gaspillage de bande passante sur votre site.

<video src="sintel.webm" controls poster="poster.jpg" width="600"></video>


```html
<video src="sintel.webm" controls poster="sintel.jpg" width="600"></video>
```

De même que pour l'audio, on peut mettre un message d'erreur entre les 2 balises, et on peut proposer différents formats :

```html
<video controls poster="sintel.jpg" width="600">
    <source src="sintel.mp4">
    <source src="sintel.webm">
    <source src="sintel.ogv">
</video>
```

**On ne peut pas protéger sa vidéo avec cette technique. Les lecteurs Flashs le peuvent mais on peut contourner**

## Responsive design avec les Media Queries

Les *media queries* sont des règles à appliquer pour changer le design d'un site en fonction des caractéristiques de l'écran.

### Mise en place des media queries
 Concrètement, vous allez pouvoir dire « Si la résolution de l'écran du visiteur est inférieure à tant, alors applique les propriétés CSS suivantes ». Cela vous permet de changer l'apparence du site dans certaines conditions : vous pourrez augmenter la taille du texte, changer la couleur de fond, positionner différemment votre menu dans certaines résolutions, etc.  
Contrairement à ce qu'on pourrait penser, les media queries ne concernent pas que les résolutions d'écran. Vous pouvez changer l'apparence de votre site en fonction d'autres critères comme le type d'écran (smartphone, télévision, projecteur…), le nombre de couleurs, l'orientation de l'écran (portrait ou paysage), etc. Les possibilités sont très nombreuses !

#### Appliquer une media query
Il y a deux façons de les utiliser :

-   en chargeant une feuille de style `.css`  différente en fonction de la règle (ex. : « Si la résolution est inférieure à 1 280 px de large, charge le fichier `petite_resolution.css`  ») ;
    
-   en écrivant la règle directement dans le fichier `.css`  habituel (ex. : « Si la résolution est inférieure à 1 280 px de large, charge les propriétés CSS ci-dessous »).

Pour charger une feuille de style différente, on change la balise `<link />`

```html
<link rel="stylesheet" media="screen and (max-width: 1280px)" href="petite_resolution.css" />
```

On pourrait par exemple avoir :

```html
<!DOCTYPE html>
<html>
    <head>
        <meta charset="utf-8" />
        <link rel="stylesheet" href="style.css" /> <!-- Pour tout le monde -->
        <link rel="stylesheet" media="screen and (max-width: 1280px)" href="petite_resolution.css" /> <!-- Pour ceux qui ont une résolution inférieure à 1280px -->
        <title>Media queries</title>
    </head>
```

Pour changer les règles directement dans la feuille de style :

```css
@media screen and (max-width: 1280px)
{
    /* Rédigez vos propriétés CSS ici */
}
```

#### Règles disponibles
-   `color`  : gestion de la couleur (en bits/pixel) ;
    
-   `height`  : hauteur de la zone d'affichage (fenêtre) ;
    
-   `width`  : largeur de la zone d'affichage (fenêtre) ;
    
-   `device-height`  : hauteur du périphérique ;
    
-   `device-width`  : largeur du périphérique ;
    
-   `orientation`  : orientation du périphérique (portrait ou paysage) ;
    
-   `media`  : type d'écran de sortie. Quelques-unes des valeurs possibles :
    
    -   `screen`  : écran « classique »,
        
    -   `handheld`  : périphérique mobile,
        
    -   `print`  : impression,
        
    -   `tv`  : télévision,
        
    -   `projection`  : projecteur,
        
    -   `all`  : tous les types d'écrans.

On peut rajouter le préfixe `min-` ou `max-` devant la plupart de ces règles. Ainsi, `min-width` signifie « largeur minimale », `max-height` « hauteur maximale », etc.  
La différence entre `width` et `device-width` se perçoit surtout sur les navigateurs mobiles des smartphones 

Les règles peuvent être combinées à l'aide des mots suivants :

-   `only`  : « uniquement » ;
    
-   `and`  : « et » ;
    
-   `not`  : « non ».

*Exemples :*

```css
/* Sur les écrans, quand la largeur de la fenêtre fait au maximum 1280px */
@media screen and (max-width: 1280px)

/* Sur tous types d'écran, quand la largeur de la fenêtre est comprise entre 1024px et 1280px */
@media all and (min-width: 1024px) and (max-width: 1280px)

/* Sur les téléviseurs */
@media tv

/* Sur tous types d'écrans orientés verticalement */
@media all and (orientation: portrait)
```

#### Mise en pratique
Sur la page suivante :
![](Obsidian/Pasted%20image%2020220326160206.png)
On peut réaliser les modifications suivantes :
-   le menu de navigation en haut à droite sera disposé en hauteur plutôt qu'en largeur, et les liens seront écrits en plus petit ;
    
-   la bannière avec le pont de San Francisco (le _Golden Gate_) sera supprimée, car elle prend beaucoup de place et n'apporte pas beaucoup d'informations ;
    
-   le bloc `<aside>`  « À propos de l'auteur » sera placé sous l'article (et non pas à côté), et son contenu sera réorganisé (la photo de Zozor sera positionnée en flottant).

Pour cela, on ajoute le CSS suivant :

```css
@media all and (max-width: 1024px)
{
   /* Pour enlever les marges et ajuster automatiquement le contenu à la taille de l'écran */
   #main_wrapper
   {
     width: auto;
   }
   /* On change la disposition de la barre de navigation afin qu'elle soit verticale et on diminue la taille de la police */
   nav
    {
        width: auto;
        text-align: left;
    }

    nav ul
    {
        flex-direction: column;
    }

    nav li
    {
        padding-left: 4px;
    }

    nav a
    {
        font-size: 1.1em;
    }

    nav a:hover
    {
        border-bottom: 0;
    }
    /* On masque la bannière */
    .presentation
    {
      display: none;
    }
    /* On modifie la partie section pour que la partie "A propos" de l'auteur se trouve en dessous*/
    section
    {
      flex-direction: column;
    }
    article, aside
    {
        width: auto;
        margin-bottom: 15px;
    }
/* On efface la flèche qui ne sert plus à rien */
    #bulle
    {
        display: none;
    }
/* La photo est affichée en flottant et non au centre de l'image */
    #zozor img
    {
        width: 110px;
        float: right;
        margin-left: 15px;
    }
/* aside p = tous les paragraphes à l'intérieur de la balise <aside>
avec :last-child, on cible le dernier paragraphe qui contient les liens vers les réseaux sociaux
On aurait aussi pu utiliser une class ou un id
*/
    aside p:last-child
    {
        text-align: center;
    }
}
```

Résultat :

![](Obsidian/Pasted%20image%2020220326161335.png)

#### Navigateurs mobiles
Pour s'adapter, les navigateurs mobiles affichent le site en « dézoomant », ce qui permet d'avoir un aperçu de l'ensemble de la page. La zone d'affichage simulée est appelée le **_viewport_**: c'est la largeur de la fenêtre du navigateur sur le mobile.
  
En CSS, avec les media queries, si vous ciblez l'écran avec `max-width`  sur un mobile, celui-ci va comparer la largeur que vous indiquez avec celle de son viewport. Le problème, c'est que le viewport change selon le navigateur mobile utilisé !

| Navigateur    | Largeur du ***viewport*** par défaut |
| ------------- | ------------------------------------ |
| Opera mobile  | 850 pixels                           |
| iPhone Safari | 980 pixels                           |
| Android       | 800 pixels                           |
| Windows Phone | 1024 pixels                          | 

Donc, pour cibler les smartphones, plutôt que d'utiliser `max-width` , il peut être intéressant de recourir à `max-device-width` : c'est la largeur du périphérique.
 Les périphériques mobiles ne dépassant pas 480 px de large, on pourra viser uniquement les navigateurs mobiles avec cette media query :
```css
 @media all and (max-device-width: 480px)
{
    /* Vos règles CSS pour les mobiles ici */
}
```

on peut (en théorie) cibler les écrans mobiles avec le media `handheld` … Malheureusement, aucun navigateur mobile à part Opera Mobile ne reconnaît `handheld` .

Vous pouvez modifier la largeur viewport du navigateur mobile avec une balise `meta`  à insérer dans l'en-tête ( `<head>`  ) du document :

```html
<meta name="viewport" content="width=320" />
```

Vous pouvez utiliser cette balise pour modifier la façon dont le contenu de votre page s'organise sur les mobiles. Pour obtenir un rendu facile à lire, sans zoom, vous pouvez demander à ce que le viewport soit le même que la largeur de l'écran :

```html
<meta name="viewport" content="width=device-width" />
```

## Aller plus loin
### JavaScrpit
Pour
- modifier des propriétés CSS sans avoir à recharger la page. Par exemple, vous pointez sur une image et le fond de votre site change de couleur (ce n'est pas possible à faire avec un `:hover`  , car cela concerne deux balises différentes ; c'est bien là une limite du CSS) ;
    
-   on peut l'utiliser aussi pour modifier le code source HTML sans avoir à recharger la page, _pendant_ que le visiteur consulte la page ;
    
-   il permet aussi d'afficher des boîtes de dialogue à l'écran du visiteur…
    
-   … ou encore de modifier la taille de la fenêtre.

JavaScript est régulièrement utilisé aujourd'hui pour faire de l'AJAX (_Asynchronous JavaScript And XML_). Cette technique permet de modifier une partie de la page web que le visiteur consulte en échangeant des données avec le serveur. Cela donne l'impression que les pages sont plus dynamiques et plus réactives. Le visiteur n'a plus besoin de recharger systématiquement toute la page.

Les navigateurs sont de plus en plus efficaces dans leur traitement de JavaScript, ce qui fait que les pages qui utilisent JavaScript sont de plus en plus réactives. On peut ainsi arriver aujourd'hui à créer des sites qui deviennent littéralement des applications web, l'équivalent de logiciels mais disponibles sous forme de sites web !  
Un exemple célèbre : Google Docs, la suite bureautique de Google, disponible sur le Web (figure suivante).

### Langages liés à HTML5
-   **Canvas** : permet de dessiner au sein de la page web, à l'intérieur de la balise HTML `<canvas>`  . On peut dessiner des formes (triangles, cercles…) mais aussi ajouter des images, les manipuler, appliquer des filtres graphiques… Au final, cela nous permet de réaliser aujourd'hui de véritables jeux et des applications graphiques directement dans des pages web ! 
    
-   **SVG** : permet de créer des dessins vectoriels au sein des pages web. À la différence de Canvas, ces dessins peuvent être agrandis à l'infini (c'est le principe du vectoriel). Le [logiciel](http://telecharger.tomsguide.fr/Inkscape,0301-6057-3462.html)   [`Inkscape`](http://telecharger.tomsguide.fr/Inkscape,0301-6057-3462.html)  est connu pour permettre de dessiner des SVG. 
    
-   **Drag & Drop** : permet de faire « glisser-déposer » des objets dans la page web, de la même façon qu'on peut faire glisser-déposer des fichiers sur son bureau. Gmail l'utilise pour permettre d'ajouter facilement des pièces jointes à un e-mail.
    
-   **File API** : permet d'accéder aux fichiers stockés sur la machine du visiteur (avec son autorisation). On l'utilisera notamment en combinaison avec le Drag & Drop.
    
-   **Géolocalisation** : pour localiser le visiteur et lui proposer des services liés au lieu où il se trouve (ex. : les horaires des salles de cinéma proches). La localisation n'est pas toujours très précise, mais cela peut permettre de repérer un visiteur à quelques kilomètres près (avec son accord).
    
-   **Web Storage** : permet de stocker un grand nombre d'informations sur la machine du visiteur. C'est une alternative, plus puissante, aux traditionnels cookies. Les informations sont hiérarchisées, comme dans une base de données.
    
-   **AppCache** : permet de demander au navigateur de mettre en cache certains fichiers, qu'il ne cherchera alors plus à télécharger systématiquement. Très utile pour créer des applications web qui peuvent fonctionner même en mode « hors ligne » (déconnecté).
    
-   **Web Sockets** : permet des échanges plus rapides, en temps réel, entre le navigateur du visiteur et le serveur qui gère le site web (c'est une sorte d'AJAX amélioré). C'est un peu l'avenir des applications web, qui pourront devenir aussi réactives que les vrais programmes.
    
-   **WebGL** : permet d'introduire de la 3D dans les pages web, en utilisant le standard de la 3D OpenGL. Les scènes 3D sont directement gérées par la carte graphique.

La plupart de ces technologies utilisent JavaScript

### Les sites web dynamiques
Ces langages ne s'exécutent pas sur la machine de l'utilisateur mais sur le serveur du site

Les langages « côté serveur » sont nombreux. Citons-en quelques-uns :

-   **PHP** : l'un des plus connus. Facile à utiliser et puissant, il est utilisé notamment par Facebook… et OpenClassrooms. J'ai d'ailleurs rédigé un [cours sur PHP](https://openclassrooms.com/courses/concevez-votre-site-web-avec-php-et-mysql) que vous êtes nombreux à suivre après avoir appris HTML et CSS !
    
-   **Java EE** (Java) : très utilisé dans le monde professionnel, il s'agit d'une extension du langage Java qui permet de réaliser des sites web dynamiques, puissants et robustes. Au début, il est un peu plus complexe à prendre en main que PHP. J'ai créé un [cours vidéo sur Java EE](https://openclassrooms.com/courses/developpez-des-sites-web-avec-java-ee) et il existe un [cours texte sur Java EE](https://openclassrooms.com/courses/creez-votre-application-web-avec-java-ee) aussi.
    
-   **ASP .NET** (C#) : assez semblable à JEE, c'est le langage de Microsoft. On l'utilise en combinaison avec d'autres technologies Microsoft (Windows Server…). Il utilise le puissant framework .NET, véritable couteau suisse des développeurs, qui offre de nombreuses fonctionnalités.
    
-   **Django** (Python) : une extension du langage Python qui permet de réaliser rapidement et facilement des sites web dynamiques. Il est connu pour générer des interfaces d'administration prêtes à l'emploi. [Apprenez d'abord Python](https://openclassrooms.com/courses/apprenez-a-programmer-en-python), puis rendez-vous sur le [cours Django sur OpenClassrooms](https://openclassrooms.com/courses/developpez-votre-site-web-avec-le-framework-django) !
    
-   **Ruby on Rails** (Ruby) : une extension du langage Ruby, assez similaire à Django, qui permet de réaliser des sites web dynamiques facilement et avec une grande souplesse. Apprenez d'abord [Ruby](https://openclassrooms.com/courses/lancez-vous-dans-la-programmation-avec-ruby), puis découvrez [Ruby on Rails](https://openclassrooms.com/fr/courses/3149156-initiez-vous-a-ruby-on-rails) 

## Envoyer son site sur le web
### Réserver un nom de domaine
  
Pour réserver un nom de domaine, deux solutions :

-   passer par un **registrar** spécialisé. C'est un organisme qui sert d'intermédiaire entre l'ICANN (l'organisation qui gère l'ensemble des noms de domaine au niveau international) et vous. 1&1 IONOS, OVH et Gandi sont de célèbres registrars français ;
    
-   encore mieux : vous pouvez commander le nom de domaine en même temps que l'hébergement (c'est ce que je vous conseille). De cette manière, vous faites d'une pierre deux coups, vu que vous aurez de toute façon besoin de l'hébergement _et_ du nom de domaine.

### L'hébergeur
  
Les hébergeurs, contrairement aux registrars, sont très très nombreux. Il y en a de tous types, à tous les prix. Il y a un vocabulaire à connaître pour vous repérer dans leurs offres :

-   **hébergement mutualisé** : si vous optez pour une offre d'hébergement mutualisé, votre site sera placé sur un serveur gérant plusieurs sites à la fois (peut-être une centaine, peut-être plus). _C'est l'offre la moins chère et c'est celle que je vous recommande de viser_ si vous démarrez votre site web ;
    
-   **hébergement dédié virtuel** : cette fois, le serveur ne gère que très peu de sites (généralement moins d'une dizaine). Cette offre est généralement adaptée aux sites qui d'un côté ne peuvent plus tenir sur un hébergement mutualisé car ils ont trop de trafic (trop de visiteurs), mais qui par ailleurs ne peuvent pas se payer un hébergement dédié (voir ci-dessous) ;
    
-   **hébergement dédié** (on parle aussi de « serveur dédié ») : c'est le nec plus ultra. Le serveur gère uniquement votre site et aucun autre. Attention, cela coûte assez cher et il vaut mieux avoir des connaissances en Linux pour administrer le serveur à distance ;
    
-   **hébergement cloud** : de plus en plus en vogue, cela consiste à envoyer notre site sur des serveurs virtuels. En fait, c'est l'équivalent d'un hébergement dédié virtuel, mais avec tout un tas de services autour pour nous permettre de gérer plus facilement le réseau, les bases de données, etc. C'est la tendance pour de plus en plus de moyens et gros sites. Parmi les hébergeurs cloud, on peut citer Amazon Web Services, Google Cloud, Microsoft Azure, etc.  
  Ce type d'hébergement est en revanche un peu _trop complexe_ pour nous qui débutons dans la création de sites web. Je recommande plutôt un hébergement mutualisé, dans notre cas.

### Utiliser un client FTP
-> Permettent de transférer les fichiers sur Internet => par exemple [FileZilla](https://filezilla-project.org/download.php?type=client)

#### Configurer le client FTP
  
Quel que soit l'hébergeur que vous avez choisi, cela fonctionne toujours de la même manière. On va vous fournir _trois informations_ qui sont indispensables pour que FileZilla puisse se connecter au serveur :

-   **l'IP** : c'est « l'adresse » du serveur. Le plus souvent, on vous donnera une information du type `ftp.mon-site.com`  , mais il peut aussi s'agir d'une suite de nombres comme `122.65.203.27`  ;
    
-   **le login** : c'est votre identifiant, on vous a probablement demandé de le choisir. Vous avez peut-être mis votre pseudo, ou le nom de votre site. Mon login pourrait par exemple être `mateo21`  .
    
-   **le mot de passe** : soit on vous a demandé de choisir un mot de passe, soit (c'est plus probable) on vous en a attribué un d'office (un truc imprononçable du genre `crf45u7h`  ).
