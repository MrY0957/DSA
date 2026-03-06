#include <iostream>
#define MAX 100
using namespace std; 
// Stack implementation using C++ array with switch case
class Stack {
    int* arr;
    int top;
    int capacity; // Maximum capacity of the stack
public:
    Stack(int size) {
        capacity = size;
        arr = new int[capacity];
        top = -1;
    }
    ~Stack() { 
        delete[] arr; 
    }  
    bool isFull() { 
        return top == capacity - 1; 
    } 
    bool isEmpty() { 
        return top == -1; 
    }

// Function to add an item to the stack. It increases top by 1
    void push(int data) {
        if (isFull()) 
        cout << "Stack Overflow\n";
        else { arr[++top] = data; 
            cout << data << " pushed\n"; 
        } 
    }
// Function to remove an item from stack. It decreases top by 1
    int pop() {
        if (isEmpty()) { 
            cout << "Stack Underflow\n"; 
            return -1; 
        }// If stack is empty, print an error message and return -1
        cout << arr[top] << " popped\n";
        return arr[top--];
    }
// Function to return the top from stack without removing it
    int peek() {
        if (isEmpty()) { 
            cout << "Stack is empty\n"; 
            return -1; 
        }
        cout << "Top element: " << arr[top] << endl;// Otherwise, return the top item
        return arr[top];
    }
// Function to return the number of elements in the stack
    void display() {
        if (isEmpty()) 
        cout << "Stack is empty\n";
            cout << "Stack elements: ";
            for (int i = 0; i <= top; i++) 
            cout << arr[i] << " ";
            cout << endl;
        }
    }
};

int main() {
    // Get stack size from user
    int size;
    cout << "Enter stack size: ";
    cin >> size;
    Stack s(size); 
    int choice, value, newMax;
    do {
        cout << "\n--- Stack Menu (C++ Array) ---\n";
        cout << "1. Push\n2. Pop\n3. Peek\n4. Display\n5. Check Empty\n6. Check Full\n7. Enter max elements\n8. Count Elements\n0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: cout << "Enter value: "; 
                    cin >> value; 
                    s.push(value); 
                    break;
            case 2: s.pop(); 
                    break;
            case 3: s.peek(); 
                    break;
            case 4: s.display(); 
                    break;
            case 5: cout << (s.isEmpty() ? "Empty\n" : "Not Empty\n"); 
                    break;
            case 6: cout << (s.isFull() ? "Full\n" : "Not Full\n"); 
                    break;
            case 7: { // Allow user to set a new max elements value, but it cannot exceed the defined MAX
                int newMax;
                cout << "Enter new max elements: ";
                cin >> newMax;
                if (newMax > MAX) 
                cout << "New max exceeds limit of " << MAX << endl;
                else cout << "Max elements set to " << newMax << endl;
                break;
            }
            case 8: cout << "Current element count: " << (s.isEmpty() ? 0 : s.peek() + 1) << endl; 
                    break;
            case 0: cout << "Exiting...\n"; 
                    break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 0);
    return 0;
}
