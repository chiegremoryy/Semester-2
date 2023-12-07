#include <iostream> //library untuk input/output standar
#include "main.h" //untuk mengikutsertakan file header "main.h" ke dalam file .cpp sewaktu dilakukannya runnign program

using namespace std;

// Program utama
int main() {
    Perpustakaan perpustakaan;
    string loop;
    int pilihan;

    do {
        cout << "[==============================================]" << endl;
        cout << "|======= SELAMAT DATANG DI PERPUSTAKAAN =======|" << endl;
        cout << "[==============================================]" << endl;

        Opsi::tampilMenu();
        pilihan = Opsi::opsiInput();

        switch (pilihan) {
            case 1:
                perpustakaan.tambahBuku();
                break;
            case 2:
                perpustakaan.tampilDaftarBuku();
                break;
            case 3:
                perpustakaan.updateBuku();
                break;
            case 4:
                //perpustakaan.cariBuku()
                break;
            case 5:
            {
                perpustakaan.hapusBuku();
                break;
            }
            case 6:
                //perpustakaan.pinjamBuku();
                break;
            case 7:
                //perpustakaan.kembalikanBuku();
                break;
            case 8:
                //perpustakaan.hitungDenda();
                break;
            case 9:
                cout << " Terima kasih telah menggunakan program perpustakaan. Sampai jumpa lagi!" << endl;
                exit(0);
                break;
            default:
                cout << " Pilihan Menu Yang Anda Pilih Tidak Tersedia." << endl;
                break;
        }

        cout << " Apakah Anda Ingin Kembali ke Menu Utama? (ya/tidak): ";
        cin >> loop;
        system("cls");

    } while (loop == "ya");
    return 0;
}


