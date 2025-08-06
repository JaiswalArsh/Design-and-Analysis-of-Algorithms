#include <iostream>
using namespace std;

const int MAX = 100;
int stack[MAX];
int top = -1;

void push(int val) {
    if (top == MAX - 1) {
        cout << "Stack Overflow\n";
        return;
    }
    stack[++top] = val;
    cout << "Pushed: " << val << "\n";
}

void pop() {
    if (top == -1) {
        cout << "Stack Underflow\n";
        return;
    }
    cout << "Popped: " << stack[top--] << "\n";
}

void display() {
    if (top == -1) {
        cout << "Stack is empty\n";
        return;
    }
    cout << "Stack: ";
    for (int i = top; i >= 0; --i)
        cout << stack[i] << " ";
    cout << "\n";
}

int main() {
    int choice, val;
    do {
        cout << "\nMenu:\n1. Push\n2. Pop\n3. Display\n0. Exit\nEnter choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> val;
                push(val);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 0:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice\n";
        }
    } while (choice != 0);
    return 0;
}
