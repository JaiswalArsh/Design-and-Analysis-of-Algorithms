#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class Stack {
private:
    Node* top;

public:
    Stack() {
        top = nullptr;
    }

    void push(int val) {
        Node* newNode = new Node(val);
        newNode->next = top;
        top = newNode;
        cout << "Pushed: " << val << "\n";
    }

    void pop() {
        if (!top) {
            cout << "Stack Underflow\n";
            return;
        }
        cout << "Popped: " << top->data << "\n";
        Node* temp = top;
        top = top->next;
        delete temp;
    }

    void display() {
        if (!top) {
            cout << "Stack is empty\n";
            return;
        }
        Node* temp = top;
        cout << "Stack: ";
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    }
};

int main() {
    Stack s;
    int choice, val;

    do {
        cout << "\nMenu:\n1. Push\n2. Pop\n3. Display\n0. Exit\nEnter choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> val;
                s.push(val);
                break;
            case 2:
                s.pop();
                break;
            case 3:
                s.display();
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
