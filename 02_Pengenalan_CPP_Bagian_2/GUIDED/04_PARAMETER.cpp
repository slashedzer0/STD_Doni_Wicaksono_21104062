#include <iostream>
#include <cstdio>

using namespace std;

void tukar(int &x, int &y);

int main()
{
    system("cls");
    int a = 4, b = 6;

    cout << "Kondisi sebelum ditukar:\n";
    cout << "a = " << a << " b = " << b << endl;

    tukar(a, b);

    cout << "Kondisi setelah ditukar:\n";
    cout << "a = " << a << " b = " << b << endl;

    cin.get();
    return 0;
}

void tukar(int &x, int &y)
{
    int temp;

    temp = x;
    x = y;
    y = temp;

    cout << "Nilai akhir pada fungsi tukar:\n";
    cout << "x = " << x << " y = " << y << endl;
}