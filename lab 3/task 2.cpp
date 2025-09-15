#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string itemName;
    float price;
    Node* next;

    Node(string name, float p) {
        itemName = name;
        price = p;
        next = nullptr;
    }
};

class ShoppingCart {
private:
    Node* head;
    Node* tail;

public:
    ShoppingCart() {
        head = nullptr;
        tail = nullptr;
    }

    
    void addItem(string name, float price) {
        Node* newNode = new Node(name, price);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        cout << name << " added to cart \n";
    }

    
    void deleteFront() {
        if (head == nullptr) {
            cout << "Cart is empty \n";
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head == nullptr) tail = nullptr; 
        delete temp;
    }

 
    void searchByName(string name) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->itemName == name) {
                cout << "Found: " << temp->itemName << " - Price: " << temp->price << endl;
                return;
            }
            temp = temp->next;
        }
        cout << name << " not found \n";
    }

    
    void searchByPosition(int pos) {
        Node* temp = head;
        int index = 1;
        while (temp != nullptr) {
            if (index == pos) {
                cout << "At position " << pos << ": " 
                     << temp->itemName << " - Price: " << temp->price << endl;
                return;
            }
            temp = temp->next;
            index++;
        }
        cout << "Invalid position \n";
    }

    void displayCart() {
        if (head == nullptr) {
            cout << "Cart is empty \n";
            return;
        }
        cout << "\n--- Shopping Cart ---\n";
        Node* temp = head;
        int index = 1;
        while (temp != nullptr) {
            cout << index++ << ". " << temp->itemName << " - $" << temp->price << endl;
            temp = temp->next;
        }
        cout << "---------------------\n";
    }
};

int main() {
    ShoppingCart cart;
    cart.addItem("Apple", 2.5);
    cart.addItem("Milk", 3.0);
    cart.addItem("Bread", 1.8);

    cart.displayCart();

    cart.searchByName("Milk");
    cart.searchByPosition(2);

    cart.deleteFront();
    cart.displayCart();

    return 0;
}
