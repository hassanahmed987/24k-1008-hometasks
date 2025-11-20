#include <iostream>
using namespace std;

class MinHeap {
    int heap[100];
    int size;

public:
    MinHeap() { size = 0; }

    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return 2 * i + 1; }
    int right(int i) { return 2 * i + 2; }

    void heapifyUp(int i) {
        while (i != 0 && heap[parent(i)] > heap[i]) {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

    void heapifyDown(int i) {
        int l = left(i), r = right(i);
        int smallest = i;

        if (l < size && heap[l] < heap[smallest]) smallest = l;
        if (r < size && heap[r] < heap[smallest]) smallest = r;

        if (smallest != i) {
            swap(heap[i], heap[smallest]);
            heapifyDown(smallest);
        }
    }

    void insert(int price) {
        heap[size] = price;
        size++;
        heapifyUp(size - 1);
    }

    int extractMin() {
        if (size == 0) return -1;
        int minVal = heap[0];
        heap[0] = heap[size - 1];
        size--;
        heapifyDown(0);
        return minVal;
    }

    void display() {
        cout << "Heap: ";
        for (int i = 0; i < size; i++)
            cout << heap[i] << " ";
        cout << endl;
    }
};

int main() {
    MinHeap orderHeap;

    // Insert initial orders
    orderHeap.insert(100);
    orderHeap.insert(50);
    orderHeap.insert(75);
    orderHeap.insert(60);

    cout << "Heap after initial orders:\n";
    orderHeap.display();

    //  Insert new order 55
    orderHeap.insert(55);
    cout << "Heap after inserting order 55:\n";
    orderHeap.display();

    // Execute order with lowest price
    int executed = orderHeap.extractMin();
    cout << "Executed order with price: " << executed << endl;
    cout << "Heap after execution:\n";
    orderHeap.display();

    return 0;
}
