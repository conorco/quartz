 


/******************************************************************************************/
/* 
/* L1 - DIE
/* Pilotage du CAN
/*
/* S. CRAND - juin 2017
/* Génération du signal d'échantillonnage
/*
/* Statut :  OK
/******************************************************************************************/

  
/*****************************/
/* CAN : Broches utilisées   */
/*****************************/

int WRB_CAN = 2; 



void setup()
{
 
/******************************************************/
/* Définition des entrées/sorties du microcontrôleur */
/******************************************************/

pinMode(WRB_CAN, OUTPUT);

}

void loop()
{

  digitalWrite(WRB_CAN, HIGH);

  delayMicroseconds(2000);

  digitalWrite(WRB_CAN, LOW);
  
  delayMicroseconds(10);

}
