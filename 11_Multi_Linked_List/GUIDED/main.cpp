#include "multilist.h"
#include <iostream>

using namespace std;

int main() {
    listinduk L;
    CreateList(L);

    address P1 = alokasi(1);
    address P2 = alokasi(2);

    insertFirst(L, P1);
    insertLast(L, P2);

    address_anak C1 = alokasiAnak(101);
    address_anak C2 = alokasiAnak(102);
    insertFirstAnak(P1->lanak, C1);
    insertLastAnak(P1->lanak, C2);

    address_anak C3 = alokasiAnak(201);
    address_anak C4 = alokasiAnak(202);
    insertFirstAnak(P2->lanak, C3);
    insertLastAnak(P2->lanak, C4);

    cout << "Isi List Induk dan Anak:" << endl;
    printInfo(L);

    return 0;
}