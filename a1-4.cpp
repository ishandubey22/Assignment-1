#include <iostream>
#include <algorithm>
using namespace std;

// Function to find the median of two sorted arrays
double findMedian(int arr1[], int size1, int arr2[], int size2) {
    // Handle the case when both arrays are empty
    if (size1 == 0 && size2 == 0) {
        cout << "Empty Array" << endl;
        return -1;  // Special return value to indicate an empty array case
    }
    
    // Handle the case when only one array is empty
    if (size1 == 0) {
        if (size2 % 2 == 0)
            return (arr2[size2 / 2 - 1] + arr2[size2 / 2]) / 2.0;
        else
            return arr2[size2 / 2];
    }
    if (size2 == 0) {
        if (size1 % 2 == 0)
            return (arr1[size1 / 2 - 1] + arr1[size1 / 2]) / 2.0;
        else
            return arr1[size1 / 2];
    }

    // Now merge the two arrays and find the median
    int merged[size1 + size2];
    int i = 0, j = 0, k = 0;

    // Merge arrays
    while (i < size1 && j < size2) {
        if (arr1[i] <= arr2[j]) {
            merged[k++] = arr1[i++];
        } else {
            merged[k++] = arr2[j++];
        }
    }

    // Copy remaining elements from arr1, if any
    while (i < size1) {
        merged[k++] = arr1[i++];
    }

    // Copy remaining elements from arr2, if any
    while (j < size2) {
        merged[k++] = arr2[j++];
    }

    // Find median of merged array
    int totalSize = size1 + size2;
    if (totalSize % 2 == 0) {
        return (merged[totalSize / 2 - 1] + merged[totalSize / 2]) / 2.0;
    } else {
        return merged[totalSize / 2];
    }
}

int main() {
    int size1;
    cin >> size1;

    int arr1[size1];
    for (int i = 0; i < size1; ++i) {
        cin >> arr1[i];
    }

    int size2;
    cin >> size2;

    int arr2[size2];
    for (int i = 0; i < size2; ++i) {
        cin >> arr2[i];
    }

    // If both arrays are empty, findMedian will handle the message
    double median = findMedian(arr1, size1, arr2, size2);

    // Only print the median if it's not an empty array case
    if (!(size1 == 0 && size2 == 0)) {
        cout << "Median = " << median << endl;
    }
    
    return 0;
}
