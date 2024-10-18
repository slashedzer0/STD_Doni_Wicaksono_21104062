#include <iostream>
using namespace std;

struct Elem {
    int val;
    Elem* next;
};

Elem* makeNode(int val) {
    Elem* node = new Elem();
    node->val = val;
    node->next = nullptr;
    return node;
}

void addFront(Elem*& head, int val) {
    Elem* node = makeNode(val);
    node->next = head;
    head = node;
}

void addBack(Elem*& head, int val) {
    Elem* node = makeNode(val);
    if (!head) {
        head = node;
    } else {
        Elem* curr = head;
        while (curr->next) {
            curr = curr->next;
        }
        curr->next = node;
    }
}

void deleteNode(Elem*& head, int val) {
    if (!head) {
        cout << "Linked list kosong. Tidak ada node yang bisa dihapus." << endl;
        return;
    }

    Elem* curr = head;
    Elem* prev = nullptr;

    if (curr && curr->val == val) {
        head = curr->next;
        delete curr;
        return;
    }

    while (curr && curr->val != val) {
        prev = curr;
        curr = curr->next;
    }

    if (!curr) {
        cout << "Node dengan nilai " << val << " tidak ditemukan." << endl;
        return;
    }

    prev->next = curr->next;
    delete curr;
}

void displayList(Elem* head) {
    if (!head) {
        cout << "Linked list kosong." << endl;
    } else {
        Elem* curr = head;
        while (curr) {
            cout << curr->val;
            if (curr->next) {
                cout << " -> ";
            }
            curr = curr->next;
        }
        cout << endl;
    }
}

int main() {
    Elem* head = nullptr;

    addFront(head, 10);
    addBack(head, 20);
    addFront(head, 5);

    cout << "Isi linked list sebelum penghapusan: ";
    displayList(head);

    int valToDelete = 10;
    cout << "Menghapus node dengan nilai: " << valToDelete << endl;
    deleteNode(head, valToDelete);

    cout << "Isi linked list setelah penghapusan: ";
    displayList(head);

    return 0;
}
