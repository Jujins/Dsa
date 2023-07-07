#include <iostream>
using namespace std;

struct Node {
    int data;
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

    void insert_Node(int n){
        struct Node* new_node = new Node;
        new_node->data = n;
        new_node->next = head;
        head = new_node;
    }

    int count_Node(){
        Node* temp = head;
        int ctr = 0;

        while (temp != NULL) {
            ctr++;
            temp = temp->next;
        }
        return ctr;
    }

    void display_nodes(){
        struct Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
};
int main(){
    LinkedList l;

    l.insert_Node(13);
    l.insert_Node(11);
    l.insert_Node(9);
    l.insert_Node(7);
    l.insert_Node(5);
    l.insert_Node(3);
    l.insert_Node(1);
    // l.insert_Node(17);

    cout << "Current contents of the Linked List: ";
    l.display_nodes();
    cout << endl;
    cout << "Current size of the Linked List: ";
    cout << l.count_Node();
    return 0;
}