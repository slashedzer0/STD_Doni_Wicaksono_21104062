#include <iostream>
using namespace std;

int main()
{
  float number1, number2;

  cout << "Masukkan bilangan pertama: ";
  cin >> number1;
  cout << "Masukkan bilangan kedua: ";
  cin >> number2;

  cout << "Hasil penjumlahan: " << number1 + number2 << endl
       << "Hasil pengurangan: " << number1 - number2 << endl
       << "Hasil perkalian: " << number1 * number2 << endl
       << "Hasil pembagian: " << number1 / number2 << endl;

  return 0;
}