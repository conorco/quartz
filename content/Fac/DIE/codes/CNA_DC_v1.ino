 


/******************************************************************************************/
/* 
/* L1 - DIE
/* Pilotage du CNA
/*
/* S. CRAND - juin 2017
/* Génération d'un signal continu - DC
/*
/* Statut : ok
/******************************************************************************************/

  
/*****************************/
/* CNA : Broches utilisées   */
/*****************************/
int CNA_DATA[8] = {
    6, 7, 8, 9, 10, 11, 12, 13};

int CNA_WRB = 5; 

/*****************************/
/* CAN : Broches utilisées   */
/*****************************/

int WRB_CAN = 2; 


/***************/
/* Variables   */
/***************/

int j = 0;
byte mask = 1;

const int nb_data = 1;
byte data[nb_data] {B10000000
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
  
  delayMicroseconds(10);
  
  digitalWrite(CNA_WRB, HIGH);
 }
}
