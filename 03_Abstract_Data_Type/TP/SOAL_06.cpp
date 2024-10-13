#include <iostream>
#include <cmath>
using namespace std;

class Kerucut
{
private:
    double r, h;

public:
    Kerucut(double r, double h) : r(r), h(h) {}
    double vol() { return M_PI * r * r * h / 3; }
    double luas() { return M_PI * r * (r + sqrt(r * r + h * h)); }
};

int main()
{
    double r, h;
    cout << "Jari-jari: ";
    cin >> r;
    cout << "Tinggi: ";
    cin >> h;
    Kerucut k(r, h);
    cout << "Volume: " << k.vol() << endl;
    cout << "Luas permukaan: " << k.luas() << endl;
    return 0;
}