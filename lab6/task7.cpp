#include <iostream>
#include <string>
using namespace std;

const int MAX = 10;

class LibraryQueue {
private:
    string queue[MAX];  
    int front, rear;    

public:
    LibraryQueue() {
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return (front == -1 || front > rear);
    }

    bool isFull() {
        return (rear == MAX - 1);
    }

    void enqueue(string name) {
        if (isFull()) {
            cout << "Queue is full! No more patrons can be added.\n";
            return;
        }
        if (front == -1) front = 0;  
        rear++;
        queue[rear] = name;
        cout << name << " has joined the queue.\n";
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty! No patrons to remove.\n";
            return;
        }
        cout << queue[front] << "'s transaction is completed and they have left the queue.\n";
        front++;

        if (front > rear) {
            front = rear = -1;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "No patrons are currently waiting.\n";
            return;
        }
        cout << "\nCurrent Queue of Patrons:\n";
        for (int i = front; i <= rear; i++) {
            cout << i - front + 1 << ". " << queue[i] << endl;
        }
    }
};

int main() {
    LibraryQueue lq;
    int choice;
    string name;

    cout << "=== Library Book Transaction Simulation ===\n";

    while (true) {
        cout << "\n1. Patron Arrives (Add to Queue)"
             << "\n2. Complete Transaction (Remove from Queue)"
             << "\n3. Show Current Queue"
             << "\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter patron name: ";
            cin >> name;
            lq.enqueue(name);
            break;
        case 2:
            lq.dequeue();
            break;
        case 3:
            lq.display();
            break;
        case 4:
            cout << "Exiting simulation. Goodbye!\n";
            return 0;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
