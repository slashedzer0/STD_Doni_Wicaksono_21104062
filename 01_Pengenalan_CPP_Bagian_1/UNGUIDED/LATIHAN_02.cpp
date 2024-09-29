#include <iostream>
#include <string>
using namespace std;

int main()
{
  int bilangan;
  string satuan[] = {"Nol", "Satu", "Dua", "Tiga", "Empat", "Lima", "Enam", "Tujuh", "Delapan", "Sembilan"};
  string belasan[] = {"Sebelas", "Dua Belas", "Tiga Belas", "Empat Belas", "Lima Belas", "Enam Belas", "Tujuh Belas", "Delapan Belas", "Sembilan Belas"};
  string puluhan[] = {"", "", "Dua Puluh", "Tiga Puluh", "Empat Puluh", "Lima Puluh", "Enam Puluh", "Tujuh Puluh", "Delapan Puluh", "Sembilan Puluh"};

  cout << "Masukkan bilangan (0-100): ";
  cin >> bilangan;

  if (bilangan >= 0 && bilangan <= 100)
  {
    if (bilangan < 10)
      cout << satuan[bilangan];
    else if (bilangan < 20)
      cout << (bilangan == 10 ? "Sepuluh" : belasan[bilangan - 11]);
    else if (bilangan == 100)
      cout << "Seratus";
    else
      cout << puluhan[bilangan / 10] << (bilangan % 10 ? " " + satuan[bilangan % 10] : "");
  }
  else
    cout << "Bilangan harus antara 0 hingga 100";

  cout << endl;
  return 0;
}