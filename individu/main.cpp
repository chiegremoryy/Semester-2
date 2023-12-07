#include <iostream>
#include <ctime>
using namespace std;

class Opsi {
public:
    // PROSEDUR UNTUK MENAMPILKAN PILIHAN MENU DARI PROGRAM BANK CHIE RI
    void tampilMenu() {
        cout << "[==============================================]" << endl;
        cout << "|======= SELAMAT DATANG DI BANK CHIE RI =======|" << endl;
        cout << "[==============================================]" << endl;
        cout << "|>>>>>>>>>>>>>>> PILIHAN MENU : <<<<<<<<<<<<<<<|" << endl;
        cout << "|=======    1. Tambah Tabungan          =======|" << endl;
        cout << "|=======    2. Setor Tunai              =======|" << endl;
        cout << "|=======    3. Tampil Data Tabungan     =======|" << endl;
        cout << "|=======    4. Tarik Saldo              =======|" << endl;
        cout << "|=======    5. Mutasi Saldo Tabungan    =======|" << endl;
        cout << "|=======    6. Cari Tabungan            =======|" << endl;
        cout << "|=======    7. Hapus Tabungan           =======|" << endl;
        cout << "|=======    8. Exit Program             =======|" << endl;
        cout << "|>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<|" << endl;
    }

    // PROSEDUR UNTUK MENGINPUTKAN PILIHAN MENU
    void opsiInput(int pilihan) {
        switch (pilihan) {
            case 1:
                opsiTambah();
                break;
            case 2:
                opsiSetor();
                break;
            case 3:
                opsiTampil();
                break;
            case 4:
                opsiTarik();
                break;
            case 5:
                opsiMutasi();
                break;
            case 6:
                opsiSearch();
                break;
            case 7:
                opsiDelete();
                break;
            case 8:
                cout << " Transaksi Selesai " << endl;
                cout << " Terima Kasih Telah Menggunakan ATM Chie RI " << endl;
                break;
            default:
                cout << " Pilihan Menu Yang Anda Pilih Tidak Tersedia. " << endl;
                break;
        }
    }

    // PROSEDUR UNTUK MENAMBAH DATA TABUNGAN KE INVENTORY
    int saldo = 1000000;
    void opsiTambah() {
        cout << "[----------------------------------------------]" << endl;
        cout << "|>>>>>>>>>>>>>> TAMBAH TABUNGAN : <<<<<<<<<<<<<|" << endl;
        cout << "[----------------------------------------------]" << endl;
        cout << "--------- Masukkan Data Tabungan Anda! ---------" << endl;
        cout << "----- SIMPEDES / BRITAMA / BRITAMA X / HAJI ----" << endl;
        // KAMUS LOKAL
        string jenis_tab;
        string nama_pemilik;
        int norek;
        string alamat;
        int saldo;
        // OUTPUT
        cout << " Jenis Tabungan : ";
        cin >> jenis_tab;
        cout << " Nama Pemilik : ";
        cin >> nama_pemilik;
        cout << " Nomor Rekening : ";
        cin >> norek;
        cout << " Alamat Pemilik : ";
        cin >> alamat;
        cout << " Setoran Awal : ";
        cin >> saldo;
        cout << "[----------------------------------------------]" << endl;
        cout << " Selamat Data Tabungan Anda Berhasil Disimpan ! " << endl;
        cout << " " << endl;
    }

    // PROSEDUR UNTUK SETOR TUNAI
    void opsiSetor() {
        cout << "[----------------------------------------------]" << endl;
        cout << "|>>>>>>>>>>>>>>>> SETOR TUNAI : <<<<<<<<<<<<<<<|" << endl;
        cout << "[----------------------------------------------]" << endl;
        // KAMUS LOKAL
        int setor_tunai;
        // OUTPUT
        cout << " Masukkan Nominal Uang Yang Ingin Disetor : ";
        cin >> setor_tunai;
        cout << " Selamat Uang Anda Berhasil Disetorkan ! " << endl;
        saldo = saldo + setor_tunai;
        cout << " Jumlah Saldo Di Tabungan Anda Yaitu : Rp " << saldo << endl;

    }

    // PROSEDUR UNTUK MENAMPILKAN DATA TABUNGAN
    void opsiTampil() {
        cout << "[----------------------------------------------]" << endl;
        cout << "|>>>>>>>>>>> TAMPIL DATA TABUNGAN : <<<<<<<<<<<|" << endl;
        cout << "[----------------------------------------------]" << endl;
        // Tambahkan logika untuk menampilkan data tabungan
    }

    // PROSEDUR UNTUK MELAKUKAN TARIK TUNAI
    void opsiTarik() {
        cout << "[----------------------------------------------]" << endl;
        cout << "|>>>>>>>>>>>>>>>> TARIK SALDO : <<<<<<<<<<<<<<<|" << endl;
        cout << "[----------------------------------------------]" << endl;
        //KAMUS LOKAL
        int tarik_tunai;
        cout << " Masukkan Nominal Uang Yang Ingin Di Tarik Tunai : ";
        cin >> tarik_tunai;
        cout << " Selamat Uang Anda Berhasil Di Tarik Tunai ! " << endl;
        saldo = saldo - tarik_tunai;
        cout << " Sisa Saldo Di Tabungan Anda Yaitu : Rp " << saldo << endl;
    }

    // PROSEDUR UNTUK MELAKUKAN MUTASI SALDO TABUNGAN
    void opsiMutasi() {
        cout << "[----------------------------------------------]" << endl;
        cout << "|>>>>>>>>>>> MUTASI SALDO TABUNGAN : <<<<<<<<<<|" << endl;
        cout << "[----------------------------------------------]" << endl;
    }

    // PROSEDUR UNTUK MENCARI TABUNGAN
    void opsiSearch() {
        cout << "[----------------------------------------------]" << endl;
        cout << "|>>>>>>>>>>>>>>> CARI TABUNGAN : <<<<<<<<<<<<<<|" << endl;
        cout << "[----------------------------------------------]" << endl;
    }

    // PROSEDUR UNTUK MENGHAPUS TABUNGAN
    void opsiDelete() {
        cout << "[----------------------------------------------]" << endl;
        cout << "|>>>>>>>>>>>>>>> HAPUS TABUNGAN : <<<<<<<<<<<<<|" << endl;
        cout << "[----------------------------------------------]" << endl;
    }
};

int main() {
    Opsi bank;
    int pilihan;

    do {
        bank.tampilMenu();
        cout << " Masukkan Menu Pilihan Anda : ";
        cin >> pilihan;
        bank.opsiInput(pilihan);
    } while (pilihan != 8);

    return 0;
}
