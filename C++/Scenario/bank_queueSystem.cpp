#include <bits/stdc++.h>
using namespace std;
//  bank queue system
// Customer struct class
struct Customer {
    int id;
    string name;
};

stack<Customer> priorityStack;      // Priority customers (VIP)
queue<Customer> normalQueue;        // Normal customers
// Add customer to appropriate data structure based on priority
void addCustomer(int id, string name, bool priority) {
    Customer c = {id, name};
    if(priority) {
        priorityStack.push(c);
        cout << "Priority customer " << name << " added!\n";
    } else {
        normalQueue.push(c);
        cout << "Normal customer " << name << " added!\n";
    }
}
// Serve customer based on priority
void serveCustomer(bool priority) {
    if(priority) {
        if(priorityStack.empty()) cout << "No priority customers!\n";
        else {
            Customer c = priorityStack.top();
            priorityStack.pop();
            cout << "Serving priority customer: " << c.name << "\n";
        }
    } else {
        if(normalQueue.empty()) cout << "No normal customers!\n";
        else {
            Customer c = normalQueue.front();
            normalQueue.pop();
            cout << "Serving normal customer: " << c.name << "\n";
        }
    }
}
// Display all waiting customers
void displayCustomers() {
    cout << "\n--- Current Waiting Customers ---\n";
    if(priorityStack.empty()) cout << "No priority customers.\n";
    else {
        cout << "Priority customers (LIFO):\n";
        stack<Customer> temp = priorityStack;
        while(!temp.empty()) {
            cout << "ID=" << temp.top().id << ", Name=" << temp.top().name << "\n";
            temp.pop();
        }
    }
    if(normalQueue.empty()) cout << "No normal customers.\n";
    else {
        cout << "Normal customers (FIFO):\n";
        queue<Customer> temp = normalQueue;
        while(!temp.empty()) {
            cout << "ID=" << temp.front().id << ", Name=" << temp.front().name << "\n";
            temp.pop();
        }
    }
}
// Simulation: Serve all priority customers first, then normal customers
void showMenu() {
    cout << "\n--- Bank Queue Menu ---\n";
    cout << "1. Add Customer\n";
    cout << "2. Serve Priority Customer\n";
    cout << "3. Serve Normal Customer\n";
    cout << "4. Display Customers\n";
    cout << "5. Exit\n";
    cout << "Enter choice: ";
}

int main() {
    int choice;
    while(true) {
        showMenu();
        cin >> choice;
        switch(choice) {
            case 1: {
                int id; string name; int type;
                cout << "Enter Customer ID: "; 
                cin >> id;
                cout << "Enter Customer Name: "; 
                cin >> name;
                cout << "Priority(1) or Normal(0): "; 
                cin >> type;
                addCustomer(id, name, type==1);
                break;
            }
            case 2: serveCustomer(true); break;
            case 3: serveCustomer(false); break;
            case 4: displayCustomers(); break;
            case 5: cout << "Exiting...\n"; return 0;
            default: cout << "Invalid choice!\n";
        }
    }
}
