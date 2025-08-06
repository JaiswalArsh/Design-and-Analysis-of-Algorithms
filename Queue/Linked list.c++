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

class Queue {
    Node *front, *rear;

public:
    Queue() {
        front = rear = nullptr;
    }

    void enqueue(int val) {
        Node* temp = new Node(val);
        if (!rear) {
            front = rear = temp;
        } else {
            rear->next = temp;
            rear = temp;
        }
        cout << "Enqueued: " << val << "\n";
    }

    void dequeue() {
        if (!front) {
            cout << "Queue Underflow\n";
            return;
        }
        cout << "Dequeued: " << front->data << "\n";
        Node* temp = front;
        front = front->next;
        if (!front) rear = nullptr;
        delete temp;
    }

    void display() {
        if (!front) {
            cout << "Queue is empty\n";
            return;
        }
        cout << "Queue: ";
        Node* temp = front;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    }
};

int main() {
    Queue q;
    int choice, val;
    do {
        cout << "\nMenu:\n1. Enqueue\n2. Dequeue\n3. Display\n0. Exit\nEnter choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> val;
                q.enqueue(val);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                q.display();
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
