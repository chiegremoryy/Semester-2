//JUDUL        : MEMBUAT PROGRAM MESIN ATM
//CREATED BY   : MUHAMMAD ARIEF HIDAYATULLAH
//NIM          : A11.2022.14788
//KELOMPOK     : A11.4219
//DATE         : 22 JUNI 2023

#include <iostream> //library untuk input/output standar
#include <fstream> //library untuk operasi file
#include <ctime> //library untuk manipulasi waktu
#include <vector> //library untuk menggunakan vektor
#include <iomanip> //library untuk memanipulasi output yang berupa setw, setfill
#include "main.h" //untuk mengikutsertakan file header "main.h" ke dalam file .cpp sewaktu dilakukannya runnign program

using namespace std;
//program running
int main() {
    //kamus global
    int pin;
    string loop;
    //looping
    do{
    cout << "[==============================================]" << endl;
    cout << "|======= SELAMAT DATANG DI ATM CHIE RI ========|" << endl;
    cout << "[==============================================]" << endl;
    cout << " Masukkan Pin ATM (angka 6 digit) : ";
    cin >> pin; //inputan

    //perkondisian
    if (pin == 200503) {
        Opsi atm; //membuat objek "atm" dari class Opsi. ini juga dapat diasumsikan bahwa class Opsi telah dideklarasikan dan diimplementasikan di dalam file header "main.h".
        //kamus lokal
        int pilihan;
            atm.tampilMenu(); //untuk memanggil function tampilMenu
            cout << " Ohayoo, Muhammad Arief Hidayatullah >/< " << endl;
            cout << " Masukkan Menu Pilihan Anda : ";
            cin >> pilihan;
            system("cls"); //untuk clear screen output sebelumnya
            atm.opsiInput(pilihan); //untuk memanggil function opsiInput dengan parameter "pilihan' yang telah diinputkan sewaktu dilakukannya running program
    } else {
            cout << " Pin yang Anda Inputkan Salah! " << endl;
    }
    cin.ignore(); //untuk mengabaikan inputan headline
    cout << " Apakah Anda Ingin Melakukan Transaksi Lagi? (ya/tidak) : "; cin >> loop;
    system("cls"); //untuk clear screen output sebelumnya
    } while(loop == "ya");
    cout << setw(42) << setfill('>') << ">" << " Transaksi Selesai " << setw(43) << setfill('<') << "<" << endl;
    cout << setw(30) << setfill('>') << ">" << " Terima Kasih Telah Menggunakan ATM Chie RI " << setw(30) << setfill('<')<<"<"<< endl;
    //cetak pesan " Transaksi Selesai " yang diapit oleh tanda ">" dan "<" pada layar dengan menggunakan manipulator setw() dan setfill() untuk mengatur lebar dan pengisian karakter.
    return 0;
}

//ALHAMDULILLAH DONE:)
