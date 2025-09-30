# Aim: Queue Implementation.

# Tool: VS CODE.

# Theory :

A queue is a linear data structure that follows the FIFO (First In, First Out) principle, meaning the element added first is removed first. It is widely used in real-world applications like printer task scheduling, CPU task scheduling, and customer service systems.

Key Operations of a Queue

Enqueue – Add an element to the rear of the queue.

Dequeue – Remove an element from the front of the queue.

isEmpty – Check if the queue is empty.

isFull – Check if the queue is full (in case of a fixed-size array).

Front/Rear – Retrieve the front or rear element without removing it.

Queue Implementation Using Array in C++

We can implement a queue using a fixed-size array with two pointers:

front – points to the first element.

rear – points to the last element.

C++ Code Example: 

#include <iostream>
using namespace std;

#define SIZE 5  // Maximum size of the queue

class Queue {
    int arr[SIZE]; // Array to store queue elements
    int front, rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    // Function to add an element to the queue
    void enqueue(int value) {
        if (rear == SIZE - 1) {
            cout << "Queue Overflow!" << endl;
            return;
        }
        if (front == -1) front = 0; // If first element
        rear++;
        arr[rear] = value;
        cout << value << " added to the queue." << endl;
    }

    // Function to remove an element from the queue
    void dequeue() {
        if (front == -1 || front > rear) {
            cout << "Queue Underflow! No element to delete." << endl;
            return;
        }
        cout << arr[front] << " removed from the queue." << endl;
        front++;
    }

    // Function to display the queue
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

    q.dequeue();
    q.dequeue();
    q.dequeue(); // Attempt to remove from empty queue

    return 0;
}

How It Works

Enqueue – Adds elements at the rear. If the rear reaches SIZE-1, the queue is full (overflow).

Dequeue – Removes elements from the front. If front > rear, the queue is empty (underflow).

The display function shows all elements from front to rear.

# Algorithm:

Algorithm for Queue Implementation Using Array

1. Initialize Queue

Create an array arr[SIZE] to store elements.

Initialize two pointers:

front = -1 (points to the front element)

rear = -1 (points to the last element)

2. Enqueue Operation (Insert Element)

Check if the queue is full:

If rear == SIZE - 1, Queue Overflow, stop.

If the queue is empty (front == -1), set front = 0.

Increment rear by 1.

Insert the new element at arr[rear].

Display confirmation message.

3. Dequeue Operation (Remove Element)

Check if the queue is empty:

If front == -1 or front > rear, Queue Underflow, stop.

Remove the element at arr[front] and display it.

Increment front by 1.

If front > rear (queue becomes empty after deletion), reset front = rear = -1.

4. Display Operation

Check if the queue is empty (front == -1 or front > rear).

If yes, display "Queue is empty".

Otherwise, traverse the array from front to rear and print elements.

5. Main Program

Create an object of the Queue class.

Perform operations: enqueue(), dequeue(), display().

Operations can be repeated as needed.

# Conclusion:

Queue is a FIFO data structure useful for scheduling and buffering tasks.

Overflow and underflow conditions must be handled to avoid runtime errors.

Implementation can be done using arrays or linked lists.

Using arrays is simple but fixed in size; linked lists allow dynamic size without overflow issues.
