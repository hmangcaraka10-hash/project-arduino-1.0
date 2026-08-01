#define led 13
#define ledHijau 12

void setup() 
{
pinMode(led, OUTPUT);
pinMode(ledHijau, OUTPUT);

}

void loop() 
{
  
digitalWrite(ledHijau, HIGH);
digitalWrite(led, LOW);
delay(500);
digitalWrite(ledHijau, LOW);
digitalWrite(led, HIGH);
delay(500);

}
