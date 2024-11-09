#include <iostream>
#include <string>
using namespace std;

// Struktur data mahasiswa
struct Student {
    string name;
    int nim;
    Student* next;
    Student(string n, int nim): name(n), nim(nim), next(nullptr) {}
};

class PQueue {
private:
    Student *head = nullptr, *tail = nullptr;

public:
    // Cek queue kosong
    bool empty() { return !head; }

    // Tambah mahasiswa (priority by NIM)
    void push(string name, int nim) {
        Student* newStudent = new Student(name, nim);
        
        if (empty() || nim < head->nim) {
            newStudent->next = head;
            head = newStudent;
            if (!tail) tail = head;
            return;
        }

        Student* curr = head;
        while (curr->next && curr->next->nim <= nim)
            curr = curr->next;

        newStudent->next = curr->next;
        curr->next = newStudent;
        if (!newStudent->next) tail = newStudent;
    }

    // Hapus mahasiswa terdepan
    void pop() {
        if (empty()) {
            cout << "Antrian kosong\n";
            return;
        }
        Student* temp = head;
        head = head->next;
        if (!head) tail = nullptr;
        delete temp;
    }

    // Tampilkan seluruh antrian
    void display() {
        if (empty()) {
            cout << "Antrian kosong\n";
            return;
        }
        int i = 1;
        for (Student* curr = head; curr; curr = curr->next)
            cout << i++ << ". Nama=" << curr->name << ", NIM=" << curr->nim << endl;
    }

    // Kosongkan antrian
    void clear() {
        while (!empty()) pop();
        cout << "Antrian dikosongkan\n";
    }
};

int main() {
    PQueue q;
    int choice;
    
    while (true) {
        cout << "\nMenu Antrian Mahasiswa:" << endl;
        cout << "1. Tambah Mahasiswa\n2. Lihat Antrian\n";
        cout << "3. Hapus Mahasiswa\n4. Kosongkan Antrian\n";
        cout << "5. Keluar\nPilihan: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string name;
                int nim;
                cout << "Masukkan Nama: ";
                cin >> name;
                cout << "Masukkan NIM: ";
                cin >> nim;
                q.push(name, nim);
                break;
            }
            case 2: q.display(); break;
            case 3: q.pop(); break;
            case 4: q.clear(); break;
            case 5: return 0;
            default: cout << "Pilihan tidak valid\n";
        }
    }
}