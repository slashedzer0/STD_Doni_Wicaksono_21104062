#include <iostream>
#include <vector>
using namespace std;

int main() {
    int vertices, edges;

    cout << "Masukkan jumlah simpul: ";
    cin >> vertices;
    cout << "Masukkan jumlah sisi: ";
    cin >> edges;
 
    vector<vector<int>> adjMatrix(vertices, vector<int>(vertices, 0));

    cout << "Masukkan pasangan simpul:\n";
    for(int i = 0; i < edges; i++) {
        int v1, v2;
        cin >> v1 >> v2;

        v1--; v2--;

        adjMatrix[v1][v2] = 1;
        adjMatrix[v2][v1] = 1;
    }

    cout << "Adjacency Matrix:\n";
    for(int i = 0; i < vertices; i++) {
        for(int j = 0; j < vertices; j++) {
            cout << adjMatrix[i][j];
        }
        cout << endl;
    }
    
    return 0;
}