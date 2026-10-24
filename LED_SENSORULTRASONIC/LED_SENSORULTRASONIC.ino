/*
  LED_SENSORULTRASONIC
  Sensor ultrasonik HC-SR04 mengendalikan dua LED.

  Perilaku:
  - LED merah menyala jika tidak ada objek terdeteksi atau jaraknya > 30 cm.
  - LED hijau menyala jika objek terdeteksi pada jarak <= 10 cm.
  - Pada jarak > 10 cm dan <= 30 cm, kedua LED mati.
*/

const byte TRIG_PIN = 9;
const byte ECHO_PIN = 10;
const byte RED_LED_PIN = 6;
const byte GREEN_LED_PIN = 7;

const float GREEN_DISTANCE_CM = 10.0;
const float RED_DISTANCE_CM = 30.0;

float readDistanceCm() {
  // Pastikan pin pemicu berada LOW sebelum mengirim pulsa.
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  // Kirim pulsa trigger 10 mikrodetik.
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Timeout mencegah program berhenti jika tidak ada pantulan.
  unsigned long duration = pulseIn(ECHO_PIN, HIGH, 30000UL);

  if (duration == 0) {
    return -1.0; // Tidak ada objek/pantulan yang terdeteksi.
  }

  return (duration * 0.0343) / 2.0;
}

void setLedState(bool redOn, bool greenOn) {
  digitalWrite(RED_LED_PIN, redOn ? HIGH : LOW);
  digitalWrite(GREEN_LED_PIN, greenOn ? HIGH : LOW);
}

void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(RED_LED_PIN, OUTPUT);
  pinMode(GREEN_LED_PIN, OUTPUT);

  setLedState(false, false);
  Serial.begin(9600);
}

void loop() {
  float distanceCm = readDistanceCm();

  if (distanceCm < 0 || distanceCm > RED_DISTANCE_CM) {
    // Tidak terdeteksi atau objek berada lebih dari 30 cm.
    setLedState(true, false);
    Serial.println("LED MERAH: objek tidak terdeteksi dalam 30 cm");
  } else if (distanceCm <= GREEN_DISTANCE_CM) {
    // Objek terdeteksi pada jarak 10 cm atau kurang.
    setLedState(false, true);
    Serial.print("LED HIJAU: objek terdeteksi pada ");
    Serial.print(distanceCm, 1);
    Serial.println(" cm");
  } else {
    // Zona antara 10 cm dan 30 cm.
    setLedState(false, false);
    Serial.print("Zona antara 10-30 cm: ");
    Serial.print(distanceCm, 1);
    Serial.println(" cm");
  }

  delay(200);
}
