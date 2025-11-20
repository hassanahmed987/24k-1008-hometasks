#include <iostream>
using namespace std;

class MinHeap {
    int *heap;
    int capacity;
    int size;

public:
    MinHeap(int cap) {
        capacity = cap;
        size = 0;
        heap = new int[cap];
    }

    int parent(int i) { return (i - 1) / 2; }

    int left(int i) { return 2 * i + 1; }

    int right(int i) { return 2 * i + 2; }

    void heapifyUp(int i) {
        while (i != 0 && heap[parent(i)] > heap[i]) {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

    void insert(int key) {
        if (size == capacity) {
            cout << "Heap full!\n";
            return;
        }
        heap[size] = key;
        size++;
        heapifyUp(size - 1);
    }

    void display() {
        cout << "Heap array: ";
        for (int i = 0; i < size; i++)
            cout << heap[i] << " ";
        cout << endl;
    }
};

int main() {
    MinHeap h(10);

    h.insert(1);
    h.insert(3);
    h.insert(4);
    h.insert(5);
    h.insert(7);
    h.insert(6);

    cout << "Heap before inserting 2:\n";
    h.display();

    h.insert(2);

    cout << "Heap after inserting 2:\n";
    h.display();

    return 0;
}
