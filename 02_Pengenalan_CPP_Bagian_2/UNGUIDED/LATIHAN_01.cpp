#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Masukkan jumlah elemen array: ";
    cin >> n;

    int arr[n];
    cout << "Masukkan nilai-nilai elemen array:\n";
    for (int &x : arr)
        cin >> x;

    cout << "Data Array: ";
    for (int x : arr)
        cout << x << " ";
    cout << "\nNomor Genap: ";
    for (int x : arr)
        if (x % 2 == 0)
            cout << x << " ";
    cout << "\nNomor Ganjil: ";
    for (int x : arr)
        if (x % 2 != 0)
            cout << x << " ";

    return 0;
}
