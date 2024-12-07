#include "multilist.h"
#include <iostream>

using namespace std;

bool ListEmpty(listinduk L) {
    return first(L) == Nil;
}

bool ListEmptyAnak(listanak L) {
    return first(L) == Nil;
}

void CreateList(listinduk &L) {
    first(L) = Nil;
    last(L) = Nil;
}

void CreateListAnak(listanak &L) {
    first(L) = Nil;
    last(L) = Nil;
}

address alokasi(infotypeinduk P) {
    address newEl = new elemen_list_induk;
    if (newEl != Nil) {
        info(newEl) = P;
        next(newEl) = Nil;
        prev(newEl) = Nil;
        CreateListAnak(newEl->lanak);
    }
    return newEl;
}

address_anak alokasiAnak(infotypeanak P) {
    address_anak newEl = new elemen_list_anak;
    if (newEl != Nil) {
        info(newEl) = P;
        next(newEl) = Nil;
        prev(newEl) = Nil;
    }
    return newEl;
}

void dealokasi(address P) {
    delete P;
}

void dealokasiAnak(address_anak P) {
    delete P;
}

void insertFirst(listinduk &L, address P) {
    if (ListEmpty(L)) {
        first(L) = P;
        last(L) = P;
    } else {
        next(P) = first(L);
        first(L)->prev = P;
        first(L) = P;
    }
}

void insertLast(listinduk &L, address P) {
    if (ListEmpty(L)) {
        insertFirst(L, P);
    } else {
        next(last(L)) = P;
        prev(P) = last(L);
        last(L) = P;
    }
}

void insertFirstAnak(listanak &L, address_anak P) {
    if (ListEmptyAnak(L)) {
        first(L) = P;
        last(L) = P;
    } else {
        next(P) = first(L);
        prev(first(L)) = P;
        first(L) = P;
    }
}

void insertLastAnak(listanak &L, address_anak P) {
    if (ListEmptyAnak(L)) {
        insertFirstAnak(L, P);
    } else {
        next(last(L)) = P;
        prev(P) = last(L);
        last(L) = P;
    }
}

void printInfo(listinduk L) {
    address P = first(L);
    while (P != Nil) {
        cout << "Induk: " << info(P) << endl;
        cout << "Anak-anak:" << endl;

        address_anak Q = first(P->lanak);
        while (Q != Nil) {
            cout << "- " << info(Q) << endl;
            Q = next(Q);
        }
        P = next(P);
    }
}