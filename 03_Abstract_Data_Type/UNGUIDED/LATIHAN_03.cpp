#include <iostream>
using namespace std;

void tampilkanArray(int array[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++)
            cout << array[i][j] << " ";
        cout << endl;
    }
}

void tukarPosisi(int array1[3][3], int array2[3][3], int baris, int kolom) {
    swap(array1[baris][kolom], array2[baris][kolom]);
}

void tukarPointer(int* ptr1, int* ptr2) {
    swap(*ptr1, *ptr2);
}

int main() {
    int array1[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int array2[3][3] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};
    int a = 10, b = 20;
    int *ptr1 = &a, *ptr2 = &b;

    cout << "Array 1 sebelum ditukar:" << endl;
    tampilkanArray(array1);
    cout << "Array 2 sebelum ditukar:" << endl;
    tampilkanArray(array2);
    
    tukarPosisi(array1, array2, 1, 1);

    cout << "\nArray 1 setelah ditukar:" << endl;
    tampilkanArray(array1);
    cout << "Array 2 setelah ditukar:" << endl;
    tampilkanArray(array2);

    cout << "\nNilai ptr1 sebelum ditukar: " << *ptr1 << endl;
    cout << "Nilai ptr2 sebelum ditukar: " << *ptr2 << endl;
    
    tukarPointer(ptr1, ptr2);

    cout << "\nNilai ptr1 setelah ditukar: " << *ptr1 << endl;
    cout << "Nilai ptr2 setelah ditukar: " << *ptr2 << endl;

    return 0;
}
