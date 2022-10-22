---
tags : code
author : Conor Cauty
date : 2022-03-15 11:17
title: Métier de développeur
listings-no-page-break: true
disable-header-and-footer: true
geometry: "left=2cm,right=2cm,top=2cm,bottom=2cm"
output:
  pdf: 
    pandoc_args: ["--from=markdown+hard_line_breaks"]
    pdf-engine: xelatex
    output: Métier de développeur.pdf
    from: markdown
    template: eisvogel 
    listings: true
---

# Métier de développeur
[Source](https://openclassrooms.com/fr/courses/6817086-decouvrez-les-metiers-de-developpeur/)

> le développeur est une personne qui imagine, conçoit, teste, documente et maintient des applications, des sites Internet ou des logiciels.

## Overview

### Missions du développeur

1. Analyser et comprendre le besoin du client
2. Traduire ce besoin avec un langage de programmation
3. Réalisation de tests et publication du produit
4. Adapter le produit pour correspondre au mieux -> **itérer** le produit

![L'itération](Obsidian/Pasted%20image%2020220315112309.png)

### Responsabilités

Le développeur est responsable de :

-   assurer la **bonne collaboration** avec les autres spécialistes de son équipe qui peuvent être très proches, comme un designer ou un chef de projet, ou plus éloignés, comme un commercial, par exemple ;
    
-   **analyser** correctement les besoins des utilisateurs ;
    
-   **planifier** au maximum tous les détails avant de passer à la fameuse traduction ;
    
-   **créer** la solution adéquate aux besoins des utilisateurs et la faire fonctionner ;
    
-   **adapter** et perfectionner régulièrement l’expérience de l’utilisateur ;
    
-   assurer le **bon fonctionnement** du produit à chaque instant, même en période de maintenance (mise à jour).

==Attention, le développeur n'est pas :==

- un informaticien qui **répare** les ordinateurs $\ne$ technicien de maintenance
- un hacker
- ne fait pas uniquement des sites web

### Compréhension du besoin

Pour implémenter[^1] une solution, il faut exprimer le besoin : sous forme de **cahier des charges**, de **user story** ou de **backlog**.

-   Un cahier des charges permet au client d’indiquer au développeur ce qu’il attend de lui. C’est un **document contractuel** à respecter.
    
-   Une user story est une demande de fonctionnalité à réaliser, basée sur un **besoin utilisateur**.
    
-   Un backlog est une **liste, ordonnée** par priorité, de toutes les **fonctionnalités** d’un projet à réaliser par une équipe.


[^1]: **Implémenter** une solution revient à traduire une idée en un programme concret.

Parmi toutes les méthodes de **gestion de projet** en entreprise, la plupart des projets qui concernent un développeur utilisent les **méthodes agiles**[^2], dont une méthode plus particulière et très populaire actuellement : la **méthode Scrum**.

![Méthode SCRUM](Obsidian/Pasted%20image%2020220315112955.png)

[^2]: Les méthodes agiles sont des procédés de pilotage et d’action d’un projet. Elles reposent sur un travail incrémental et itératif impliquant le demandeur au maximum, permettant ainsi plus de souplesse sur un projet, et une réactivité sur les demandes.

-   chaque projet est découpé en plusieurs grandes phases appelées _**sprints**_ ;
    
-   chaque sprint est composé de plusieurs tâches à réaliser, aussi appelées _**issues**_ ;
    
-   chacun des développeurs du projet se voit assigner plusieurs **issues à résoudre** ;
    
-   tous les matins, lors d’une réunion appelée **_daily scrum_**, chaque développeur explique ce qu’il a fait la veille, ainsi que ses points bloquants, pour identifier rapidement chaque **retard ou problème** ;
    
-   toute la journée, le développeur jongle entre plusieurs tâches : répondre aux **e-mails**, venir en **aide** à un collègue, consulter **l’historique des opérations** (**logs**) pour trouver la source d’erreurs, **coder** et **tester** son code.

### Hard skills

#### Gestionnaire des versions

Le **gestionnaire de version**. Un gestionnaire de version sert principalement à :

-   garder un **historique** de modifications ;
    
-   **travailler en équipe** sur le même projet de développement ;
    
-   créer des branches de développement (**séparer chaque nouvelle fonctionnalité** de la version principale tant qu’elle n’est pas terminée).

![Git](Obsidian/Pasted%20image%2020220315113613.png)

#### Test de votre code – le “**testing**”

Le testing est une partie à ne pas négliger ! Il est indispensable de tester que votre solution effectue bien ce qu’il faut. On parle souvent de **tests “unitaires”**. Pour chaque fonctionnalité, définissez en quoi elle consiste, puis créez les tests associés.

Mieux vos tests sont définis, plus vous **réduisez** le nombre potentiel de **bugs** sur votre solution.

#### Clarté et lisibilité du code : "norming" ou "beautifying"
-   Un code “**sale**” peut devenir un réel **enfer à déchiffrer** et donc une **perte de temps** considérable.
    
-   Lorsque vous aurez besoin d’aide, la personne qui vous aidera n’aura pas de mal à comprendre votre code. Le contraire est également vrai.
    
-   Si un développeur doit travailler sur votre code, son **temps d’adaptation sera relativement court**. Le contraire est également vrai.
    
-   Si votre code est **propre** et **lisible**, c’est toute votre équipe qui vous remerciera.

#### Documentation et commentaires

Si le code est lisible, presque pas besoin de le documenter
Les commentaires sont généralement rédigés en anglais

## Corps de métiers
En général, équipe de développement constituée de :
-   un designer ;
    
-   un développeur front-end ;
    
-   un développeur back-end ;
    
-   un développeur mobile ;
    
-   un développeur full-stack ;
    
-   un chef de projet.

![équipe de développement logiciel typique](Obsidian/Pasted%20image%2020220315114405.png)

> Les **maquettes**, faites par le designer, permettent de représenter le site avant qu'il soit développé, afin que tout le monde sache vers quel rendu l'équipe doit aller.

Le designer a créé les **maquettes** avant que les sprints commencent. Le designer est présent en appui pour accompagner le **front-end** et le **développeur mobile**, qui s’occuperont de la partie site web et application.

Le **développeur back-end** est en charge de toute la partie qui ne sera pas visuelle, pour que le front-end et le mobile puissent avoir les bonnes informations au bon moment pour les afficher.

Le **full-stack** est là pour aider chacun des 3 développeurs en cas de besoin, et interviendra en cas de retard. Il s’occupe de l’architecture du projet et de la mise en production en bout de course.

Il y a donc 4 spécialités de développeurs :
- front-end
- back-end
- mobile
- full-stack

### Développeur front-end

Réalise les interactions et l'expérience d'un utilisateur sur une plateforme. C'est le pont entre les UI/UX designers et les développeurs back-end

![Exemple de partie front-end sans back-end](Obsidian/Pasted%20image%2020220315114911.png)

Il est à noter qu’il existe deux types de sites web. Les **sites web statiques** et les **sites web dynamiques**.

Un site web statique n’aura pas besoin d’un back-end pour fonctionner, car son contenu ne bougera pas.

#### Missions principales

-   transformer une **maquette en code** ;
    
-   faire fonctionner correctement sa plateforme sur n’importe quel appareil (ordinateur, tablettes et téléphones mobiles) ;
    
-   respecter les bonnes pratiques en **référencement web ou SEO**, pour être le plus haut possible dans les résultats de recherche Google, de manière naturelle ;
    
-   développer des fonctionnalités pour améliorer l’**expérience de l’utilisateur** sur le site web ;
    
-   optimiser des pages web pour une **rapidité maximale** ;
    
-   **tester** sa plateforme et réparer les **bugs**.

#### Compétences

Maitrise des 3 langages de programmation compris par le navigateur :

- HTML -> langage standard
- CSS -> mise en page du site
- JavaScript -> permet d'ajouter de l'**interaction**

Le développeur front-end doit absolument maîtriser certains frameworks et **bibliothèques** [^3]

[^3]: Une **bibliothèque**, ou **_library_**, est un ensemble d’extensions et de programmes prêts à l’emploi pour faciliter la réalisation de fonctionnalités répétitives et routinières. Elles sont enregistrées dans votre code.

Un **framework**, ou _infrastructure logicielle_, regroupe un ensemble de composants permettant de créer les fondations ainsi que les grandes lignes d’un logiciel/site web/application mobile.

##### La bibliothèque jQuery

jQuery est une **library JavaScript**. Elle rassemble des extensions et des programmes prêts à l’emploi, pour rendre le développement JavaScript plus rapide et plus simple.

Au lieu d’avoir à tout écrire depuis zéro, vous pourrez utiliser les éléments contenus dans la librairie jQuery, puis les personnaliser à votre convenance avec du JavaScript. D’où l’importance du JS.

##### Un framework JavaScript comme AngularJS, ReactJS ou VueJS

Les frameworks JS offrent une **structure prête à l’emploi** pour votre code JavaScript.

Il existe plusieurs types de frameworks JS en fonction de vos besoins, de vos préférences ou de ceux que votre entreprise utilise. Les 3 mentionnés sont les plus connus. Ils vous offrent une **rapidité et un confort** de développement. Ils peuvent être utilisés avec jQuery pour minimiser au maximum le code que vous devrez écrire depuis zéro.

##### Un framework CSS comme Bootstrap, Materialize ou Semantic UI

Les frameworks CSS servent également de fondation à votre code, mais pour la partie CSS (souvenez-vous, celle qui permet d’ajouter du style à votre page HTML). Ils sont très utilisés et permettent de travailler plus rapidement vos visuels.

![Frameworks vs bibliothèques](Obsidian/Pasted%20image%2020220317160815.png)

**Bootstrap** est un des framework les plus connus. Grâce à Bootstrap, tous vos éléments CSS seront **déjà construits** ; comme vos boutons, cartes, barres latérales, popups, etc. Vous n’aurez plus qu’à les personnaliser grâce à du CSS additionnel.

L’utilisation d’un framework CSS est **fortement recommandée**. Elle vous permettra de respecter tous les classiques actuels en design et architecture de page responsive. Le tout sans avoir à tout réécrire depuis zéro !

### Développeur mobile

Seule différence avec le développeur front-end -> travaille sur des applications et pas sur un site vu par un navigateur

![Application mobile sans la partie back-end](Obsidian/Pasted%20image%2020220317161030.png)

#### Missions

-   rendre agréable l’**expérience de l’utilisateur sur l’application** ;
    
-   veiller à ce que les applications anciennes et nouvelles répondent aux **normes de qualité** ;
    
-   respecter les règles imposées par les **magasins d’applications**. Il en est entièrement dépendant, contre quoi son application pourrait ne jamais voir le jour ;
    
-   faire fonctionner correctement son application ;
    
-   prendre en compte tous les **avis des utilisateurs** ;
    
-   **tester** son application, réparer les **bugs** et la **mettre à jour**.

#### Compétences 

Iels doivent avoir des bases en HTML, CSS et JavaScript mais pas que !
Il existe 2 types de devs mobile :

- natif
- hybride

Les devs **natifs** utilisent les langages proposés nativement par les créateur.ices du système d'exploitation.

- sur Android : Java
- sur iOS : Swift et Objective-C

Les devs **hybrides** utilisent des outils qui permettent de créer 1 seule fois l'application, pour ensuite la dupliquer sur plusieurs OS. Le framework **React Native** est un exemple à utiliser, il est tiré du langage JavaScript et offre comme résultat une véritable application native.

Les technologies hybrides seront toujours **moins performantes** que des technologies natives, et ne correspondent qu’à des besoins simples, mais permettent un réel gain de temps de développement.

#### Les langages de programmation du développeur mobile

Ces dernières années, les smartphones ont pris une **très grosse ampleur**, modifiant la façon dont les entreprises fonctionnent dans le monde entier.

Pour réaliser une application mobile, il faut savoir sur quelle plateforme vous souhaitez la construire. Ce choix définira le langage de programmation que vous utiliserez, en gardant à l’esprit les avantages et inconvénients d’une application **hybride ou native**.

##### Ionic

Ionic est **un des frameworks les plus réputés** dans la réalisation **d’applications hybrides**. Le framework ne contient que des composants HTML, CSS et JS favorisant la construction d’applications mobiles interactives. 

##### Objective-C

Objective-C est le langage de programmation principal pour les applications iOS. Construit sur un ensemble de langage C pour un résultat plus robuste et évolutif, **il est présent dans toutes les applications Apple**.  
Aujourd’hui, il est de plus en plus remplacé par un langage plus puissant, le Swift.

##### Swift

Si Objective-C est le langage de programmation principal d’Apple, Swift est **le dernier à être apparu sur iOS**.

Objective-C est une base, mais aujourd’hui de plus en plus de développeurs se sont tournés vers Swift pour réaliser des applications mobiles de pointe sur iOS, tout en réduisant le nombre de vulnérabilités de sécurité possibles avec Objective-C.

##### Java

Le langage Java est le langage le plus utilisé pour le développement d’**applications Android**. Il peut aussi bien être exécuté sur un navigateur qu’en tant qu’application mobile.

Plus de **3 milliards d’appareils** numériques à travers le monde utilisent Java. Ce qui fait de lui un des langages de programmation les **plus populaires**.

##### React Native

React Native est un framework **créé par Facebook**, tout comme ReactJS. Il a été créé pour construire des applications d’une façon native, comme si vous utilisiez **Swift ou Java**.

Vous ne pourrez pas différencier une application React Native d’une application Swift ou Java. Contrairement à une application créée via Ionic, par exemple.

Cela est possible car React Native utilise les **mêmes composants** que ceux disponibles pour iOS et Android. La seule différence, c’est que vous utilisez du JavaScript !

### Développeur back-end

 Il traite toutes les informations présentes sur une plateforme.

Le back-end est en relation directe avec les développeurs front-end et mobile afin de :

-   **recevoir** et **traiter** les informations dont le développeur front-end ou mobile a besoin ;
    
-   stocker ces informations dans une **base de données** ;
    
-   envoyer toutes les informations dont les développeurs front-end ou mobile ont besoin.

#### Missions

Correspond au développement côté serveur, qui communique avec la base de données.

Le back-end est donc responsable de :

-   analyser des données et échanger avec une base de données (insérer, modifier, récupérer ou supprimer des données ) ;
    
-   collaborer avec les développeurs front-end et mobile pour concevoir les codes les plus cohérents pour l’expérience de l’utilisateur ;
    
-   établir la bonne communication entre les développeurs front-end et mobile, et la base de données  ;
    

Le développeur back-end représente le **cœur d’un projet**. Sans lui, aucune donnée ne transite. Il permet la **bonne communication** entre le front-end et la base de données.


#### Compétences

Encore une fois, le HTML, le CSS et le JavaScript sont une base à avoir, mais le développeur back-end doit avant tout avoir une **bonne logique**, une bonne connaissance des bases de données et d’au moins un langage back-end comme le Python, Node.js, Ruby...

Il doit savoir comment **architecturer un projet**, comprendre comment les serveurs fonctionnent (évidemment), et surtout comment les **monitorer**[^4].

[^4]:Monitorer un serveur, c’est **être capable de le gérer**. Poser des petits repères partout pour avoir une vue d’ensemble, et ainsi savoir exactement **où regarder en cas de problème**.

Il existe plusieurs manières de créer un back-end, dont l'une des plus réputée actuellement est l'API (= Application Programming Interface)

##### Construire une API

API = messager -> récupère une requête, la traite et envoie une réponse

Par exemple l'API de Google quand on a un bouton `Se connecter avec Google`, ou pour intégrer une fonctionnalité de paiement sur un site -> utiliser l'API de **Stripe**

![exemple api de google](Obsidian/Pasted%20image%2020220317163005.png)

##### _PHP_

Le **PHP**, ou “Hypertext Preprocessor”, auparavant “Personal Home Page”, est un langage utilisé côté serveur. Il est très populaire et est utilisé par les plus grands, comme WordPress ou Facebook.

PHP est cependant un langage assez vieux. Il reste un des **précurseurs du back-end**, mais n’est plus conseillé pour construire des projets complexes.

PHP dispose cependant d’un framework très utilisé en ce moment, appelé **Symfony**. Celui-ci permet d’utiliser tous les avantages liés à PHP, d’une façon plus optimisée par rapport aux besoins d’aujourd’hui.

##### _JavaScript_


JavaScript est **un langage front-end que back-end**.

**Node.js** est le principal framework utilisé pour réaliser un back-end en JavaScript. Il est très rapide et vous permet de gérer simultanément plein d’actions différentes, contrairement au PHP qui les réalisera une par une.

JavaScript est donc un langage indispensable à connaître aujourd’hui.

##### _Java_

**À différencier de JavaScript** qui est un langage totalement différent, Java est un langage de programmation général. Il n’est pas seulement réservé au monde du web. Java est un langage assez simple et basique, une fois que vous avez compris le concept de la **programmation orientée objet**[^5].

[^5]:La **programmation orientée objet**, ou **_POO_**, permet de modéliser son application sous la forme d’interactions entre objets. Les objets ont des propriétés et peuvent faire des actions. _Un objet, en programmation, peut être considéré comme un objet du monde réel, mais qui ne se limite pas qu’au matériel_. 

##### _Python_

Si Python est le langage phare en termes d’analyse de données, de machine learning, d'intelligence artificielle… à l’exception du front-end, il est comme le JavaScript très présent. Python est un langage de programmation “**haut niveau**”, indépendant de chaque plateforme, orienté objet et relativement simple à apprendre, grâce à une syntaxe proche de notre langage.

Python est principalement utilisé en back-end grâce à son framework **Django ou Flask**.

#### Langages de base de données

Le développeur doit absolument connaître au moins un **langage de base de données** pour communiquer avec cette dernière. Ces langages permettent d’écrire et manipuler les données d’une base de données.

Il est à noter que désormais, tous les développeurs back-end utilisent des **ORM** (carte relationnelle d’objets). Un ORM a l’avantage de **faciliter l’écriture de vos requêtes** vers la base de données. Il vous permet d’écrire plus simplement des requêtes plus complexes dans votre langage de programmation préféré.

_Il est néanmoins indispensable de connaître comment fonctionnent les requêtes standard, comme les requêtes_ _SQL ou NoSQL._

### Développeur full-stack

Le full-stack maîtrise tout son environnement. Il est en relation directe avec le designer et le chef de projet :

-   il travaille avec le chef de projet pour bien comprendre le besoin et découper les tâches ;
    
-   le designer imagine un résultat final pour que le full-stack l’intègre ;
    
-   Le full-stack s’occupe du reste.

#### Missions

Le développeur full-stack **peut être spécialisé** dans un langage front-end, back-end ou mobile, mais il a appris un ou plusieurs autres langages complémentaires qui lui permettent d’être **entièrement autonome** dans la réalisation d’un projet. 

Il connaît les parties serveur et client, et est capable de créer les interfaces visuelles, tout comme la gestion et l’analyse de données qu’il y a derrière. Il peut créer un prototype rapidement, aider tous les membres de l’équipe, réduire le coût d’un projet et réduire les échanges car **il gère toutes les “stacks” de son projet**.

Le full-stack a également tendance à connaître à la fois la **logique commerciale** et l’**expérience des utilisateurs**, ce qui signifie qu’en plus d’être à même de réaliser tout ou partie d’un projet, il peut guider la stratégie d’une entreprise.

_Le full-stack est libre de travailler sur le front-end, le back-end, l’analyse de données, l’architecture d’un projet, les choix techniques et même les phases de réflexion autour du projet avec un client._

#### Compétences

Le full-stack est compétent en HTML, CSS et JavaScript. L’avantage du JavaScript, c’est surtout qu’il dispose d’au moins **un framework dans chaque spécialité** (back-end, front-end, mobile).

Le full-stack doit maîtriser au moins **un framework front-end et back-end**. Il doit savoir construire une base de données et interagir avec, et connaître les bonnes pratiques en sécurité, tout comme en design et expérience utilisateur.

Sa connaissance en **gestion de projet** et en **design** seront un grand plus pour compléter les “**stacks**” déjà acquises. 

S'il travaille seul, le full-stack sera chargé de réaliser le site web dans son **intégralité**, de la phase de réflexion sur le projet jusqu’à la mise en production, en passant par les tests, la gestion du projet et la sécurité. S'il travaille en équipe, il pourra se plonger sur **n’importe quelle fonctionnalité** en cas de besoin.

#### Langages de programmation

-   Le HTML, CSS et JavaScript.
    

Ce sont les **langages fondamentaux** du web.  Aucun développeur web ne peut s’en passer. Encore moins le full-stack !

-   Un ou plusieurs frameworks front-end, comme React.js, Angular.js ou Vue.js.
    

Il doit connaître **au moins un framework front-end** pour être à l’aise et répondre à la demande des entreprises sur le marché.

-   Un ou plusieurs frameworks CSS, comme Bootstrap.
    

Pour construire des designs plus rapidement, il doit maîtriser au moins un framework CSS. Nous citons Bootstrap, mais il en existe d’autres, comme Materialize ou Semantic UI. En plus de permettre un développement **plus simple et rapide**, ils garantissent un **respect des normes** en termes de design et de **responsive**.

-   Un ou plusieurs langages de programmation back-end comme Ruby, PHP, Python.
    

Comme nous l’avons vu, il n’est pas que front-end. Il est full-stack ! Pour compléter ses stacks, il doit donc maîtriser **un langage back-end**.

-   Un ou plusieurs frameworks back-end comme Ruby on Rails, Node.js, Python Django ou PHP Symfony.
    

Il est aujourd’hui impensable de ne pas s’appuyer sur ces structures de codes très solides.

-   Une connaissance en base de données SQL et NoSQL, ainsi que l’ORM associé à son framework back-end.
    

Qui dit back-end dit **base de données** ! Le back-end permettant de communiquer avec une base de données, le full-stack doit être **capable de créer ses interfaces visuelles et de les dynamiser**. 

-   Une connaissance des bonnes pratiques à mettre en place en termes de sécurité.

S'il est le seul développeur, et dans la plupart des cas, il doit **sécuriser** sa plateforme ! Faire attention aux utilisateurs **malveillants** qui chercheraient à soutirer les informations personnelles des autres utilisateurs, ou simplement casser notre belle plateforme.

-   Une connaissance de la méthode Scrum et des pratiques de base en termes de gestion de projet.
    

Un stack de plus ne serait pas de refus ! Un vrai full-stack est capable de se **gérer lui-même et surtout les autres**.

-   Une connaissance des bonnes pratiques en design d’expérience utilisateur et d’interfaces utilisateurs.
    

Pour compléter tout son arbre de connaissances : pourquoi ne pas avoir de bonnes bases en design ? Lui permettant de mieux **comprendre les enjeux des utilisateurs** finaux pour penser sa plateforme en fonction de ces derniers.


## Plateformes pour apprendre à coder
- CodinGame
- CheckiO
- HackerRank