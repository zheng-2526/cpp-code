#include <bits/stdc++.h>
using namespace std;

int a[1000005], n, x;

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = arr[high];
        int i = low - 1;
        for (int j = low; j < high; j++) {
            if (arr[j] < pivot) {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);
        quickSort(arr, low, i);
        quickSort(arr, i + 2, high);
    }
}

void findn(int arr[], int x, int left, int right) {
    if(left >= right) {
        cout << -1;
        exit(0);
    }
    int mid = (left + right) / 2;
    if(arr[mid] == x) {
        cout << mid;
        exit(0);
    } else if(arr[mid] < x) {
        findn(arr, x, mid + 1, right);
    } else {
        findn(arr, x, left, mid - 1);
    }
}

int main() {
    cin >> n >> x;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    quickSort(a, 1, n);
    findn(a, x, 1, n);
    return 0;
}