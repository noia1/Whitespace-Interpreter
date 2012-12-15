#include "Lexer.h"

std::stack<int> myStack;
std::map<int, int> myMap;

void StackPush(int i) {
    //printf("Pushing: %d\n", i);
    myStack.push(i);
}

void StackPop() {
    if (myStack.empty()) {
        printf("Stack is empty, cannot pop.\n");
        return;
    }
    myStack.pop();
}

void Addition() {
    if (myStack.size() < 2) {
        printf("Stack does not contain enough values to perform Addition.\n");
        return;
    }
    int a = myStack.top();
    myStack.pop();
    //printf("(%d + %d)", a, myStack.top());
    a += myStack.top();
    myStack.pop();
    myStack.push(a);
}

void Subtraction() {
    if (myStack.size() < 2) {
        printf("Stack does not contain enough values to perform Subtraction.\n");
        return;
    }
    int a = myStack.top();
    myStack.pop();
    //printf("(%d + %d)", a, myStack.top());
    a -= myStack.top();
    myStack.pop();
    myStack.push(a);
}

void Multiplication() {
    if (myStack.size() < 2) {
        printf("Stack does not contain enough values to perform Multiplication.\n");
        return;
    }
    int a = myStack.top();
    myStack.pop();
    //printf("(%d * %d)", a, myStack.top());
    a *= myStack.top();
    myStack.pop();
    myStack.push(a);
}

void Division() {
    if (myStack.size() < 2) {
        printf("Stack does not contain enough values to perform Division.\n");
        return;
    }
    int a = myStack.top();
    myStack.pop();
    //printf("(%d / %d)", a, myStack.top());
    a /= myStack.top();
    myStack.pop();
    myStack.push(a);
}

void Modulo() {
    if (myStack.size() < 2) {
        printf("Stack does not contain enough values to perform Modulo.\n");
        return;
    }
    int a = myStack.top();
    myStack.pop();
    //printf("(%d mod %d)", a, myStack.top());
    a %= myStack.top();
    myStack.pop();
    myStack.push(a);
}

void HeapPush() {
    if (myStack.size() < 2) {
        printf("Stack does not contain enough values to perform a push to the heap.\n");
        return;
    }
    int value = myStack.top();
    myStack.pop();
    int key = myStack.top();
    myMap[key] = value;
    myStack.pop();
}  
void HeapRetrieve() {
    if (myStack.empty()) {
        printf("Stack is empty, cannot retrieve from heap.\n");
        return;
    }
    int i = myStack.top();
    myStack.pop();
    if (!myMap[i]) {
        printf("Value not in the map.\n");
        return;
    }
    int key = myMap[i];
    myStack.push(key);
}

void CharOut() {
    if (myStack.empty()) {
        printf("Stack is empty, cannot output the character.\n");
        return;
    }
    char c = (char)myStack.top();
    printf("%c", c);
    myStack.pop();
}

void IntOut() {
    if (myStack.empty()) {
        printf("Stack is empty, cannot output the integer.\n");
        return;
    }
    int i = myStack.top();
    printf("%d", i);
    myStack.pop();
}

void CharIn() {
    if (myStack.empty()) {
        printf("Stack is empty, cannot input a character.\n");
        return;
    }
    char c;
    scanf("%c", &c);
    int key = myStack.top();
    myStack.pop();
    myMap[key] = (int)c;
}

void IntIn() {
    if (myStack.empty()) {
        printf("Stack is empty, cannot input a integer.\n");
        return;
    }
    int i;
    scanf("%d", &i);
    int key = myStack.top();
    myStack.pop();
    myMap[key] = i;
}
