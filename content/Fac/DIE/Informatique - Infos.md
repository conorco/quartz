---
tags: cours, DIE
---

# Infos
- [Page Moodle du cours](https://foad.univ-rennes1.fr/course/view.php?id=1010963)  
- [Document principal de cours](Fac/DIE/documentation-projet.pdf)
- [Tableau de bord](http://depot-l1miee.irisa.fr/informations/)
- [Rendu des fichiers](http://depot-l1miee.irisa.fr/webApps/RenduSAS/)
- [Accueil JupyterLab](http://sasdie.irisa.fr/)

## Machine (RPI)
Login : pilic129
[Clé](http://prototypel1.irisa.fr/documentation/cles/cle_rsa_die129) 
Machine de développement : pilic19.irisa.fr

## Commandes/notes

**Connexion en SSH** `ssh pilic129@pilic19.irisa.fr -i cle_rsa`
**Déconnexion** `exit`

**Copier des fichiers sur RPI** : `scp -i cle_rsa fichier pilic129@pilic19.irisa.fr:.`
	==ne pas oublier le `:.` qui indique le répertoire personnel==

**Copier des fichiers de RPI vers session (en étant connecté à la session Jupyter) :** `scp -i cle_rsa_die129 pilic129@pilic19.irisa.fr:/home/pilic129/2022/dataBAM.csv .`


### Nano 
Pour remplacer : `Alt + R`
Pour sauvegarder : `Ctrl + O`

### API
Pour lire une API :
```python
import requests
response=requests.get("https://data.rennesmetropole.fr/api/records/1.0/search/?dataset=amenagement_cyclable&q=")
```

### Output dans un fichier
```python
f = open('output.html','w')
f.write(cartehtml) #carte html est une string
```
## Projet informatique
Relevé de la qualité de l'air avec des données provenant :
1. De bus : fichier `.csv` des données du capteur
2. D'un capteur à l'extérieur du laboratoire : données en temps réel reliées à un Raspberry Pi

**Objectif :** Produire une carte avec les valeurs de la qualité de l'air


## Sprint 10
Importer les pistes cyclabes : fichier .csv
La colonne Geo Shape donne les différents tronçons de pistes cyclables (avec points de coordonnés commençant le tronçon et finissant le tronçon) :
```csv
{"coordinates": [[[-1.686733707141351, 48.10403557068757], [-1.6865576450345, 48.10403932487934]]], "type": "MultiLineString"}


{"coordinates": [[[-1.601655597113559, 48.12348785776592], [-1.601657563414685, 48.12347438004593], [-1.601651457135138, 48.12345581198702], [-1.601637078787095, 48.123439417473136], [-1.601615837816611, 48.12342679978677], [-1.601609149995328, 48.12342484545008], [-1.601589813271201, 48.12341919393355], [-1.60156155058508, 48.12341734592858], [-1.601533819062435, 48.12342143420066], [-1.601509332541546, 48.12343106094645], [-1.601490486993818, 48.12344528245058], [-1.601479127006993, 48.123462706727125], [-1.601478098355957, 48.12346975780597], [-1.601476365486677, 48.12348162957699], [-1.601482472967122, 48.12350019669362], [-1.601496851282992, 48.12351659122661], [-1.601518092261335, 48.123529208934684], [-1.601544116851642, 48.12353681480392], [-1.60157237834173, 48.1235386637646], [-1.601600111185123, 48.123534574531845], [-1.601624597738186, 48.12352494776699], [-1.601643443278055, 48.12351072624114], [-1.601654803219981, 48.12349330194857], [-1.601655597113559, 48.12348785776592]]], "type": "MultiLineString"}
```

➡ ajouter sur la carte toutes les pistes cyclables d'après ces coordonnées

1. Convertir les données (JSON) en données exploitables par Python
```python
import json
coord=[]
for value in geoshape:
    objet=json.loads(value) # objet est un dictionnaire avec nos coordonnées
    coord.append(objet["coordinates"]) # on ajoute les coordonnées à la liste des coordonnées
```



## Examen
Les questions suivantes sont similaires à celles qui seront posées pendant l'examen terminal. Les réponses sont _vrai_ ou _faux_. Pour l'examen, chaque question vaut 1 point. Une réponse fausse donne un malus de -0,5. Pas de réponse est neutre sur la note.  Pendant l'examen vous avez droit aux documents papiers.

**1.** Le navigateur Firefox interprète le code HTML

==Vrai==

**2.** La fonction my.macle() permet la construction de l’adresse http d’un fichier sur le serveur prototypel1.irisa.fr correspondant à vos fichiers

==Faux== --> permet de récupérer la clé du compte sur prototype.l1.irisa.fr

**3.** L’instruction Python _if cond: ... else: ..._ exécute la partie else si _cond_ est la valeur _None_

==Vrai==

**4.** La connexion à la machine pilicX.irisa.fr se fait par un protocole chiffré

==Vrai==

**5.** Pendant les TP vous pouviez vous logger (connecter) sur la machine prototypel1.irisa.fr et exécuter un terminal shell  

==Faux==

**6.** La commande "scp" est effective pour des transferts de fichiers des RPI vers le JupyterLab

==Vrai==

**7.** Python est un langage compilé

==Faux==

**8.** L’ensemble des fichiers des RPI sont organisés dans une structure en arbre  

==Vrai==

**9**. Lors des TP,  la connexion aux machines pilicX.irisa.fr nécessite une clé publique

==Vrai== --> on a besoin d'une clée publique, privée et d'une passphrase

**10.** L’instruction shell "more /2021/dataBAM.csv" affiche le contenu du fichier dataBAM.csv?

  ==Vrai==

**11.**  La commande "scp" chiffre les données copiées ?

  ==Vrai==

**12** La commande « cp » permet de copier des fichiers entre deux machines ?

  ==Faux==

**13.** Pour chaque variable en Python, il y a une zone correspondante dans la mémoire de l’ordinateur ?  

==Vrai==

**14.** L’opérateur Python de concaténation, +, peut s’appliquer aux deux valeurs suivantes: _"pas une chaine ", ’de caractères’_

==Vrai==

**15.** Dans le projet DIE nous avons utilisé le système Linux ?

==Vrai==

**16.** Le numéro « 131.254.150.242 » est une adresse IP?

==Faux==

**17.** La machine prototypel1.irisa.fr est un serveur Web qui permet l’accès à des pages par le protocole http ?

==Vrai==

**18.** En Python, (_cond_ est une valeur booléenne, _x_ un entier)   

_if cond:  
    x=x+2
else:  
    x=x+1_

est équivalent à 

_if not cond:  
     x=x+1
else:  
     x= x+2_

==Vrai==

**19.** La page suivante respecte-t-elle la structure d’une page HTML telle que présentée en cours?
```html
<html>
 <head>
  <title> une page HTML </title>
  <meta charset="UTF-8">
 </head>
  <body>
    <h1> ma première page </h1>
    
</html>
```

==Faux==
Il manque `</body>`

**20.** Les indentations du code en Python ont un effet sur la séquence d'exécution des instructions?

==Vrai==

**21.** En Python l'opérateur de concaténation de chaînes de caractères est + ?

==Vrai==

_**22.**_ Le code suivant fait la somme de 0,1,2,3,4?  
_sum = 0  
for i in range(5)  
    print(i)
sum = sum +i_

==Faux== --> erreur d'indentation

**23.** L'expression _2+"deux"_ est elle correcte?

==Faux==

**24.** En Python _"L = []"_ créer une liste vide? 

==Vrai==

**25.** En Python, si la liste L est vide l'instruction L[2] = "deux" ajoute un élément chaine de caractères à la liste?

==Faux==

**26.** L'instruction "cd /" positionne le répertoire courant à la racine des fichiers de la machine?

==Vrai==

**27.** Dans le shell le JupyterLab L'instruction "_cp monfichier.txt /2021/._" fonctionne (le fichier  _monfichier.txt_ étant dans le répertoire courant)?

==Faux== car `/2021` n'existe pas

**28.** La commande shell "_python_" lance l'interpréteur du langage du même nom?

==Vrai==

**29.** La commande "_ping_" permet de savoir si une machine est en ligne?

==Faux==

**30.** La commande shell "_history_" donne votre historique de connexion?

==Faux==

**31.** Si la machine X peut se connecter avec le protocole SSH sur la machine Y alors Y peut toujours se connecter par SSH avec X?  

==Faux==

**32.** Dans une terminal du JupyterLab la commande

            scp -i cle pilic300@pilic20.irisa.fr:  2021/dataBAM.csv .

a-t-elle la bonne syntaxe?


==Non== => pas d'espace entre ` pilic300@pilic20.irisa.fr:` et `2021/dataBAM.csv .`
**33.** Vous pouvez vous connecter avec SSH sur votre JupyterLab?

==Faux==

**34.** Un fichier  _xxxx.ipynb_ (xxxx est le nom du notebook) ne contient que du code Python?

==Faux==

**35.** Un fichier CSV doit obligatoirement avoir une ligne de titre?

==Faux==

**36.** Dans un fichier CSV, les ";" séparent les colonnes?

==Vrai==

**37.** Les données du capteur utilisé dans le sprint  7 sont produites de manière asynchrone?

==Vrai==

**38.** Dans PM25, "25" fait référence à la taille des particules? 

==Vrai==  

**39.** Dans le sprint 7 la méthode d.ecritureDuFichierCSV(...) doit être appelée plusieurs fois

==Faux==

**40.** Les RPI sont connectés a un capteur de mesure du Co2

==Faux==

**41.** Dans le sprint 7, _d.lectureDonnéesCourante()_ peut retourner pendant plusieurs appels successifs le même échantillon de mesure

==Vrai==

**42. L**e fichier dataBAM.csv comporte des mesures de PM25 et PM10?

==Vrai==

**43.** L'instruction Python _print("DIE"," 2021")_ concatène les chaînes de caractères *DIE"* et *" 2021"*

==Faux==

**44.**  Pour une liste _L_, _L.append(e)_ ajoute l'élément _e_ à la fin de la liste

==Vrai==