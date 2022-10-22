#Initialisation et importation des fonctions nécessaires
import sasdie
#Quelques initialisations de variables
sasdie.init()
#Création de la structure qui fournit les méthodes
c = sasdie.Sasdie()
#Connexion au serveur « prototypel1.irisa.fr »
c.setLogin("conor.cauty@etudiant.univ-rennes1.fr")
c.setPasswd("20201867")
if not c.connect():
 print("La connexion a échouée")
 exit(1) # arrêt du programme
#Récupération de la clé de votre compte sur
#« prototypel1.irisa.fr »
textepage=c.macle()
#Publier un contenu sur le serveur
# textepage est une chaine de caractères
c.publierpage_html(textepage) #error name 'textepage' is not defined
