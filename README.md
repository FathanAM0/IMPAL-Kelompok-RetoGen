## Deskripsi Proyek
Repository ini berisi implementasi Process Specification (PSPEC) untuk mata kuliah Implementasi dan Pengujian Perangkat Lunak. Proyek ini mencakup empat program berbeda yang diimplementasikan dalam bahasa C dan Pascal.

## Anggota Kelompok RetoGen
- Fathan Arya Maulana (103012300083)
- Rafiq Labib (103012330353)
- Dzaky Alfaris (103012300391)
- M. Rifqi Dzaky Azhad (103012330009)

## Daftar Program

### 1. Program Determine Triangle - C (M. Rifqi Dzaky Azhad)

**Deskripsi:** Program untuk menentukan validitas dan jenis segitiga berdasarkan tiga bilangan input.

**Input:** Tiga bilangan bertipe data Integer atau Double.

**Output:** String yang menunjukkan jenis segitiga:
- TIDAK ADA SEGITIGA
- SEGITIGA SAMA SISI
- SEGITIGA SAMA KAKI
- SEGITIGA SIKU SIKU
- SEGITIGA BEBAS

**Fitur:**
- Mendukung input bilangan bulat dan pecahan
- Toleransi 1% untuk bilangan pecahan
- Validasi ketidaksamaan segitiga

**Flow Graph:**
```
[Start]
   ↓
[Input: Pilih Mode (Bulat/Pecahan)]
   ↓
[Input: a, b, c]
   ↓
[Validasi: a ≤ 0 || b ≤ 0 || c ≤ 0?]
   ↓ Ya → [Output: TIDAK ADA SEGITIGA] → [End]
   ↓ Tidak
[Cari max, sum]
   ↓
[Cek: max == sum?]
   ↓ Ya → [Output: TIDAK ADA SEGITIGA] → [End]
   ↓ Tidak
[Cek: a == b == c?]
   ↓ Ya → [Output: SEGITIGA SAMA SISI] → [End]
   ↓ Tidak
[Cek: a == b || b == c || a == c?]
   ↓ Ya → [Output: SEGITIGA SAMA KAKI] → [End]
   ↓ Tidak
[Cek: a² + b² == c² (atau permutasi)?]
   ↓ Ya → [Output: SEGITIGA SIKU SIKU] → [End]
   ↓ Tidak
[Output: SEGITIGA BEBAS]
   ↓
[End]
```

---

### 2. Program Servis Komputer - C (Dzaky Alfaris)

**Deskripsi:** Program untuk menghitung biaya servis komputer berdasarkan jumlah perangkat dan kondisi layanan.

**Input:**
- Jumlah komputer (integer)
- Jumlah peripheral (integer)
- Status jam operasional (boolean sebagai integer: 0/1)
- Kesediaan drop-off dan pick-up (boolean sebagai integer: 0/1)

**Output:** Rincian biaya servis meliputi:
- Biaya dasar
- Biaya tambahan (peripheral)
- Diskon drop-off (jika ada)
- Biaya diluar jam kerja (jika ada)
- Total biaya servis

**Aturan Perhitungan:**
- 1-2 komputer: base fee $50, additional fee $0
- 3-10 komputer: base fee $100, additional fee $10 per peripheral
- >10 komputer: base fee $500, additional fee $10 per peripheral
- Diluar jam bisnis: base fee dikali 2
- Drop-off & pick-up: diskon 50% dari total base fee

**Flow Graph:**
```
[Start]
   ↓
[Input: computer_amount, peripheral_count, is_business_hours, is_willing_dropoff]
   ↓
[Cek: computer_amount <= 2?]
   ↓ Ya → [base_fee = 50, additional_fee = 0]
   ↓ Tidak
[Cek: computer_amount <= 10?]
   ↓ Ya → [base_fee = 100, additional_fee = 10 × peripheral_count]
   ↓ Tidak
[base_fee = 500, additional_fee = 10 × peripheral_count]
   ↓
[total_base_fee = base_fee]
   ↓
[Cek: is_business_hours == 0?]
   ↓ Ya → [total_base_fee = base_fee × 2]
   ↓ Tidak
[Cek: is_willing_dropoff == 1?]
   ↓ Ya → [total_base_fee = total_base_fee ÷ 2]
   ↓ Tidak
[total_fee = total_base_fee + additional_fee]
   ↓
[Output: Rincian Biaya]
   ↓
[End]
```

