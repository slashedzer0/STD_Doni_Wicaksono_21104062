#include <iostream>
#include "list.h"
using namespace std;

int main()
{
    List L;
    createList(L);

    int input;
    address p;

    cout << "Masukkan angka pertama: ";
    cin >> input;
    p = allocate(input);
    insertFirst(L, p);
    printInfo(L);

    cout << "Masukkan angka kedua: ";
    cin >> input;
    p = allocate(input);
    insertFirst(L, p);
    printInfo(L);

    cout << "Masukkan angka ketiga: ";
    cin >> input;
    p = allocate(input);
    insertFirst(L, p);
    printInfo(L);

    return 0;
}

// --------------------------------

int main()
{
    List L;
    createList(L);

    int digit;
    address p;
    cout << "Masukkan NIM per- digit\n";

    for (int i = 1; i <= 10; i++)
    {
        cout << "Digit " << i << ": ";
        cin >> digit;

        p = allocate(digit);

        insertLast(L, p);
    }

    cout << "Isi list : ";
    printInfo(L);

    return 0;
}