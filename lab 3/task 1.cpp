#include <iostream>
#include <string>
using namespace std;

class node {
public:
    string item;
    int price;
    node* next;

    node(string name, int value) {
        item = name;
        price = value;
        next = NULL;
    }
};

class list {
    node* head;
    node* tail;

public:
    list() {
        head = tail = NULL;
    }

    
    void addfront(string name, int price) {
        node* newnode = new node(name, price);
        if (head == NULL) {
            head = tail = newnode;
        } else {
            newnode->next = head;
            head = newnode;
        }
    }

   
    void addback(string name, int price) {
        node* newnode = new node(name, price);
        if (tail == NULL) {
            head = tail = newnode;
        } else {
            tail->next = newnode;
            tail = newnode;
        }
    }

    
    void insertbyvalue(string name, int price, string oldname) {
        node* temp = head;
        while (temp != NULL && temp->item != oldname) {
            temp = temp->next;
        }
        if (temp == NULL) {
            cout << "Item " << oldname << " not found!" << endl;
            return;
        }
        node* newnode = new node(name, price);
        newnode->next = temp->next;
        temp->next = newnode;
        if (temp == tail) tail = newnode;
    }

    
    void search(string name) {
        node* temp = head;
        while (temp != NULL) {
            if (temp->item == name) {
                cout << name << " found, Price = $" << temp->price << endl;
                return;
            }
            temp = temp->next;
        }
        cout << name << " not found in cart." << endl;
    }

   
    void display() {
        node* temp = head;
        cout << "\nShopping Cart Items:\n";
        while (temp != NULL) {
            cout << temp->item << " - $" << temp->price << endl;
            temp = temp->next;
        }
    }
};

int main() {
    list cart;

    
    cart.addback("Laptop", 1000);
    cart.addback("Phone", 700);
    cart.addback("Tablet", 400);
    cart.addback("Headphones", 150);
    cart.display(); 
   
    cart.addfront("Smartwatch", 200);             
    cart.addback("Keyboard", 80);                  
    cart.insertbyvalue("Monitor", 300, "Phone");   
    cart.search("Tablet");                         
    cart.display();                                

    return 0;
}
