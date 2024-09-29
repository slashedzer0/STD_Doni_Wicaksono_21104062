#include <iostream>
using namespace std;

int main()
{
  int n;
  cout << "Masukkan bilangan: ";
  cin >> n;

  for (int i = n; i >= 1; i--)
  {
    cout << string(2 * (n - i), ' ');
    for (int j = i; j >= 1; j--)
      cout << j << ' ';
    cout << "* ";
    for (int j = 1; j <= i; j++)
      cout << j << ' ';
    cout << endl;
  }
  cout << string(2 * n, ' ') << "*\n";
  return 0;
}