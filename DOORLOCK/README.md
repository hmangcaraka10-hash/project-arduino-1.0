# DOORLOCK

Sistem kunci pintu berbasis Arduino menggunakan pembaca RFID MFRC522, tombol manual, dan solenoid. Solenoid berubah status ON/OFF ketika kartu RFID yang diizinkan ditempelkan atau tombol ditekan.

## Komponen dan wiring

| Komponen | Pin Arduino |
|---|---:|
| MFRC522 SDA/SS | D10 |
| MFRC522 RST | D9 |
| MFRC522 MOSI/MISO/SCK | SPI board |
| Tombol | D7 |
| Solenoid | D4 |
| MFRC522 VCC/GND | Sesuai kebutuhan modul |

Pin `D3` dan `D6` disiapkan sebagai output (`in1` dan `in2`), tetapi belum digunakan dalam logika program saat ini.

## Akses RFID

UID kartu yang diizinkan di dalam kode adalah:

```text
D1 2D D4 06
```

Ganti nilai `targetUID` pada `DOORLOCK.ino` dengan UID kartu yang ingin diberi akses. UID dibaca dan ditampilkan di Serial Monitor pada baud rate `9600`.

## Cara kerja

- Tombol menggunakan `INPUT_PULLUP`: kondisi LOW berarti tombol ditekan.
- Tombol melakukan toggle solenoid dengan debounce 100 ms.
- Kartu dengan UID yang sesuai melakukan toggle solenoid.
- Kartu yang tidak sesuai menghasilkan pesan `Akses Ditolak`.
- Jeda antarpembacaan kartu yang diterima adalah 1,5 detik.

## Library

- `MFRC522`
- `SPI` (bawaan Arduino)

Gunakan driver/transistor atau modul relay yang sesuai untuk mengendalikan solenoid; jangan menghubungkan solenoid langsung ke pin Arduino.
