#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

class LinkedList {
private:
    Node* head;
public:
    LinkedList() {
        head = NULL;
    }

    bool checkDuplicate(int value) {
        Node* temp = head;
        while (temp != NULL) {
            if (temp->data == value) {
                return true; // Duplicate found
            }
            temp = temp->next;
        }
        return false; // No duplicate found
    }

    void addAtStart(int value) {
        if (checkDuplicate(value)) {
            cout << "Value " << value << " already exists in the list." << endl;
            return;
        }

        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = head;
        head = newNode;
        cout << "Value " << value << " added at the beginning" << endl;
    }

    void addAtEnd(int value) {
        if (checkDuplicate(value)) {
            cout << "Value " << value << " already exists in the list." << endl;
            return;
        }

        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }

        cout << "Value " << value << " added at the end" << endl;
    }

    void addAtPosition(int value, int position) {
        if (position <= 0) {
            cout << "Invalid position.\n" << endl;
            return;
        }

        if (checkDuplicate(value)) {
            cout << "Value " << value << " already exists in the list." << endl;
            return;
        }

        Node* newNode = new Node;
        newNode->data = value;

        if (position == 1) {
            newNode->next = head;
            head = newNode;
            cout << "Value " << value << " added at position " << position << endl;
            return;
        }

        Node* temp = head;
        int currentPosition = 1;

        while (temp != NULL && currentPosition < position - 1) {
            temp = temp->next;
            currentPosition++;
        }

        if (temp == NULL) {
            cout << "Invalid position." << endl;
            return;
        }

        newNode->next = temp->next;
        temp->next = newNode;
        cout << "Element " << value << " added at position " << position << endl;
    }

    void deleteFromStart() {
        if (head == NULL) {
            cout << "The list is empty." << endl;
            return;
        }

        Node* temp = head;
        head = head->next;
        delete temp;
        cout << "Deleted the first element from the list." << endl;
    }

    void deleteFromEnd() {
        if (head == NULL) {
            cout << "The list is empty." << endl;
            return;
        }

        if (head->next == NULL) {
            delete head;
            head = NULL;
            cout << "Deleted the last element from the list." << endl;
            return;
        }

        Node* temp = head;
        while(temp->next->next != NULL) {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = NULL;
        cout << "Deleted the last element from the list." << endl;
    }

    void deleteFromPosition(int position) {
        if (head == NULL) {
            cout << "The list is empty." << endl;
            return;
        }

        if (position <= 0) {
            cout << "Invalid position. Please enter a positive position value." << endl;
            return;
        }

        if (position == 1) {
            Node* temp = head;
            head = head->next;
            delete temp;
            cout << "Deleted the element at position " << position << endl;
            return;
        }

        Node* temp = head;
        int currentPosition = 1;

        while (temp->next != NULL && currentPosition < position - 1) {
            temp = temp->next;
            currentPosition++;
        }

        if (temp->next == NULL) {
            cout << "Invalid position." << endl;
            return;
        }

        Node* nodeToDelete = temp->next;
        temp->next = temp->next->next;
        delete nodeToDelete;
        cout << "Deleted the element at position " << position<< endl;
    }

    void display() {
        if (head == NULL) {
            cout << "The list is empty." << endl;
            return;
        }

        Node* temp = head;
        cout << "Your List: ";
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    int searchPosition(int value) {
        Node* temp = head;
        int position = 1;
        while (temp != NULL) {
            if (temp->data == value) {
                return position; // Found the value at this position
            }
            temp = temp->next;
            position++;
        }
        return -1; // Value not found in the list
    }
};

int main() {
    LinkedList linkedList;
    int value, position;
    char choice;

    while (true) {
        cout << "Menu:\n";
        cout << "a. Add\n";
        cout << "b. Delete\n";
        cout << "c. Display\n";
        cout << "d. Search Position\n";
        cout << "e. Exit\n";
        cout << "\nEnter your choice: ";
        cin >> choice;
        cout << endl;

        switch (choice) {
            case 'a':
                cout << "Add Menu:\n";
                cout << "a. START\n";
                cout << "b. END\n";
                cout << "c. ANY POSITION\n";
                cout << "\nEnter your choice: ";
                cin >> choice;

                switch (choice) {
                    case 'a':
                        cout << "\nEnter the value to add: ";
                        cin >> value;
                        linkedList.addAtStart(value);
                        break;
                    case 'b':
                        cout << "\nEnter the value to add: ";
                        cin >> value;
                        linkedList.addAtEnd(value);
                        break;
                    case 'c':
                        cout << "\nEnter the value to add: ";
                        cin >> value;
                        cout << "\nEnter the position to add: ";
                        cin >> position;
                        linkedList.addAtPosition(value, position);
                        break;
                    default:
                        cout << "\nInvalid choice.\n";
                }
                break;
            case 'b':
                cout << "Delete Menu:\n";
                cout << "a. START\n";
                cout << "b. END\n";
                cout << "c. DELETE\n";
                cout << "\nEnter your choice: ";
                cin >> choice;

                switch (choice) {
                    case 'a':
                        linkedList.deleteFromStart();
                        break;
                    case 'b':
                        linkedList.deleteFromEnd();
                        break;
                    case 'c':
                        cout << "\nEnter the position to delete: ";
                        cin >> position;
                        linkedList.deleteFromPosition(position);
                        break;
                    default:
                        cout << "Invalid choice." << endl;
                }
                break;
            case 'c':
                linkedList.display();
                break;
            case 'd':
                cout << "Enter the value to search for: ";
                cin >> value;
                position = linkedList.searchPosition(value);
                if (position != -1) {
                    cout << "Value " << value << " found at position " << position << endl;
                } else {
                    cout << "Value " << value << " not found in the list." << endl;
                }
                break;
            case 'e':
                cout << "Exiting program." << endl;
                exit(0);
            default:
                cout << "Invalid choice." << endl;
        }

        cout << endl;
    }

    return 0;
}
