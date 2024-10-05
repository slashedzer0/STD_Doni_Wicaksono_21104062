#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Masukkan jumlah elemen array: ";
    cin >> n;

    int arr[n];
    cout << "Masukkan nilai elemen-elemen array:\n";
    for (int &x : arr)
        cin >> x;

    bool exit = false;
    while (!exit)
    {
        int pilihan;
        cout << "\nMenu:\n1. Maksimum\n2. Minimum\n3. Rata-rata\n4. Keluar\nPilih opsi: ";
        cin >> pilihan;

        switch (pilihan)
        {
        case 1:
        {
            int maxVal = arr[0];
            for (int i = 1; i < n; i++)
                if (arr[i] > maxVal)
                    maxVal = arr[i];
            cout << "Nilai Maksimum: " << maxVal << endl;
            break;
        }
        case 2:
        {
            int minVal = arr[0];
            for (int i = 1; i < n; i++)
                if (arr[i] < minVal)
                    minVal = arr[i];
            cout << "Nilai Minimum: " << minVal << endl;
            break;
        }
        case 3:
        {
            double sum = 0;
            for (int x : arr)
                sum += x;
            cout << "Nilai Rata-rata: " << sum / n << endl;
            break;
        }
        case 4:
            exit = true;
            break;
        default:
            cout << "Pilihan tidak valid.\n";
        }
    }

    return 0;
}
