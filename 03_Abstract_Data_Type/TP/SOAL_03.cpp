#include <iostream>
using namespace std;

int main()
{
    int angka = 42;
    int *ptr = &angka;

    cout << "Nilai angka: " << angka << endl;
    cout << "Alamat angka: " << &angka << endl;
    cout << "Nilai yang disimpan ptr: " << ptr << endl;
    cout << "Nilai yang ditunjuk ptr: " << *ptr << endl;

    return 0;
}