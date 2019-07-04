void setup() {
  // put your setup code here, to run once:
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);

  Serial.begin(9600);
}

int input;
int output=0;
int i=0;


void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()>0)
  {
    input=Serial.read();
    input=input-48;

    while(input>0)
    {
      output=input%2;
      digitalWrite(2+i,output);
      input=input/2;
      i++;
      }
    i=0;  
    delay(1000);
      
    }
}
