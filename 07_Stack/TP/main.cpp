#include <iostream>
#include "stack.h"

using namespace std;

int main() {
    stack myStack;
    initializeStack(myStack);

    int lastNIMDigit = 2;
    string wordSequence;

    switch (lastNIMDigit % 4) {
        case 0:
            wordSequence = "IFLABJAYA";
            cout << "Result:" << endl;
            break;
        case 1:
            wordSequence = "HALOBANDUNG";
            cout << "Result:" << endl;
            break;
        case 2:
            wordSequence = "PERCAYADIRI";
            cout << "Result:" << endl;
            break;
        case 3:
            wordSequence = "STRUKTURDATA";
            cout << "Result:" << endl;
            break;
        default:
            cout << "Invalid NIM last digit." << endl;
            return 0;
    }

    for (int idx = wordSequence.length() - 1; idx >= 0; idx--) {
        pushElement(myStack, wordSequence[idx]);
    }

    cout << "Isi Stack Awal: ";
    displayStack(myStack);

    int elementsToRemove = wordSequence.length() - 4;
    for (int idx = 0; idx < elementsToRemove; idx++) {
        popElement(myStack);
    }

    cout << "Isi Stack Setelah Pop: ";
    displayStack(myStack);

    return 0;
}