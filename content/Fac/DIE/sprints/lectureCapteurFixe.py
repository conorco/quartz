#Importe les méthodes nécessaires
import RPI_Sasdie_Lib

# Créer la structure de données (classe) pour l’accès aux méthodes
d = RPI_Sasdie_Lib.DataStream()

#Lit la dernière valeur produite par le capteur.
#Attention à chaque fois que vous appelez la méthode,
#elle ne produit pas nécessairement une nouvelle valeur. La valeur
#retournée (data) comporte deux champs : data.count le numéro de
#l’échantillon produit et data.pm25 la mesure des PM25.
contenuFichier="Numéro d'échantillon;PM25\n"
l_count=[]
while len(l_count) <10: #tant qu'on a pas 10 valeurs
	data=d.lectureDonnéesCourante() # on lit la dernière valeur
	if data.count not in l_count: # si le numéro n'était pas déjà présent dans la liste
		l_count.append(data.count) # on incrémente le compteur
		contenuFichier+=str(len(l_count))+";"+str(data.pm25)+"\n" # on ajoute au fichier


#Effectue l’écriture du contenu de contenuFichier
#dans le fichier data_pm25.csv.
#contenuFichier est une chaîne de caractères. A chaque appel de
#cette méthode l’ensemble du contenu du fichier est réécrit. Il
#n’y a PAS de concaténation du nouveau contenu à la fin du fichier.

d.ecritureDuFichierCSV(contenuFichier)
