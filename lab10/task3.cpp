#include <iostream>
using namespace std;

struct Task {
    string name;
    int priority;
};

class MaxHeap {
    Task heap[100];
    int size;

public:
    MaxHeap() { size = 0; }

    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return 2 * i + 1; }
    int right(int i) { return 2 * i + 2; }

    void heapifyUp(int i) {
        while (i != 0 && heap[parent(i)].priority < heap[i].priority) {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

    void heapifyDown(int i) {
        int l = left(i);
        int r = right(i);
        int largest = i;

        if (l < size && heap[l].priority > heap[largest].priority) largest = l;
        if (r < size && heap[r].priority > heap[largest].priority) largest = r;

        if (largest != i) {
            swap(heap[i], heap[largest]);
            heapifyDown(largest);
        }
    }

    void insert(Task t) {
        heap[size] = t;
        size++;
        heapifyUp(size - 1);
    }

    Task extractMax() {
        if (size == 0) return {"", -1};
        Task maxTask = heap[0];
        heap[0] = heap[size - 1];
        size--;
        heapifyDown(0);
        return maxTask;
    }

    void display() {
        cout << "Heap:\n";
        for (int i = 0; i < size; i++)
            cout << heap[i].name << "(" << heap[i].priority << ") ";
        cout << endl;
    }
};

int main() {
    MaxHeap taskHeap;

    //Insert tasks A(5), B(3), C(8)
    taskHeap.insert({"A", 5});
    taskHeap.insert({"B", 3});
    taskHeap.insert({"C", 8});

    cout << "Heap after inserting A(5), B(3), C(8):\n";
    taskHeap.display();

    // Remove highest priority task
    Task removed = taskHeap.extractMax();
    cout << "Removed task with highest priority: " << removed.name 
         << "(" << removed.priority << ")\n";
    cout << "Heap after removal:\n";
    taskHeap.display();

    //Insert new task D(6)
    taskHeap.insert({"D", 6});
    cout << "Heap after inserting D(6):\n";
    taskHeap.display();

    return 0;
}
