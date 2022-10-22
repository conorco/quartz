# Oscilloscope

**Tension sinusoïdale** : $Ve = Vme \times \sin(2\cdot \pi \cdot Fe \cdot t)$ 
$Vme$ = tension maximale

| Fe (Hz)        | 500           | 1k            | 5k           | 10k          | 15           | 20k          |
| -------------- | ------------- | ------------- | ------------ | ------------ | ------------ | ------------ |
| Calibre (/div) | 500 $\micro$s | 250 $\micro$s | 50 $\micro$s | 25 $\micro$s | 25 $\micro$s | 10 $\micro$s | 

9 divisions en temps ; 8 divisions en tension
# Filtre passe-bas

▶ coupe les tensions à **haute fréquence**

**Fréquence de coupure :** $Fc=\frac{1}{2\cdot \pi \cdot R \cdot C}$ donc si R augmente, Fc baisse (donc + de fréquences sont coupées)
**Gain :** $G = \frac{Vs}{Ve}$

Pour $f=f_{c}$ , on a $G=\frac{Vs}{Ve}=\frac{1}{\sqrt{2}}$  

# Amplificateur de tension

| Schéma                                            | Montage |
| ------------------------------------------------- | ------- |
| ![](Obsidian/Pasted%20image%2020221017175751.png) | ![](Obsidian/Pasted%20image%2020221018091829.png)        |



**Tension de sortie de l'amplificateur :** $Vs = Ve\times \frac{\text{R6}+\text{R7}}{\text{R6}}$ 
**Gain :** $G= \frac{\text{R6}+\text{R7}}{\text{R6}}$ 

# Comparateur
![](Obsidian/Pasted%20image%2020221017173040.png)

La sortie du comparateur est à l'état bas si V- > V+ et à l'état haut sinon

**Exemple avec un signal triangulaire** (même comportement avec un signal sinusoïdal)
![](Obsidian/Pasted%20image%2020221017173300.png)

**Rapport cyclique de la tension de sortie $\alpha$** : $\alpha = \frac{\text{Durée état haut}}{\text{période}}$ 

# Convertisseur Analogique Numérique (CAN)

CAN sur la carte est un convertisseur **8 bits** contrôlé par le **microcontroleur**. Il peut convertir, X, Ve, Vp.
==DBi = 0 : LED allumée
DBi = 1 : LED éteinte==

La tension analogique numérisée $V_{an}$ est telle que :
$$
V_{an} = \sum^{7}_{i=0} \frac{5}{2^{8-i}}\times DBi
$$

![](Obsidian/Pasted%20image%2020221017173952.png)

La **fréquence d'échantillonnage** doit être **au moins 2 fois plus élevée que la fréquence max** afin d'éviter des problèmes en haute fréquence (cela s'appelle le "crénelage")

# Convertisseur Numérique Analogique (CNA)

La tension de sortie $V_{out}$ est telle que :
$$
V_{out}=-V_{ref}\times \frac{D}{256}
$$
($V_{ref}$ tension de signal appliquée sur l'entrée REF = -5V)

D est sur 10 bits, on a la formule suivante pour convertir une donnée DB sur 8 bits en une donnée sur 10 bits :

$$
D=\sum^{7}_{i=0}2^{i}\times DBi
$$

**Période/fréquence d'échantillonage**
![400](Obsidian/Pasted%20image%2020221017174605.png)

# Joystick

Fonctionne avec un CAN sur 10 bits (alors que le CAN externe au microcontrôleur du joystick fonctionne sur 8 bits) ▶ donne des données comprises entre 0 et 1023
Le signal analogique d'entrée est compris entre 0 et 5 V, donc 5V donne une sortie à 1023 = 2<sup>10</sup> - 1, soit la tension de sortie du joystick :
$$
V_{out} = \frac{V_{in}\times 5}{2^{10}-1}
$$

# Capteur ultrason

**Retard entre le signal émis (Trigger) et le signal reçu (Echo)** : $t = \frac{2d}{v}$ avec $v = 340 m\cdot s^{-1}$ 

# Capteur de température
![](Obsidian/Pasted%20image%2020221017175128.png)

$V_{temp} = f(V_{out}) = 11\times V_{out}$ et donc la température est telle que :
$$
T = 10^{2}\times V_{out} = \frac{100}{11}\times V_{temp}
$$
En effet, la tension de sortie du composant varie de **10 mV/°C**
