
/******************************************************************************************/
/* 
/* L1 - DIE
/* Pilotage du CAN
/*
/* S. CRAND - septembre 2018
/* Fusion de données
/* Génération d'une trame :
/* balisedebut
/* joystick,x,514
/* joystick,y,123
/* joystick,bp,0
/* temperature,19
/* ultrason,25
/* son,72
/* lumiere,2
/* balisefin
/*
/* Statut :  OK
/******************************************************************************************/


/*********************************************/
/* Joystick : Broches utilisées              */
/*********************************************/


int bp = A3;       // pin ADC3
int x = A4;        // pin ADC4
int y = A5;        // pin ADC5

/*********************************************/
/* Capteur température : Broches utilisées   */
/*********************************************/

int temp = A2;        // pin ADC2                       

/************************************/
/* Capteur US : Broches utilisées   */
/************************************/

int echo = 4;        // pin 4                       
int trigger = 3;     // pin 3

/*********************************************/
/* Capteur audio : Broches utilisées   */
/*********************************************/

int son = A1;        // pin ADC1 

/*********************************************/
/* Capteur température : Broches utilisées   */
/*********************************************/

int lum = A0;        // pin ADC0
         

		 
int data_bp;
int data_x;
int data_y;
int data_temp;
int data_capus;
int data_son;
int data_lum;

unsigned long pulseTime = 0;                    // stores the pulse in Micro Seconds
unsigned long distance = 0;                     // variable for storing the distance (cm)
const int numOfReadings = 5;                   // Nombre de mesures pour calculer la distance
int readings[numOfReadings];                   // Stockage de la distance dans un tableau de taille numOfReadings
int total = 0;                                  
int averageDistance = 0;


int data;
int data_moy;
int nb_echantillons;
int i;



boolean appui;
                         
void setup() {
              
/******************************************************/
/* Définition du débit de transmission : 9600 bits/s  */
/******************************************************/
  Serial.begin(9600);
  
   pinMode(trigger, OUTPUT);                     
   pinMode(echo, INPUT); 
  
} 



void loop() {

  
/**********************/
/* Joystick           */
/**********************/
  data_bp = analogRead(bp) ;
  data_x = analogRead(x) ;
  data_y = analogRead(y) ;
 
  
  if (data_bp < 100) {
    appui = true;
	data_bp = 0;
  }
  else {
	appui = false; 
	data_bp = 1;
  } 
  
/*************************/
/* Capteur Temperature   */
/*************************/

data_temp = analogRead(temp); 
   
  
/**********************/
/* Capteur Ultrason   */
/**********************/
  
digitalWrite(trigger, HIGH);                    
delayMicroseconds(10);                  
digitalWrite(trigger, LOW);                    
pulseTime = pulseIn(echo, HIGH);             
distance = pulseTime/58;                        

data_capus = distance;         
 

/**********************/
/* Capteur audio      */
/**********************/

data_son = analogRead(A1) ;

/*************************/
/* Capteur Lumiere       */
/*************************/


 data_lum = analogRead(lum) ;

  
/****************************************/
/* Envoi trames sur le port série       */
/****************************************/


  /************************************/
  Serial.println("balisedebut");
  Serial.print("joystick,x,");
  Serial.println(data_x);
  Serial.print("joystick,y,");
  Serial.println(data_y);
  Serial.print("joystick,bp,");
  Serial.println(data_bp);
  Serial.print("temperature,");
  Serial.println(data_temp);
  Serial.print("ultrason,");
  Serial.println(data_capus);
  Serial.print("son,");
  Serial.println(data_son);
  Serial.print("lumiere,");
  Serial.println(data_lum);
  Serial.println("balisefin");
  /************************************/

  delay(2000);                      

}


