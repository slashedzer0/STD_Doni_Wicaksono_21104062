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
    
    cout << "Isi linked list: ";
    displayList(head);

    return 0;
}
