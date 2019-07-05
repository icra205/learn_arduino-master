#include "Arduino.h"


void morse(int pin);
void dot();
void dash();
void w_space();
void s_space();



int letter[28][4]={

// A to I

{1,2,0,0},{2,1,1,1},{2,1,2,1},{2,1,1,0},{1,0,0,0},{1,1,2,1},{2,2,1,0},{1,1,1,1},{1,1,0,0},

// J to R 

{1,2,2,2},{2,1,2,0},{1,2,1,1},{2,2,0,0},{2,1,0,0},{2,2,2,0},{1,2,2,1},{2,2,1,2},{1,2,1,0},

// S to Z

{1,1,1,0},{2,0,0,0},{ 1,1,2,0},{1,1,1,2},{1,2,2,0},{2,1,1,2},{2,1,2,2},{2,2,1,1 },{3,0,0,0},{4,0,0,0}

};



void setup()

{

  morse (8);  

  Serial.begin(9600);

  

}




int _pin;
int _dottime;


//*-** *---****

void loop()

{

  while(Serial.available() > 0 )

  {

  int ascii=Serial.read();

 

  ascii=ascii-65;



  for(int i=0;i<4;i++)

  {

    if(letter[ascii][i]==1)

    {

      dot();

      Serial.println('*');

      }

    else if(letter[ascii][i]==2)

    {

      dash();

      Serial.println('_');

      }

    else if(letter[ascii][i]==3)

    {

      c_space();

      Serial.println(' ');

      }

    else if(letter[ascii][i]==4)

    {

      w_space();

      Serial.println('\n');

      }

  }

  delay(3000);

  Serial.println('@');

  }



}




void morse(int pin)

{

  pinMode(pin,OUTPUT);

  _pin=pin;

  _dottime=250;

}



void dot()

{

  digitalWrite(_pin,HIGH);

  delay(_dottime);

  digitalWrite(_pin,LOW);

  delay(_dottime);

}



void dash()

{

  digitalWrite(_pin,HIGH);

  delay(_dottime*4);

  digitalWrite(_pin,LOW);

  delay(_dottime);

}



void c_space()

{

  digitalWrite(_pin,LOW);

  delay(_dottime*3);

}



void w_space()

{

  digitalWrite(_pin,LOW);

  delay(_dottime*7);

}
