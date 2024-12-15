#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

void create_graph() {
    int n;
    cout << "Silakan masukan jumlah simpul : ";
    cin >> n;
    cin.ignore();
    
    cout << "Silakan masukan nama simpul" << endl;
    vector<string> cities(n);
    for(int i = 0; i < n; i++) {
        cout << "Simpul " << i+1 << " : ";
        getline(cin, cities[i]);
    }
    
    vector<vector<int>> graph(n, vector<int>(n, 0));

    cout << "Silakan masukkan bobot antar simpul" << endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i != j) {
                cout << cities[i] << "--> " << cities[j] << " = ";
                cin >> graph[i][j];
            }
        }
    }

    cout << "      ";
    for(const string& city : cities) {
        cout << setw(6) << city;
    }
    cout << endl;

    for(int i = 0; i < n; i++) {
        cout << setw(6) << cities[i];
        for(int j = 0; j < n; j++) {
            cout << setw(6) << graph[i][j];
        }
        cout << endl;
    }
}

int main() {
    create_graph();
    return 0;
}