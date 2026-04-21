#include <bits/stdc++.h>
using namespace std;
#define MAX 10
// Task library system 
// Book structure
struct Book {
    int id;
    string name;
};

// Stack for returned books
Book stackArr[MAX];
int top = -1;

// Queue for students waiting for books
Book queueArr[MAX];
int front = -1, rear = -1;

// Stack Operations
void push(Book b) {
    if(top == MAX-1) {
        cout << "Stack Overflow!\n";
    } else {
        stackArr[++top] = b;
        cout << "Book '" << b.name << "' pushed into Stack (Returned)\n";
    }
}

Book pop() {
    if(top == -1) {
        cout << "Stack Underflow!\n";
        return {-1,""};
    } else {
        Book b = stackArr[top--];
        cout << "Book '" << b.name << "' popped from Stack\n";
        return b;
    }
}

// Queue Operations
void enqueue(Book b) {
    if(rear == MAX-1) {
        cout << "Queue Overflow!\n";
    } else {
        if(front == -1) front = 0;
        queueArr[++rear] = b;
        cout << "Book '" << b.name << "' enqueued into Queue (Student Request)\n";
    }
}

Book dequeue() {
    if(front == -1 || front > rear) {
        cout << "Queue Underflow!\n";
        return {-1,""};
    } else {
        Book b = queueArr[front++];
        cout << "Book '" << b.name << "' dequeued from Queue (Issued)\n";
        return b;
    }
}

// Display Stack
void displayStack() {
    if(top == -1) {
        cout << "Stack Empty!\n";
    } else {
        cout << "Books in Stack (Returned):\n";
        for(int i=0; i<=top; i++) cout << "ID=" << stackArr[i].id << ", Name=" << stackArr[i].name << "\n";
    }
}

// Display Queue
void displayQueue() {
    if(front == -1 || front > rear) {
        cout << "Queue Empty!\n";
    } else {
        cout << "Books in Queue (Waiting Students):\n";
        for(int i=front; i<=rear; i++) cout << "ID=" << queueArr[i].id << ", Name=" << queueArr[i].name << "\n";
    }
}

// Simulation: Pop from stack → Enqueue to queue → Dequeue for issue
void simulate() {
    cout << "\n--- Simulation Start ---\n";
    while(top != -1) {
        Book b = pop();
        enqueue(b);
    }
    while(front != -1 && front <= rear) {
        dequeue();
    }
    cout << "--- Simulation End ---\n";
}

void showMenu(){
    cout << "\n--- Library Menu ---\n";
    cout << "1. Push Returned Book (Stack)\n";
    cout << "2. Pop Book from Stack\n";
    cout << "3. Enqueue Student Request (Queue)\n";
    cout << "4. Dequeue Book (Issue)\n";
    cout << "5. Display Stack\n";
    cout << "6. Display Queue\n";
    cout << "7. Run Simulation (Stack → Queue → Issue)\n";
    cout << "8. Exit\n";
    cout << "Enter choice: ";
}

int main() {
    int choice;
    while(true) {
        showMenu();
        cin >> choice;
        switch(choice) {
            case 1: {
                Book b;
                cout << "Enter Book ID: "; cin >> b.id;
                cout << "Enter Book Name: "; cin >> b.name;
                push(b);
                break;
            }
            case 2: pop(); break;
            case 3: {
                Book b;
                cout << "Enter Book ID: "; cin >> b.id;
                cout << "Enter Book Name: "; cin >> b.name;
                enqueue(b);
                break;
            }
            case 4: dequeue(); break;
            case 5: displayStack(); break;
            case 6: displayQueue(); break;
            case 7: simulate(); break;
            case 8: cout << "Exiting program...\n"; return 0;
            default: cout << "Invalid choice!\n";
        }
    }
}
