#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct mahasiswa
{
    char nim[10];
    int nilai1, nilai2;
};

void inputMhs(mahasiswa &m);
float rata2(mahasiswa m);

int main()
{
    mahasiswa mhs;
    inputMhs(mhs);
    cout << "Rata-rata = " << rata2(mhs) << endl;
    return 0;
}

void inputMhs(mahasiswa &m)
{
    cout << "NIM: ";
    cin >> m.nim;
    cout << "Nilai 1: ";
    cin >> m.nilai1;
    cout << "Nilai 2: ";
    cin >> m.nilai2;
}

float rata2(mahasiswa m)
{
    return (m.nilai1 + m.nilai2) / 2.0;
}