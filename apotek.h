#ifndef APOTEK_H_INCLUDED
#define APOTEK_H_INCLUDED

#include <iostream>
#include <string>
using namespace std;

struct Obat {
    int noBatch;
    string nama;
};

const int MAX_OBAT = 100; // Kapasitas maksimal data obat
inline Obat dataObat[MAX_OBAT];  // Definisi array obat
inline int jumlahObat = 0;       // Definisi jumlah obat

void tambahData();
void tampilkanData();
int binarySearch(int left, int right, int noBatch);
int sequentialSearch(int noBatch);
void menu();
void pilih(int pilihan);

#endif // APOTEK_H_INCLUDED
