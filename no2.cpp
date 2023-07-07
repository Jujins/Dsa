#include <iostream>
using namespace std;

struct Node {
    int num;
    Node* next;
};

class LinkedList {
private:
    Node* head;
    Node* tail;
public:
    LinkedList () {
        head = NULL;
        tail = NULL;
    }

    void insert_Node(int n) {
        struct Node* new_node = new Node;
        new_node->num = n;
        new_node->next = head;
        head = new_node;
    }

    void display_all_nodes() {
        cout << "The list contains the data entered:\n";
        struct Node* temp = head;
        while (temp != NULL) {
            cout << temp->num << " ";
            temp = temp->next;
            cout << endl;
        }
    }
};

int main(){
    LinkedList l;

    l.insert_Node(1);
    l.insert_Node(3);
    l.insert_Node(5);
    l.insert_Node(7);
    l.insert_Node(9);
    l.insert_Node(11);
    l.display_all_nodes();

    return 0;
}