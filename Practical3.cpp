#include <iostream>
using namespace std;

#define MAX 5

int stack[MAX], top = -1;

void push(int x) {
    if (top == MAX - 1) cout << "Stack Overflow\n";
    else stack[++top] = x;
}

void pop() {
    if (top == -1) cout << "Stack Underflow\n";
    else cout << "Popped: " << stack[top--] << endl;
}

void peek() {
    if (top == -1) cout << "Stack Empty\n";
    else cout << "Top: " << stack[top] << endl;
}

void display() {
    if (top == -1) cout << "Stack Empty\n";
    else
        for (int i = top; i >= 0; i--)
            cout << stack[i] << " ";
    cout << endl;
}

int main() {
    push(10);
    push(20);
    push(30);

    display();
    peek();
    pop();
    display();

    return 0;
}