---

### 3. Program Invoice Servis Komputer - C (Rafiq Labib)

**Deskripsi:** Program untuk memvalidasi ID akun dan menampilkan informasi invoice penjualan.

**Input:** Satu bilangan integer sebagai representasi ID akun.

**Output:**
- Jika ID ditemukan: Nomor akun dan jumlah penjualan
- Jika ID tidak ditemukan: Pesan error "Akun tidak ditemukan atau tidak valid"

**Kondisi:**
- **Precondition 1:** Customer datang dengan account-number yang cocok di ACCOUNTS dengan status-code "valid"
- **Postcondition 1:** Invoice diproduksi dengan account-number dan amount-of-sale
- **Precondition 2:** Account-number tidak ditemukan atau status-code bukan "valid"
- **Postcondition 2:** Error message ditampilkan

**Flow Graph:**
```
[Start]
   ↓
[Input: account_number]
   ↓
[Cari account_number di array ACCOUNTS]
   ↓
[Cek: Account ditemukan?]
   ↓ Tidak → [Output: ERROR - Akun tidak valid] → [End]
   ↓ Ya
[Cek: status_code == "valid"?]
   ↓ Tidak → [Output: ERROR - Akun tidak valid] → [End]
   ↓ Ya
[Output: Account Number & Amount of Sale]
   ↓
[End]
```

---

### 4. Program Servis Komputer - Pascal (Fathan Arya Maulana)

**Deskripsi:** Implementasi Pascal untuk menghitung biaya servis komputer dengan aturan yang sama seperti program C versi Dzaky Alfaris.

**Input:**
- Jumlah komputer (integer)
- Jumlah peripheral (integer)
- Status jam operasional (boolean sebagai integer: 0/1)
- Kesediaan drop-off dan pick-up (boolean sebagai integer: 0/1)

**Output:** Rincian biaya servis meliputi:
- Biaya dasar
- Biaya tambahan (peripheral)
- Diskon drop-off (jika ada)
- Biaya diluar jam kerja (jika ada)
- Total biaya servis

**Flow Graph:**
```
[Start]
   ↓
[Input: computer_amount, peripheral_count, is_business_hours, is_willing_dropoff]
   ↓
[Cek: computer_amount <= 2?]
   ↓ Ya → [base_fee = 50, additional_fee = 0]
   ↓ Tidak
[Cek: computer_amount <= 10?]
   ↓ Ya → [base_fee = 100, additional_fee = 10 × peripheral_count]
   ↓ Tidak
[base_fee = 500, additional_fee = 10 × peripheral_count]
   ↓
[total_base_fee = base_fee]
   ↓
[Cek: is_business_hours == 0?]
   ↓ Ya → [total_base_fee = base_fee × 2]
   ↓ Tidak
[Cek: is_willing_dropoff == 1?]
   ↓ Ya → [total_base_fee = total_base_fee ÷ 2]
   ↓ Tidak
[total_fee = total_base_fee + additional_fee]
   ↓
[Output: Rincian Biaya]
   ↓
[End]
```

---

## Cara Menjalankan Program

### Program C
```bash
# Compile
gcc nama_file.c -o nama_program

# Run
./nama_program
```

### Program Pascal
```bash
# Compile
fpc nama_file.pas

# Run
./nama_file
```

## Link Repository
[https://github.com/FathanAM0/IMPAL-Kelompok-RetoGen](https://github.com/FathanAM0/IMPAL-Kelompok-RetoGen)