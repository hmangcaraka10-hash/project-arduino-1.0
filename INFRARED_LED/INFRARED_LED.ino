#define infrared 13
#define led 12

void setup() 
{
Serial.begin(9600);
pinMode(infrared, INPUT);
pinMode(led, OUTPUT);

}

void loop() 
{
if(digitalRead(infrared) == LOW){
  Serial.println("Objek terdeteksi");
  digitalWrite(led, HIGH);
  delay(1000);
}
if(digitalRead(infrared) == HIGH){
  Serial.println("Objek tidak terdeteksi");
  digitalWrite(led, LOW);
  delay(1000);
}

}
