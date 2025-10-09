/*
Reason:
Shell Sort is more efficient than simple sorts like Insertion or Bubble Sort 
because it allows elements that are far apart to be compared and moved early, 
reducing the total number of swaps and shifts required to reach the sorted order.
It performs better on moderately large or partially unsorted data by breaking 
the sequence into smaller sublists using 'gaps'. As the gap reduces, the list 
becomes nearly sorted, so the final insertion-like pass is very fast.
*/

// ---------------------- SHELL SORT IMPLEMENTATION ----------------------

#include <iostream>
using namespace std;

void display(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void shellSort(int arr[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
            arr[j] = temp;
        }
        cout << "After gap = " << gap << ": ";
        display(arr, n);
    }
}

// ---------------------- MAIN PROGRAM ----------------------

int main() {
    // -------------------- Q1: Book IDs --------------------
    cout << "Q1: Shell Sort for Book IDs\n";
    int bookIDs[] = {205, 102, 310, 450, 120, 90};
    int n1 = sizeof(bookIDs) / sizeof(bookIDs[0]);

    cout << "Original IDs: ";
    display(bookIDs, n1);

    shellSort(bookIDs, n1);

    cout << "Final Sorted Book IDs: ";
    display(bookIDs, n1);

    cout << "\nReasoning:\n";
    cout << "- Shell Sort is more efficient than Insertion Sort because it reduces large displacements early.\n";
    cout << "- Insertion Sort moves elements only one position at a time, while Shell moves them across larger gaps first.\n";
    cout << "- This saves time for inputs like [205, 102, 310, 450, 120, 90], where 90 must move several positions forward.\n\n";

    // -------------------- Q2: Luggage Weights --------------------
    cout << "Q2: Shell Sort for Luggage Weights\n";
    int weights[] = {32, 25, 40, 12, 18, 50, 28};
    int n2 = sizeof(weights) / sizeof(weights[0]);

    cout << "Original Weights: ";
    display(weights, n2);

    shellSort(weights, n2);

    cout << "Final Sorted Weights: ";
    display(weights, n2);

    cout << "\nComparison and Efficiency Discussion:\n";
    cout << "- Shell Sort performs fewer swaps than Bubble Sort, which repeatedly scans the entire list for each element.\n";
    cout << "- In Bubble Sort, each pass only moves one element to its correct place; Shell Sort moves multiple elements efficiently per pass.\n";
    cout << "- For airport luggage sorting, Shell Sort is faster, reducing total scan time before X-ray screening.\n";
    cout << "- If luggage is nearly sorted, Shell Sort becomes even faster, approaching O(n log n) performance,\n";
    cout << "  while Bubble Sort still takes roughly O(n^2) time.\n";

    return 0;
}
