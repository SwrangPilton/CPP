#include <iostream>
#include <vector>
using namespace std;

// Function to get the largest element from an array
int getMax(vector<int> array, int n) {
    int max = array[0];
    for (int i = 1; i < n; i++)
        if (array[i] > max)
            max = array[i];
    return max;
}

// Using counting sort to sort the elements in the basis of significant places
void countingSort(vector<int> &array, int size, int place) {
    const int max = 10;
    int output[size];
    vector<int> count(max, 0);

    // Calculate count of elements
    for (int i = 0; i < size; i++) {
        count[(array[i] / place) % 10]++;
    }

    // Calculate cumulative count
    for (int i = 1; i < max; i++) {
        count[i] += count[i - 1];
    }

    // Place the elements in sorted order
    for (int i = size - 1; i >= 0; i--) {
        output[count[(array[i] / place) % 10] - 1] = array[i];
        count[(array[i] / place) % 10]--;
    }

    for (int i = 0; i < size; i++) {
        array[i] = output[i];
    }
}

// Main function to implement radix sort
void radixsort(vector<int> &array, int size) {
    // Get maximum element
    int max = getMax(array, size);

    // Apply counting sort to sort elements based on place value.
    for (int place = 1; max / place > 0; place *= 10) {
        countingSort(array, size, place);
    }
}

// Driver code
int main() {
    vector<int> array{121, 432, 564, 23, 1, 45, 788};
    // vector<int> array{121, 432, 564, 23, 1, 45, 788};
    int n = array.size();
    radixsort(array, n);
    for (auto x : array) cout << x << " ";
};