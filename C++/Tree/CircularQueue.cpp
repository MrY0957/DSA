#include <iostream>
using namespace std;

#define SIZE 5
int queuearr[SIZE];
int front = -1, rear = -1;

bool isFull() {
    return (front == (rear+1)%SIZE);
}

bool isEmpty() {
    return (front == -1);
}

void enqueue(int data) {
    if(isFull()) {
        cout << "Queue Overflow\n";
    } else if(isEmpty()) {
        front = rear = 0;
        queuearr[rear] = data;
    } else {
        rear = (rear+1)%SIZE;
        queuearr[rear] = data;
    }
    cout << "Enqueued " << data << endl;
}

void dequeue() {
    if(isEmpty()) {
        cout << "Queue Underflow\n";
    } else if(front == rear) {
        cout << "Deleted value " << queuearr[front] << endl;
        front = rear = -1;
    } else {
        cout << "Deleted value " << queuearr[front] << endl;
        front = (front+1)%SIZE;
    }
}

void peek() {
    if(isEmpty()) {
        cout << "Queue is empty\n";
    } else {
        cout << "Front value = " << queuearr[front] << endl;
    }
}

void display() {
    if(isEmpty()) {
        cout << "Queue is empty\n";
    } else {
        cout << "Queue elements: ";
        int i = front;
        while(true) {
            cout << queuearr[i] << " ";
            if(i == rear) break;
            i = (i+1)%SIZE;
        }
        cout << endl;
    }
}

int main() {
    int choice, value;
    while(true) {
        cout << "\nChoose option:\n";
        cout << "1.Enqueue\n";
        cout << "2.Dequeue\n";
        cout << "3.Peek\n";
        cout << "4.Display\n";
        cout << "5.Exit\n";
        cout << "Enter your Choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                cout << "Exiting program...\n";
                return 0;
            default:
                cout << "Invalid choice!\n";
        }
    }
}
