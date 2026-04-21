#include <bits/stdc++.h>
using namespace std;
#define MAX 10
// Simulation of a warehouse system using Stack and Queue
// Stack
int stackArr[MAX];
int top = -1;

// Queue
int queueArr[MAX];
int front = -1, rear = -1;

// Stack Operations-LIFO
void push(int item) {
    if(top == MAX-1) {
        cout << "Stack Overflow!\n";
    } else {
        stackArr[++top] = item;
        cout << "Pushed " << item << " into Stack\n";
    }
}

int pop() {
    if(top == -1) {
        cout << "Stack Underflow!\n";
        return -1;
    } else {
        int item = stackArr[top--];
        cout << "Popped " << item << " from Stack\n";
        return item;
    }
}

// Queue Operations-FIFO
void enqueue(int item) {
    if(rear == MAX-1) {
        cout << "Queue Overflow!\n";
    } else {
        if(front == -1) front = 0;
        queueArr[++rear] = item;
        cout << "Enqueued " << item << " into Queue\n";
    }
}

int dequeue() {
    if(front == -1 || front > rear) {
        cout << "Queue Underflow!\n";
        return -1;
    } else {
        int item = queueArr[front++];
        cout << "Dequeued " << item << " from Queue\n";
        return item;
    }
}

// Display Stack
void displayStack() {
    if(top == -1) {
        cout << "Stack Empty!\n";
    } else {
        cout << "Stack items: ";
        for(int i=0; i<=top; i++) cout << stackArr[i] << " ";
        cout << endl;
    }
}

// Display Queue
void displayQueue() {
    if(front == -1 || front > rear) {
        cout << "Queue Empty!\n";
    } else {
        cout << "Queue items: ";
        for(int i=front; i<=rear; i++) cout << queueArr[i] << " ";
        cout << endl;
    }
}

// Simulation: Pop from stack → Enqueue to queue → Dequeue for shipping
void simulate() {
    cout << "\n--- Simulation Start ---\n";
    // Step 1: Pop all items from stack and enqueue into queue
    while(top != -1) { 
        int item = pop();
        enqueue(item);
    }
    // Step 2: Dequeue all items from queue (shipping)
    while(front != -1 && front <= rear) {
        dequeue();
    }
    cout << "--- Simulation End ---\n";
}

void showMenu(){
    cout << "\n--- Warehouse Menu ---\n";
    cout << "1. Push to Stack (Store Item Code)\n";
    cout << "2. Pop from Stack (Remove Item Code)\n";
    cout << "3. Enqueue to Queue (Add to Shipping)\n";
    cout << "4. Dequeue from Queue (Ship Item Code)\n";
    cout << "5. Display Stack\n";
    cout << "6. Display Queue\n";
    cout << "7. Run Simulation (Stack → Queue → Shipping)\n";
    cout << "8. Exit\n";
          cout << "Enter choice: ";
}
int main() {
    int choice, itemCode;
    while(true) {
        showMenu();
  
        cin >> choice;
        switch(choice) {
            case 1:
                cout << "Enter item Code (int): ";
                cin >> itemCode;
                push(itemCode);
                break;
            case 2:
                pop();
                break;
            case 3:
                cout << "Enter item Code (int): ";
                cin >> itemCode;
                enqueue(itemCode);
                break;
            case 4:
                dequeue();
                break;
            case 5:
                displayStack();
                break;
            case 6:
                displayQueue();
                break;
            case 7:
                simulate();
                break;
            case 8:
                cout << "Exiting program...\n";
                return 0;
            default:
                cout << "Invalid choice!\n";
        }
    }
}
