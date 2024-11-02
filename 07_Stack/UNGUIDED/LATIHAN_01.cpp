#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

bool isPalindrome(const string &originalText) {
    stack<char> characterStorage;
    string normalizedText;
    
    for (char currentChar : originalText) {
        if (isalnum(currentChar)) {
            char lowercaseChar = tolower(currentChar);
            normalizedText += lowercaseChar;
            characterStorage.push(lowercaseChar);
        }
    }
    
    int normalTextPosition = 0;
    while (!characterStorage.empty()) {
        char reversedChar = characterStorage.top();
        
        if (reversedChar != normalizedText[normalTextPosition]) {
            return false;
        }
        
        characterStorage.pop();
        normalTextPosition++;
    }
    
    return true;
}

int main() {
    string userInput;
    
    cout << "Masukkan teks untuk diperiksa (dapat berupa kata/kalimat): ";
    getline(cin, userInput);
    
    if (isPalindrome(userInput)) {
        cout << "✓ Teks tersebut adalah palindrom!" << endl;
        cout << "  (Dapat dibaca sama dari depan dan belakang)" << endl;
    } else {
        cout << "✗ Teks tersebut bukan palindrom." << endl;
        cout << "  (Tidak dapat dibaca sama dari depan dan belakang)" << endl;
    }
    
    return 0;
}

/*
Program Pemeriksa Palindrom
--------------------------
Program ini memeriksa apakah sebuah teks merupakan palindrom atau bukan. Cara kerjanya:
1. Menerima input teks dari user
2. Membersihkan teks dari spasi & tanda baca, mengubah ke huruf kecil
3. Menyimpan teks bersih dalam stack (jadi terbalik) & string biasa
4. Membandingkan kedua versi teks. Jika sama = palindrom
5. Menampilkan hasil ke user dengan format yang mudah dibaca

Contoh palindrom: "Kasur ini rusak", "Race a car", "12321"
*/