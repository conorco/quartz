
/******************************************************************************************/
/* 
/* L1 - DIE
/* Pilotage du CAN
/*
/* S. CRAND - juin 2017
/* Capteur à ultrason
/*
/* Statut :  en développement
/******************************************************************************************/

const int numOfReadings = 5;                   // Nombre de mesures pour calculer la distance
int readings[numOfReadings];                    // Stockage de la distance dans un tableau de taille numOfReadings
int total = 0;                                  
int averageDistance = 0;                        // Calcul de la distance moyenne


/************************************/
/* Capteur US : Broches utilisées   */
/************************************/

int echo = 4;        // pin 4                       
int trigger = 3;     // pin 3                          

unsigned long pulseTime = 0;                    // stores the pulse in Micro Seconds
unsigned long distance = 0;                     // variable for storing the distance (cm)

void setup() {
  
/******************************************************/
/* Définition des entrées/sorties du microcontrôleur  */
/******************************************************/
  pinMode(trigger, OUTPUT);                     
  pinMode(echo, INPUT);                      

/******************************************************/
/* Définition du débit de transmission : 9600 bits/s  */
/******************************************************/
  Serial.begin(9600);
} 



void loop() {
  
/*******************************************************************/
/* Initialisation du tableau de données pemermettant le moyennage  */
/*******************************************************************/
  for (int thisReading = 0; thisReading < numOfReadings; thisReading++) {
    readings[thisReading] = 0;
  }
  total = 0;

  for (int arrayIndex = 0; arrayIndex < numOfReadings; arrayIndex++) {
    digitalWrite(trigger, HIGH);                    
    delayMicroseconds(10);                  
    digitalWrite(trigger, LOW);                    
    pulseTime = pulseIn(echo, HIGH);             
    distance = pulseTime/58;                        
    readings[arrayIndex] = distance;               
    total= total + readings[arrayIndex];     
    delay(100);         
  }
  averageDistance = total / numOfReadings;      // Calcul de la moyenne

  Serial.println(averageDistance, DEC);         // Envoi de la distance sur le port série
 // delay(100);                                   

}

