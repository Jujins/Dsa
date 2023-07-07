#include <iostream>
#define MAX_SIZE 5
using namespace std;

class Queue {
private:
    int myQueue[MAX_SIZE], front, rear;
public:
    Queue () {
        front = -1;
        rear = -1;
    }

    void qinsert(int item) {
        if (rear == MAX_SIZE-1) {
            cout<<"\nQUEUE OVERFLOW (" << item <<  ")";
        }
        else if (front==-1 && rear==-1) {
            front=rear=0;
            myQueue[rear]=item;
            cout<<"\nITEM INSERTED: "<<item;
        } else {
            rear++;
            myQueue[rear]=item;
            cout<<"\nITEM INSERTED: "<<item;
        }
    }

    void qdelete(){
        int item;
        if(rear==-1){
            cout<<"\nQUEUE UNDERFLOW";
        }
        else if(front==0 && rear==0){
            item = myQueue[front];
            front=rear=-1;
            cout<<"\n\nITEM DELETED: "<<item;
        } else {
            item=myQueue[front];
            front++;
            cout<<"\n\nITEM DELETED: "<<item;
        }
    }

    void qtraverse() {
        if(front==-1) {
            cout<<"\n\nQUEUE IS EMPTY\n";
        } else {
            cout<<"\n\nQUEUE ITEMS\n";
            for (int i=front;i<=rear;i++) {
            cout<< myQueue[i] <<" ";
        }
        cout<<endl;
        }
    }
};

int main () {
    Queue myq;

    myq.qdelete();
    myq.qtraverse();

    cout << "Queue created: " << endl;
    myq.qinsert(1);
    myq.qinsert(3);
    myq.qinsert(5);
    myq.qinsert(7);
    myq.qinsert(9);
    myq.qinsert(99);

    myq.qtraverse();

    myq.qdelete();

    myq.qtraverse();
    return 0;
}