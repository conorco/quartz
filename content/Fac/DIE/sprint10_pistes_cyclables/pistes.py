#### AVEC FOLIUM ####

import folium
from folium import plugins
from folium.plugins import MarkerCluster
### 1. afficher les pistes cyclables sur la carte

donnees_pistes="amenagement_cyclable.geojson" # import par le fichier téléchargé


carte=folium.Map(location=[48.1113, -1.6809], zoom_start=13) # initialisation de la carte

folium.GeoJson(donnees_pistes, name="Pistes Cyclables").add_to(carte) # lecture du fichier GeoJSON contenant les pistes cyclables
print(folium.GeoJson(donnees_pistes, name="Pistes Cyclables"))

### 2. afficher les données remontées des bus

import csv
# ligne du csv :
# ['-1.686560325', '48.141622895', '-1.686554773', '48.141037278', '1605011191197', '1605011191197', '3.309999942779541', 'Bus700', 'OPC_N3:20', '2020-11-10T12:26:31.197Z', '2020-11-10T12:26:31.197Z', '']

## Pour faire des clusters de points et que la carte soit plus lisible
faible=folium.FeatureGroup(name='Faible pollution', show=False)
carte.add_child(faible)

marker_cluster_faible = MarkerCluster().add_to(faible)

fort=folium.FeatureGroup(name='Forte pollution', show=True)
carte.add_child(fort)
marker_cluster_fort = MarkerCluster().add_to(fort)

long_list = []
lat_list = []


with open("data-pm-sasdie-bus.csv", newline='') as file:
    donnees_bus = csv.reader(file, delimiter=';')
    for row in donnees_bus:
        long=(float(row[0])+float(row[2]))/2 #moyenne arithmétique des longitudes
        lat=(float(row[1])+float(row[3]))/2 #moyenne arithmétique des latitudes
        point=[lat,long]
        #coord.append([lat,long])
        if float(row[6])>40: #écréter à 40 pm
            pm=40
        else:
            pm=float(row[6])
        #cercles de 15m de diamètre qui représentent les données de pollution autour des bus
        if pm<10:
            folium.Circle(radius=15,popup=pm,location=point,color="green",fill=True).add_to(marker_cluster_faible)
        else:
            folium.Circle(radius=15,popup=pm,location=point,color="red",fill=True).add_to(marker_cluster_fort)
            long_list.append(long)
            lat_list.append(lat)




### 3. Afficher les pistes cyclables ayant une intersection avec une zone ayant une moyenne de pollution supérieure à 10 µg/m3

# on a déjà affiché uniquement les zones ayant une pollution supérieur à 10 µg/m3 : dans "fort"


# import json
# f = open('amenagement_cyclable.geojson')
# data=json.load(f)
#
# for i in range(len(data['features'])):
#     print(data['features'][i]['geometry']['coordinates'][0][0], len(data['features'][i]['geometry']['coordinates']))
#




#### Sauvegarde de la carte

folium.LayerControl().add_to(carte)
carte.save("carte.html")


### MODULES UTILISES ###
# folium
# csv
# geopandas
# matplotlib
# mapclassify
