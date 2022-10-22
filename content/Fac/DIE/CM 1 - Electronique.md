---
tags : cours, DIE
author : Conor Cauty
date : 2022-09-12 16:51
title: CM 1
listings-no-page-break: true
disable-header-and-footer: true
geometry: "left=2cm,right=2cm,top=2cm,bottom=2cm"
output:
  pdf: 
    pandoc_args: ["--from=markdown+hard_line_breaks"]
    pdf-engine: xelatex
    output: CM 1.pdf
    from: markdown
    template: eisvogel 
    listings: true
---

# CM 1
```toc
```
## Présentation UE

**Examen après les 2 séances de TP d'électronique** ![](Obsidian/Pasted%20image%2020220909141443.png)

![](Obsidian/Pasted%20image%2020220909141455.png)

## Contexte

```ad-info
title: Informatique
- Automatiser l’exécution de tâches et applications
- Mise en œuvre de logiciels (Software)
- Information traitée par l’exécution de programmes (codes) sur des
machines
```

```ad-info
title: Electronique 
- Traiter et gérer des signaux électriques 
- Mise en œuvre de composants matériels (Hardware) 
- Signaux (tension/courant) traités par des circuits constitués de composants
```

2 types de composants :

* **passifs** : pas de source d'énergie
* **actifs** : besoin d'une source d'énergie

![](Obsidian/Pasted%20image%2020220909142025.png)

=> Utilisation de la **tension** car + facile à observer que le courant

## Un système électronique

![](Obsidian/Pasted%20image%2020220909142106.png)

**CAN** = capteur Analogique Numérique **CNA** = capteur Numérique Analogique

![](Obsidian/Pasted%20image%2020220909142243.png)

![](Obsidian/Pasted%20image%2020220909142521.png)

### Objectifs de la conversion analogique-numérique

