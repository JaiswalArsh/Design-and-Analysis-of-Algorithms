#include <bits/stdc++.h>
using namespace std;

const int MAX = 100;  // Maximum array size

void display(int arr[], int size) {
    cout << "Array: ";
    for(int i = 0; i < size; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

void insertAt(int arr[], int &size, int index, int value) {
    if(index < 0 || index > size || size >= MAX) {
        cout << "Invalid index or array full.\n";
        return;
    }

    for(int i = size; i > index; --i)
        arr[i] = arr[i - 1];

    arr[index] = value;
    size++;
}

void deleteAt(int arr[], int &size, int index) {
    if(index < 0 || index >= size) {
        cout << "Invalid index.\n";
        return;
    }

    for(int i = index; i < size - 1; ++i)
        arr[i] = arr[i + 1];
    size--;
}

int main() {
    int arr[MAX], size, choice, index, value;
    cout << "Enter initial size of array: ";
    cin >> size;
    cout << "Enter " << size << " elements:\n";
    for(int i = 0; i < size; ++i)
        cin >> arr[i];
    do {
        cout << "\nMenu:\n";
        cout << "1. Insert at index\n";
        cout << "2. Insert before index\n";
        cout << "3. Insert after index\n";
        cout << "4. Delete at index\n";
        cout << "5. Display\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter index and value to insert: ";
                cin >> index >> value;
                insertAt(arr, size, index, value);
                break;

            case 2:
                cout << "Enter index and value to insert before: ";
                cin >> index >> value;
                insertAt(arr, size, index - 1, value);
                break;

            case 3:
                cout << "Enter index and value to insert after: ";
                cin >> index >> value;
                insertAt(arr, size, index + 1, value);
                break;

            case 4:
                cout << "Enter index to delete: ";
                cin >> index;
                deleteAt(arr, size, index);
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
    } while(choice != 0);
    return 0;
}
