#include <iostream>
#include "apotek.h"

using namespace std;

int main() {
    int pilihan;
    do {
        menu();        // Tampilkan menu
        cin >> pilihan; // Input pilihan dari user
        pilih(pilihan); // Jalankan pilihan yang diinputkan
        cout << endl;   // Beri jarak antar operasi untuk tampilan yang lebih baik
    } while (pilihan != 0); // Ulangi hingga user memilih keluar

    cout << "Terima kasih telah menggunakan aplikasi apotek sederhana.\n";
    return 0;
}
