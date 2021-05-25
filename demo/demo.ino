#include <IRremote.h>
int RECEIVE_PIN = 11;
IRrecv irrecv(RECEIVE_PIN);
decode_results results;
int i=0;
void setup()
{
  Serial.begin(250000);
  irrecv.enableIRIn();
  pinMode(13,OUTPUT);
}
void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
    irrecv.resume();
    if(results.value==0xFF30CF)
    {
        i++;
        int x=i%2;
        digitalWrite(13, x);
    }
  }
}
