#include <iostream>
#include <algorithm> // for std::merge

using namespace std;

// Function to find the median of two sorted arrays
double findMedian(int arr1[], int size1, int arr2[], int size2) {
    int totalSize = size1 + size2;
    int merged[totalSize];

    // Merge the two arrays into a single sorted array
    merge(arr1, arr1 + size1, arr2, arr2 + size2, merged);

    // If the total size is odd, return the middle element
    if (totalSize % 2 == 1) {
        return merged[totalSize / 2];
    }
    // If the total size is even, return the average of the two middle elements
    else {
        int mid1 = totalSize / 2;
        int mid2 = mid1 - 1;
        return (merged[mid1] + merged[mid2]) / 2.0;
    }
}

int main() {
    int size1;
    cin >> size1;

    int arr[size1];
    for (int i = 0; i < size1; ++i) {
        cin >> arr[i];
    }

    int size2;
    cin >> size2;

    int arr1[size2];
    for (int i = 0; i < size2; ++i) {
        cin >> arr1[i];
    }

    cout << "Median = " << findMedian(arr, size1, arr1, size2) << endl;

    return 0;
}
