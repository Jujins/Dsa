#include <iostream>

using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

// Function to insert a node at the start of the linked list
void insertNode(Node** head, int newData) {
    // Create a new node
    Node* newNode = new Node();
    newNode->data = newData;
    newNode->next = *head;
    *head = newNode;
}

// Function to count the number of nodes in the linked list
int countNodes(Node* head) {
    int count = 0;
    Node* current = head;
    while (current != nullptr) {
        count++;
        current = current->next;
    }
    return count;
}

// Function to display the nodes in the linked list
void displayNodes(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr; // Initialize an empty linked list

    char choice;
    do {
        int data;
        cout << "Enter data for the node: ";
        cin >> data;
        insertNode(&head, data);

        cout << "Do you want to add another node? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    cout << "Linked List: ";
    displayNodes(head);

    int nodeCount = countNodes(head);
    cout << "Number of nodes: " << nodeCount << endl;

    return 0;
}
