---
tags : code
author : Conor Cauty
date : 2022-03-26 17:14
title: Git et GitHub
listings-no-page-break: true
disable-header-and-footer: true
geometry: "left=2cm,right=2cm,top=2cm,bottom=2cm"
output:
  pdf: 
    pandoc_args: ["--from=markdown+hard_line_breaks"]
    pdf-engine: xelatex
    output: Git et GitHub.pdf
    from: markdown
    template: eisvogel 
    listings: true
---

[source](https://openclassrooms.com/fr/courses/7162856-gerez-du-code-avec-git-et-github/7166041-tirez-le-maximum-de-ce-cours)
# Git et GitHub
Sous Windows -> utiliser **Git bash**
Sous Linux -> utiliser le terminal

## Créer un dépôt local
Se placer dans le dossier contenant le dossier créé

```bash
cd Documents/code/project
```

Dans git bash, lancer la commande 

```bash
git init
```

## Fonctionnement de Git
![](Obsidian/Pasted%20image%2020220327161144.png)
### Working directory
Dossier du projet **sur l'ordinateur**

### Stage / index
Tous les fichier modifiés que l'on souhaite voir apparaître dans la prochaine version du code

### Repository
Zone de stockage des nouvelles versions d'un projet
  
Prenons un exemple pour y voir plus clair !

Imaginez un projet composé de 3 fichiers : fichier1, fichier2 et fichier3.

Nous faisons une modification sur fichier1, puis une modification sur fichier2, depuis le working directory. Super ! Nous avons maintenant une version évoluée de notre projet.

Nous aimerions sauvegarder cette version grâce à Git, c'est-à-dire la stocker dans le repository.

Pour pour faire cela, nous allons envoyer les fichiers modifiés (fichier1 et fichier2) du working directory vers l’index. **On dit qu’on va indexer** fichier1 et fichier2. Une fois les fichiers indexés, nous pouvons créer une nouvelle version de notre projet.

## Créer des fichiers
1. Créer des fichiers dans le dossier initialisé avec `git init`
2. Indexer les fichiers avec 

```bash
git add fichier1 fichier2 etc
```

3. Créer une nouvelle version avec `git commit`

```bash
git commit -m "Ajout des fichiers fichier1 et fichier2"
```

>  "-m" permet de définir un message particulier rattaché au commit effectué. Si vous n’utilisez pas cet argument, la commande “git commit” ouvrira un éditeur de texte dans lequel vous pourrez saisir le message de commit.

4. Envoyer les commit sur le dépôt distant avec `git push`
Pour cela, il faut d'abord ajouter le dépôt distant avec :
```bash
git remote add "https://github.com/lien.git"
#les "" au cas où ça bug avec le copié coller et qu'il y a : fatal error 'https' not supported
git branch -M main
```

Et ensuite on peut utiliser :
```bash
git push -u origin main
```

Donc, pour ajouter un fichier à un dépôt distant déjà ajouté :
```bash
git add fichier #indexe le fichier
git commit -m "message" #créé une nouvelle version
git push origin main #envoie la nouvelle version sur le dépôt distant
```

## Le système de branches
Les différentes branches correspondent à des copies de votre code principal à un instant T, où vous pourrez tester toutes vos idées les plus folles sans que cela impacte votre code principal.

Sous Git, la branche principale est appelée **branche main** ou **master** (pour les dépôts créés avant octobre 2020)

La branche **main** portera l'intégralité des modifications effectuées. Le but est donc de réaliser les modifications sur d'autres branches, et après divers tests, de les intégrer sur la branche principale.

![Exemple|400](Obsidian/Pasted%20image%2020220327165659.png)
Git va créer une branche virtuelle, mémoriser tous vos changements, et seulement quand vous le souhaitez, les ajouter à votre application principale. Il va vérifier s'il n’y a pas de conflits avec d’autres fusions, et hop, le tour est joué !

Pour connaître les branches présentes sur le projet :
```bash
git branch
#qui retourne 
* main # l'étoile signifie que c'est la branche sur laquelle on se trouve
```

Il est conseillé de créer une branche par fonctionnalité. On peut créer une branche avec la commande :

```bash
git branch nomdelabranche
```

Pour basculer sur une autre branche :

```bash
git checkout nomdelabranche
```

Pour réaliser un push, on utilise la commande `git commit` :
```bash
git commit origin nomdelabranche
```

### Fusionner une branche
Il faut d'abord se mettre dans la branche dans laquelle nous voulons apporter des modifications :
```bash
git checkout main
```

On utilise ensuite la commande `merge` :
```bash
git merge cagnotte
```

## Travailler avec un dépôt distant
1. Récupérer l'URL du dépôt distant :
![](Obsidian/Pasted%20image%2020220329134751.png)
2. taper la commande :
```bash
git clone https://github.com/conorco/conorcausite.git
```

3. Pour créer un raccourci, ici `site`, utiliser la commande :
```bash
git remote add site https://github.com/conorco/conorcausite.git
```

4. Pour récupérer les modifications sur la branche main :
```bash
git pull site main
```

## Collaborer sur GitHub
- Vérifier si des nouvelles fonctionnalités sont en cours `git branch`
=> généralement, le merge sur la branche main est bloqué

### Pull request
Une **pull request**, ou _demande de pull_, en français, est une fonctionnalité de GitHub qui permet de demander aux propriétaires d’un repository l’autorisation de fusionner nos changements sur la branche principale ou toute autre branche sur laquelle on souhaite apporter nos modifications.

On peut voir sur l'interface GitHub que lorsqu'une branche est créé, on a un bandeau :
![](Obsidian/Pasted%20image%2020220329135714.png)

On peut donc faire une demande de *pull request* :

![](Obsidian/Pasted%20image%2020220329135818.png)

### Demande de relecture
  
Sur des projets d’envergure, il peut arriver que votre code ne puisse être fusionné sur la branche principale sans être relu et validé par d’autres membres du projet. C’est ce qu’on appelle une _Code Review_, ou _revue de code_, en français. Cela permet de prévenir les erreurs éventuelles, de discuter sur un choix, une prise de position ou même de poser des questions.

## Commandes sous git en cas d'erreurs 
### Supprimer une branche
```bash
git branch -D nom de la branche
```
### Annuler une modification sur la branche principale et la basculer sur une autre branche
- Voir l'état du dépôt (fichiers indexés etc) : `git status`
- Créer un stash : `git stash` (il n'y a plus rien à commit, à vérifier avec `git status`)
- Créer une nouvelle branche `brancheCommit`
- Basculer sur la nouvelle branche : `git checkout brancheCommit`
- Appliquer le stash pour récupérer et appliquer les modifications sur la nouvelle branche : `git stash apply`

Pour appliquer un autre stash, regarder la liste des stash : `git stash list` :
![](Obsidian/Pasted%20image%2020220329145006.png)
Et appliquer le stash avec le bon identifiant : 
```bash
git stash appli stash@{0}
```

### Annuler une modification de branche après avoir fait un commit
Pour réparer cette erreur :
- Analyser les derniers commits avec `git log`, noter l'identifiant du commit en question (seuls les 8 premiers caractères sont nécessaires)
- Exécuter : `git reset --hard HEAD^` 
HEAD correspond au dernier commit à supprimer
- Créer une nouvelle branche `git branch truc`, et basculer `git checkout truc`
- Renouveler la commande : `git reset --hard 8premiers_caractères_id`

### Modifier le message d'un commit
ne fonctionne que pour le dernier commit réalisé.

`git commit --amend -m "nouveau message"`

### Ajouter un fichier oublié dans un commit
1. ajouter le fichier : `git add fichier_oublie`
2. utiliser `git commit --amend --no-edit`

La commande `--no-edit` permet de ne pas modifier le message du commit

### Annuler un push
Annuler un commit public avec `git revert` :
```bash
git revert HEAD^
```

Cette commande n'a donc **aucun impact sur l'historique** ! Par conséquent, il vaut mieux utiliser `git revert` pour annuler des changements apportés à une branche publique, et `git reset` pour faire de même, mais sur une branche privée.

`git revert` sert à annuler des changements commités, tandis que `git reset HEAD`  permet d'annuler des changements non commités.

### Ajout du mauvais fichier au commit
La commande **git revert** vous permet de revenir à l'état précédent, tout en faisant un deuxième commit.  Au lieu de supprimer le commit de l'historique du projet, elle détermine comment **annuler les changements** introduits par le commit et ajoute un nouveau commit avec le contenu ainsi obtenu. Vous allez donc revenir à l'état précédent mais avec un nouveau commit. Ainsi, Git ne perd pas l'historique, lequel est important pour l'intégrité de votre historique de révision et pour une collaboration fiable.

> Quelle est la différence entre git reset et git revert ?

`git reset`  va revenir à l'état précédent sans créer un nouveau commit, alors que  `git revert`  va créer un nouveau commit.

![](Obsidian/Pasted%20image%2020220329152707.png)

## Problèmes avec le dépôt distant
### Accès à distance ne fonctionne pas
Si votre accès à distance ne fonctionne pas, cela peut être dû à un problème d’authentification de votre réseau. Pour le résoudre, il vous faut créer une paire de **clés SSH**.

Pour obtenir la clé SSH :
`ssh-keygen -t rsa -b 4096 -C "cauty@protonmail.com"`

- `id_rsa` est la **clé privée**
- `id_rsa.pub` est la **clé publique**

On peut copier la clé publique, et ensuite aller sur GitHub
Dans les Paramètres, aller dans **SSH and GPG keys**
On peut ensuite ajouter une clé : ![](Obsidian/Pasted%20image%2020220329150753.png)
## Utiliser git reset
git reset permet de revenir en arrière, par exemple si on voulait une fonctionnalité et que finalement on ne la veut plus.

Il y 3 type de réinitialisation de Git : ![](Obsidian/Pasted%20image%2020220329150902.png)
### reset --hard
==Attention à bien être sûr de ce qu'on fait avant de lancer cette commande==

```bash
git reset commitCible --hard
```

  
Cette commande permet de **revenir à n'importe quel commit** mais en oubliant absolument tout ce qu'il s'est passé après ! Quand je dis tout, c'est TOUT ! Que vous ayez fait des modifications après ou d'autres commits, tout sera effacé ! C'est pourquoi il est extrêmement important de revérifier plusieurs fois avant de la lancer, vous pourriez perdre toutes vos modifications si elle est mal faite.

Cette utilisation de    `git reset`  constitue une manière simple d'annuler des changements qui n'ont pas encore été partagés. Cette commande est incontournable lorsque vous commencez à travailler sur une fonctionnalité, que vous vous êtes trompé et que vous voulez recommencer de zéro.

### reset --mixed
Le    `git reset --mixed`  va permettre de revenir juste après votre dernier commit ou le commit spécifié, sans supprimer vos modifications en cours. Il permet aussi, dans le cas de fichiers indexés mais pas encore commités, de désindexer les fichiers.

git reset HEAD~

Si rien n'est spécifié après    `git reset`  , par défaut il exécutera un    `git reset --mixed HEAD~`  .

> Le **HEAD** est un pointeur, une référence sur votre position actuelle dans votre répertoire de travail Git. 

C’est un peu comme votre ombre : elle vous suit où que vous alliez ! Par défaut, HEAD pointe sur la branche courante, main/master, et peut être déplacé vers une autre branche ou un autre commit.

### reset --soft
Cette commande permet de se placer sur un commit spécifique afin de voir le code à un instant donné, ou de créer une branche partant d'un ancien commit. Elle ne supprime aucun fichier, aucun commit, et ne crée pas de HEAD détaché.

## Résoudre des conflits en cas de merge
  
Vous avez modifié du code pour afficher le message "Une super cagnotte !" alors qu'était déjà en place le message "Une cagnotte". Lorsque vous allez fusionner les deux branches, les choses ne vont donc pas très bien se passer :

```
git checkout main git merge ameliorationCagnotte Auto-merging cagnotte.php CONFLICT
 (content): merge conflict in cagnotte.php Automatic merge failed; fix conflicts and
 then commit the result
 ```

Git va voir que sur la même ligne on essaie de fusionner deux choses différentes. Il ne va pas pouvoir deviner laquelle prendre, la ligne "Une cagnotte", ou bien "Une super cagnotte !" ? Il est fort mais pas devin ! 
Git va donc afficher un conflit sur le fichier cagnotte.php et arrêtera le processus de fusion ou merge. Ce conflit, vous allez devoir le résoudre en ouvrant le fichier avec votre éditeur habituel :

```
<<<<<<< HEAD Une cagnotte ======= Une super cagnotte ! >>>>>>> ameliorationCagnotte
```

Maintenant, réglez les conflits en comparant les deux lignes et en choisissant quelle modification vous voulez garder. Ici, il faut garder "Une super cagnotte !", on va donc supprimer les autres lignes et ne garder que celle-ci :

Une super cagnotte !

Maintenant que vous avez résolu le conflit, il vous reste à le dire à Git !

```bash
git add cagnotte.php git commit
```

Git va détecter que vous avez résolu les conflits et va vous proposer un message de commit. Vous pouvez bien entendu le modifier.

## Corriger un commit raté
### git reflog
La journalisation, ou _history_, en anglais, désigne l'enregistrement dans un **fichier** ou une **base de données*** de tous les événements affectant une application. Le **journal** (en anglais _log file_ ou plus simplement _log_), désigne alors le fichier contenant ces enregistrements.

L'objectif d'un gestionnaire de versions est d'enregistrer les changements apportés à votre code. Il vous permet de **consulter l'historique de votre projet** pour :

-   savoir qui a contribué à quoi ;
    
-   déterminer où des bugs ont été introduits ;
    
-   annuler les changements problématiques.

Pour gérer l'historique d'un projet, on peut utiliser la commande : `git log`

 Par défaut, `git log` **énumère en ordre chronologique inversé** les commits réalisés. Cela signifie que les commits les plus récents apparaissent en premier. Cette commande affiche chaque commit avec son **identifiant SHA**[^1], l'auteur du commit, la date et le message du commit.

[^1]:Le SHA ou _Secure Hash Algorithm_ est un identifiant. C'est ce grand code incompréhensible qui nous permettra de revenir en arrière si besoin, à un commit exact.

Il existe un outil encore plus puissant : `git reflog`

`git reflog`  va loguer les commits ainsi que toutes les autres actions que vous avez pu faire en local : vos modifications de messages, vos merges, vos resets, enfin tout, quoi  !

Comme    `git log`   ,   `git reflog`  affiche un identifiant SHA-1 pour chaque action. Il est donc très facile de revenir à une action donnée grâce au SHA. Cette commande, c'est votre joker, elle assure votre survie en cas d'erreur. Pour revenir à une action donnée, on prend les 8 premiers caractères de son SHA et on fait :

```bash
git checkout e789e7c
```

### git blame
  
La commande `git blame`  permet **d’examiner le contenu d’un fichier ligne par ligne** et de déterminer la date à laquelle chaque ligne a été modifiée, et le nom de l’auteur des modifications !

`git blame`  va afficher pour chaque ligne modifiée :

-   son ID ;
    
-   l'auteur ;
    
-   l'horodatage ;
    
-   le numéro de la ligne ;
    
-   le contenu de la ligne.
    

Avec   `git blame`  , vous devenez un super espion de votre projet !

### git cherry-pick

Parfois, vous ne voulez pas fusionner une branche entière dans une autre et vous n'avez besoin que de choisir un ou deux commits spécifiques. Ce processus s'appelle **cherry-pick** ! 

> `git cherry-pick`  n'est pas une commande très appréciée dans la communauté des développeurs car elle duplique **des commits existants**. Je vous conseille plutôt de réaliser un merge.

Admettons que vous travailliez sur une branche "Mes évolutions", et que vous ayez déjà réalisé plusieurs commits. Votre collègue a besoin de l'une de ces évolutions pour la livrer au client, mais pas des autres. C'est dans ce cas bien précis que nous allons faire appel à    `git cherry-pick`  ! Cette commande va permettre de sélectionner un ou plusieurs commits grâce à leur SHA (décidément ils sont partout) et de les migrer sur la branche principale, sans pour autant fusionner toute la branche "Mes évolutions".

```
git cherry-pick d356940 de966d4
```

Ici, nous prenons les deux commits ayant pour SHA d356940 et de966d4, et nous les ajoutons à la branche principale sans pour autant les enlever de votre branche actuelle. Nous les dupliquons !

## récap
![](Obsidian/Pasted%20image%2020220329171759.png)