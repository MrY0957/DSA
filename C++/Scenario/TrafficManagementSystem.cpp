#include <bits/stdc++.h>
using namespace std;
#define SIZE 10
// Traffic Management System using Circular Queue
// Vehicle struct class
struct Vehicle {
    int id;
    float arrival;   // Arrival time as float
    int dir;         // 0=N,1=E,2=S,3=W
};
// Circular Queue for Vehicles
Vehicle vehicleQueue[SIZE];
int front = -1, rear = -1;

bool isFull() { 
    return (front == (rear+1)%SIZE);
}
bool isEmpty() { 
    return (front == -1); 
}
// Enqueue takes a Vehicle struct as input
void enqueue(Vehicle v) {
    if(isFull()) {
        cout << "Queue Overflow!\n";
        return;
    }
    if(front == -1) front = 0;
    rear = (rear+1)%SIZE; // Move rear to next position
    vehicleQueue[rear] = v; // Add vehicle to queue
    cout << "Vehicle " << v.id << " enqueued!\n";
}
// Dequeue returns the vehicle at front
Vehicle dequeue() {
    Vehicle v = vehicleQueue[front];
    if(front == rear) {
        front = rear = -1;
    } else {
        front = (front+1)%SIZE;
    }
    return v;
}
// Helper to get direction name
string getDirectionName(int d) {
    switch(d) {
        case 0: return "North";
        case 1: return "East";
        case 2: return "South";
        case 3: return "West";
        default: return "Unknown";
    }
}

void display() {
    if(isEmpty()) {
        cout << "Queue Empty!\n";
        return;
    }
    cout << "\nVehicles in Queue:\n";
    int i = front;
    while(true) {
        cout << "ID=" << vehicleQueue[i].id 
             << ", Arrival=" << fixed << setprecision(2) << vehicleQueue[i].arrival 
             << ", Direction=" << getDirectionName(vehicleQueue[i].dir) << "\n";
        if(i == rear) break;
        i = (i+1)%SIZE;
    }
}

void simulateTraffic() {
    if(isEmpty()) {
        cout << "No vehicles to process!\n";
        return;
    }
    int current_direction = 0; // Start from North
    cout << "\n--- Simulation Start ---\n";
    while(!isEmpty()) {
        Vehicle v = dequeue();
        if(v.dir == current_direction) {
            cout << "Vehicle " << v.id << " from " << getDirectionName(v.dir) << " passed at time " << v.arrival << "\n";
        } else {
            cout << "Vehicle " << v.id << " from " << getDirectionName(v.dir) << " waiting (not its turn)\n";
        }
        current_direction = (current_direction+1)%4;
    }
    cout << "--- Simulation End ---\n";
}

void showMenu() {
    cout << "\n--- Traffic Menu ---\n";
    cout << "1. Enqueue Vehicle\n";
    cout << "2. Dequeue Vehicle\n";
    cout << "3. Display Queue\n";
    cout << "4. Simulate Traffic\n";
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
                Vehicle v;
                cout << "Enter Vehicle ID (int): ";
                cin >> v.id;
                cout << "Enter Arrival Time (float, e.g. 10.30): ";
                cin >> v.arrival;
                cout << "Enter Direction (0=N,1=E,2=S,3=W): ";
                cin >> v.dir;
                enqueue(v);
                break;
            }
            case 2: {
                if(!isEmpty()) {
                    Vehicle v = dequeue();
                    cout << "Dequeued Vehicle " << v.id << "\n";
                } else {
                    cout << "Queue Empty!\n";
                }
                break;
            }
            case 3: display(); break;
            case 4: simulateTraffic(); break;
            case 5: cout << "Exiting program...\n"; return 0;
            default: cout << "Invalid choice!\n";
        }
    }
}
