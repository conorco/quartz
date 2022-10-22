


/******************************************************************************************/
/* 
/* L1 - DIE
/* Pilotage du CNA
/*
/* S. CRAND - juin 2017
/* Génération d'un signal carré - DC
/*
/* Statut : OK
/******************************************************************************************/



/*************************/
/* Broches utilisées     */
/*************************/

/*****************************/
/* CAN : Broches utilisées   */
/*****************************/

int WRB_CAN = 2; 
 
/*********/
/* CNA   */
/*********/
int CNA_DATA[8] = {
    6, 7, 8, 9, 10, 11, 12, 13};

int CNA_WRB = 5; 

/***************/
/* VARIABLES   */
/***************/

int j = 0;
byte mask = 1;

const int nb_data = 2;
const byte data_h = B10000000;
const byte data_l = B00000000;

byte data[nb_data] {data_h,data_l
};


void setup()
{
  
/******************************************************/
/* Définition des entrées/sorties du microcontrôleur */
/******************************************************/

pinMode(WRB_CAN, OUTPUT);

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
 //delayMicroseconds(1000);
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




