#include<bits/stdc++.h>
using namespace std;
// Emergency Hospital Treatment Management System using Stack and Queue
// Patient struct class
struct Patient {
int id;
string name;
};

stack<Patient> criticalStack; // Stack for critical patients
queue<Patient> nonCriticalQueue; // Queue for non-critical patients

// Add patient to appropriate data structure based on criticality
void addPatient(int id, string name, bool critical) {
    Patient p = {id, name};
    
    if(critical) {
        criticalStack.push(p);
        cout << "Critical patient " << name << " added!\n";
    } else {
        nonCriticalQueue.push(p);
        cout << "Non-critical patient " << name << " added!\n";
    }
}
// Treat patient based on criticality
void treatPatient(bool critical) {
    if(critical) {
        if(criticalStack.empty()) {
            cout << "No critical patients waiting!\n";
        } else {
            Patient p = criticalStack.top();
            criticalStack.pop();
            cout << "Treating critical patient: " << p.name << "\n";
        }
    } else {
        if(nonCriticalQueue.empty()) {
            cout << "No non-critical patients waiting!\n";
        } else {
            Patient p = nonCriticalQueue.front();
            nonCriticalQueue.pop();
            cout << "Treating non-critical patient: " << p.name << "\n";
        }
    }
}
// Display all waiting patients
void displayPatients() {
    cout << "\n--- Current Waiting Patients ---\n";
// Display critical patients (stack)
    if(criticalStack.empty()) {
        cout << "No critical patients.\n";
    } else {
        cout << "Critical patients (LIFO order):\n";
        stack<Patient> temp = criticalStack;
        while(!temp.empty()) {
            cout << "ID=" << temp.top().id << ", Name=" << temp.top().name << "\n";
            temp.pop();
        }
    }
// Display non-critical patients (queue)
    if(nonCriticalQueue.empty()) {
        cout << "No non-critical patients.\n";
    } else {
        cout << "Non-critical patients (FIFO order):\n";
        queue<Patient> temp = nonCriticalQueue;
        while(!temp.empty()) {
            cout << "ID=" << temp.front().id << ", Name=" << temp.front().name << "\n";
            temp.pop();
        }
    }
}
void showMenu() {
    cout << "\n--- Emergency Room Menu ---\n";
    cout << "1. Add Patient\n";
    cout << "2. Treat Critical Patient\n";
    cout << "3. Treat Non-Critical Patient\n";
    cout << "4. Display Patients\n";
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
            cout << "Enter Patient ID (int): ";
            cin >> id;
            cout << "Enter Patient Name: ";
            cin >> name;
            cout << "Critical(1) or Non-Critical(0): ";
            cin >> type;
            addPatient(id, name, type==1);
            break;
        }
        case 2:
        treatPatient(true);
        break;
        case 3:
        treatPatient(false);
        break;
        case 4:
        displayPatients();
        break;
        case 5:
        cout << "Exiting program...\n";
        return 0;
        default:
        cout << "Invalid choice!\n";
        }
    }
}
