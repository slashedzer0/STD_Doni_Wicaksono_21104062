#include <iostream>
#include <string>
using namespace std;

struct Node {
    int nim;
    string nama;
    Node* next;
    Node(int n, string nm) : nim(n), nama(nm), next(nullptr) {}
};

class StudentList {
private:
    Node* head;

public:
    StudentList() : head(nullptr) {}
    
    void add(int nim, string nama) {
        Node* newNode = new Node(nim, nama);
        
        if (!head || head->nim >= nim) {
            newNode->next = head;
            head = newNode;
            return;
        }
        
        Node* curr = head;
        while (curr->next && curr->next->nim < nim) {
            curr = curr->next;
        }
        newNode->next = curr->next;
        curr->next = newNode;
    }
    
    void find(int nim) {
        Node* curr = head;
        
        while (curr) {
            if (curr->nim == nim) {
                cout << "Mahasiswa ditemukan!\n";
                cout << "NIM  : " << curr->nim << "\n";
                cout << "Nama : " << curr->nama << "\n";
                return;
            }
            curr = curr->next;
        }
        
        cout << "Mahasiswa dengan NIM " << nim << " tidak ditemukan\n";
    }
    
    void print() {
        Node* curr = head;
        cout << "\nDaftar Mahasiswa:\n";
        while (curr) {
            cout << curr->nim << " - " << curr->nama << "\n";
            curr = curr->next;
        }
        cout << endl;
    }
};

int main() {
    StudentList list;
    int choice, nim;
    string nama;
    
    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Tambah Mahasiswa\n";
        cout << "2. Cari Mahasiswa\n";
        cout << "3. Tampilkan Semua\n";
        cout << "4. Keluar\n";
        cout << "Pilihan: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "Masukkan NIM: ";
                cin >> nim;
                cout << "Masukkan Nama: ";
                cin.ignore();
                getline(cin, nama);
                list.add(nim, nama);
                cout << "Data berhasil ditambahkan!\n";
                break;
                
            case 2:
                cout << "Masukkan NIM yang dicari: ";
                cin >> nim;
                list.find(nim);
                break;
                
            case 3:
                list.print();
                break;
                
            case 4:
                cout << "Program selesai\n";
                return 0;
                
            default:
                cout << "Pilihan tidak valid!\n";
        }
    }
}