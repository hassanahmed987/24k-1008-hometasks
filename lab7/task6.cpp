#include <iostream>
#include <string>
using namespace std;

struct Employee {
    string name;
    int id;
    double salary;
};

void merge(Employee arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    Employee* L = new Employee[n1];
    Employee* R = new Employee[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i].salary >= R[j].salary)
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];

    delete[] L;
    delete[] R;
}

void mergeSort(Employee arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    Employee emp[12] = {
        {"Ali", 101, 75000},
        {"Sara", 102, 85000},
        {"Hassan", 103, 60000},
        {"Fatima", 104, 90000},
        {"Ahmed", 105, 50000},
        {"Zara", 106, 78000},
        {"Bilal", 107, 92000},
        {"Usman", 108, 64000},
        {"Noor", 109, 88000},
        {"Hamza", 110, 71000},
        {"Ayesha", 111, 99000},
        {"Tariq", 112, 56000}
    };

    int n = 12;
    mergeSort(emp, 0, n - 1);

    cout << "Top 3 Highest Paid Employees:\n";
    for (int i = 0; i < 3; i++) {
        cout << emp[i].name << " (ID: " << emp[i].id 
             << ") - Salary: " << emp[i].salary << endl;
    }

    return 0;
}
