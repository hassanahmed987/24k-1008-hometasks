#include <iostream>
#include <string>
using namespace std;

struct Order {
    int orderID;
    string itemName;
    int quantity;
};

class OrderQueue {
private:
    Order arr[100];
    int front, rear, size;
public:
    OrderQueue() {
        front = 0;
        rear = -1;
        size = 0;
    }

    bool isEmpty() { return size == 0; }
    bool isFull() { return size == 100; }

    void enqueue(Order order) {
        if (isFull()) {
            cout << "Queue Overflow! Cannot take more orders.\n";
            return;
        }
        rear = (rear + 1) % 100;
        arr[rear] = order;
        size++;
        cout << "Order #" << order.orderID << " added: " 
             << order.itemName << " (x" << order.quantity << ")\n";
    }

    Order dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow! No pending orders.\n";
            return {0, "", 0};
        }
        Order order = arr[front];
        front = (front + 1) % 100;
        size--;
        cout << "Processing Order #" << order.orderID << "...\n";
        return order;
    }

    void printProcessedOrders() {
        cout << "\n--- Processed Orders ---\n";
        if (isEmpty()) {
            cout << "No orders in queue.\n";
            return;
        }
        int count = size;
        int index = front;
        for (int i = 0; i < count; i++) {
            cout << "Order #" << arr[index].orderID << " | Item: "
                 << arr[index].itemName << " | Qty: " << arr[index].quantity << endl;
            index = (index + 1) % 100;
        }
    }
};

int main() {
    OrderQueue q;

    q.enqueue({1, "Burger", 2});
    q.enqueue({2, "Pizza", 1});
    q.enqueue({3, "Pasta", 3});

    q.dequeue();
    q.dequeue();

    q.printProcessedOrders();

    return 0;
}
