#include <iostream>
using namespace std;

int main()
{
    int d1, d2, d3;

    cout << "Masukkan ukuran dimensi pertama: ";
    cin >> d1;
    cout << "Masukkan ukuran dimensi kedua: ";
    cin >> d2;
    cout << "Masukkan ukuran dimensi ketiga: ";
    cin >> d3;

    int ***array3D = new int **[d1];
    for (int i = 0; i < d1; i++)
    {
        array3D[i] = new int *[d2];
        for (int j = 0; j < d2; j++)
        {
            array3D[i][j] = new int[d3];
        }
    }

    cout << "Masukkan nilai elemen-elemen array:\n";
    for (int i = 0; i < d1; i++)
    {
        for (int j = 0; j < d2; j++)
        {
            for (int k = 0; k < d3; k++)
            {
                cout << "Elemen [" << i << "][" << j << "][" << k << "]: ";
                cin >> array3D[i][j][k];
            }
        }
    }

    cout << "\nElemen-elemen array:\n";
    for (int i = 0; i < d1; i++)
    {
        for (int j = 0; j < d2; j++)
        {
            for (int k = 0; k < d3; k++)
            {
                cout << array3D[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    for (int i = 0; i < d1; i++)
    {
        for (int j = 0; j < d2; j++)
        {
            delete[] array3D[i][j];
        }
        delete[] array3D[i];
    }
    delete[] array3D;

    return 0;
}
