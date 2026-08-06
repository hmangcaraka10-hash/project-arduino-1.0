#define ledmerah 13
#define ledHijau 12

void setup() 
{
pinMode(ledmerah, OUTPUT);
pinMode(ledHijau, OUTPUT);

}

void loop() 
{
  
digitalWrite(ledHijau, HIGH);
digitalWrite(ledmerah, LOW);
delay(500);
digitalWrite(ledHijau, LOW);
digitalWrite(ledmerah, HIGH);
delay(500);

}
