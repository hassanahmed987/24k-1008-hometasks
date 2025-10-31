#include <iostream>
#include <iomanip>
using namespace std;

void display(int arr[], int n, int pass) {
    if (pass == 0)
        cout << "\nBefore Sorting:\n";
    else
        cout << "\nAfter pass " << pass << " (sorted by " << pass << " digit):\n";

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int getMax(int arr[], int n) {
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}

void countSort(int arr[], int n, int exp) {
    int output[n];
    int count[10] = {0};

    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--) {
        int idx = (arr[i] / exp) % 10;
        output[count[idx] - 1] = arr[i];
        count[idx]--;
    }

    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

void radixSort(int arr[], int n) {
    int m = getMax(arr, n);
    display(arr, n, 0);
    int pass = 1;
    for (int exp = 1; m / exp > 0; exp *= 10) {
        countSort(arr, n, exp);
        display(arr, n, pass++);
    }
}

int main() {
    const int n = 20;
    int arr[n];

    cout << "Enter 20 product IDs (5-digit integers):\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    radixSort(arr, n);

    cout << "\nFinal Sorted Product IDs (Ascending):\n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
