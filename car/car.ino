void setup()
{
  pinMode(5 , OUTPUT);
  pinMode(6 , OUTPUT);
  pinMode(9 , OUTPUT);
  pinMode(10, OUTPUT);
  Serial.begin(9600);
}

int income=0;

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()>0)
  {
    income=Serial.read();
    switch(income)
    {
      case 'f':
        forward();
        break;
      case 'b':
        back();
        break;
      case 'l':
        left();
        break;
      case 'r':
        right();
        break;
      case 's':
        stoped();
        break;
      default:
        break;
    }
    }
}

void forward()
{
  digitalWrite(5 , HIGH);
  digitalWrite(6 , LOW );
  digitalWrite(9 , HIGH);
  digitalWrite(10, LOW );
  }

void back()
{
  digitalWrite(5 , LOW );
  digitalWrite(6 , HIGH);
  digitalWrite(9 , LOW );
  digitalWrite(10, HIGH);
  }
  
void left()
{
  digitalWrite(5 , HIGH);
  digitalWrite(6 , LOW );
  digitalWrite(9 , LOW );
  digitalWrite(10, HIGH);
  }

void right()
{
  digitalWrite(5 , LOW );
  digitalWrite(6 , HIGH);
  digitalWrite(9 , HIGH);
  digitalWrite(10, LOW );
  }

void stoped()
{
  digitalWrite(5 , LOW );
  digitalWrite(6 , LOW );
  digitalWrite(9 , LOW );
  digitalWrite(10, LOW );
  }
