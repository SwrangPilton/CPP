#include <bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int> &arr) {
    int n = arr.size();
    for (int count = 1; count <= n - 1; count++) {
        int flag = 0;
        for (int j = 0; j <= n - 2; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                flag = 1;
            }
        }
        if (flag == 0) break;
    }
}

int main() {
    vector<int> arr{5, 4, 3, 1, 2, 7, 8, 9, 6};
    bubbleSort(arr);
    for (auto x : arr) {
        cout << x << " ";
    }
    return 0;
}