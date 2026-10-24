# LED1213

Program Arduino untuk menyalakan tiga LED secara bergantian seperti lampu indikator tiga warna.

## Komponen dan wiring

| LED | Pin Arduino |
|---|---:|
| LED merah | D13 |
| LED hijau | D12 |
| LED biru | D8 |

Hubungkan setiap LED melalui resistor pembatas arus, misalnya 220 ohm, dan hubungkan katodanya ke GND.

## Cara kerja

LED hijau menyala selama 500 ms, kemudian LED merah menyala selama 500 ms, lalu LED biru menyala selama 500 ms. Hanya satu LED yang menyala pada satu waktu, dan urutan ini berulang terus-menerus.

Upload `LED1213.ino` menggunakan Arduino IDE setelah memilih board dan port yang sesuai.
