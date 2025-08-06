#include <iostream>
using namespace std;

const int MAX = 100;
int queue[MAX];
int front = -1, rear = -1;

void enqueue(int val) {
    if (rear == MAX - 1) {
        cout << "Queue Overflow\n";
        return;
    }
    if (front == -1) front = 0;
    queue[++rear] = val;
    cout << "Enqueued: " << val << "\n";
}

void dequeue() {
    if (front == -1 || front > rear) {
        cout << "Queue Underflow\n";
        return;
    }
    cout << "Dequeued: " << queue[front++] << "\n";
}

void display() {
    if (front == -1 || front > rear) {
        cout << "Queue is empty\n";
        return;
    }
    cout << "Queue: ";
    for (int i = front; i <= rear; i++)
        cout << queue[i] << " ";
    cout << "\n";
}

int main() {
    int choice, val;
    do {
        cout << "\nMenu:\n1. Enqueue\n2. Dequeue\n3. Display\n0. Exit\nEnter choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> val;
                enqueue(val);
                break;
            case 2:
                dequeue();
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
