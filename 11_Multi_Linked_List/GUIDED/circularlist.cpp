#include "circularlist.h"
#include <iostream>

using namespace std;

void CreateList(List &L) {
    L.first = nullptr;
}

address alokasi(infotype x) {
    address P = new ElmList;
    if (P != nullptr) {
        P->info = x;
        P->next = nullptr;
    }
    return P;
}

void dealokasi(address P) {
    delete P;
}

void insertFirst(List &L, address P) {
    if (L.first == nullptr) {
        P->next = P; 
        L.first = P;
    } else {
        address last = L.first;
        while (last->next != L.first) {
            last = last->next;
        }
        P->next = L.first;
        last->next = P;
        L.first = P;
    }
}

void insertLast(List &L, address P) {
    if (L.first == nullptr) {
        insertFirst(L, P);
    } else {
        address last = L.first;
        while (last->next != L.first) {
            last = last->next;
        }
        last->next = P;
        P->next = L.first;
    }
}

void insertAfter(List &L, address Prec, address P) {
    if (Prec != nullptr) {
        P->next = Prec->next;
        Prec->next = P;
    }
}

void deleteFirst(List &L, address &P) {
    if (L.first != nullptr) {
        P = L.first;
        if (P->next == L.first) {
            L.first = nullptr;
        } else {
            address last = L.first;
            while (last->next != L.first) {
                last = last->next;
            }
            L.first = P->next;
            last->next = L.first;
        }
        P->next = nullptr;
    }
}

void deleteLast(List &L, address &P) {
    if (L.first != nullptr) {
        address prev = nullptr;
        P = L.first;
        while (P->next != L.first) {
            prev = P;
            P = P->next;
        }
        if (prev == nullptr) { 
            L.first = nullptr;
        } else {
            prev->next = L.first;
        }
        P->next = nullptr;
    }
}

void deleteAfter(List &L, address Prec, address &P) {
    if (Prec != nullptr && Prec->next != L.first) {
        P = Prec->next;
        Prec->next = P->next;
        P->next = nullptr;
    }
}

address findElm(List L, infotype x) {
    address P = L.first;
    if (P != nullptr) {
        do {
            if (P->info.nim == x.nim) {
                return P;
            }
            P = P->next;
        } while (P != L.first);
    }
    return nullptr;
}

void printInfo(List L) {
    address P = L.first;
    if (P != nullptr) {
        do {
            cout << "Nama: " << P->info.nama << ", "
                 << "NIM: " << P->info.nim << ", "
                 << "Jenis Kelamin: " << P->info.jenis_kelamin << ", "
                 << "IPK: " << P->info.ipk << endl;
            P = P->next;
        } while (P != L.first);
    } else {
        cout << "List kosong." << endl;
    }
}