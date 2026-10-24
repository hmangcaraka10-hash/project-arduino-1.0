# LED_SENSORULTRASONIC

Sketch C++ Arduino untuk sensor ultrasonik HC-SR04 dan dua LED indikator.

## Perilaku

- **LED merah** menyala jika tidak ada pantulan yang terdeteksi atau objek berada lebih dari 30 cm.
- **LED hijau** menyala jika objek terdeteksi pada jarak 10 cm atau kurang.
- Jika objek berada di antara 10 cm dan 30 cm, kedua LED mati.

## Wiring

| Komponen | Pin Arduino |
|---|---:|
| HC-SR04 VCC | 5V |
| HC-SR04 GND | GND |
| HC-SR04 TRIG | D9 |
| HC-SR04 ECHO | D10 |
| LED merah (anoda melalui resistor 220 ohm) | D6 |
| LED hijau (anoda melalui resistor 220 ohm) | D7 |
| Katoda kedua LED | GND |

Buka `LED_SENSORULTRASONIC.ino` menggunakan Arduino IDE, pilih board dan port yang sesuai, lalu upload ke Arduino.
