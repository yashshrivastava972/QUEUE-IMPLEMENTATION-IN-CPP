// NAME: YASH SHRIVASTAVA
// PRN: 24070123137
// BATCH: E&TC-B2
// TITLE: ADD, DELETE THE MEMBERS IN THE QUEUE. CHECK THE QUEUE IS OVERFLOW OR EMPTY (EXPERIMENT: 18)

// CODE: 

#include<iostream>
using namespace std;

#define SIZE 5   // maximum size of the queue

class Queue {
    int arr[SIZE];   // array to hold elements
    int front, rear; // pointers for queue ends

public:   // make functions accessible
    Queue() {
        front = -1;
        rear = -1;
    }

    void enqueue(int value) {
        if (rear == SIZE - 1) {
            cout << "Queue Overflow!" << endl;
            return;
        }
        if (front == -1) front = 0; // first element inserted
        arr[++rear] = value;
        cout << value << " inserted into queue." << endl;
    }

    void dequeue() {
        if (front == -1 || front > rear) {
            cout << "Queue Underflow!" << endl;
            return;
        }
        cout << arr[front] << " removed from queue." << endl;
        front++;
        if (front > rear) { // reset when queue becomes empty
            front = rear = -1;
        }
    }

    void display() {
        if (front == -1 || front > rear) {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();

    q.dequeue();
    q.display();

    q.enqueue(40);
    q.display();

    q.dequeue();
    q.dequeue();
    q.dequeue(); // queue becomes empty
    q.display();

    q.enqueue(50); // works again after reset
    q.display();

    return 0;
}

// OUTPUT:

// 10 inserted into queue.
// 20 inserted into queue.
// 30 inserted into queue.
// Queue elements: 10 20 30 
// 10 removed from queue.
// Queue elements: 20 30 
// 40 inserted into queue.
// Queue elements: 20 30 40 
// 20 removed from queue.
// 30 removed from queue.
// 40 removed from queue.
// Queue is empty.
// 50 inserted into queue.
// Queue elements: 50 
