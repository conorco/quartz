---
tags : code
author : Conor Cauty
date : 2022-03-20 16:04
title: Comprendre le web
listings-no-page-break: true
disable-header-and-footer: true
geometry: "left=2cm,right=2cm,top=2cm,bottom=2cm"
output:
  pdf: 
    pandoc_args: ["--from=markdown+hard_line_breaks"]
    pdf-engine: xelatex
    output: Comprendre le web.pdf
    from: markdown
    template: eisvogel 
    listings: true
---
[source](https://openclassrooms.com/fr/courses/1946386-comprendre-le-web/6874331-tirez-un-maximum-de-ce-cours)
# Comprendre le web
Internet $\ne$ web, car Internet contient plusieurs services, *dont le web* :
-   **Le Web** (le plus connu d’entre eux) : vous ouvrez un navigateur web pour y aller, comme Google Chrome, Firefox, Internet Explorer, Edge, Safari...
    
-   **Les e-mails :** pour échanger des messages. Il s’agit tout simplement de courrier électronique.
    
-   **Les newsgroups :** moins connus, ils sont l’ancêtre des forums et permettent de discuter à plusieurs en postant des messages.
    
-   **Le FTP :** un moyen d’échanger des fichiers entre ordinateurs.
    
-   Etc.

## Historique d'Internet
-   1969 : création de l’ancêtre d’Internet, appelé alors **ARPAnet**. C’est un réseau militaire qui se veut décentralisé (il n’a pas de lieu de commande central). Le réseau a ensuite évolué pour devenir un lieu d’échange universitaire avant de devenir progressivement grand public sous le nom d’Internet.
    
-   1972 : apparition des **e-mails** pour échanger des messages.
    
-   1991 : lancement du **Web**, pour afficher des pages d’information.

## Langages du web

- **Langages client** : HTML, CSS, JavaScript
- **Langages serveur** : PHP, Java, Python, C#, Ruby

![communication entre client/serveur|400](Obsidian/Pasted%20image%2020220320162607.png)

-   Créer un champ texte “Adresse mail ou nom d’utilisateur” -> ~~**serveur**~~ **client**
    
-   Autoriser la connexion des utilisateurs ayant un mot de passe respectant les critères de sécurité -> **serveur**
    
-   Faire apparaître le bouton “SE CONNECTER” en violet -> **client**
    
-   Créer le bouton à cocher “Se souvenir de moi” -> **client**
    
-   Souligner en violet le lien “Mot de passe oublié ?” -> **client**
    
-   Autoriser les utilisateurs ayant une adresse mail correcte à se connecter -> **serveur**
    
-   Générer un tableau de bord personnalisé pour les utilisateurs se connectant -> **serveur**
    
-   Créer un lien vers la page “Inscrivez-vous gratuitement” -> **client**

![schéma serveur/client/base de données | 400](Obsidian/Pasted%20image%2020220320164206.png)

Quelques exemples de requêtes SQL sur une base de données contenant les numéros et noms de département associés :

```SQL
SELECT departement_code, departement_nom FROM departement;
 /* permet d'afficher le n° et le nom de tous les départements */
SELECT departement_code, departement_nom FROM departement WHERE departement_code = '30';
/* affiche le département portant le numéro 30 */
SELECT departement_code, departement_nom FROM departement WHERE departement_nom LIKE 'C%';
/* affiche les départements qui commencent par la lettre C*/
```

## Serveurs
![équilvalence nom d'hôte/adresse IP | 400](Obsidian/Pasted%20image%2020220320181748.png)

google.com = nom d'hôte
205.89.177.26 = adresse ip

Des sites comme [pingtool.org](https://pingtool.org/) peuvent donner l'équivalence nom d'hôte/adresse IP

Pour que les machines se parlent entre elles et se comprennent -> **protocoles**

### Protocoles bas niveau
Dans toutes les communications, on a : 

-   TCP (_Transmission Control Protocol_)
    
-   UDP (_User Datagram Protocol_)

Sans TCP => pas de communication réseau, utilisé pour faire transiter des pages web, des mail, des vidéos

### Protocoles haut niveau

Ils sont basés sur TCP et forment une surcouche qui englobe TCP :
-   **HTTP :** le protocole qui permet d’échanger des pages web entre le client et le serveur. En plus du langage HTML, Tim Berners-Lee a inventé les bases du protocole HTTP qui permet d’échanger les pages. C’est ce que signifie le "http://" que vous voyez au début des adresses web !
    
-   **HTTPS :** identique à HTTP, avec le "S" en plus qui signifie "Secure". Les pages sont chiffrées, pour garantir que personne ne peut les lire (par exemple quelqu’un qui espionnerait les données qui transitent dans les câbles sous-marins !).
    
-   **FTP :** permet d’échanger des fichiers.
    
-   **SMTP :** permet d’envoyer des e-mails.
    
-   Etc.

Le site [reqbin](https://reqbin.com/curl) permet d'afficher les retour HTTP d'un serveur

Quelques codes HTTP 
- 200 OK : la page existe et a bien été transmise
- 404 : la page n'existe pas (elle n'a pas été trouvée)

## Métiers du web
### Développeur
cf [Métier de développeur](MOOC/Métier%20de%20développeur.md)

### UX designer
= user experience designer 
=> fait en sorte que l'utilisation d'un site/d'une application soit la plus simple possible

**$\ne$ entre UX et UI designer** :
UI = user interface, donc l'UI designer se concentre sur l'interface (alors que l'UX s'intéresse à l'expérience **globale** de l'utilisateur)
Ils ne sont des fois pas différenciés et on parle de **product designer**

### Technicien informatique

Ils font partie des métiers liés aux **systèmes d'information** (SI)
Le rôle du technicien informatique au sein d'une entreprise est d'assurer le bon fonctionnement du **parc informatique**, et de fournir aux utilisateurs des **solutions** pour pallier les éventuelles **pannes** ou **difficultés** qu’ils peuvent rencontrer.

Il gère donc par exemple le **support technique**