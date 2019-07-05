void setup() {
  // put your setup code here, to run once:
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);

  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);

  pinMode(10,1);
  pinMode(11,1);
  pinMode(12,1);
  pinMode(13,1);

  Serial.begin(9600);
}

int input_0;
int i=0;
int num=0;
int letter[10][4]={
  {0,0,0,0},{0,0,0,1},{0,0,1,0},{0,0,1,1},{0,1,0,0},
  {0,1,0,1},{0,1,1,0},{0,1,1,1},{1,0,0,0},{1,0,0,1}
  };

int LSX[4][4]={
  {0,1,1,1},{1,0,1,1},{1,1,0,1},{1,1,1,0}
  };


void pr(int LSX_,int input);

void loop() {
  // put your main code here, to run repeatedly:
  
  if(Serial.available()>0)
  {
    input_0=Serial.read();

    if(num==16)
    num=0;

    pr(num%4,input_0);
       
    num++;
    
    }
  
}

void pr(int LSX_,int input)
{
  
  for(i=0;i<4;i++)
  {
    digitalWrite(10+i,LSX[LSX_][i]);
    }
  
  input=input-48;

  for(i=0;i<4;i++)
  {
    digitalWrite(5-i,letter[input][i]);
    }
       
  delay(1000);
      
  }
