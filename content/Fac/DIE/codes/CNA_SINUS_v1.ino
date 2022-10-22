 


/******************************************************************************************/
/* 
/* L1 - DIE
/* Pilotage du CNA
/*
/* S. CRAND - juin 2017
/* Génération d'un signal sinus - DC
/*
/* Statut : OK
/******************************************************************************************/

/*****************************/
/* CAN : Broches utilisées   */
/*****************************/

int WRB_CAN = 2; 



/*****************************/
/* CNA : Broches utilisées   */
/*****************************/

int CNA_DATA[8] = {
    6, 7, 8, 9, 10, 11, 12, 13};

int CNA_WRB = 5; 

/***************/
/* VARIABLES   */
/***************/

int j = 0;
byte mask = 1;

const int nb_data = 51;

byte data[nb_data] {B10000000,
B10010000,
B10011111,
B10101111,
B10111101,
B11001011,
B11010111,
B11100010,
B11101100,
B11110011,
B11111001,
B11111101,
B11111111,
B11111111,
B11111101,
B11111001,
B11110011,
B11101100,
B11100010,
B11010111,
B11001011,
B10111101,
B10101111,
B10100000,
B10010000,
B10000000,
B01110000,
B01100000,
B01010001,
B01000010,
B00110100,
B00101000,
B00011101,
B00010100,
B00001100,
B00000110,
B00000010,
B00000000,
B00000000,
B00000010,
B00000110,
B00001100,
B00010011,
B00011101,
B00101000,
B00110100,
B01000010,
B01010000,
B01011111,
B01101111,
B01111111,

};


void setup()
{
  pinMode(WRB_CAN, OUTPUT);
  

/******************************************************/
/* Définition des entrées/sorties du microcontrôleur */
/******************************************************/
for (int i=0; i<8; i++)
{
	pinMode(CNA_DATA[i], OUTPUT); 
}
pinMode(CNA_WRB, OUTPUT);
}



void loop()
{

digitalWrite(WRB_CAN, HIGH);

for (int ii=0; ii<nb_data; ii++)
 {
 j = 0;
delayMicroseconds(1000);
 for (mask = 00000001; mask>0; mask <<= 1) { 
    if (data[ii] & mask){ 
      digitalWrite(CNA_DATA[j],HIGH); 
    }
    else{ 
      digitalWrite(CNA_DATA[j],LOW); 
    }
    j = j + 1;
  }

  digitalWrite(CNA_WRB, LOW);
  
  delayMicroseconds(1);
  
  digitalWrite(CNA_WRB, HIGH);
 }
}




