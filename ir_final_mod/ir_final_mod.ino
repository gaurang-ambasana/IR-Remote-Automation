#include <IRremote.h>

const int RECV_PIN=12;
IRrecv irrecv(RECV_PIN);
decode_results results;

#define F1 8
#define F2 9
#define L1 10
#define L2 11

unsigned int i=0,j=0,k=0,n=0;

void setup()
{
  Serial.begin(250000);
  
  pinMode(F1, OUTPUT);
  pinMode(L1, OUTPUT);
  pinMode(L2, OUTPUT);
  pinMode(F2, OUTPUT);
  irrecv.enableIRIn();
  irrecv.blink13(true);

  digitalWrite(F1,HIGH);
  digitalWrite(F2,HIGH);
  digitalWrite(L1,HIGH);
  digitalWrite(L2,HIGH);
}

void loop() 
{
  
  if (irrecv.decode(&results)) {
     Serial.println(results.value, HEX);
     delay(100); 
     if((results.value==0x9716BE3F)|(results.value==0xFF30CF))// long dis
     {
        i++;
        int x=i%2;
        digitalWrite(F1, x);
        delay(200);
     }
    
     else if((results.value==0x3D9AE3F7)|(results.value==0xFF18E7)) 

     {
        j++;
        int x=j%2;
        digitalWrite(L1, x);
        delay(200);
     }
   
     else if((results.value==0x6182021B)|(results.value==0xFF7A85))
     {
        k++;
        int x=k%2;
        digitalWrite(F2, x);
        delay(200);
     }
       
       else if((results.value==0x8C22657B)|(results.value==0xFF10EF))
       {
          n++;
          int x=n%2;
          digitalWrite(L2, x);
          delay(200);
       }
     irrecv.resume();
     delay(100);
   }
}
