#include <iostream>
using namespace std;

class MaxHeap {
    int heap[100]; 
    int size;

public:
    MaxHeap() { size = 0; }

    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return 2 * i + 1; }
    int right(int i) { return 2 * i + 2; }

    void heapifyUp(int i) {
        while (i != 0 && heap[parent(i)] < heap[i]) {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

    void heapifyDown(int i) {
        int l = left(i);
        int r = right(i);
        int largest = i;

        if (l < size && heap[l] > heap[largest]) largest = l;
        if (r < size && heap[r] > heap[largest]) largest = r;

        if (largest != i) {
            swap(heap[i], heap[largest]);
            heapifyDown(largest);
        }
    }

    void insert(int severity) {
        heap[size] = severity;
        size++;
        heapifyUp(size - 1);
    }

    int extractMax() {
        if (size == 0) return -1;
        int maxVal = heap[0];
        heap[0] = heap[size - 1];
        size--;
        heapifyDown(0);
        return maxVal;
    }

    void display() {
        cout << "Heap: ";
        for (int i = 0; i < size; i++) cout << heap[i] << " ";
        cout << endl;
    }
};

int main() {
    MaxHeap erHeap;

    erHeap.insert(15);
    erHeap.insert(12);
    erHeap.insert(9);
    erHeap.insert(8);
    erHeap.insert(10);
    erHeap.insert(6);

    cout << "Heap before inserting patient with severity 10:\n";
    erHeap.display();

    erHeap.insert(10);
    cout << "Heap after inserting patient with severity 10:\n";
    erHeap.display();

    int treated = erHeap.extractMax();
    cout << "Treated patient with severity: " << treated << endl;
    cout << "Heap after treating patient:\n";
    erHeap.display();

    return 0;
}
