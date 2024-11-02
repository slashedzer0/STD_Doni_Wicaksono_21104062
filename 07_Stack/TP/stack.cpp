#include <iostream>
#include "stack.h"

using namespace std;

void initializeStack(stack &stk) {
    stk.topIndex = 0;
}

bool isStackEmpty(stack stk) {
    return (stk.topIndex == 0);
}

bool isStackFull(stack stk) {
    return (stk.topIndex == STACK_CAPACITY);
}

void pushElement(stack &stk, elementType element) {
    if (isStackFull(stk)) {
        cout << "Stack is full! Cannot add more elements." << endl;
    } else {
        stk.elements[stk.topIndex] = element;
        stk.topIndex++;
        cout << "Element " << element << " successfully added to stack." << endl;
    }
}

elementType popElement(stack &stk) {
    if (isStackEmpty(stk)) {
        cout << "Stack is empty! No elements to remove." << endl;
        return 0;
    } else {
        stk.topIndex--;
        return stk.elements[stk.topIndex];
    }
}

void displayStack(stack stk) {
    if (isStackEmpty(stk)) {
        cout << "Stack is empty!" << endl;
    } else {
        for (int idx = stk.topIndex - 1; idx >= 0; idx--) {
            cout << stk.elements[idx] << " ";
        }
        cout << endl;
    }
}