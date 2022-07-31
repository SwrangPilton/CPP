#include <bits/stdc++.h>
using namespace std;

void countingSort(vector<int> &arr) {
    int n = arr.size();
    int largest = -1;

    //! Find the largest element
    for (int x : arr) {
        largest = max(largest, x);
    }

    //! Array Frequency of Largest Element + 1
    vector<int> freq(largest + 1, 0);
    for (int x : arr) {
        freq[x]++;
    }

    // for (int i = 0; i < freq.size() - 1; i++) {
    //     cout << i << " " << freq[i] << endl;
    // }

    //! Replace Old Array with sorted values
    int j = 0;
    for (int i = 0; i <= largest; i++) {
        while (freq[i] > 0) {
            arr[j] = i;
            freq[i]--;
            j++;
        }
    }
}

int main() {
    vector<int> arr{5, 4, 2, 3, 1, 6, 7, 9, 8};
    countingSort(arr);
    for (auto x : arr) {
        cout << x << " ";
    }
    return 0;
}