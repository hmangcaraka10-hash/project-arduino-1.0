# RFID_RELAY

Program Arduino untuk membaca UID kartu RFID menggunakan MFRC522 dan mengendalikan dua output relay berdasarkan kartu yang dipindai.

## Komponen dan wiring

| Komponen | Pin Arduino |
|---|---:|
| MFRC522 SDA/SS | D10 |
| MFRC522 RST | D9 |
| MFRC522 MOSI/MISO/SCK | SPI board |
| Output relay 1 | D7 |
| Output relay 2 | D6 |
| MFRC522 VCC/GND | Sesuai kebutuhan modul |

## Kartu yang dikenali

UID yang diberi perlakuan khusus adalah:

```text
F9 A6 13 06
```

UID lain akan menjalankan cabang output alternatif. UID lain yang tercatat pada komentar kode adalah `D1 2D D4 06`, tetapi belum digunakan sebagai UID akses di logika program.

## Cara kerja

- Kartu dengan UID `F9 A6 13 06` menyalakan output relay 2 (`D7 HIGH`, `D6 LOW`) selama 3 detik.
- Kartu dengan UID lain menyalakan output relay 1 (`D7 LOW`, `D6 HIGH`) selama 3 detik.
- UID kartu dicetak ke Serial Monitor pada baud rate `9600`.

## Library

- `MFRC522`
- `SPI` (bawaan Arduino)

Sesuaikan logika HIGH/LOW dengan jenis modul relay yang digunakan. Gunakan catu daya dan driver relay yang sesuai, bukan menghubungkan beban berdaya besar langsung ke pin Arduino.
