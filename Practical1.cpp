#include <iostream>
using namespace std;

int main() {
    int arr[100], n, pos, value, key;

    // Create and input array
    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Traversal
    cout << "\nArray elements: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    // Insertion
    cout << "\n\nEnter position for insertion: ";
    cin >> pos;

    cout << "Enter value to insert: ";
    cin >> value;

    for (int i = n; i >= pos; i--) {
        arr[i] = arr[i - 1];
    }

    arr[pos - 1] = value;
    n++;

    cout << "Array after insertion: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    // Deletion
    cout << "\n\nEnter position for deletion: ";
    cin >> pos;

    for (int i = pos - 1; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }

    n--;

    cout << "Array after deletion: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    // Search
    cout << "\n\nEnter element to search: ";
    cin >> key;

    int found = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            cout << "Element found at position " << i + 1 << endl;
            found = 1;
            break;
        }
    }

    if (found == 0) {
        cout << "Element not found." << endl;
    }

    return 0;
}