# Pendeteksi Objek dengan Sensor Infrared & LED (Arduino)

Proyek ini adalah sistem pendeteksi objek sederhana berbasis mikrokontroler Arduino. Sistem menggunakan **Sensor Obstacle Infrared (IR)** untuk mendeteksi keberadaan objek di depannya, mengontrol **LED** sebagai indikator visual, dan mengirimkan status ke **Serial Monitor**.

---

## 📌 Fitur Utama

* **Deteksi Objek Otomatis**: Memantau objek secara *real-time* menggunakan sensor infrared.
* **Indikator LED**: LED akan menyala saat objek terdeteksi dan mati saat tidak ada objek.
* **Log Serial Monitor**: Menampilkan status pembacaan ("Objek terdeteksi" / "Objek tidak terdeteksi") melalui komunikasi Serial.

---

## 🛠️ Skema Pin & Komponen

| Komponen | Pin Arduino | Keterangan |
| :--- | :--- | :--- |
| **Sensor IR (Out)** | `Pin 13` | Signal Pin (Input Digital) |
| **Sensor IR (VCC)** | `5V` | Catu Daya Sensor |
| **Sensor IR (GND)** | `GND` | Ground |
| **LED (Anoda / +)** | `Pin 12` | Output Digital (Gunakan Resistor 220Ω) |
| **LED (Katoda / -)** | `GND` | Ground |

---

## ⚙️ Cara Kerja Sistem

1. **Active LOW Output**: Sebagian besar modul sensor infrared obstacle memberikan sinyal **LOW (`0`)** saat mendeteksi pantulan cahaya dari objek.
2. **Kondisi Objek Terdeteksi (`LOW`)**:
   * Pesan `"Objek terdeteksi"` dikirim ke Serial Monitor.
   * LED menyala (`HIGH`).
   * Jeda/delay selama 1 detik.
3. **Kondisi Objek Tidak Terdeteksi (`HIGH`)**:
   * Pesan `"Objek tidak terdeteksi"` dikirim ke Serial Monitor.
   * LED mati (`LOW`).
   * Jeda/delay selama 1 detik.

---

## 🚀 Langkah Penggunaan

1. Rangkai komponen Arduino, sensor IR, dan LED sesuai dengan tabel pin di atas.
2. Buka **Arduino IDE** di PC/Laptop Anda.
3. Buat file baru, lalu salin (*copy-paste*) kode program ke dalam IDE.
4. Hubungkan board Arduino ke komputer menggunakan kabel USB.
5. Pilih **Board** dan **Port** yang sesuai pada menu `Tools`.
6. Klik tombol **Upload** (`Ctrl + U`).
7. Buka **Serial Monitor** (`Ctrl + Shift + M`) dengan *baud rate* **9600** untuk melihat status deteksi.