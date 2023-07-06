#include <iostream>
#include <string>

using namespace std;

struct stack_header {
    string data[100];
    int top;
    int bottom;
    int capacity;
};

typedef struct stack_header* stack;

stack stack_new() {
    stack S = new stack_header;
    S->bottom = 0;
    S->top = -1;
    S->capacity = 100;
    return S;
}

void push(stack S, string e) {
    if (S->top == S->capacity - 1) {
        cout << "Cannot add element.\n";
    } else {
        S->data[++S->top] = e;
        cout << "Element added\n";
    }
}

void pop(stack S) {
    if (S->top == S->bottom - 1) {
        cout << "Stack is empty.\n";
    } else {
        cout << " " << S->data[S->top--] << " deleted from the stack.\n";
    }
}

void remove(stack S, string e) {
    bool found = false;
    int originalTop = S->top;
    for (int i = S->bottom; i <= S->top; i++) {
        if (S->data[i] == e) {
            found = true;
            continue;
        }
        S->data[++S->top] = S->data[i];
    }
    if (found) {
        cout << "Element removed\n";
        S->top = originalTop;
    } else {
        cout << "Element not found\n";
    }
}

void display(stack S) {
    cout << "Stack: ";
    for (int i = S->bottom; i <= S->top; i++) {
        cout << S->data[i] << " ";
    }
    cout << "\n";
}

bool search(stack S, string e) {
    for (int i = S->bottom; i <= S->top; i++) {
        if (S->data[i] == e) {
            return true;
        }
    }
    return false;
}

int main() {
    stack myStack = stack_new();

    char option = ' ';
    string element;

    while (option != 'e') {
        cout << "Options:\n";
        cout << "a. PUSH\n";
        cout << "b. POP\n";
        cout << "c. Display stack\n";
        cout << "d. Peek last element\n";
        cout << "e. Exit\n";
        cout << "Enter option: ";
        cin >> option;

        switch (option) {
            case 'a':
                cout << "Enter element to PUSH: ";
                cin >> ws; // Skip whitespace
                getline(cin, element);
                push(myStack, element);
                break;

            case 'b':
                pop(myStack);
                break;

            case 'c':
                display(myStack);
                break;

            case'd':
                if (myStack->top == myStack->bottom - 1) {
                    cout << "Stack is empty.\n";
                } else {
                    cout << "Last element: " << myStack->data[myStack->top] << endl;
                }
                break;

            case 'e':
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid option. Please try again.\n";
                // Clear the input stream
                cin.clear();
                // Ignore remaining characters in the input line
                while (cin.get() != '\n')
                    continue;
                break;
        }

        cout << endl;
    }

    delete myStack;

    return 0;
}
