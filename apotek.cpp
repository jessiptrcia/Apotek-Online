#include <iostream>
#include "apotek.h"

void tambahData() {
    if (jumlahObat >= MAX_OBAT) {
        cout << "Kapasitas penyimpanan penuh. Tidak bisa menambah data baru.\n";
        return;
    }
    Obat obatBaru;
    cout << "Masukkan No. Batch Obat: ";
    cin >> obatBaru.noBatch;
    cin.ignore();
    cout << "Masukkan Nama Obat: ";
    getline(cin, obatBaru.nama);
    dataObat[jumlahObat] = obatBaru;
    jumlahObat++;
    cout << "Data berhasil ditambahkan.\n";
}

void tampilkanData() {
    if (jumlahObat == 0) {
        cout << "Tidak ada data obat.\n";
        return;
    }
    cout << "Data Obat:\n";
    for (int i = 0; i < jumlahObat; ++i) {
        cout << "No. Batch: " << dataObat[i].noBatch
             << ", Nama: " << dataObat[i].nama << '\n';
    }
}

int binarySearch(int left, int right, int noBatch) {
    if (left > right) {
        return -1; // Basis rekursi: tidak ditemukan
    }

    int mid = left + (right - left) / 2;
    if (dataObat[mid].noBatch == noBatch) {
        return mid;
    } else if (dataObat[mid].noBatch > noBatch) {
        return binarySearch(left, mid - 1, noBatch);
    } else {
        return binarySearch(mid + 1, right, noBatch);
    }
}

int sequentialSearch(int noBatch) {
    for (int i = 0; i < jumlahObat; ++i) {
        if (dataObat[i].noBatch == noBatch) {
            return i;
        }
    }
    return -1;
}

void menu() {
    cout << "=== Aplikasi Apotek Sederhana ===\n";
    cout << "1. Tambah Data Obat\n";
    cout << "2. Tampilkan Data Obat\n";
    cout << "3. Cari Data Obat (Binary Search)\n";
    cout << "4. Cari Data Obat (Sequential Search)\n";
    cout << "0. Keluar\n";
    cout << "Pilih menu: ";
}

void pilih(int pilihan) {
    if (pilihan == 1) {
        tambahData();
    } else if (pilihan == 2) {
        tampilkanData();
    } else if (pilihan == 3) {
        int noBatch;
        cout << "Masukkan No. Batch obat yang ingin dicari: ";
        cin >> noBatch;

        int index = binarySearch(0, jumlahObat - 1, noBatch);

        if (index == -1) {
            cout << "Obat dengan No. Batch tersebut tidak ditemukan.\n";
        } else {
            cout << "No. Batch: " << dataObat[index].noBatch
                 << ", Nama: " << dataObat[index].nama << '\n';
        }
    } else if (pilihan == 4) {
        int noBatch;
        cout << "Masukkan No. Batch obat yang ingin dicari: ";
        cin >> noBatch;

        int index = sequentialSearch(noBatch);

        if (index == -1) {
            cout << "Obat dengan No. Batch tersebut tidak ditemukan.\n";
        } else {
            cout << "No. Batch: " << dataObat[index].noBatch
                 << ", Nama: " << dataObat[index].nama << '\n';
        }
    } else if (pilihan == 0) {
        cout << "Keluar dari aplikasi.\n";
    } else {
        cout << "Pilihan tidak valid. Silakan pilih menu yang tersedia.\n";
    }
}
