#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

class CircularLinkedList {
    Node* head;

public:
    CircularLinkedList() {
        head = NULL;
    }

    // Insert at beginning
    void insertBeginning(int value) {
        Node* newNode = new Node();
        newNode->data = value;

        // If list is empty
        if (head == NULL) {
            head = newNode;
            newNode->next = head;
        }
        else {
            Node* temp = head;

            // Find last node
            while (temp->next != head) {
                temp = temp->next;
            }

            newNode->next = head;
            head = newNode;
            temp->next = head;
        }

        cout << "Node inserted at beginning." << endl;
    }

    // Insert at end
    void insertEnd(int value) {
        Node* newNode = new Node();
        newNode->data = value;

        // If list is empty
        if (head == NULL) {
            head = newNode;
            newNode->next = head;
        }
        else {
            Node* temp = head;

            // Find last node
            while (temp->next != head) {
                temp = temp->next;
            }

            temp->next = newNode;
            newNode->next = head;
        }

        cout << "Node inserted at end." << endl;
    }

    // Insert after a given node
    void insertAfter(int givenValue, int value) {
        if (head == NULL) {
            cout << "List is empty!" << endl;
            return;
        }

        Node* temp = head;

        do {
            if (temp->data == givenValue) {
                Node* newNode = new Node();

                newNode->data = value;
                newNode->next = temp->next;
                temp->next = newNode;

                cout << "Node inserted successfully." << endl;
                return;
            }

            temp = temp->next;

        } while (temp != head);

        cout << "Given node not found!" << endl;
    }

    // Delete first node
    void deleteFirst() {
        if (head == NULL) {
            cout << "List is empty!" << endl;
            return;
        }

        // Only one node
        if (head->next == head) {
            delete head;
            head = NULL;
        }
        else {
            Node* last = head;

            // Find last node
            while (last->next != head) {
                last = last->next;
            }

            Node* temp = head;
            head = head->next;
            last->next = head;

            delete temp;
        }

        cout << "First node deleted." << endl;
    }

    // Delete last node
    void deleteLast() {
        if (head == NULL) {
            cout << "List is empty!" << endl;
            return;
        }

        // Only one node
        if (head->next == head) {
            delete head;
            head = NULL;
            cout << "Last node deleted." << endl;
            return;
        }

        Node* temp = head;

        // Find second-last node
        while (temp->next->next != head) {
            temp = temp->next;
        }

        Node* last = temp->next;
        temp->next = head;

        delete last;

        cout << "Last node deleted." << endl;
    }

    // Delete node after a given node
    void deleteAfter(int givenValue) {
        if (head == NULL) {
            cout << "List is empty!" << endl;
            return;
        }

        Node* temp = head;

        do {
            if (temp->data == givenValue) {

                // Only one node
                if (temp->next == temp) {
                    cout << "No node exists after the given node!" << endl;
                    return;
                }

                Node* deleteNode = temp->next;
                temp->next = deleteNode->next;

                // If deleting head, update head
                if (deleteNode == head) {
                    head = deleteNode->next;
                }

                delete deleteNode;

                cout << "Node after given node deleted." << endl;
                return;
            }

            temp = temp->next;

        } while (temp != head);

        cout << "Given node not found!" << endl;
    }

    // Display all nodes
    void display() {
        if (head == NULL) {
            cout << "List is empty!" << endl;
            return;
        }

        Node* temp = head;

        cout << "Circular Linked List: ";

        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);

        cout << "HEAD" << endl;
    }
};

int main() {
    CircularLinkedList list;

    int choice, value, givenValue;

    do {
        cout << "\n===== Singly Circular Linked List =====" << endl;
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
                cout << "Enter given node value: ";
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
                cout << "Enter given node value: ";
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
