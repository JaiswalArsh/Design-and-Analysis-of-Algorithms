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

class CircularQueue {
private:
    Node* front;
    Node* rear;

public:
    CircularQueue() {
        front = rear = nullptr;
    }

    void enqueue(int val) {
        Node* newNode = new Node(val);
        if (!front) {
            front = rear = newNode;
            rear->next = front;
        } else {
            rear->next = newNode;
            rear = newNode;
            rear->next = front;
        }
    }

    void dequeue() {
        if (!front) {
            cout << "Queue is empty\n";
            return;
        }

        if (front == rear) {
            delete front;
            front = rear = nullptr;
        } else {
            Node* temp = front;
            front = front->next;
            rear->next = front;
            delete temp;
        }
    }

    void display() {
        if (!front) {
            cout << "Queue is empty\n";
            return;
        }
        Node* temp = front;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != front);
        cout << endl;
    }
};

int main() {
    CircularQueue q;
    int choice, value;

    do {
        cout << "\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\nEnter choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value;
                q.enqueue(value);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                q.display();
                break;
        }
    } while (choice != 4);

    return 0;
}
