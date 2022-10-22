
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

int temp = A2;        // pin ADC2                       
int data;
                         
void setup() {
              
/******************************************************/
/* Définition du débit de transmission : 9600 bits/s  */
/******************************************************/
  Serial.begin(9600);
} 



void loop() {
  
/*******************************************************************/
/* Initialisation du tableau de données pemermettant le moyennage  */
/*******************************************************************/
  data = analogRead(temp);  
  Serial.println(data);                
  delayMicroseconds(10000);                           

}

