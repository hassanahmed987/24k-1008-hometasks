#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    int ticketID;
    string customerName;
    string rideName;
    Node* next;

    Node(int id, string cname, string rname) {
        ticketID = id;
        customerName = cname;
        rideName = rname;
        next = NULL;
    }
};

class CircularList {
private:
    Node* head;
    Node* tail;
    int countTickets;

public:
    CircularList() {
        head = tail = NULL;
        countTickets = 0;
    }

    void issueTicketEnd(int id, string cname, string rname) {
        Node* newNode = new Node(id, cname, rname);
        if (head == NULL) {
            head = tail = newNode;
            tail->next = head;
        } else {
            tail->next = newNode;
            tail = newNode;
            tail->next = head; 
        }
        countTickets++;
        cout << "Ticket issued at end for " << cname << endl;
    }

    void issueTicketFront(int id, string cname, string rname) {
        Node* newNode = new Node(id, cname, rname);
        if (head == NULL) {
            head = tail = newNode;
            tail->next = head;
        } else {
            newNode->next = head;
            head = newNode;
            tail->next = head; 
        }
        countTickets++;
        cout << "Priority Ticket issued at front for " << cname << endl;
    }

    void cancelTicketByID(int id) {
        if (head == NULL) {
            cout << "No tickets to cancel!" << endl;
            return;
        }
        Node* temp = head;
        Node* prev = tail;
        do {
            if (temp->ticketID == id) {
                if (temp == head && temp == tail) { 
                    head = tail = NULL;
                } else if (temp == head) {
                    head = head->next;
                    tail->next = head;
                } else if (temp == tail) {
                    tail = prev;
                    tail->next = head;
                } else {
                    prev->next = temp->next;
                }
                delete temp;
                countTickets--;
                cout << "Ticket ID " << id << " canceled." << endl;
                return;
            }
            prev = temp;
            temp = temp->next;
        } while (temp != head);

        cout << "Ticket ID " << id << " not found." << endl;
    }

    void cancelFirstTicket() {
        if (head == NULL) {
            cout << "No tickets to cancel!" << endl;
            return;
        }
        cancelTicketByID(head->ticketID);
    }

    void searchTicket(int id) {
        if (head == NULL) {
            cout << "No tickets booked." << endl;
            return;
        }
        Node* temp = head;
        do {
            if (temp->ticketID == id) {
                cout << "Ticket Found -> ID: " << temp->ticketID
                     << ", Customer: " << temp->customerName
                     << ", Ride: " << temp->rideName << endl;
                return;
            }
            temp = temp->next;
        } while (temp != head);

        cout << "Ticket ID " << id << " not found." << endl;
    }

    void displayTickets() {
        if (head == NULL) {
            cout << "No tickets booked." << endl;
            return;
        }
        Node* temp = head;
        cout << "Tickets in Circular Order:" << endl;
        do {
            cout << "[ID: " << temp->ticketID
                 << ", Name: " << temp->customerName
                 << ", Ride: " << temp->rideName << "]" << endl;
            temp = temp->next;
        } while (temp != head);
    }

    void countTotalTickets() {
        cout << "Total tickets booked: " << countTickets << endl;
    }

    void findNextTicket(int id) {
        if (head == NULL) {
            cout << "No tickets booked." << endl;
            return;
        }
        Node* temp = head;
        do {
            if (temp->ticketID == id) {
                Node* nextTicket = temp->next;
                cout << "Next Ticket -> ID: " << nextTicket->ticketID
                     << ", Customer: " << nextTicket->customerName
                     << ", Ride: " << nextTicket->rideName << endl;
                return;
            }
            temp = temp->next;
        } while (temp != head);

        cout << "Ticket ID " << id << " not found." << endl;
    }
};

int main() {
    CircularList booking;

    booking.issueTicketEnd(101, "Ali", "Roller Coaster");
    booking.issueTicketEnd(102, "Sara", "Ferris Wheel");
    booking.issueTicketFront(201, "VIP_Ahmed", "Haunted House");

    booking.displayTickets();
    booking.countTotalTickets();

    booking.searchTicket(102);
    booking.findNextTicket(102);

    booking.cancelTicketByID(201);
    booking.cancelFirstTicket();

    booking.displayTickets();
    booking.countTotalTickets();

    return 0;
}
