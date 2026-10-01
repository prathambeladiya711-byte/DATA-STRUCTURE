#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

class SinglyLinkedList {
    Node* head;

public:
    SinglyLinkedList() {
        head = NULL;
    }

    // Insert at beginning
    void insertBeginning(int value) {
        Node* newNode = new Node();

        newNode->data = value;
        newNode->next = head;
        head = newNode;

        cout << "Node inserted at beginning." << endl;
    }

    // Insert at end
    void insertEnd(int value) {
        Node* newNode = new Node();

        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
        }
        else {
            Node* temp = head;

            while (temp->next != NULL) {
                temp = temp->next;
            }

            temp->next = newNode;
        }

        cout << "Node inserted at end." << endl;
    }

    // Insert after a given node
    void insertAfter(int givenValue, int value) {
        Node* temp = head;

        while (temp != NULL && temp->data != givenValue) {
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "Given node not found!" << endl;
            return;
        }

        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = temp->next;
        temp->next = newNode;

        cout << "Node inserted successfully." << endl;
    }

    // Delete first node
    void deleteFirst() {
        if (head == NULL) {
            cout << "List is empty!" << endl;
            return;
        }

        Node* temp = head;
        head = head->next;

        delete temp;

        cout << "First node deleted." << endl;
    }

    // Delete last node
    void deleteLast() {
        if (head == NULL) {
            cout << "List is empty!" << endl;
            return;
        }

        // Only one node
        if (head->next == NULL) {
            delete head;
            head = NULL;
            cout << "Last node deleted." << endl;
            return;
        }

        Node* temp = head;

        while (temp->next->next != NULL) {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = NULL;

        cout << "Last node deleted." << endl;
    }

    // Delete node after a given node
    void deleteAfter(int givenValue) {
        Node* temp = head;

        while (temp != NULL && temp->data != givenValue) {
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "Given node not found!" << endl;
            return;
        }

        if (temp->next == NULL) {
            cout << "No node exists after the given node!" << endl;
            return;
        }

        Node* deleteNode = temp->next;
        temp->next = deleteNode->next;

        delete deleteNode;

        cout << "Node after given node deleted." << endl;
    }

    // Display all nodes
    void display() {
        if (head == NULL) {
            cout << "List is empty!" << endl;
            return;
        }

        Node* temp = head;

        cout << "Linked List: ";

        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }

        cout << "NULL" << endl;
    }
};

int main() {
    SinglyLinkedList list;
    int choice, value, givenValue;

    do {
        cout << "\n===== Singly Linked List =====" << endl;
        cout << "1. Insert at Beginning" << endl;
        cout << "2. Insert at End" << endl;
        cout << "3. Insert After Given Node" << endl;
        cout << "4. Delete First Node" << endl;
        cout << "5. Delete Last Node" << endl;
        cout << "6. Delete Node After Given Node" << endl;
        cout << "7. Display" << endl;
        cout << "8. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

            case 1:
                cout << "Enter value: ";
                cin >> value;
                list.insertBeginning(value);
                break;

            case 2:
                cout << "Enter value: ";
                cin >> value;
                list.insertEnd(value);
                break;

            case 3:
                cout << "Enter the given node value: ";
                cin >> givenValue;

                cout << "Enter value to insert: ";
                cin >> value;

                list.insertAfter(givenValue, value);
                break;

            case 4:
                list.deleteFirst();
                break;

            case 5:
                list.deleteLast();
                break;

            case 6:
                cout << "Enter the given node value: ";
                cin >> givenValue;

                list.deleteAfter(givenValue);
                break;

            case 7:
                list.display();
                break;

            case 8:
                cout << "Program terminated." << endl;
                break;

            default:
                cout << "Invalid choice!" << endl;
        }

    } while (choice != 8);

    return 0;
}
