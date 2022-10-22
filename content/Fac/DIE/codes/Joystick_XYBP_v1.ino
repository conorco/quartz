
/******************************************************************************************/
/* 
/* L1 - DIE
/* Pilotage du CAN
/*
/* S. CRAND - juin 2017
/* Joystick X Y BP
/*
/* Statut :  OK
/******************************************************************************************/

int bp = A3;       // pin ADC3
int x = A4;        // pin ADC4
int y = A5;        // pin ADC5
                 
int data_bp;
int data_x;
int data_y;

boolean appui;
                         
void setup() {
              
/******************************************************/
/* Définition du débit de transmission : 9600 bits/s  */
/******************************************************/
  Serial.begin(9600);
} 



void loop() {

  
  data_bp = analogRead(bp) ;
  data_x = analogRead(x) ;
  data_y = analogRead(y) ;

  if (data_bp < 100) {
    appui = true;
  }
  else appui = false; 

  if (appui) {
  Serial.println("BP appuye");
  }
  else Serial.println("BP non appuye");
  
  Serial.print("X = ");
  Serial.println(data_x);
  Serial.print("Y = ");
  Serial.println(data_y);


  delay(100);                      

}


