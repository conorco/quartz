---
tags : code
author : Conor Cauty
date : 2022-04-01 15:15
title: CSS avec Sass
listings-no-page-break: true
disable-header-and-footer: true
geometry: "left=2cm,right=2cm,top=2cm,bottom=2cm"
output:
  pdf: 
    pandoc_args: ["--from=markdown+hard_line_breaks"]
    pdf-engine: xelatex
    output: CSS avec Sass.pdf
    from: markdown
    template: eisvogel 
    listings: true
---
[source](https://openclassrooms.com/fr/courses/6106181-simplifiez-vous-le-css-avec-sass/6595695-structurez-votre-css)
# CSS avec Sass
Le but est d'apprendre comment écrire du CSS qui est à la fois mieux **organisé et surtout maintenable**, en :

-   appliquant des **structures de fichiers** clairement définies ;
-   travaillant avec un **préprocesseur CSS** appelé **Sass**, une technologie qui améliore votre codebase et vous simplifie la vie.

## Principe du DRY
DRY = Don't repeat yourself
Donc la première étape est de trouver des points communs dans le code CSS : 
![](Obsidian/Pasted%20image%2020220401152131.png)

Les couches de règles CSS répétées, empêchent de créer un code DRY, ce qui le rend plus difficile à maintenir et complique sa modification

La première étape clé consiste à faire un **refactoring** ; en d’autres termes, effectuez un grand ménage dans votre code pour éviter les répétitions. Rappelez-vous : “**Ne vous répétez pas !**”. Commençons par passer en revue tous vos sélecteurs pour trouver des points communs. Prenons l’exemple d’un bouton. Il faut regarder tous les boutons décrits dans le code et noter quelles règles sont identiques. Disons que vous remarquez que tous vos boutons ont la même couleur de fond, la même couleur et le même padding. Au lieu de placer tous ces attributs dans chacun de vos boutons, vous allez les réunir au même endroit et éviter de vous répéter. Vous obtiendrez quelque chose qui ressemble à :

```css
.btn {
  background-color: #001534;
  color: #15DEA5;
  padding: 1.5rem;
}
```

Et si on veut un bouton plus large, ou plus arrondi, on peut faire des **règles additionnelle** :
```css
.btn-wide {
  width: 100%;
}

/* And... */
.btn-rounded {
  border-radius: 3rem;
}
```

Et on va aussi modifier le HTML :
```html
<!-- on passse de : -->
< button class="btn" >...</button>
<!-- à un markup comme ceci -->
< button class="btn btn-rounded btn-wide" >...</button>
```

Cela s'appelle :  _**separation of concerns**_ (ou _séparation des préoccupations_). L’idée est que votre HTML ne contient que les informations nécessaires à son contenu. Ainsi, toutes vos règles de style sont définies dans votre fichier CSS et sont réutilisables. Fini le CSS en dur dans le HTML ! Dans notre exemple de bouton .btn, nous avons défini l’apparence de nos boutons et rien de plus.

## La spécificité dans la structure du code
_**La spécificité**_ _est la manière dont le navigateur décide quelle règle s’applique si plusieurs règles ont des sélecteurs différents, mais peuvent quand même s’appliquer au même élément._

Par exemple, si on a :
```html
<div id="submit-button" class="button">Click Here!</div>
```

En que dans le fichier CSS, on a 2 couleurs différentes pour `#subit-button` et `.button` :
```css
#submit-button {
  background-color: #15DEA5;
}

.button {
  background-color: #DB464B;
}
```

Comment le navigateur va choisir la couleur qui prime sur l'autre ?
=> le navigateur appliquera la règle émanant du sélecteur **le plus spécifique**.

### Règles de spécificité
Il y a 4 catégories de règles CSS :
1. Le style *inline*, défini directement dans le HTML : `style="background-color:#15DEA5;`
2. Les *id* : sont uniques et s'appliquent à un objet unique
3. Les *classes, pseudoclasses et attributs*
   Les pseudoclasses sont `:hover` par exemple, les attributs permettent de sélectionner un sélecteur précis
4. Les éléments et pseudoéléments
   Par exemple les `div`

L'ordre de spécificité est celui indiqué au-dessus.
Le navigateur va procéder en comptant les éléments sous la forme d'un tableau.
Par exemple, pour une `div` :

| Inline | ID  | Class | Element |
| ------ | --- | ----- | ------- |
| 0      | 0   | 0     | 1       |

Une fois cette comptabilisation effectuée, le navigateur commence par regarder les scores des sélecteurs dans la **colonne de gauche**, parce que **le CSS local (dans le HTML, inline) est plus spécifique**. S’il y trouve un sélecteur avec un score plus élevé que les autres dans la première colonne, le navigateur appliquera son style en priorité. En cas d’égalité, il passe à la colonne suivante et effectue la même opération.

Peu importe qu’un sélecteur ait deux classes ou 200, un sélecteur id sera toujours plus spécifique qu’une classe.

En cas d'égalité, par exemple avec 2 classes contradictoires, le navigateur sélectionne le **dernier sélecteur** à avoir été déclaré