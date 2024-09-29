#include <iostream>
using namespace std;

float ctof(float celcius);
int main()
{
  float celcius, fahrenheit;
  cout << "nilai celcius? ";
  cin >> celcius;
  fahrenheit = ctof(celcius);
  cout << celcius << " celcius adalah "
       << "Fahrenheit =" << fahrenheit << endl;
  return 0;
}

float ctof(float celcius)
{
  return celcius * 1.8 + 32;
}