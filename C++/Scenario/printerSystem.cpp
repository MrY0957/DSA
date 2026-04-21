#include <bits/stdc++.h>
using namespace std;
//  printer job management system

struct PrintJob {
    int id;
    string fileName;
};

stack<PrintJob> urgentStack;     // Urgent jobs (LIFO)
queue<PrintJob> normalQueue;     // Normal jobs (FIFO)

void addJob(int id, string fileName, bool urgent) {
    PrintJob job = {id, fileName};
    if(urgent) {
        urgentStack.push(job);
        cout << "Urgent job " << fileName << " added!\n";
    } else {
        normalQueue.push(job);
        cout << "Normal job " << fileName << " added!\n";
    }
}

void processJob(bool urgent) {
    if(urgent) {
        if(urgentStack.empty()) cout << "No urgent jobs!\n";
        else {
            PrintJob job = urgentStack.top();
            urgentStack.pop();
            cout << "Processing urgent job: " << job.fileName << "\n";
        }
    } else {
        if(normalQueue.empty()) cout << "No normal jobs!\n";
        else {
            PrintJob job = normalQueue.front();
            normalQueue.pop();
            cout << "Processing normal job: " << job.fileName << "\n";
        }
    }
}

void displayJobs() {
    cout << "\n--- Current Print Jobs ---\n";
    if(urgentStack.empty()) cout << "No urgent jobs.\n";
    else {
        cout << "Urgent jobs (LIFO):\n";
        stack<PrintJob> temp = urgentStack;
        while(!temp.empty()) {
            cout << "ID=" << temp.top().id << ", File=" << temp.top().fileName << "\n";
            temp.pop();
        }
    }
    if(normalQueue.empty()) cout << "No normal jobs.\n";
    else {
        cout << "Normal jobs (FIFO):\n";
        queue<PrintJob> temp = normalQueue;
        while(!temp.empty()) {
            cout << "ID=" << temp.front().id << ", File=" << temp.front().fileName << "\n";
            temp.pop();
        }
    }
}

void showMenu() {
    cout << "\n--- Printer Job Menu ---\n";
    cout << "1. Add Print Job\n";
    cout << "2. Process Urgent Job\n";
    cout << "3. Process Normal Job\n";
    cout << "4. Display Jobs\n";
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
                int id; string file; int type;
                cout << "Enter Job ID: "; cin >> id;
                cout << "Enter File Name: "; cin >> file;
                cout << "Urgent(1) or Normal(0): "; cin >> type;
                addJob(id, file, type==1);
                break;
            }
            case 2: processJob(true); break;
            case 3: processJob(false); break;
            case 4: displayJobs(); break;
            case 5: cout << "Exiting...\n"; return 0;
            default: cout << "Invalid choice!\n";
        }
    }
}
