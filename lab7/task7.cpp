#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

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
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

void radixSort(int arr[], int n) {
    int m = getMax(arr, n);
    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(arr, n, exp);
}

int main() {
    srand(time(0));
    const int n = 50;
    int scores[n];
    
    for (int i = 0; i < n; i++)
        scores[i] = rand() % 101;

    cout << "Original Scores:\n";
    for (int i = 0; i < n; i++)
        cout << scores[i] << " ";
    cout << "\n\n";

    radixSort(scores, n);

    cout << "Sorted Scores (Ascending Order):\n";
    for (int i = 0; i < n; i++)
        cout << scores[i] << " ";
    cout << "\n\n";

    cout << "Ranks:\n";
    for (int i = n - 1, rank = 1; i >= 0; i--, rank++)
        cout << "Student with score " << scores[i] << " is Rank " << rank << endl;

    return 0;
}
