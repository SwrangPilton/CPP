#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &arr, int s, int e) {
    int i = s - 1;
    int pivot = arr[e];

    for (int j = s; j < e; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[e]);
    return i + 1;
}

void quickSort(vector<int> &arr, int s, int e) {
    // base case
    if (s >= e) return;

    // rec case
    int p = partition(arr, s, e);
    quickSort(arr, s, p - 1);
    quickSort(arr, p + 1, e);
}

int main() {
    vector<int> arr{10, 5, 2, 0, 7, 6, 4};
    int s = 0;
    int e = arr.size() - 1;
    quickSort(arr, s, e);
    for (auto x : arr) cout << x << " ";
    return 0;
}