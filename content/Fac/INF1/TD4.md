# Exercice 1 : Conditionnelles
## Question 1
```java
public static int plusGrand(int a, int b){
		if (a>b) return a;
		return b;
}
```

## Question 2

```java
public static int salaire(int heures){
	int salaire_total = 0;
	if (heures < 4) return heures*20;
	salaire_total += 4*20;
	if (heures < 8) return salaire_total+= (heures - 4)*25;
	salaire_total+= 4*20;
	if (heures < 13) return salaire_total+=(heures - 8)*35;
	salaire_total+= 5*35;
	if(heures <20) return salaire_total+= (heures-13)*50;
	salaire_total+= 7*50;
	if (heures > 27) return salaire_total+=(heures-20)*100;
}

//autre possibilité
public static int salaire(int heures){
	int s=0;
	for(int i=1; i <=heures;i++){
	if(i<=4) s+=20;
	else if (i<=8) s+=25;
	else if (i<=13) s+=35;
	else if(i<=20) s+=50;
	else s+=100;
	}
	return s;
}

```

Possible aussi de faire avec des **seuils** afin de pouvoir modifier plus facilement

# Exercice 2 : Boucles
## Question 1

```java
public static int sommeEntiers(int n){
	int somme =0;
	for(int i=1 ; i<=n ; i++) somme+=i;
	return somme;
}
```

## Question 2
```java
///Version 1 qui appeler sommeEntiers
public static void afficheTouteslesSommesV1(int n){
	for(int i=1;i<=n;i++){
		somme=sommeEntiers(i);
		System.out.print(somme+" ");
	}
}

///Version 2 qui n'appelle pas sommeEntiers
public static void afficheToutesLesSommesV2(int n){
	int somme =0;
	for(int i = 1; i<=n ;i++){
		somme+=i;
		System.out.print(somme+" ");
	}
}

```


## Question 3

```java
public static void premiereLigneTable(int n){
		System.out.print("x ");
		for(int i=1; i<=n;i++) System.out.print(i+"	");
}

public static void autresLignesTable(int ligne, int n){
	System.out.print(ligne+" ");
	for (int i=1; i<=n;i++) System.out.print(ligne*i+"	");
}

public static void tablesDeMultiplications(int n){
	premiereLigneTable(n);
	for (int i=1; i<=n;i++){
		System.out.println();
		autresLignesTable(i,n);
	}
}
```

# Exercice 4 : Représentation décimale des entiers

## Question 1
```java
public static int compteChiffres(int n){
	int compteur=0;
	while(n>0){
		compteur++;
		n=n/10;
	}
	return compteur;
}

```

## Question 2

```java
public static int inverseChiffres(int n){
		int nombre_chiffres=compteChiffres(n);
	//	System.out.println(nombre_chiffres);
		int[] tab_inverse= new int[nombre_chiffres];
		for(int i =0; i<nombre_chiffres;i++){
			tab_inverse[i]=n%10;
			//System.out.println("tab "+tab_inverse[i]+" n "+n);
			n=n/10;
		}
		
		int nombre_inverse =0;
		int puissance=1;
		for(int i = nombre_chiffres-1;i>=0;i--) {
			nombre_inverse+=puissance*tab_inverse[i];
			puissance*=10;
		}
		return nombre_inverse;
	
}
```

# Exercice 5 : Tableaux
## Question 1

```java
public static int[] initTableau(int n){
	int[] tableau = new int[n];
	for(int i=0;i<n;i++){
		tableau[i]=0;
	}
	return tableau;
}
```

## Question 2

```java
public static void afficheTableau(int[] tableau){
	for (int i=0;i<tableau.length;i++) System.out.print(tableau[i]+" ");
}
```

## Question 3

On devrait modifier les `int[]` en `double[]`, aussi bien dans la sortie de `initTableau`, que dans les valeurs prises par `afficheTableau`

## Question 4

```java
public static int plusPetitElement(int[] tableau){
	int min=tableau[0];
	for(int i=1;i<tableau.length;i++){
		if (tableau[i]<min) min=tableau[i];
	}
	return min;
}
```

## Question 5

```java
public static int secondPlusPetit(int[] tableau){
	int indice=0;
	int min=tableau[0];
	for(int i=1;i<tableau.length;i++){
		if (tableau[i]<min) {
		min=tableau[i];
		indice=i;
		}
	}
	int min2=tableau[0];
	//on parcourt une deuxième fois le tableau
	for (int i=0; i<tableau.length;i++){
		if (tableau[i]<min && i!= indice) min2=tableau[i];
	}
	return min2;
}
```