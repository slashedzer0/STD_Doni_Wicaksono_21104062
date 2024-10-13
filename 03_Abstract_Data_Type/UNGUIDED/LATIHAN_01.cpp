#include <iostream>
#include <string>
using namespace std;

struct Mahasiswa {
    string nama, nim;
    float uts, uas, tugas, nilai_akhir;
};

float hitung_nilai_akhir(float uts, float uas, float tugas) {
    return 0.3 * uts + 0.4 * uas + 0.3 * tugas;
}

int main() {
    Mahasiswa mhs[10];
    int jml;

    cout << "Jumlah mahasiswa (max 10): ";
    cin >> jml;
    if (jml > 10) {
        cout << "Maksimum 10 mahasiswa\n";
        return 1;
    }

    for (int i = 0; i < jml; i++) {
        cout << "\nData Mahasiswa ke-" << i+1 << ":\n";
        cin.ignore();
        cout << "Nama: "; getline(cin, mhs[i].nama);
        cout << "NIM: "; getline(cin, mhs[i].nim);
        cout << "Nilai UTS: "; cin >> mhs[i].uts;
        cout << "Nilai UAS: "; cin >> mhs[i].uas;
        cout << "Nilai Tugas: "; cin >> mhs[i].tugas;
        mhs[i].nilai_akhir = hitung_nilai_akhir(mhs[i].uts, mhs[i].uas, mhs[i].tugas);
    }

    cout << "\nData Mahasiswa:\n";
    for (int i = 0; i < jml; i++) {
        cout << "\nMahasiswa ke-" << i+1 << ":\n"
             << "Nama: " << mhs[i].nama << "\n"
             << "NIM: " << mhs[i].nim << "\n"
             << "Nilai UTS: " << mhs[i].uts << "\n"
             << "Nilai UAS: " << mhs[i].uas << "\n"
             << "Nilai Tugas: " << mhs[i].tugas << "\n"
             << "Nilai Akhir: " << mhs[i].nilai_akhir << "\n";
    }

    return 0;
}