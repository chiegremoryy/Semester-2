//JUDUL        : MEMBUAT PROGRAM MESIN ATM
//CREATED BY   : MUHAMMAD ARIEF HIDAYATULLAH
//NIM          : A11.2022.14788
//KELOMPOK     : A11.4219
//DATE         : 22 JUNI 2023

#include <iostream> // library untuk input/output standar
#include <fstream> // library untuk operasi file
#include <ctime> // library untuk manipulasi waktu
#include <vector> // library untuk menggunakan vektor

using namespace std;
//deklarasi class Mutasi
class Mutasi {
//attribute class
public:
    string tanggal;
    string keterangan;
    int jumlah;
};

//deklarasi class Opsi
class Opsi {
//attribute class
private:
    int saldo;
    vector<Mutasi> mutasi;

public:
    int setor_tunai;
    string cari;
    int rekening;
    int transfer;
    int tarik_tunai;

    // PROSEDUR UNTUK MENAMPILKAN PILIHAN MENU
    void tampilMenu() {
        cout << "|>>>>>>>>>>>>>>> PILIHAN MENU : <<<<<<<<<<<<<<<|" << endl;
        cout << "|=======    1. Tarik Tunai              =======|" << endl;
        cout << "|=======    2. Setor Tunai              =======|" << endl;
        cout << "|=======    3. Tampil Saldo             =======|" << endl;
        cout << "|=======    4. Transfer Saldo           =======|" << endl;
        cout << "|=======    5. Mutasi Saldo             =======|" << endl;
        cout << "|=======    6. Cari Transaksi           =======|" << endl;
        cout << "|>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<|" << endl;
    }

    // PROSEDUR UNTUK MENGINPUTKAN PILIHAN MENU YANG DIPILIH
    void opsiInput(int pilihan) {
        switch (pilihan) {
            case 1:
                opsiTarik();
                break;
            case 2:
                opsiSetor();
                break;
            case 3:
                opsiTampil();
                break;
            case 4:
                opsiTransfer();
                break;
            case 5:
                opsiMutasi();
                break;
            case 6:
                cout << " Format Tanggal : YYYY-MM-DD " << endl;
                cout << " Masukkan Tanggal : " ;
                cin >> cari;
                opsiCari(cari);
                break;
            default:
                cout << " Pilihan Menu Yang Anda Pilih Tidak Tersedia. " << endl;
                break;
        }
    }

    // PROSEDUR UNTUK MELAKUKAN TARIK TUNAI
    void opsiTarik() {
        cout << "[----------------------------------------------]" << endl;
        cout << "|>>>>>>>>>>>>>>>> TARIK SALDO : <<<<<<<<<<<<<<<|" << endl;
        cout << "[----------------------------------------------]" << endl;
        cout << " Masukkan Nominal Uang Yang Ingin Di Tarik Tunai : ";
        cin >> tarik_tunai;
        cout << " Selamat Uang Anda Berhasil Di Tarik Tunai ! " << endl;
        saldo = saldo - tarik_tunai;
        cout << " Sisa Saldo Di Tabungan Anda Saat Ini: Rp " << saldo << endl;
        Mutasi m;
        m.tanggal = getCurrentTime(); // fungsi untuk mengambil waktu saat ini dari sistem dan mengembalikan nilainya dalam bentuk string dengan format "YYYY-MM-DD HH:MM:SS".
        m.keterangan = " Tarik Tunai "; //keterangan transaksi yang masuk ke dalam file txt
        m.jumlah = tarik_tunai;
        mutasi.push_back(m); // perintah yang digunakan untuk memasukkan objek m ke dalam vektor mutasi.
        simpanMutasiData(m); // untuk menyimpan data mutasi ke dalam file "mutasi_tabungan.txt". Fungsi ini akan membuka file, menuliskan informasi mutasi ke dalam file, dan menutup file setelah selesai.
    }

