#include <iostream>
using namespace std;

const int MAX = 100;

void display(int arr[], int size) {
    cout << "Array: ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

int findIndex(int arr[], int size, int value) {
    for (int i = 0; i < size; i++)
        if (arr[i] == value)
            return i;
    return -1; // Not found
}

void insertAtIndex(int arr[], int &size, int index, int value) {
    if (size >= MAX || index < 0 || index > size) {
        cout << "Invalid index or array full.\n";
        return;
    }
    for (int i = size; i > index; i--)
        arr[i] = arr[i - 1];
    arr[index] = value;
    size++;
}

void insertAtValue(int arr[], int &size, int target, int value) {
    int idx = findIndex(arr, size, target);
    if (idx == -1) {
        cout << "Value not found.\n";
        return;
    }
    arr[idx] = value;
}

void insertBeforeValue(int arr[], int &size, int target, int value) {
    int idx = findIndex(arr, size, target);
    if (idx == -1) {
        cout << "Value not found.\n";
        return;
    }
    insertAtIndex(arr, size, idx, value);
}

void insertAfterValue(int arr[], int &size, int target, int value) {
    int idx = findIndex(arr, size, target);
    if (idx == -1) {
        cout << "Value not found.\n";
        return;
    }
    insertAtIndex(arr, size, idx + 1, value);
}

void deleteByValue(int arr[], int &size, int target) {
    int idx = findIndex(arr, size, target);
    if (idx == -1) {
        cout << "Value not found.\n";
        return;
    }
    for (int i = idx; i < size - 1; i++)
        arr[i] = arr[i + 1];
    size--;
}

int main() {
    int arr[MAX], size, choice, target, value;

    cout << "Enter initial size of array: ";
    cin >> size;

    cout << "Enter " << size << " elements:\n";
    for (int i = 0; i < size; i++)
        cin >> arr[i];

    do {
        cout << "\nMenu:\n";
        cout << "1. Insert at a value (replace)\n";
        cout << "2. Insert before a value\n";
        cout << "3. Insert after a value\n";
        cout << "4. Delete by value\n";
        cout << "5. Display\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter target value to replace and new value: ";
                cin >> target >> value;
                insertAtValue(arr, size, target, value);
                break;

            case 2:
                cout << "Enter target value and value to insert before: ";
                cin >> target >> value;
                insertBeforeValue(arr, size, target, value);
                break;

            case 3:
                cout << "Enter target value and value to insert after: ";
                cin >> target >> value;
                insertAfterValue(arr, size, target, value);
                break;

            case 4:
                cout << "Enter value to delete: ";
                cin >> target;
                deleteByValue(arr, size, target);
                break;

            case 5:
                display(arr, size);
                break;

            case 0:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice.\n";
        }

    } while (choice != 0);

    return 0;
}
