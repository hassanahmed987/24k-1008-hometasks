#include <iostream>
#include <string>
using namespace std;

class node {
public:
    int id;
    string name;
    int price;
    node* next;
    node* prev;

    node(int i, string na, int pri) {
        id = i;
        name = na;
        price = pri;
        next = prev = nullptr;
    }
};

class doubly {
public:
    node* head;
    node* tail;

    doubly() {
        head = tail = nullptr;
    }

    void addend(int id, string name, int price) {
        node* newnode = new node(id, name, price);
        if (head == nullptr) {
            head = tail = newnode;
        } else {
            tail->next = newnode;
            newnode->prev = tail;
            tail = newnode;
        }
    }

    void addfront(int id, string name, int price) {
        node* newnode = new node(id, name, price);
        if (head == nullptr) {
            head = tail = newnode;
        } else {
            newnode->next = head;
            head->prev = newnode;
            head = newnode;
        }
    }

    void removefirst() {
        if (head == nullptr) {
            cout << "List empty" << endl;
            return;
        }
        if (head == tail) { 
            delete head;
            head = tail = nullptr;
        } else {
            node* temp = head;
            head = head->next;
            head->prev = nullptr;
            delete temp;
        }
    }

    void removelast() {
        if (head == nullptr) {
            cout << "List empty" << endl;
            return;
        }
        if (head == tail) { 
            delete tail;
            head = tail = nullptr;
        } else {
            node* temp = tail;
            tail = temp->prev;
            tail->next = nullptr;
            delete temp;
        }
    }

    void searchitem(int id) {
        node* temp = head;
        bool found = false;
        while (temp != nullptr) {
            if (temp->id == id) {
                cout << "Item found: ID " << temp->id
                     << ", Name " << temp->name
                     << ", Price " << temp->price << endl;
                found = true;
                break;
            }
            temp = temp->next;
        }
        if (!found) cout << "Item not found" << endl;
    }

    void updateprice(int id, int newprice) {
        node* temp = head;
        bool found = false;
        while (temp != nullptr) {
            if (temp->id == id) {
                temp->price = newprice;
                cout << "Updated price: " << temp->price
                     << " for item " << temp->name << endl;
                found = true;
                break;
            }
            temp = temp->next;
        }
        if (!found) cout << "Item not found" << endl;
    }

    void display() {
        node* temp = head;
        while (temp != nullptr) {
            cout << "ID: " << temp->id
                 << " Name: " << temp->name
                 << " Price: " << temp->price << endl;
            temp = temp->next;
        }
    }

    void reversedisplay() {
        node* temp = tail;
        while (temp != nullptr) {
            cout << "ID: " << temp->id
                 << " Name: " << temp->name
                 << " Price: " << temp->price << endl;
            temp = temp->prev;
        }
    }

    int count() {
        int cnt = 0;
        node* temp = head;
        while (temp != nullptr) {
            cnt++;
            temp = temp->next;
        }
        return cnt;
    }

    void searchexpensive() {
        if (head == nullptr) {
            cout << "List empty" << endl;
            return;
        }
        node* temp = head;
        node* expensiveItem = head;
        while (temp != nullptr) {
            if (temp->price > expensiveItem->price) {
                expensiveItem = temp;
            }
            temp = temp->next;
        }
        cout << "Most expensive item: " << expensiveItem->name
             << " Price: " << expensiveItem->price << endl;
    }
};

int main() {
    doubly cart;

    cart.addend(1, "Laptop", 80000);
    cart.addend(2, "Phone", 50000);
    cart.addfront(3, "Charger", 2000);

    cout << "\nCart (Front to End):\n";
    cart.display();

    cout << "\nCart (End to Front):\n";
    cart.reversedisplay();

    cout << "\nSearching for ID 2:\n";
    cart.searchitem(2);

    // Update price
    cout << "\nUpdating price of ID 1:\n";
    cart.updateprice(1, 75000);

    cout << "\nCart after update:\n";
    cart.display();

    cout << "\nRemoving first item...\n";
    cart.removefirst();
    cart.display();

    cout << "\nRemoving last item...\n";
    cart.removelast();
    cart.display();

    cout << "\nTotal items in cart: " << cart.count() << endl;

    cout << "\nFinding most expensive item:\n";
    cart.searchexpensive();

    return 0;
}
