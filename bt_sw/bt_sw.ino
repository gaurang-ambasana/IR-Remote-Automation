#define relay1 13
#define sw 2
int buttonState = 1;         // variable for reading the pushbutton status
int lastbuttonState = 1;         // variable for reading the pushbutton status
int stat=0,temp=0;
char btstr;
void setup()
{
   Serial.begin(9600);
   pinMode(relay1, OUTPUT);
   pinMode(sw,INPUT_PULLUP);
   digitalWrite(relay1, LOW);
}
void loop()
{
  if(temp==1)
  {
    temp=0;
    if(stat==1)
    {digitalWrite(relay1, LOW);delay(100);stat=0;}
    else
    {digitalWrite(relay1, HIGH);delay(100);stat=1;}
  }
  else
  { lastbuttonState = digitalRead(sw);
    if(lastbuttonState!=buttonState)
    {buttonState=lastbuttonState;
    if(stat==1)
    {digitalWrite(relay1, LOW);delay(100);stat=0;}
    else
    {digitalWrite(relay1, HIGH);delay(100);stat=1;}
    }
  }
}

void serialEvent() 
 {
  while(Serial.available()) 
  {
      btstr=Serial.read();
      if(btstr=='a')
      {
        temp=1;
        return;
      } 
  } 
 }
