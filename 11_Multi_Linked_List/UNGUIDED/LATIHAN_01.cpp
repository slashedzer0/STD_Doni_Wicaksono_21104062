#include <iostream>
#include <string>
using namespace std;

struct NodeProyek {
    string namaProyek;
    int durasi;
    NodeProyek* berikutnya;
};

struct NodePegawai {
    string nama;
    string id;
    NodeProyek* proyek;
    NodePegawai* berikutnya;
};

class PengelolaPegawaiProyek {
private:
    NodePegawai* kepala;

public:
    PengelolaPegawaiProyek() {
        kepala = NULL;
    }

    void tambahPegawai(string nama, string id) {
        NodePegawai* pegawaiBaru = new NodePegawai();
        pegawaiBaru->nama = nama;
        pegawaiBaru->id = id;
        pegawaiBaru->proyek = NULL;
        pegawaiBaru->berikutnya = NULL;

        if (kepala == NULL) {
            kepala = pegawaiBaru;
        } else {
            NodePegawai* temp = kepala;
            while (temp->berikutnya != NULL) {
                temp = temp->berikutnya;
            }
            temp->berikutnya = pegawaiBaru;
        }
    }

    void tambahProyek(string idPegawai, string namaProyek, int durasi) {
        NodePegawai* pegawai = cariPegawai(idPegawai);
        if (pegawai != NULL) {
            NodeProyek* proyekBaru = new NodeProyek();
            proyekBaru->namaProyek = namaProyek;
            proyekBaru->durasi = durasi;
            proyekBaru->berikutnya = NULL;

            if (pegawai->proyek == NULL) {
                pegawai->proyek = proyekBaru;
            } else {
                NodeProyek* temp = pegawai->proyek;
                while (temp->berikutnya != NULL) {
                    temp = temp->berikutnya;
                }
                temp->berikutnya = proyekBaru;
            }
        }
    }

    void hapusProyek(string idPegawai, string namaProyek) {
        NodePegawai* pegawai = cariPegawai(idPegawai);
        if (pegawai != NULL) {
            NodeProyek* sekarang = pegawai->proyek;
            NodeProyek* sebelumnya = NULL;

            while (sekarang != NULL && sekarang->namaProyek != namaProyek) {
                sebelumnya = sekarang;
                sekarang = sekarang->berikutnya;
            }

            if (sekarang != NULL) {
                if (sebelumnya == NULL) {
                    pegawai->proyek = sekarang->berikutnya;
                } else {
                    sebelumnya->berikutnya = sekarang->berikutnya;
                }
                delete sekarang;
            }
        }
    }

    NodePegawai* cariPegawai(string id) {
        NodePegawai* temp = kepala;
        while (temp != NULL) {
            if (temp->id == id) {
                return temp;
            }
            temp = temp->berikutnya;
        }
        return NULL;
    }

    void tampilkanSemua() {
        NodePegawai* pegawai = kepala;
        while (pegawai != NULL) {
            cout << "\nNama Pegawai: " << pegawai->nama;
            cout << "\nID Pegawai: " << pegawai->id;
            cout << "\nProyek:";
            
            NodeProyek* proyek = pegawai->proyek;
            if (proyek == NULL) {
                cout << " Tidak ada proyek yang ditugaskan";
            }
            while (proyek != NULL) {
                cout << "\n- " << proyek->namaProyek << " (" << proyek->durasi << " bulan)";
                proyek = proyek->berikutnya;
            }
            cout << "\n";
            pegawai = pegawai->berikutnya;
        }
    }
};

int main() {
    PengelolaPegawaiProyek pengelola;
    pengelola.tambahPegawai("Andi", "P001");
    pengelola.tambahPegawai("Budi", "P002");
    pengelola.tambahPegawai("Citra", "P003");

    pengelola.tambahProyek("P001", "Aplikasi Mobile", 12);
    pengelola.tambahProyek("P002", "Sistem Akuntansi", 8);
    pengelola.tambahProyek("P003", "E-commerce", 10);

    pengelola.tambahProyek("P001", "Analisis Data", 6);

    pengelola.hapusProyek("P001", "Aplikasi Mobile");

    cout << "Data Pegawai dan Proyek:";
    pengelola.tampilkanSemua();
    return 0;
}