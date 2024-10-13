#include <iostream>
using namespace std;

int main()
{
    int num = 42;
    double pi = 3.14159;
    char letter = 'A';

    cout << "Nilai dan alamat memori variabel:" << endl;
    cout << "num: " << num << ", Alamat: " << &num << endl;
    cout << "pi: " << pi << ", Alamat: " << &pi << endl;
    cout << "letter: " << letter << ", Alamat: " << static_cast<void *>(&letter) << endl;

    return 0;
}