
/******************************************************************************************/
/* 
/* L1 - DIE
/* Pilotage du CAN
/*
/* S. CRAND - juin 2017
/* Capteur de température
/*
/* Statut :  OK
/******************************************************************************************/


/*********************************************/
/* Capteur température : Broches utilisées   */
/*********************************************/

int son = A1;        // pin ADC1   
                 
int data;
int data_moy;
//int data_cum;
int nb_echantillons;
int i;
                         
void setup() {
              
/******************************************************/
/* Définition du débit de transmission : 9600 bits/s  */
/******************************************************/
  Serial.begin(9600);
} 



void loop() {

nb_echantillons = 0;
data_moy = 0;
  for (i= 1; i<= 500 ; i++ )
  {
    data = analogRead(A1) ;
    if (( ( data ) > ( data_moy ) ))
    {
      data_moy=data+data_moy;
      nb_echantillons=nb_echantillons+1;
    }
  }
  data_moy=data_moy/nb_echantillons;

  
  Serial.println(data_moy);                           

}


