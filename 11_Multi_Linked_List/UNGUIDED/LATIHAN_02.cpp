#include <iostream>
#include <string>
using namespace std;

struct NodeBuku {
    string judulBuku;
    string tanggalKembali;
    NodeBuku* berikutnya;
};

struct NodeAnggota {
    string nama;
    string id;
    NodeBuku* daftarBuku;
    NodeAnggota* berikutnya;
};

class SistemPerpustakaan {
private:
    NodeAnggota* kepala;

public:
    SistemPerpustakaan() {
        kepala = NULL;
    }

    void tambahAnggota(string nama, string id) {
        NodeAnggota* anggotaBaru = new NodeAnggota();
        anggotaBaru->nama = nama;
        anggotaBaru->id = id;
        anggotaBaru->daftarBuku = NULL;
        anggotaBaru->berikutnya = NULL;

        if (kepala == NULL) {
            kepala = anggotaBaru;
        } else {
            NodeAnggota* temp = kepala;
            while (temp->berikutnya != NULL) {
                temp = temp->berikutnya;
            }
            temp->berikutnya = anggotaBaru;
        }
    }

    void tambahBuku(string idAnggota, string judulBuku, string tanggalKembali) {
        NodeAnggota* anggota = cariAnggota(idAnggota);
        if (anggota != NULL) {
            NodeBuku* bukuBaru = new NodeBuku();
            bukuBaru->judulBuku = judulBuku;
            bukuBaru->tanggalKembali = tanggalKembali;
            bukuBaru->berikutnya = NULL;

            if (anggota->daftarBuku == NULL) {
                anggota->daftarBuku = bukuBaru;
            } else {
                NodeBuku* temp = anggota->daftarBuku;
                while (temp->berikutnya != NULL) {
                    temp = temp->berikutnya;
                }
                temp->berikutnya = bukuBaru;
            }
        }
    }

    NodeAnggota* cariAnggota(string id) {
        NodeAnggota* temp = kepala;
        while (temp != NULL) {
            if (temp->id == id) {
                return temp;
            }
            temp = temp->berikutnya;
        }
        return NULL;
    }

    void hapusAnggota(string id) {
        NodeAnggota* current = kepala;
        NodeAnggota* prev = NULL;

        while (current != NULL && current->id != id) {
            prev = current;
            current = current->berikutnya;
        }

        if (current != NULL) {
            NodeBuku* bukuCurrent = current->daftarBuku;
            while (bukuCurrent != NULL) {
                NodeBuku* nextBuku = bukuCurrent->berikutnya;
                delete bukuCurrent;
                bukuCurrent = nextBuku;
            }

            if (prev == NULL) {
                kepala = current->berikutnya;
            } else {
                prev->berikutnya = current->berikutnya;
            }
            delete current;
        }
    }

    void tampilkanSemua() {
        if (kepala == NULL) {
            cout << "\nTidak ada anggota terdaftar.";
            return;
        }

        NodeAnggota* anggota = kepala;
        while (anggota != NULL) {
            cout << "\n\nData Anggota:";
            cout << "\nNama: " << anggota->nama;
            cout << "\nID: " << anggota->id;
            cout << "\nBuku yang Dipinjam:";
            
            NodeBuku* buku = anggota->daftarBuku;
            if (buku == NULL) {
                cout << "\n- Tidak ada buku yang dipinjam";
            }
            while (buku != NULL) {
                cout << "\n- " << buku->judulBuku;
                cout << " (Pengembalian: " << buku->tanggalKembali << ")";
                buku = buku->berikutnya;
            }
            anggota = anggota->berikutnya;
        }
        cout << "\n";
    }
};

int main() {
    SistemPerpustakaan perpustakaan;
    perpustakaan.tambahAnggota("Rani", "A001");
    perpustakaan.tambahAnggota("Dito", "A002");
    perpustakaan.tambahAnggota("Vina", "A003");

    perpustakaan.tambahBuku("A001", "Pemrograman C++", "01/12/2024");
    perpustakaan.tambahBuku("A002", "Algoritma Pemrograman", "15/12/2024");

    perpustakaan.tambahBuku("A001", "Struktur Data", "10/12/2024");

    perpustakaan.hapusAnggota("A002");

    cout << "Data Perpustakaan:";
    perpustakaan.tampilkanSemua();
    return 0;
}