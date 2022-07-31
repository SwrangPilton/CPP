#include <bits/stdc++.h>
using namespace std;

void insertionSort(vector<int> &arr) {
    int n = arr.size();

    for (int i = 1; i <= n - 1; i++) {
        int current = arr[i];
        int prev = i - 1;
        cout << "i[outside] :" << i << endl;
        cout << "prev[outside] :" << prev << endl;
        while (prev >= 0 && arr[prev] > current) {
            arr[prev + 1] = arr[prev];
            prev = prev - 1;
            cout << "prev[inside] :" << prev << endl;
        }
        cout << "prev[after] :" << prev << endl;
        arr[prev + 1] = current;
        cout << "arr[prev + 1] :" << arr[prev + 1] << endl;
        cout << endl;
    }
}

int main() {
    vector<int> arr{5, 4, 2, 3, 1};
    insertionSort(arr);
    for (auto x : arr) {
        cout << x << " ";
    }
    return 0;
}