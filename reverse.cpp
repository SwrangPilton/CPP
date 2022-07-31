#include <bits/stdc++.h>
using namespace std;

void reverse(int arr[], int n) {
    int s = 0;
    int e = n - 1;
    while (s <= e) {
        swap(arr[s], arr[e]);
        s++;
        e--;
    }
}

void myswap(int &a, int &b) {
    int c = a;
    a = b;
    b = c;
}

void printAllPairs(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        int x = arr[i];
        for (int j = 0; j < n; j++) {
            int y = arr[j];
            if (x == y) continue;
            cout << x << "," << y << endl;
        }
        cout << endl;
    }
}

int main() {
    int arr[] = {10, 20, 30, 40, 50, 60};
    int n = 6;
    printAllPairs(arr, n);
    // for (auto x : arr) {
    //     cout << x << " ";
    // }
    return 0;
}