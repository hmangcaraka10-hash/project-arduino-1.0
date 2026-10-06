#define ledMerah 13
#define ledHijau 12
#define ledBiru 8


void setup() 
{
pinMode(ledMerah, OUTPUT);
pinMode(ledHijau, OUTPUT);
pinMode(ledBiru, OUTPUT);

}

void loop() 
{
  
digitalWrite(ledHijau, HIGH);
digitalWrite(ledMerah, LOW);
digitalWrite(ledBiru, LOW);
delay(500);
digitalWrite(ledHijau, LOW);
digitalWrite(ledMerah, HIGH);
digitalWrite(ledBiru, LOW);
delay(500);
digitalWrite(ledHijau, LOW);
digitalWrite(ledMerah, LOW);
digitalWrite(ledBiru, HIGH);
delay(500);

  
}
