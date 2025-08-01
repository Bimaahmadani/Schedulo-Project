# Schedulo - Manajer Tugas & Jadwal Kuliah (Qt Project)

**Schedulo** adalah aplikasi desktop berbasis Qt yang dirancang untuk membantu mahasiswa dalam mengelola jadwal kuliah dan tenggat waktu tugas secara efisien. Aplikasi ini memungkinkan pengguna untuk menambahkan, melihat, mencari, dan menghapus tugas dengan antarmuka grafis yang sederhana dan intuitif.

## ✨ Fitur Utama
- Tambah tugas lengkap dengan mata kuliah, deadline, dan keterangan.
- Tampilkan daftar tugas dalam tabel dengan fitur pencarian dan penghapusan.
- Data tersimpan permanen dalam file CSV.
- Siap dikembangkan dengan fitur status tugas seperti *belum selesai*, *urgent*, *terlambat*, dan *selesai*.

## 💡 Konsep Pemrograman yang Digunakan
Aplikasi ini merupakan penerapan dari berbagai konsep dasar pemrograman C++, di antaranya:
- **Struct dan Array Dinamis**: Representasi data tugas secara fleksibel.
- **Input / Proses / Output**: Pengambilan input pengguna dan menampilkannya secara terstruktur.
- **Percabangan dan Perulangan**: Menentukan status tugas berdasarkan deadline dan perulangan data.
- **Fungsi Modular**: Pemisahan logika ke dalam fungsi untuk kemudahan perawatan kode.
- **File Handling**: Menyimpan dan membaca data dari file `.csv`.
- **Sorting (opsional)**: Penyusunan data berdasarkan deadline.

## 🛠️ Teknologi
- Qt Creator (C++ GUI Framework)
- Qt Widgets (QDialog, QTableView, QLineEdit, dll.)
- File I/O dengan `QFile` dan `QTextStream`
- Data model menggunakan `QStandardItemModel`

## 📁 Struktur File Penting
- `main.cpp` – Entry point aplikasi
- `menuwindow.*` - Menu Utama aplikasi
- `tambahtugaswindow.*` – Dialog untuk menambah tugas baru
- `daftartugaswindow.*` – Tampilan daftar tugas
- `tugas.csv` – File penyimpanan tugas
