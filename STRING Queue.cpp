#include <iostream>
#include <string>
using namespace std;

struct queue_header {
    string* data;
    int front;
    int back;
    int capacity;
};

typedef struct queue_header* queue;

void enqueue(queue Q, const string& element) {
    if (Q->back == Q->capacity) {
        cout << "Queue is full." << endl;
        return;
    }

    Q->data[Q->back] = element;
    Q->back++;
}

string dequeue(queue Q) {
    string element = Q->data[Q->front];
    Q->front++;
    return element;
}

int searchElement(queue Q, const string& element) {
    for (int i = Q->front; i < Q->back; i++) {
        if (Q->data[i] == element) {
            return i - Q->front;
        }
    }
    return -1;
}

void displayElements(queue Q) {
    if (Q->front == Q->back) {
        cout << "Queue is empty." << endl;
    } else {
        cout << "Queue elements: ";
        for (int i = Q->front; i < Q->back; i++) {
            cout << Q->data[i] << " ";
        }
        cout << endl;
    }
}

string findFirstElement(queue Q) {
    if (Q->front == Q->back) {
        return "";  // Return an empty string if the queue is empty
    }
    return Q->data[Q->front];
}

int main() {
    queue_header q;
    string choice;

    const int capacity = 100;
    q.data = new string[capacity];
    q.front = 0;
    q.back = 0;
    q.capacity = capacity;

    while (true) {
        cout << "Menu:" << endl;
        cout << "a. Add element" << endl;
        cout << "b. Delete Element" << endl;
        cout << "c. Search Element" << endl;
        cout << "d. Display Elements" << endl;
        cout << "e. Identify the First Element" << endl;
        cout << "f. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice.at(0)) {
            case 'a': {
                cout << "Enter the element to enqueue: ";
                string element;
                cin.ignore();  // Ignore the newline character from previous input
                getline(cin, element);
                enqueue(&q, element);
                cout << "Element enqueued." << endl;
                break;
            }
            case 'b': {
                if (q.front == q.back) {
                    cout << "Queue is empty." << endl;
                } else {
                    string element = dequeue(&q);
                    cout << "Dequeued element: " << element << endl;
                }
                break;
            }
            case 'c': {
                cout << "Enter the element to search: ";
                string element;
                cin.ignore();  // Ignore the newline character from previous input
                getline(cin, element);
                int index = searchElement(&q, element);
                if (index != -1) {
                    cout << "Element found at index " << index << "." << endl;
                } else {
                    cout << "Element not found." << endl;
                }
                break;
            }
            case 'd': {
                displayElements(&q);
                break;
            }
            case 'e': {
                if (q.front == q.back) {
                    cout << "Queue is empty." << endl;
                } else {
                    string firstElement = findFirstElement(&q);
                    cout << "The first element of the queue is: " << firstElement << endl;
                }
                break;
            }
            case 'f': {
                cout << "Exiting program." << endl;
                delete[] q.data;
                return 0;
            }
            default:
                cout << "Invalid choice. Please try again." << endl;
        }

        cout << endl;
    }
}


//string findLastElement(queue Q) {
//    if (Q->front == Q->back) {
//        return "";  // Return an empty string if the queue is empty
//    }
//    return Q->data[Q->back - 1];
//}
//
//case 'e': {
//    if (q.front == q.back) {
//        cout << "Queue is empty." << endl;
//    } else {
//        string lastElement = findLastElement(&q);
//        cout << "The last element of the queue is: " << lastElement << endl;
//    }
//    break;
//}
