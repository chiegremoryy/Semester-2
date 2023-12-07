#include <iostream>
#include <fstream>>
#include <vector>
#include <ctime>
using namespace std;

// Deklarasi class Buku
class Buku {
public:
    string judul;
    string kodeBuku;
    string penulis;
    string penerbit;
    int tahunTerbit;
    int stok;

    // Konstruktor
    Buku(string judul, string kodeBuku, string penulis, string penerbit, int tahunTerbit, int stok)
        : judul(judul), kodeBuku(kodeBuku), penulis(penulis), penerbit(penerbit), tahunTerbit(tahunTerbit), stok(stok) {}
};

// Deklarasi class Perpustakaan
class Perpustakaan {
private:
    vector<Buku> daftarBuku;

public:
    // Menambahkan Buku ke Daftar Buku
    void tambahBuku() {
        string judul, kodeBuku, penulis, penerbit;
        int tahunTerbit, stok;

        cout << " Masukkan Data Buku " << endl;
        cout << "Kode Buku: ";
        cin >> kodeBuku;
        cout << "Judul: ";
        cin.ignore();
        getline(cin, judul);
        cout << "Penulis: ";
        cin.ignore();
        getline(cin, penulis);
        cout << "Penerbit: ";
        getline(cin, penerbit);
        cout << "Tahun Terbit: ";
        cin >> tahunTerbit;
        cout << "Stok: ";
        cin >> stok;
        cout << endl;

        Buku buku(judul, kodeBuku, penulis, penerbit, tahunTerbit, stok);
        daftarBuku.push_back(buku);
        simpanDataBuku(buku);
        cout << " Buku berhasil ditambahkan ke perpustakaan." << endl;
    }

    // Menampilkan daftar buku
    void tampilDaftarBuku() {
        cout << "[----------------------------------------------]" << endl;
        cout << "|>>>>>>>>>>>>>>> DAFTAR BUKU : <<<<<<<<<<<<<<<<|" << endl;
        cout << "[----------------------------------------------]" << endl;
        ifstream inputFile("daftar_buku.txt");
        if (!inputFile) {
            cout << " Gagal membuka file. " << endl;
            return;
        }

        string line;
        while (getline(inputFile, line)) {
            cout << line << endl;
        }

        inputFile.close();
    }

    // Mengupdate data buku berdasarkan kode buku
    void updateBuku() {
        string kodeBuku;
        cout << "Masukkan Kode Buku yang akan diupdate: ";
        cin >> kodeBuku;

        editDataBuku(kodeBuku);

        for (Buku& buku : daftarBuku) {
            if (buku.kodeBuku == kodeBuku) {
                string judul, kodeBuku, penulis, penerbit;
                int tahunTerbit, stok;

                cout << " Masukkan Data Buku " << endl;
                cout << "Kode Buku: ";
                cin >> kodeBuku;
                cout << "Judul: ";
                cin.ignore();
                getline(cin, judul);
                cout << "Penulis: ";
                cin.ignore();
                getline(cin, penulis);
                cout << "Penerbit: ";
                getline(cin, penerbit);
                cout << "Tahun Terbit: ";
                cin >> tahunTerbit;
                cout << "Stok: ";
                cin >> stok;
                cout << endl;

                Buku buku(judul, kodeBuku, penulis, penerbit, tahunTerbit, stok);
                daftarBuku.push_back(buku);
                simpanDataBuku(buku);
                cout << "Data buku berhasil diupdate." << endl;
                return;
            }
        }

        cout << "Buku dengan kode buku tersebut tidak ditemukan." << endl;
    }

    // Menghapus buku berdasarkan kode buku
    void hapusBuku() {
        string kodeBuku;
        cout << "Masukkan Kode Buku yang akan dihapus: ";
        cin >> kodeBuku;

        for (auto it = daftarBuku.begin(); it != daftarBuku.end(); ++it) {
            if (it->kodeBuku == kodeBuku) {
                daftarBuku.erase(it);
                hapusDataBuku(kodeBuku);
                cout << "Buku berhasil dihapus." << endl;
                return;
            }
        }

        cout << "Buku dengan kode buku tersebut tidak ditemukan." << endl;
    }