    // PROSEDUR UNTUK SETOR TUNAI
    void opsiSetor() {
        cout << "[----------------------------------------------]" << endl;
        cout << "|>>>>>>>>>>>>>>>> SETOR TUNAI : <<<<<<<<<<<<<<<|" << endl;
        cout << "[----------------------------------------------]" << endl;
        // OUTPUT
        cout << " Masukkan Nominal Uang Yang Ingin Disetor : ";
        cin >> setor_tunai;
        cout << " Selamat Uang Anda Berhasil Disetorkan ! " << endl;
        saldo = saldo + setor_tunai;
        cout << " Jumlah Saldo Di Tabungan Anda Saat Ini : Rp " << saldo << endl;
        Mutasi m;
        m.tanggal = getCurrentTime(); // fungsi untuk mengambil waktu saat ini dari sistem dan mengembalikan nilainya dalam bentuk string dengan format "YYYY-MM-DD HH:MM:SS".
        m.keterangan = " Setor Tunai "; //keterangan transaksi yang masuk ke dalam file txt
        m.jumlah = setor_tunai;
        mutasi.push_back(m); // perintah yang digunakan untuk memasukkan objek m ke dalam vektor mutasi.
        simpanMutasiData(m); // untuk menyimpan data mutasi ke dalam file "mutasi_tabungan.txt". Fungsi ini akan membuka file, menuliskan informasi mutasi ke dalam file, dan menutup file setelah selesai.
    }

    // PROSEDUR UNTUK MENAMPILKAN SALDO
    void opsiTampil() {
        cout << "[----------------------------------------------]" << endl;
        cout << "|>>>>>>>>>>>>>>> TAMPIL SALDO : <<<<<<<<<<<<<<<|" << endl;
        cout << "[----------------------------------------------]" << endl;
        ifstream inputFile("mutasi_tabungan.txt"); //untuk membaca file txt sebagai penyimpanan transaksi yang telah dilakukan
        if (!inputFile) {
            cout << " Gagal membuka file. " << endl;
            return;
        }

        int jml = 0;
        string line;

        while (getline(inputFile, line)) {
            if (line.find("Keterangan:") != string::npos) {
                string keterangan = line.substr(line.find(":") + 1);
                getline(inputFile, line); // fungsi membaca baris berikutnya untuk mendapatkan jumlah
                string jumlahStr = line.substr(line.find(":") + 1);
                int jumlah = stoi(jumlahStr);

                if (keterangan == "Setor Tunai") {
                    jml += jumlah;
                } else if (keterangan == "Tarik Tunai") {
                    jml -= jumlah;
                }
            }
        }
        inputFile.close();
        cout << " Total Saldo Anda Saat Ini : Rp " << saldo << endl;
    }

    // PROSEDUR UNTUK MELAKUKAN TRANSFER SALDO
    void opsiTransfer() {
        cout << "[----------------------------------------------]" << endl;
        cout << "|>>>>>>>>>>>>>> TRANSFER SALDO : <<<<<<<<<<<<<<|" << endl;
        cout << "[----------------------------------------------]" << endl;
        // OUTPUT
        cout << " Masukkan Rekening Tujuan : ";
        cin >> rekening;
        cout << "------------------------------------------------" << endl;
        cout << " Rekening Yang Akan Ditransfer " << rekening << endl;
        cout << " Masukkan Nominal Saldo Yang Ingin Ditransfer : ";
        cin >> transfer;
        cout << " Selamat Uang Anda Berhasil Ditransfer ke Rekening Tujuan ! " << endl;
        saldo = saldo - transfer;
        cout << " Jumlah Saldo Di Tabungan Anda Saat Ini : Rp " << saldo << endl;
        Mutasi m;
        m.tanggal = getCurrentTime(); // fungsi untuk mengambil waktu saat ini dari sistem dan mengembalikan nilainya dalam bentuk string dengan format "YYYY-MM-DD HH:MM:SS".
        m.keterangan = " Transfer Saldo ";
        m.jumlah = transfer;
        mutasi.push_back(m); // perintah yang digunakan untuk memasukkan objek m ke dalam vektor mutasi.
        simpanMutasiData(m); // untuk menyimpan data mutasi ke dalam file "mutasi_tabungan.txt". Fungsi ini akan membuka file, menuliskan informasi mutasi ke dalam file, dan menutup file setelah selesai.
    }

