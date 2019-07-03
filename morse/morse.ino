#include <Morse.h>
 
Morse morse(8);

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
  
  Serial.begin(9600);
  
}

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
    morse.dot();
    else if(letter[ascii][i]==2)
    morse.dash();
    else if(letter[ascii][i]==3)
    morse.c_space();
    else if(letter[ascii][i]==4)
    morse.w_space();
  }
  
  delay(3000);
  }

}
