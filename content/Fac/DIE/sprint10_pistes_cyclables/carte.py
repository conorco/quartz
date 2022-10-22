# Initialisation API
import sasdie
sasdie.init()
c = sasdie.Sasdie()
# pour bien publier la page
c.setLogin("conor.cauty@etudiant.univ-rennes1.fr")
c.setPasswd("20201867")
if not c.connect():
    print("La connexion a échouée")
    exit(1)

#lecture de data-pm-sasdie-bus.csv
#et création de la liste des échantillons.
#csvdp est une liste que vous pouvez parcourir avec une boucle for.
csvdp = c.lireDonneesPollution("data-pm-sasdie-bus.csv")
c.creerCarte()

# une ligne de csvdp
# ['-1.686560325', '48.141622895', '-1.686554773', '48.141037278', '1605011191197', '1605011191197', '3.309999942779541', 'Bus700', 'OPC_N3:20', '2020-11-10T12:26:31.197Z', '2020-11-10T12:26:31.197Z', '']

pol=[] #initialisation de la liste pour les valeurs de PM25
for row in csvdp:
    long=(float(row[0])+float(row[2]))/2 #moyenne arithmétique des longitudes
    lat=(float(row[1])+float(row[3]))/2 #moyenne arithmétique des latitudes
    etiq=row[6]
    pol.append(float(row[6])) #afin de faire la moyenne des valeurs de PM25, enregistrement dans une liste de toutes les valeurs de PM25
    c.macarte.ajoutCercleSurLaCarte(str(long),str(lat),5,etiq)
    #long et lat sont des chaines des caratères, cercle de diamètre 5m

moy_pol=sum(pol)/len(pol) # calcul de la moyenne des valeurs de pollution 

# coordonnées mairie de Rennes : 48.11136, -1.68007
c.macarte.ajoutCercleSurLaCarte('-1.68007','48.11136',500,str(moy_pol)) #ajout du cercle de 500 m de diamètre aux coordonnées de la mairie de Rennes


#lecture des emplacements déclarés
# avec la fonction publierCoordonneesGPS.
# csvcs est une liste que vous pouvez parcourir avec une boucle for.
csvcs = c.lireCoordonneesGPS()
for row in csvcs:
    long1=float(row[0])
    lat1=float(row[1])
    c.macarte.ajoutMarqueurSurLaCarte(str(long1),str(lat1),"bar/restaurant")


#produit le texte HTML (et javascript) de la carte
cartehtml = c.macarte.produireHTMLCarte()

#f = open('output.html','w')
#f.write(cartehtml)

#Publication de la page sur le serveur prototypel1.irisa.fr
c.serveur.publierpage_html(cartehtml)