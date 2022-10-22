import sasdie
sasdie.init()
c = sasdie.Sasdie()
# pour bien publier la page
c.setLogin("conor.cauty@etudiant.univ-rennes1.fr")
c.setPasswd("20201867")
if not c.connect():
    print("La connexion a échouée")
    exit(1)

#lecture du fichier data_pm25.csv
#La variable donnees peut typiquement être parcourue par une boucle
#« for row in donnees: ». L’expression row[0] correspond à l’élément
#en première colonne et row[1] de celui en deuxième colonne)
donnees = c.lireDonneesPollutionRPI()

texthtml="<!DOCTYPE html>\n<html lang=\"fr\">\n  <head>\n    <meta charset=\"utf-8\">\n    <title>Données</title>\n  </head>\n  <body>\n    <h1>Données RPI</h1>\n    <table border=\"1\">\n      <tr><th>Numéro d'échantillon</th><th>PM25</th></tr>\n"


for row in donnees[1:]:
    texthtml+="      <tr><td>"+row[0]+"</td><td>"+row[1]+"</td></tr>\n"

texthtml+="    </table>\n  </body>\n</html>"
#Publication du contenu HTML, "textHTML"
#est une chaine de caractères
#correspondant au source de la page.
#f=open("output.html","w")
#f.write(texthtml)

c.serveur.publierpage_html(texthtml)
