# initialisation liste
T=["livre","tableau","craie","ordinateur","stylo"]
chaine="extension de chaîne"
#boucle
for i in range(len(T)):
    T[i]=T[i]+chaine

#boucle d'affichage des résultats
for i in T:
    print(i)
