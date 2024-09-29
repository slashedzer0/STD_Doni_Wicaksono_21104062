#include <iostream>
#include <conio.h>
using namespace std;

// Perulangan For
int main()
{
  int jum;
  cout << "jumlah perulangan: ";
  cin >> jum;
  for (int i = 0; i < jum; i++)
  {
    cout << "saya pintar\n";
  }
  getch();
  return 0;
}

// Perulangan While
int main()
{
  int i = 1;
  int jum;
  cout << "masukan banyak baris: ";
  cin >> jum;
  while (i <= jum)
  {
    cout << "baris ke-" << i << endl;
    i++;
  }
  getch();
  return 0;
}

// Perulangan Do-While
int main()
{
  int i = 1;
  int jum;
  cin >> jum;
  do
  {
    cout << "baris ke-" << i + 1 << endl;
    i++;
  } while (i < jum);
  getch();
  return 0;
}