    // PROSEDUR UNTUK MELAKUKAN MUTASI SALDO TABUNGAN
    void opsiMutasi() {
        cout << "[----------------------------------------------]" << endl;
        cout << "|>>>>>>>>>>> MUTASI SALDO TABUNGAN : <<<<<<<<<<|" << endl;
        cout << "[----------------------------------------------]" << endl;
        cout << "============= Mutasi Saldo Tabungan ============" << std::endl;
        ifstream data("mutasi_tabungan.txt");
            bool found = false;
            if (data.is_open()) {
                //kamus Lokal
                string line;
                while (getline(data, line)) {
                    cout << line << endl;
                }
                data.close();
            } else {
                cout << " File tidak dapat dibuka." << endl;
            }
    }

    // PROSEDUR UNTUK MENCARI TABUNGAN
    /*metode searching yang saya gunakan disini adalah " string searching " atau pencarian berdasarkan string, dengan tahapan sebagai berikut:
    1. membaca file `mutasi_tabungan.txt` menggunakan `ifstream`.
    2. melakukan pencarian baris per baris dalam file menggunakan loop `while (getline(data, line))`.
    3. menggunakan function `find` untuk mencari string yang sesuai dengan pola " Tanggal: " + tanggal di setiap baris. jika ditemukan, maka transaksi pada tanggal tersebut dianggap ditemukan.
    4. jika transaksi ditemukan, baris-baris transaksi selanjutnya akan ditampilkan hingga ditemui baris kosong atau baris pemisah.
    5. jika transaksi tidak ditemukan, pesan " Transaksi pada tanggal [tanggal] tidak ditemukan. " akan ditampilkan.
    6. jika file tidak dapat dibuka, pesan " File tidak dapat dibuka. " akan ditampilkan.
    */
    void opsiCari(string tanggal) {
    cout << "[----------------------------------------------]" << endl;
    cout << "|>>>>>>>>>>>>>>> CARI TRANSAKSI : <<<<<<<<<<<<<|" << endl;
    cout << "[----------------------------------------------]" << endl;
    ifstream data("mutasi_tabungan.txt");
    bool found = false;
    if (data.is_open()) {
        string line;
        while (getline(data, line)) {
            if (line.find(" Tanggal: " + tanggal) != string::npos){
                cout << " Data Transaksi pada tanggal " << tanggal << endl;
                found = true;
                while (getline(data, line)) {
                    if (line.empty()) {
                        break; // untuk melewati baris kosong dan baris pemisah
                    }
                    cout << line << endl;
                }
                break; // keluar dari loop saat data ditemukan
            }
        }

        if (!found) {
            cout << " Transaksi pada tanggal " << tanggal << " tidak ditemukan." << endl;
        }
        data.close();
    } else {
        cout << "File tidak dapat dibuka." << endl;
    }
}
    //PROSEDUR SIMPAN DATA
    void simpanMutasiData(const Mutasi& mutasi) {
        ofstream file("mutasi_tabungan.txt", ios_base::app);
        if (file.is_open()) {
            file << " Tanggal: " << mutasi.tanggal << endl;
            file << " Keterangan: " << mutasi.keterangan << endl;
            file << " Jumlah: " << mutasi.jumlah << endl;
            file << "---------------------------------------" << endl;
            file.close();
        } else {
            cout << " Gagal menyimpan data mutasi. " << endl;
        }
    }

    //function untuk mengambil data date n time yang ada di device
    string getCurrentTime() {
        time_t now = time(0); //mengambil waktu saat ini dalam bentuk time_t
        tm* timeinfo = localtime(&now); //mengkonversi time_t menjadi struct tm yang berisi informasi waktu terperinci
        char buffer[80];
        strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", timeinfo); //menggunakan strftime untuk memformat waktu dalam string
        return string(buffer); //mengembalikan string yang berisi waktu dalam format yang diinginkan
    }

};
