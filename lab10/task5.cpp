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

    void insert(int rating) {
        heap[size] = rating;
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
        cout << "Queue: ";
        for (int i = 0; i < size; i++)
            cout << heap[i] << " ";
        cout << endl;
    }
};

int main() {
    MaxHeap queue;

    //  Initial players
    queue.insert(1500);
    queue.insert(1200);
    queue.insert(1800);
    queue.insert(1600);

    cout << "Initial queue:\n";
    queue.display();

    //  New player 1700 joins
    queue.insert(1700);
    cout << "Queue after inserting player 1700:\n";
    queue.display();

    // Match highest-rated player
    int matched = queue.extractMax();
    cout << "Matched player with rating: " << matched << endl;
    cout << "Queue after matching:\n";
    queue.display();

    return 0;
}
