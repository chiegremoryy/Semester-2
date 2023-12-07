#include <iostream> //library untuk input/output standar
#include "main.h" //untuk mengikutsertakan file header "main.h" ke dalam file .cpp sewaktu dilakukannya runnign program

using namespace std;
//program running
// Program utama
int main() {
    Perpustakaan perpustakaan;
    string loop;
    int pilihan;

    do {
        cout << "[=========================================================]" << endl;
        cout << "|======= SELAMAT DATANG DI PERPUSTAKAAN SIPLUSPLUS =======|" << endl;
        cout << "[=========================================================]" << endl;

        Opsi::tampilMenu();
        pilihan = Opsi::opsiInput();

        switch (pilihan) {
            case 1:
                cout << "[----------------------------------------------]" << endl;
                cout << "|>>>>>>>>>>>>>>   TAMBAH BUKU :  <<<<<<<<<<<<<<|" << endl;
                cout << "[----------------------------------------------]" << endl;
                perpustakaan.tambahBuku();
                break;
            case 2:
                perpustakaan.tampilDaftarBuku();
                break;
            case 3:
                perpustakaan.updateBuku();
                break;
            case 4:
                // Implementasi opsiSorting()
                break;
            case 5:
                // Implementasi opsiSearch()
                break;
            case 6:
            {
                perpustakaan.hapusBuku();
                break;
            }
            case 7:
                // Implementasi opsiPinjam()
                break;
            case 8:
                // Implementasi opsiKembali()
                break;
            case 9:
                // Implementasi opsiDenda()
                break;
            case 10:
                cout << "Terima kasih telah menggunakan program perpustakaan. Sampai jumpa lagi!" << endl;
                exit(0);
                break;
            default:
                cout << "Pilihan Menu Yang Anda Pilih Tidak Tersedia." << endl;
                break;
        }

        cout << "Apakah Anda Ingin Kembali ke Menu Utama? (ya/tidak): ";
        cin >> loop;
        system("cls");

    } while (loop == "ya");
    return 0;
}


