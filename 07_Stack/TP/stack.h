#ifndef STACK_H
#define STACK_H

const int STACK_CAPACITY = 15;

typedef char elementType;

struct stack {
    elementType elements[STACK_CAPACITY];
    int topIndex;
};

void initializeStack(stack &stk);
bool isStackEmpty(stack stk);
bool isStackFull(stack stk);
void pushElement(stack &stk, elementType element);
elementType popElement(stack &stk);
void displayStack(stack stk);

#endif