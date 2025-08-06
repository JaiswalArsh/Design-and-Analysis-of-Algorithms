#include <iostream>
using namespace std;

const int MAX = 100;

class PriorityQueue {
private:
    int arr[MAX];
    int size;

public:
    PriorityQueue() {
        size = 0;
    }

    void insert(int val) {
        if (size == MAX) {
            cout << "Queue is full\n";
            return;
        }

        int i;
        for (i = size - 1; i >= 0 && arr[i] < val; i--) {
            arr[i + 1] = arr[i];
        }
        arr[i + 1] = val;
        size++;
    }

    void deleteMax() {
        if (size == 0) {
            cout << "Queue is empty\n";
            return;
        }
        size--;  // Highest priority at index 0
    }

    void display() {
        if (size == 0) {
            cout << "Queue is empty\n";
            return;
        }
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    PriorityQueue pq;
    int choice, value;

    do {
        cout << "\n1. Insert\n2. Delete Max\n3. Display\n4. Exit\nEnter choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                pq.insert(value);
                break;
            case 2:
                pq.deleteMax();
                break;
            case 3:
                pq.display();
                break;
        }
    } while (choice != 4);

    return 0;
}
