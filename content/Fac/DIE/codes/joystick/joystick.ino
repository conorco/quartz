
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
char x_text;
char y_text;
                         
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


  if (data_x < 100) {
    x_text = "à gauche";
  }

  if (data_x > 900) {
    x_text = "à droite";
  }

  if (data_x > 400 and data_x < 600) {
    x_text = "au milieu";
  } 

  if (data_y < 100) {
    y_text = "en haut";
  }

  if (data_y > 900) {
    y_text = "en bas";
  }

  if (data_y > 400 and data_y < 600) {
    y_text = "au milieu";
  } 


  if (data_bp < 100) {
    appui = true;
  }
  else appui = false; 

  if (appui) {
  Serial.println("BP appuye");
  }
  else Serial.println("BP non appuye");
  
  Serial.print(x_test)
  Serial.print(y_test)

//  Serial.print("X = ");
//  Serial.println(data_x);
//  Serial.print("Y = ");
//  Serial.println(data_y);


  delay(100);                      

}


