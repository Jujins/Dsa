#include <iostream>
#include <string>

using namespace std;

class Node {
public:
    string data;
    Node* next;

    Node(const string& value) {
        data = value;
        next = NULL;
    }
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = NULL;
    }

    void addAtStart(const string& value) {
        Node* newNode = new Node(value);
        if (head == NULL) {
            head = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
        cout << "Added \"" << value << "\" at the start of the list." << endl;
    }

    void addAtEnd(const string& value) {
        Node* newNode = new Node(value);
        if (head == NULL) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        cout << "Added \"" << value << "\" at the end of the list." << endl;
    }

    void addAtPosition(const string& value, int position) {
        if (position <= 0) {
            cout << "Invalid position. Please enter a positive position value." << endl;
            return;
        }

        if (position == 1) {
            addAtStart(value);
            return;
        }

        Node* newNode = new Node(value);
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
        cout << "Added \"" << value << "\" at position " << position << endl;
    }

    void deleteFromStart() {
        if (head == NULL) {
            cout << "The list is empty." << endl;
            return;
        }

        Node* temp = head;
        head = head->next;
        delete temp;
        cout << "Deleted the element from the start of the list." << endl;
    }

    void deleteFromEnd() {
        if (head == NULL) {
            cout << "The list is empty." << endl;
            return;
        }

        if (head->next == NULL) {
            delete head;
            head = NULL;
            cout << "Deleted the element from the end of the list." << endl;
            return;
        }

        Node* temp = head;
        Node* prev = NULL;

        while (temp->next != NULL) {
            prev = temp;
            temp = temp->next;
        }

        prev->next = NULL;
        delete temp;
        cout << "Deleted the element from the end of the list." << endl;
    }

    void deleteAllOccurrences(const string& value) {
        if (head == NULL) {
            cout << "The list is empty." << endl;
            return;
        }

        Node* curr = head;
        Node* prev = NULL;
        int count = 0;

        while (curr != NULL) {
            if (curr->data == value) {
                Node* temp = curr;
                if (prev == NULL) {
                    head = curr->next;
                } else {
                    prev->next = curr->next;
                }
                curr = curr->next;
                delete temp;
                count++;
            } else {
                prev = curr;
                curr = curr->next;
            }
        }

        if (count > 0) {
            cout << "Deleted " << count << " occurrences of \"" << value << "\" from the list." << endl;
        } else {
            cout << "No occurrences of \"" << value << "\" found in the list." << endl;
        }
    }

    void deleteFromPosition(int position) {
        if (position <= 0) {
            cout << "Invalid position. Please enter a positive position value." << endl;
            return;
        }

        if (head == NULL) {
            cout << "The list is empty." << endl;
            return;
        }

        if (position == 1) {
            deleteFromStart();
            return;
        }

        Node* temp = head;
        Node* prev = NULL;
        int currentPosition = 1;

        while (temp != NULL && currentPosition < position) {
            prev = temp;
            temp = temp->next;
            currentPosition++;
        }

        if (temp == NULL) {
            cout << "Invalid position." << endl;
            return;
        }

        prev->next = temp->next;
        delete temp;
        cout << "Deleted the element at position " << position << endl;
    }

    void findPositions(const string& value) {
        if (head == NULL) {
            cout << "The list is empty." << endl;
            return;
        }

        Node* temp = head;
        int position = 1;
        bool found = false;

        while (temp != NULL) {
            if (temp->data == value) {
                cout << "Found \"" << value << "\" at position " << position << endl;
                found = true;
            }
            temp = temp->next;
            position++;
        }

        if (!found) {
            cout << "No occurrences of \"" << value << "\" found in the list." << endl;
        }
    }

    void display() {
        if (head == NULL) {
            cout << "The list is empty." << endl;
            return;
        }

        Node* temp = head;
        cout << "Linked List: ";
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList linkedList;
    char choice;
    string value;
    int position;

    while (true) {
        cout << "Menu:\n";
        cout << "A. Add\n";
        cout << "B. Delete\n";
        cout << "C. Display\n";
        cout << "D. Exit\n";
        cout << "\nEnter your choice: ";
        cin >> choice;
        cout << endl;

        switch (toupper(choice)) {
            case 'A':
                cout << "Add Menu:\n";
                cout << "1. Add from Start\n";
                cout << "2. Add from End\n";
                cout << "3. Add from any Position\n";
                cout << "\nEnter your choice: ";
                cin >> choice;

                switch (choice) {
                    case '1':
                        cout << "\nEnter the value to add: ";
                        cin.ignore();
                        getline(cin, value);
                        linkedList.addAtStart(value);
                        break;
                    case '2':
                        cout << "\nEnter the value to add: ";
                        cin.ignore();
                        getline(cin, value);
                        linkedList.addAtEnd(value);
                        break;
                    case '3':
                        cout << "\nEnter the value to add: ";
                        cin.ignore();
                        getline(cin, value);
                        cout << "\nEnter the position to add: ";
                        cin >> position;
                        linkedList.addAtPosition(value, position);
                        break;
                    default:
                        cout << "Invalid choice." << endl;
                }
                break;
            case 'B':
                cout << "Delete Menu:\n";
                cout << "1. Display from Head to Tails\n";
                cout << "2. Delete\n";
                cout << "\nEnter your choice: ";
                cin >> choice;

                switch (choice) {
                    case '1':
                        linkedList.display();
                        break;
                    case '2':
                        cout << "Delete Menu:\n";
                        cout << "a. Delete Duplication\n";
                        cout << "b. Delete the Start\n";
                        cout << "c. Delete the End\n";
                        cout << "d. Delete from any position\n";
                        cout << "\nEnter your choice: ";
                        cin >> choice;

                        switch (choice) {
                            case 'a':
                                cout << "\nEnter the value to delete: ";
                                cin.ignore();
                                getline(cin, value);
                                linkedList.deleteAllOccurrences(value);
                                break;
                            case 'b':
                                linkedList.deleteFromStart();
                                break;
                            case 'c':
                                linkedList.deleteFromEnd();
                                break;
                            case 'd':
                                cout << "\nEnter the position to delete: ";
                                cin >> position;
                                linkedList.deleteFromPosition(position);
                                break;
                            default:
                                cout << "Invalid choice." << endl;
                        }
                        break;
                    default:
                        cout << "Invalid choice." << endl;
                }
                break;
            case 'C':
                linkedList.display();
                break;
            case 'D':
                cout << "Exiting the program." << endl;
                return 0;
            default:
                cout << "Invalid choice." << endl;
        }

        cout << endl;
    }

    return 0;
}

