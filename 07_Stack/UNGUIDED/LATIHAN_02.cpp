#include <iostream>
#include <stack>
using namespace std;

void reverseText(const string &originalText) {
    stack<char> characterStack;
    
    for (char currentChar : originalText) {
        characterStack.push(currentChar);
    }
    
    cout << "Hasil pembalikan teks: ";
    
    while (!characterStack.empty()) {
        cout << characterStack.top();
        characterStack.pop();
    }
    cout << endl;
}

int main() {
    string userInput;
    cout << "Masukkan teks: ";
    getline(cin, userInput);
    
    if (userInput.empty()) {
        cout << "Error: Teks tidak boleh kosong!" << endl;
        return 1;
    }
    
    reverseText(userInput);
    return 0;
}

/*
Program Pembalik Teks
--------------------
Program sederhana untuk membalik urutan karakter dalam teks.
Cara kerja: memasukkan setiap karakter ke dalam stack, lalu
mengeluarkannya kembali (LIFO - Last In First Out) sehingga
urutan karakternya terbalik. Contoh: "hello" menjadi "olleh".
*/