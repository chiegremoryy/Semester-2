#include <iostream>
#include <vector>
#include <fstream>
#include <ctime>

struct Mutasi {
    std::string tanggal;
    std::string keterangan;
    int jumlah;
};

class Tabungan {
private:
    int saldo;
    std::vector<Mutasi> mutasi;

public:
    Tabungan() {
        saldo = 0;
    }

    void tampilMenu() {
        std::cout << "[==============================================]" << std::endl;
        std::cout << "|======= SELAMAT DATANG DI BANK CHIE RI =======|" << std::endl;
        std::cout << "[==============================================]" << std::endl;
        std::cout << "|>>>>>>>>>>>>>>> PILIHAN MENU : <<<<<<<<<<<<<<<|" << std::endl;
        std::cout << "|=======    1. Tambah Tabungan          =======|" << std::endl;
        std::cout << "|=======    2. Setor Tunai              =======|" << std::endl;
        std::cout << "|=======    3. Tampil Data Tabungan     =======|" << std::endl;
        std::cout << "|=======    4. Tarik Saldo              =======|" << std::endl;
        std::cout << "|=======    5. Mutasi Saldo Tabungan    =======|" << std::endl;
        std::cout << "|=======    6. Cari Tabungan            =======|" << std::endl;
        std::cout << "|=======    7. Hapus Tabungan           =======|" << std::endl;
        std::cout << "|=======    8. Exit Program             =======|" << std::endl;
        std::cout << "|>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<|" << std::endl;
    }

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
                std::cout << " Transaksi Selesai " << std::endl;
                std::cout << " Terima Kasih Telah Menggunakan ATM Chie RI " << std::endl;
                break;
            default:
                std::cout << " Pilihan Menu Yang Anda Pilih Tidak Tersedia. " << std::endl;
                break;
        }
    }

    void opsiTambah() {
        std::cout << "[----------------------------------------------]" << std::endl;
        std::cout << "|>>>>>>>>>>>>>> TAMBAH TABUNGAN : <<<<<<<<<<<<<|" << std::endl;
        std::cout << "[----------------------------------------------]" << std::endl;
        std::cout << "--------- Masukkan Data Tabungan Anda! ---------" << std::endl;
        std::cout << "----- SIMPEDES / BRITAMA / BRITAMA X / HAJI ----" << std::endl;
        std::string jenis_tab;
        std::string nama_pemilik;
        int norek;
        std::string alamat;
        int saldo;
        std::cout << " Jenis Tabungan : ";
        std::cin >> jenis_tab;
        std::cout << " Nama Pemilik : ";
        std::cin >> nama_pemilik;
        std::cout << " Nomor Rekening : ";
        std::cin >> norek;
        std::cout << " Alamat Pemilik : ";
        std::cin >> alamat;
        std::cout << " Setoran Awal : ";
        std::cin >> saldo;
        std::cout << "[----------------------------------------------]" << std::endl;
        std::cout << " Selamat Data Tabungan Anda Berhasil Disimpan ! " << std::endl;
        std::cout << " " << std::endl;
        Mutasi m;
        m.tanggal = getCurrentTime();
        m.keterangan = "Tambah Tabungan";
        m.jumlah = saldo;
        mutasi.push_back(m);
        simpanData(jenis_tab, nama_pemilik, norek, alamat, saldo);
    }

    void opsiSetor() {
        std::cout << "[----------------------------------------------]" << std::endl;
        std::cout << "|>>>>>>>>>>>>>>>> SETOR TUNAI : <<<<<<<<<<<<<<<|" << std::endl;
        std::cout << "[----------------------------------------------]" << std::endl;
        int setor_tunai;
        std::cout << " Masukkan Nominal Uang Yang Ingin Disetor : ";
        std::cin >> setor_tunai;
        std::cout << " Selamat Uang Anda Berhasil Disetorkan ! " << std::endl;
        saldo += setor_tunai;
        std::cout << " Jumlah Saldo Di Tabungan Anda Yaitu : Rp " << saldo << std::endl;
        Mutasi m;
        m.tanggal = getCurrentTime();
        m.keterangan = "Setor Tunai";
        m.jumlah = setor_tunai;
        mutasi.push_back(m);
        simpanMutasiData(m);
    }

    void opsiTampil() {
        std::cout << "[----------------------------------------------]" << std::endl;
        std::cout << "|>>>>>>>>>>> TAMPIL DATA TABUNGAN : <<<<<<<<<<<|" << std::endl;
        std::cout << "[----------------------------------------------]" << std::endl;
        // Tambahkan logika untuk menampilkan data tabungan
        std::ifstream file("data_tabungan.txt");
        std::string line;
        while (std::getline(file, line)) {
            std::cout << line << std::endl;
        }
        file.close();
    }

    void opsiTarik() {
        std::cout << "[----------------------------------------------]" << std::endl;
        std::cout << "|>>>>>>>>>>>>>>>> TARIK SALDO : <<<<<<<<<<<<<<<|" << std::endl;
        std::cout << "[----------------------------------------------]" << std::endl;
        int tarik_tunai;
        std::cout << " Masukkan Nominal Uang Yang Ingin Di Tarik Tunai : ";
        std::cin >> tarik_tunai;
        if (saldo >= tarik_tunai) {
            std::cout << " Selamat Uang Anda Berhasil Di Tarik Tunai ! " << std::endl;
            saldo -= tarik_tunai;
            std::cout << " Sisa Saldo Di Tabungan Anda Yaitu : Rp " << saldo << std::endl;
            Mutasi m;
            m.tanggal = getCurrentTime();
            m.keterangan = "Tarik Tunai";
            m.jumlah = -tarik_tunai; // Jumlah ditandai negatif karena ini adalah penarikan
            mutasi.push_back(m);
            simpanMutasiData(m);
        } else {
            std::cout << " Saldo tidak mencukupi." << std::endl;
        }
    }

    void opsiMutasi() {
        std::cout << "[----------------------------------------------]" << std::endl;
        std::cout << "|>>>>>>>>>>> MUTASI SALDO TABUNGAN : <<<<<<<<<<|" << std::endl;
        std::cout << "[----------------------------------------------]" << std::endl;
        std::cout << "============= Mutasi Saldo Tabungan ============" << std::endl;
        for (const auto& m : mutasi) {
            std::cout << "Tanggal: " << m.tanggal << std::endl;
            std::cout << "Keterangan: " << m.keterangan << std::endl;
            std::cout << "Jumlah: " << m.jumlah << std::endl;
            std::cout << "---------------------------------------" << std::endl;
        }
    }

    void opsiSearch() {
        std::cout << "[----------------------------------------------]" << std::endl;
        std::cout << "|>>>>>>>>>>>>>>> CARI TABUNGAN : <<<<<<<<<<<<<<|" << std::endl;
        std::cout << "[----------------------------------------------]" << std::endl;
        std::cout << " Masukkan Nomor Rekening yang Ingin Dicari : ";
        int norek;
        std::cin >> norek;
        std::ifstream file("data_tabungan.txt");
        std::string line;
        bool found = false;
        while (std::getline(file, line)) {
            if (line.find(" Nomor Rekening: " + std::to_string(norek)) != std::string::npos) {
                found = true;
                std::cout << line << std::endl; // Menampilkan baris yang sesuai dengan nomor rekening
                while (std::getline(file, line)) {
                    if (line.find("---------------------------------------") != std::string::npos) {
                        break; // Berhenti ketika menemukan pemisah antar data
                    }
                    std::cout << line << std::endl; // Menampilkan data tambahan
                }
                break;
            }
        }
        file.close();
        if (!found) {
            std::cout << " Data tabungan dengan nomor rekening " << norek << " tidak ditemukan." << std::endl;
        }
    }


    void opsiDelete() {
        std::cout << "[----------------------------------------------]" << std::endl;
        std::cout << "|>>>>>>>>>>>>>>> HAPUS TABUNGAN : <<<<<<<<<<<<<|" << std::endl;
        std::cout << "[----------------------------------------------]" << std::endl;
        std::cout << " Masukkan Nomor Rekening yang Ingin Dihapus : ";
        int norek;
        std::cin >> norek;
        if (hapusData(norek)) {
            std::cout << " Data tabungan dengan nomor rekening " << norek << " telah dihapus." << std::endl;
        } else {
            std::cout << " Data tabungan dengan nomor rekening " << norek << " tidak ditemukan." << std::endl;
        }
    }

    std::string getCurrentTime() {
        time_t now = time(0);
        char* dt = ctime(&now);
        return dt;
    }

    void simpanData(const std::string& jenis_tab, const std::string& nama_pemilik, int norek, const std::string& alamat, int saldo) {
        std::ofstream file("data_tabungan.txt", std::ios_base::app);
        if (file.is_open()) {
            file << " Jenis Tabungan: " << jenis_tab << std::endl;
            file << " Nama Pemilik: " << nama_pemilik << std::endl;
            file << " Nomor Rekening: " << norek << std::endl;
            file << " Alamat Pemilik: " << alamat << std::endl;
            file << " Saldo: " << saldo << std::endl;
            file << "---------------------------------------" << std::endl;
            file.close();
        } else {
            std::cout << "Gagal menyimpan data tabungan." << std::endl;
        }
    }

    void simpanMutasiData(const Mutasi& mutasi) {
        std::ofstream file("mutasi_tabungan.txt", std::ios_base::app);
        if (file.is_open()) {
            file << " Tanggal: " << mutasi.tanggal << std::endl;
            file << " Keterangan: " << mutasi.keterangan << std::endl;
            file << " Jumlah: " << mutasi.jumlah << std::endl;
            file << "---------------------------------------" << std::endl;
            file.close();
        } else {
            std::cout << " Gagal menyimpan data mutasi. " << std::endl;
        }
    }

    bool hapusData(int norek) {
        std::ifstream file("data_tabungan.txt");
        std::vector<std::string> lines;
        std::string line;
        bool found = false;
        while (std::getline(file, line)) {
            if (line.find("Nomor Rekening: " + std::to_string(norek)) != std::string::npos) {
                found = true;
            } else {
                lines.push_back(line);
            }
        }
        file.close();
        std::ofstream outfile("data_tabungan.txt");
        for (const auto& l : lines) {
            outfile << l << std::endl;
        }
        outfile.close();
        return found;
    }
};

int main() {
    Tabungan atm;
    int pilihan;

    do {
        atm.tampilMenu();
        std::cout << " Silahkan Masukkan Pilihan Anda : ";
        std::cin >> pilihan;
        atm.opsiInput(pilihan);
    } while (pilihan != 8);

    return 0;
}
