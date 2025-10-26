#include <iostream>
#include <string>
using namespace std;

struct Call {
    string name;
    string number;
    int duration; 
};

class CallHistory {
private:
    static const int MAX = 100; 
    Call stack[MAX];
    int topIndex;

public:
    CallHistory() {
        topIndex = -1;
    }

    bool empty() {
        return topIndex == -1;
    }

    bool full() {
        return topIndex == MAX - 1;
    }

    void push(Call c) {
        if (full()) {
            cout << "Call history is full! Cannot add more records.\n";
            return;
        }
        stack[++topIndex] = c;
        cout << "\n New call added successfully.\n";
        display();
    }

    void pop() {
        if (empty()) {
            cout << "No calls to delete. History is empty.\n";
            return;
        }
        cout << "\n Removing call: " << stack[topIndex].name << " (" << stack[topIndex].number << ")\n";
        topIndex--;
        display();
    }

    void top() {
        if (empty()) {
            cout << "No recent calls.\n";
            return;
        }
        cout << "\n Most recent call:\n";
        cout << "Name: " << stack[topIndex].name << endl;
        cout << "Number: " << stack[topIndex].number << endl;
        cout << "Duration: " << stack[topIndex].duration << " minutes\n";
    }

    void display() {
        if (empty()) {
            cout << "Call history is empty.\n";
            return;
        }
        cout << " Current Call Log:\n";
        for (int i = topIndex; i >= 0; i--) {
            cout << i + 1 << ". " << stack[i].name << " | " 
                 << stack[i].number << " | " 
                 << stack[i].duration << " min\n";
        }
    }
};

int main() {
    CallHistory history;
    int choice;
    do {
        cout << "\n==== MOBILE CALL HISTORY SYSTEM ====\n";
        cout << "1. Add New Call (Push)\n";
        cout << "2. Remove Recent Call (Pop)\n";
        cout << "3. View Most Recent Call (Top)\n";
        cout << "4. Check if Call History is Empty\n";
        cout << "5. Display Call History\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            Call c;
            cout << "Enter Name: ";
            cin.ignore();
            getline(cin, c.name);
            cout << "Enter Number: ";
            getline(cin, c.number);
            cout << "Enter Duration (in minutes): ";
            cin >> c.duration;
            history.push(c);
            break;
        }
        case 2:
            history.pop();
            break;
        case 3:
            history.top();
            break;
        case 4:
            if (history.empty())
                cout << "\n?? Call history is empty.\n";
            else
                cout << "\n?? Call history has records.\n";
            break;
        case 5:
            history.display();
            break;
        case 0:
            cout << "\nExiting program...\n";
            break;
        default:
            cout << "Invalid choice! Please try again.\n";
        }

    } while (choice != 0);

    return 0;
}
