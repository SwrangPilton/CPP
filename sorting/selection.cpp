#include <bits/stdc++.h>
using namespace std;

void selectionSort(vector<int> &arr) {
    int n = arr.size();
    for (int i = 0; i <= n - 2; i++) {
        int smallest = i;
        for (int j = i + 1; j <= n - 1; j++) {
            if (arr[j] < arr[smallest]) {
                smallest = j;
            }
        }

        swap(arr[i], arr[smallest]);
    }
}
int main() {
    vector<int> arr{5, 2, 3, 1, 4};
    for (auto x : arr) cout << x << " ";
    cout << endl;
    selectionSort(arr);
    for (auto x : arr) cout << x << " ";
    return 0;
}