* réduire le **nombre de données** = échantillonnage (en évitant de perdre de l'information, sur le **temps**)

```ad-example
Pour le son, on ne peut échantilloner toutes les 10 secondes => **perte d'information**
```

* réduire leur représentation = quantification (sur **l'amplitude**)

![](Obsidian/Pasted%20image%2020220909142852.png)

à chaque niveau ↪ une valeur numérique donc approximation donc le passage de l'analogique au numérique **perd de l'information**

### Objectifs de la conversion analogique-numérique

A chaque valeur = une tension analogique correspondante ![](Obsidian/Pasted%20image%2020220909143158.png)

### Cerveau du système

constitué de 2 parties :

* contrôle
* traitement

![](Obsidian/Pasted%20image%2020220909143251.png)

![](Obsidian/Pasted%20image%2020220909143415.png)

## La carte capteurs

![](Obsidian/Pasted%20image%2020220909143549.png)

```ad-tip
➡ Faire le lien entre le schéma fonctionnel et la carte
```

![](Obsidian/Pasted%20image%2020220909143823.png)

Une petite partie du microcontrôleur est **mixte** (convertisseurs analogiques)

## Le microcontrôleur

![diapo microcontroleur](Obsidian/Pasted%20image%2020220909144006.png)

```ad-info
title: Microcontroleur
- Système quasi-autonome
- Unité centrale avec un processeur
- Mémoire vive + morte
- Interfaces pour communiquer

➡ peut se contrôler

- **Ressources très limitées** donc $\neq$ d'un "ordinateur" => permet de faire un pré-traitement et de gérer uniquement les données **utiles**
```

![schéma microcontroleur informatique/électronique](Obsidian/Pasted%20image%2020220909144341.png)

```ad-info
title: en TP : microcontroleur ATmega328
Le microcontroleur n'est **pas** Arduino

- Architecture RISC (Reduced instruction set computer) 
- Low Power 
- In System programmable system 
- 20 **MIPS** (Mega Instructions Per Second) 
- 3 types de mémoire (Flash, SRAM, EEPROM) 
- 6 A/D Converters de 10 bits 
- 6 PWM (Pulse Width Modulation)
```

```ad-note
title: Les mémoires internes
**Flash memory**
- non volatile : **pas de perte d'information** quand on coupe l'alimentation (*exemple : clé USB*)
- rapide
- stockage du Bootloader (programme initial -> permet d'utiliser le microcontrôleur)
- stockage du programme application / code applicatif (programme compilé/traduit en un langage machine et sauvegardé dans la mémoire flash)

**SRAM :  Static Random Acces Memory**
- mémoire vive : mémoire accessible **en écriture et en lecture**
- volatile
- stockage intermédiaire des données (*exemple : boucle for*)

**EEPROM : Electrically Erasable Programmable _Read Only_ Memory**
- non volatile
- stockage de paramètres utiles à l'application (*exemple : données constructeurs...*)
```

## Fonctions électroniques

7 fonctions étudiées :

1. [Conversion courant tension](#Conversion%20courant%20tension)
2. [Conversion tension lumière](#Conversion%20tension%20lumi%C3%A8re)
3. [Filtrage](#Filtrage)
4. [Amplification](#Amplification)
5. [Comparaison](#Comparaison)
6. [Conversion analogique numérique](#Conversion%20analogique%20num%C3%A9rique)
7. [Conversion numérique analogique](#Conversion%20num%C3%A9rique%20analogique)

### Conversion courant/tension

![](Obsidian/Pasted%20image%2020220909144718.png)

Le courant *traverse* la résistance, alors que la tension est *aux bornes* de la résistance => plus facile d'observer une tension qu'un courant

```ad-info
title: Courant
- Quantité d'électricité qui parcourt un conducteur 
- Débit de charges électriques dans ce conducteur. 
- Appelé aussi intensité (électrique) 
- Noté I et exprimé en Ampère (A)
```ad-tip
title: Analogie avec une rivière
- le lit de la rivière = le conducteur électrique 
- le débit d'eau = l'intensité électrique
```


```ad-info
title: Tension
- Différence de 2 potentiels électriques 
- Liée à une énergie potentiellement disponible (voir l'analogie avec la rivière) 
- U<sub>AB</sub>=V<sub>A</sub> -V<sub>B</sub> et exprimée en Volt (V).
```ad-tip
title: Analogie avec une rivière
- l'altitude = le potentiel électrique 
- la différence d'altitude entre le début et la fin de la rivière  (le dénivelé) = la différence de potentiels (la tension)
```


![](Obsidian/Pasted%20image%2020220909145819.png)

### Conversion tension/lumière

![](Obsidian/Pasted%20image%2020220909150233.png)

Le courant est bloqué jusqu'à un certain seuil : ![](Obsidian/Pasted%20image%2020220909150402.png)

### Filtrage

```ad-info
title: Filtrage: : Fonction très utilisée dans les systèmes électroniques
- traitement du signal
- modifications des caractéristiques spectrales d'un signal électrique
- 
**Objectif du filtrage :** extraire une information utile : *« Le but du filtrage est d’extraire une partie de l’information, afin de restituer un signal plus intelligible*
```

```ad-info
title: Filtre
Ensemble de composants électroniques permettant de modifier la forme d’un signal électrique (spectre de fréquence et/ou phase) ; peut être analogique et numérique
```

![](Obsidian/Pasted%20image%2020220909150616.png)

```ad-tip
title: Fonction de transfert H(f)
Rapport entre la tension de sortie et la tension d’entrée
```

![](Obsidian/Pasted%20image%2020220909150905.png)

```ad-info
title: Caractérisation d’un filtre
deux courbes en fonction de la fréquence permettent d’expliciter les modifications de forme entre V<sub>2</sub> et V<sub>1</sub> 
- amplitude/fréquence => gain en fonction de la fréquence 
- phase/fréquence => déphasage en fonction de la fréquence
```

![](Obsidian/Pasted%20image%2020220909151209.png)

#### Applications

**Nettoyer un signal bruité** ![](Obsidian/Pasted%20image%2020220909151239.png)

**Modifier la forme d'un signal** ![](Obsidian/Pasted%20image%2020220909151258.png)

**Mixer de la musique** ![](Obsidian/Pasted%20image%2020220909151321.png)

#### Types de filtres

![](Obsidian/Pasted%20image%2020220909151356.png)

filtre de base : filtre **passe-haut**

### Amplification

**Objectifs :** Augmenter l’amplitude d’un signal sans en modifier la forme

```ad-info
title: Amplificateur
Composants électroniques permettant de multiplier un signal par une constante, appelée gain
```

![](Obsidian/Pasted%20image%2020220909152105.png)

```ad-info
title: Gain
G = Constante
	Si G est > 0 => Amplificateur non inverseur
	Si G est < 0 => Amplificateur inverseur
```

![](Obsidian/Pasted%20image%2020220909152149.png)

#### Applications

![](Obsidian/Pasted%20image%2020220909152205.png)

### Comparaison

**Objectif de de la comparaison** : Comparer l’amplitude d’un signal à une amplitude de référence appelée seuil

```ad-info
title: Comparateur
Composants électroniques permettant de générer une sortie avec uniquement 2 états (haut et bas)
```

![](Obsidian/Pasted%20image%2020220909152249.png)

=> transformation d'un signal triangulaire en signal carré (mais les 2 sont des signaux analogiques)

#### Applications

![](Obsidian/Pasted%20image%2020220909152310.png)

### Bilan fonctions analogiques

![](Obsidian/Pasted%20image%2020220909152824.png)

### Conversion analogique numérique

```ad-info
title: Conversion analogique numérique : Fonction indispensable pour interagir avec l’environnement
➡ Environnement : monde analogique 
➡ Informatique : monde numérique 

**Objectif du convertisseur** : Convertir un signal analogique (tension ou courant) en une donnée numérique

**Convertisseur** : Ensemble de composants analogiques et numériques
```

![](Obsidian/Pasted%20image%2020220909152948.png)

Ici, en sortie 2$^3$ = 8 valeurs possibles stockées sur 3 bits (V1 est l'entrée **analogique** et D0, D1, D2 sont les sorties **numériques**)

**Fonction de transfert d'un CAN :** 
![](Obsidian/Pasted%20image%2020220919101936.png)

Quand on choisit un composant --> choisir les bonnes caractéristiques de ce composant

```ad-example
title: Paramètres à choisir
- **PE** : pleine échelle ou plage de conversion => plage qui peut être convertie en numérique (en TP : on peut convertir de 0 à 5V)
- **Code** : représentation de la donnée numérique (par exemple on peut coder différement un nombre négatif ou positif)
- **Q** : quantum ou pas de quantification $Q=\frac{\text{pleine échelle}}{\text{nombre d'états de sortie}}$
```

**Toujours** une perte d'information mais qui peut être négligeable
Pour la réduire (donc pour réduire Q) :
- augmenter le nombre de bits du convertisseur
- réduire la pleine échelle

![](Obsidian/Pasted%20image%2020220919103101.png)

```ad-tldr
title: En TP : carte capteurs ADC0804
![Schéma de la carte capteurs](Obsidian/Pasted%20image%2020220919103554.png)
sortie du CAN associée à des LEDs : *Exemple si DB7=0 alors la LED L7 est allumée, si DB7=1 alors la LED L7 est éteinte*


**Entrées et sorties :**
- entrées de contrôle /CS et /RD mises à 0 => Connectées au GND (0 volt) 
- entrée /WR : signal généré par un composant externe au CAN (le microcontrôleur) 
	- ordre de conversion (écriture) si /WR passe de 1 à 0 => **début conversion** 
- sortie /INTR : signal **généré** par le CAN 
	- information de fin de conversion si /INTR = 0 => **conversion terminée**

![graphique](Obsidian/Pasted%20image%2020220919104558.png)

**Observation en TP : il y a des LEDs qui clignotent**
=> car le pas de quantification est petit (pour une tension donnée, on a le signal idéal + le bruit et si le bruit est supérieur à 19,5mV (plus petite tension convertie) ➡ LED qui clignote)

Les composants ne sont pas *parfaits* donc il y a **toujours** une incertitude sur les valeurs converties

On ne peut convertir que des valeurs positives de tension avec le CAN utilisé

![](Obsidian/Pasted%20image%2020220919103220.png)
```


```ad-info
title: Temps de conversion
Le **temps de conversion** est le temps nécessaire pour effectuer une action ➡ important dans les caractéristiques d'un composant
	=> on ne **peut pas** utiliser le convertisseur avec une fréquence supérieure à 10 kHz
Temps de conversion $\neq$ temps d'échantillonnage
```

```ad-tip
title: Pour convertir un signal avec des valeurs négatives
On peut utiliser un **additionneur** pour avoir des valeurs uniquement positives (si le CAN ne peut convertir que des données positives)
```

![](Obsidian/Pasted%20image%2020220919103110.png)


### Conversion numérique analogique
```ad-info
title: Conversion numérique analogique : Fonction indispensable pour interagir avec l’environnement
➡ Environnement : monde analogique 
➡ Informatique : monde numérique 

**Objectif du convertisseur** : Convertir un signal numérique (tension ou courant) en une donnée analogique
```

![](Obsidian/Pasted%20image%2020220919104800.png)

![diapo 52](Obsidian/Pasted%20image%2020220919104814.png)

**Pas de perte d'information** => au contraire on "fabrique" de l'information car on crée les données qui se trouvent entre les paliers (on passe de données discrètes à continues)

```ad-warning
title: Fonction de transfert du CNA
Ne pas relier les points entre eux quand on trace la fonction de transfert d'un CNA ➡ sinon on créé de l'information
Le CNA ne prend en entrée que des données discrètes
```

![entrée et sortie CNA](Obsidian/Pasted%20image%2020220919105007.png)

`````ad-tip
title: Principe du codage
En numérique : utilisation de la base 2 pour représenter un signal numérique car on utilise des composants qui utilisent 2 états (passant/bloquant) 

Tout entier N positif peut être représenté en numération binaire : 
N = a<sub>n</sub>2<sup>n</sup> + a<sub>n-1</sub>2^<sup>n-1</sup> + … + a<sub>1</sub>2<sup>1</sup> + a<sub>0</sub>2<sup>0</sup> avec (a<sub>i</sub> = 0 ou 1)

```ad-example
title: Exemple sur 3 bits
N<sub>10</sub> = 6 = 1*2<sup>2</sup> + 1*2<sup>1</sup> + 0*2<sup>0</sup>
N<sub>2</sub> = 110
```
`````

```ad-info
title: en TP : utilisation d’un TLC7524
![](Obsidian/Pasted%20image%2020220919105900.png)
![](Obsidian/Pasted%20image%2020220919110038.png)

chaque donnée numérique (entrée) est connectée à une sortie du microcontrôleur
/CS : entrée de contrôle mise à 0 => Connectée au GND
/WR : entrée et signal généré par un composant externe (microcontrôleur) au CNA ordre de conversion (écriture) si /WR passe de 1 à 0 => début conversion
```

## L'environnement logiciel Arduino
```ad-info
title: IDE : Integrated development environment
**Fonctions de l'IDE :**
- compilation du code programme
- transfert du code compilé dans la mémoire flash du microcontrôleur

Voir [Arduino.cc](https://www.arduino.cc)
```

![programme arduino](Obsidian/Pasted%20image%2020220919111523.png)

```C
// Déclarations des constants, variables, bibliothèques,...
void setup() 
{ 
// Instructions exécutées une fois 
} 

void loop() 
{ 
// Instructions exécutées indéfiniment 
}
```

L'ordre d'écriture des instructions a une importance : les instructions sont exécutées **l'une après l'autre** (car les ressources sont limitées)

**Quelques fonctions**
- **Pause** : `delay(durée du délai)`
	  *Exemple pause de 100 millisecondes* : `delay(100);`
	  Le temps est mesuré de manière relative (par rapport à une horloge qui envoie un signal tous les x temps)
- **Définition des entrées/sorties numériques**
	`pinMode(nom de la broche, mode de la broche)`
	*Exemple : définition d'une sortie* :
	```C
	int enable = 14 ;
	pinMode(enable,output);
	```
- **Durée d'une impulsion** : `durée = pulseIn(entrée, type, délaimax)`
	*Exemple :* `duration = pulseIn(in1, HIGH);`
- **Modification des sorties numériques** : `digitalWrite(nom de la broche, valeur)`
	*Exemple : mise à l'état haut d'une sortie enable :* `digitalWrite(enable,HIGH)`
- **Lecture des entrées numériques** : `Valeur = digitalRead(nom de la broche)`
	*Exemple : lecture de l'entrée in1* `Valeur = digitalRead(in1);`
- **Lecture des entrées analogiques : présence de CAN** `Valeur = analogRead(nom de la broche)`
	*Exemple : lecture de l'entrée ina1 :* `Valeur = analogRead(ina1);` 
- **Modification des sorties analogiques : Absence de CNA - utilisation de PWN** : `analogWrite(nom de la broche, rapport cyclique)`
	*Exemple : mise à VCC/2 d'une sortir outa1 (filtrage en aval nécessaire* `analoglWrite(outa1, 50);`

```ad-info
title: Communication avec le PC
**Utilisation du port série** 
	La carte Arduino UNO met à disposition un port série asynchrone (indépendant de l'horloge) => plus difficile à gérer qu'en synchrone
		- Broche 0 « réception » : Rx 
		- Broche 1 « émission » : Tx 
	La carte Arduino UNO dispose d’une interface USB pour le chargement du soft 
		- Création d’un port COM virtuel 
		- Utilisation possible d’un serialMonitor dans l’IDE ou d’un hyperterminal

**Initialisation du port Serial :**
	`Serial.begin(vitesse)` 
	Fonction à prévoir dans le `setup` 
		vitesse = Vitesse standard de transmission 
		Exemple : initialisation du port série asynchrone à 9600 bauds 
		`Serial.begin(9600); // 9600 bits/sec`
![](Obsidian/Pasted%20image%2020220919112729.png)
```

## Les capteurs
### Joystick
Permet de récupérer la position en X et en Y, et une troisième information (interrupteur)
![](Obsidian/Pasted%20image%2020220919112819.png)

- Les tensions aux points X et Y, V<sub>X</sub> et V<sub>Y</sub> sont proportionnelles à la position des points X et Y
- Si l’interrupteur est fermé : V<sub>S</sub> = GND 
- Si l’interrupteur est ouvert : V<sub>S</sub> = VCC *(si on rajoute une résistance dite de pull-up)*

`````ad-hint
title: Résistance de pull-up
La tension aux bornes de la résistance quand l'interrupteur est ouvert est de 0V 
--> en ajoutant la résistance de pull-up : cela impose un potentiel égal à 5V sur l'interrupteur


```ad-quote
![](Obsidian/Pasted%20image%2020220919114044.png)
title: Résitance de pull-up/tirage avec un interrupteur
Lorsqu'un simple [interrupteur](https://fr.wikipedia.org/wiki/Interrupteur "Interrupteur") mécanique est utilisé comme entrée à un circuit logique, une résistance de tirage est nécessaire pour ne pas laisser flottante l'entrée du circuit. La résistance de tirage sert dans ce cas-ci à imposer le niveau haut tandis que l'interrupteur peut encore imposer un niveau bas. Sans résistance de tirage, l'entrée serait flottante et ainsi donc à un niveau logique indéfini ce qui pourrait causer un fonctionnement erratique du circuit.
```
`````

### Capteur ultrason
![](Obsidian/Pasted%20image%2020220919114137.png)
![](Obsidian/Pasted%20image%2020220919114146.png)

**Applications : **
- radar de recul
- robotique : capteur de positionnement

![](Obsidian/Pasted%20image%2020220919114222.png)

**Trigger** : Entrée du capteur – ordre d’émission généré par le microcontrôleur
**Echo** : Sortie du capteur – information récupérée par le microcontrôleur

![](Obsidian/Pasted%20image%2020220919114514.png)


**Rôle du microcontrôleur :**
- Contrôler le capteur => Trigger
- Récupérer l’information => Echo
- Interpréter l’information
- Calculer la distance (grâce à la vitesse du son, car le calcul est simple à effectuer sinon on aurait pu effectuer le calcul avec le PC)
- Transmettre la distance

### Capteur de température
![](Obsidian/Pasted%20image%2020220919114648.png)
![](Obsidian/Pasted%20image%2020220919114655.png)

V<sub>out</sub> : Tension analogique
**Rôle du microcontrôleur :**
![](Obsidian/Pasted%20image%2020220919114726.png)

### Capteur de lumière
![](Obsidian/Pasted%20image%2020220919114849.png)
![](Obsidian/Pasted%20image%2020220919114901.png)

Lum : tension analogique

**Rôle du microcontrôleur :**
![](Obsidian/Pasted%20image%2020220919114918.png)

### Capteur de son
![](Obsidian/Pasted%20image%2020220919114944.png)

## Fusion des données
Pour transmettre des données "capteurs" à une machine (PC)

➡ Utilisation de la liaison série du microcontrôleur et USB du PC
➡ Définition d'un protocole : langage commun
➡ Ecriture du code