    // Simpan data buku ke file
    void simpanDataBuku(const Buku& buku) {
        ofstream file("daftar_buku.txt", ios_base::app);
        if (file.is_open()) {
            file << "Kode Buku: " << buku.kodeBuku << endl;
            file << "Judul: " << buku.judul << endl;
            file << "Penulis: " << buku.penulis << endl;
            file << "Penerbit: " << buku.penerbit << endl;
            file << "Tahun Terbit: " << buku.tahunTerbit << endl;
            file << "Stok: " << buku.stok << endl;
            file << "---------------------------------------" << endl;
            file.close();
        } else {
            cout << "Gagal menyimpan data buku." << endl;
        }
    }

    // Hapus data buku dari file berdasarkan kode buku
    void hapusDataBuku(const string& kodeBuku) {
        ifstream inputFile("daftar_buku.txt");
        if (!inputFile) {
            cout << "Gagal membuka file." << endl;
            return;
        }

        ofstream outputFile("temp.txt");
        if (!outputFile) {
            cout << "Gagal membuka file." << endl;
            return;
        }

        string line;
        bool found = false;
        while (getline(inputFile, line)) {
            if (line.find("Kode Buku: " + kodeBuku) != string::npos) {
                found = true;
                for (int i = 0; i < 6; i++) {
                    getline(inputFile, line);
                }
                continue;
            }

            outputFile << line << endl;
        }

        inputFile.close();
        outputFile.close();

        if (found) {
            remove("daftar_buku.txt");
            rename("temp.txt", "daftar_buku.txt");
        } else {
            remove("temp.txt");
            cout << "Buku dengan kode buku tersebut tidak ditemukan." << endl;
        }
    }

    // Hapus data buku dari file berdasarkan kode buku
    void editDataBuku(const string& kodeBuku) {
        ifstream inputFile("daftar_buku.txt");
        if (!inputFile) {
            cout << "Gagal membuka file." << endl;
            return;
        }

        ofstream outputFile("temp.txt");
        if (!outputFile) {
            cout << "Gagal membuka file." << endl;
            return;
        }

        string line;
        bool found = false;
        while (getline(inputFile, line)) {
            if (line.find("Kode Buku: " + kodeBuku) != string::npos) {
                found = true;
                for (int i = 0; i < 6; i++) {
                    getline(inputFile, line);
                }
                continue;
            }

            outputFile << line << endl;
        }

        inputFile.close();
        outputFile.close();

        if (found) {
            remove("daftar_buku.txt");
            rename("temp.txt", "daftar_buku.txt");
        } else {
            remove("temp.txt");
        }
    }
};


// Deklarasi class Opsi
class Opsi {
public:
    // Menampilkan pilihan menu
    static void tampilMenu() {
        cout << "|>>>>>>>>>>>>>>> PILIHAN MENU : <<<<<<<<<<<<<<<|" << endl;
        cout << "|=======    1. Tambah Data Buku         =======|" << endl;
        cout << "|=======    2. Tampil Daftar Buku       =======|" << endl;
        cout << "|=======    3. Edit Data Buku           =======|" << endl;
        cout << "|=======    4. Sorting Buku             =======|" << endl;
        cout << "|=======    5. Cari Buku                =======|" << endl;
        cout << "|=======    6. Hapus Data Buku          =======|" << endl;
        cout << "|=======    7. Peminjaman Buku          =======|" << endl;
        cout << "|=======    8. Pengembalian Buku        =======|" << endl;
        cout << "|=======    9. Hitung Denda             =======|" << endl;
        cout << "|=======    10. Exit Program            =======|" << endl;
        cout << "|>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<|" << endl;
    }

    // Meminta input pilihan menu yang dipilih
    static int opsiInput() {
        int pilihan;
        cout << "Masukkan Menu Pilihan Anda: ";
        cin >> pilihan;
        return pilihan;
    }
};

