# DHT_LCD

Program Arduino untuk membaca kelembapan dan suhu dari sensor **DHT11**, menampilkan kelembapan pada LCD I2C 16x2, serta mencetak kelembapan dan suhu ke Serial Monitor.

## Komponen dan wiring

| Komponen | Pin Arduino |
|---|---:|
| DHT11 DATA | D2 |
| DHT11 VCC | 5V |
| DHT11 GND | GND |
| LCD I2C SDA | SDA (A4 pada Arduino Uno) |
| LCD I2C SCL | SCL (A5 pada Arduino Uno) |
| LCD I2C VCC/GND | 5V/GND |

Alamat LCD yang digunakan adalah `0x27`.

## Cara kerja

Program membaca sensor setiap 2 detik. Kelembapan ditampilkan pada LCD dengan format `humid : ...`, sedangkan kelembapan dan suhu dicetak ke Serial Monitor pada baud rate `9600`.

Jika pembacaan gagal, pesan kesalahan dikirim ke Serial Monitor.

## Library

- `DHT sensor library`
- `LiquidCrystal_I2C`

Pilih board dan port yang sesuai di Arduino IDE, lalu upload `DHT_LCD.ino`.
