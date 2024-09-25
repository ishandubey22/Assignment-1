#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Helper function to find the k-th smallest element using Quickselect
int kthSmallest(int arr[], int size, int k);

// Function to partition the array around a pivot
int partition(int arr[], int left, int right, int pivotIndex);

// Median of Medians algorithm to select a good pivot (Partition size = 2)
int medianOfMedians(int arr[], int left, int right, int k);

// Function to find the combined median of two unsorted arrays
double findMedian(int arr1[], int size1, int arr2[], int size2) {
    int totalSize = size1 + size2;

    // If the total size is odd, find the middle element
    if (totalSize % 2 == 1) {
        return kthSmallest(arr1, size1, arr2, size2, totalSize / 2);
    } else {
        // If the total size is even, find the average of the two middle elements
        int leftMedian = kthSmallest(arr1, size1, arr2, size2, totalSize / 2 - 1);
        int rightMedian = kthSmallest(arr1, size1, arr2, size2, totalSize / 2);
        return (leftMedian + rightMedian) / 2.0;
    }
}

// Function to partition an array around a pivot
int partition(int arr[], int left, int right, int pivotIndex) {
    int pivotValue = arr[pivotIndex];
    swap(arr[pivotIndex], arr[right]);
    int storeIndex = left;

    for (int i = left; i < right; i++) {
        if (arr[i] < pivotValue) {
            swap(arr[i], arr[storeIndex]);
            storeIndex++;
        }
    }
    swap(arr[storeIndex], arr[right]);
    return storeIndex;
}

// Quickselect Algorithm to find the k-th smallest element in two arrays
int quickselect(int arr[], int left, int right, int k) {
    if (left == right) {
        return arr[left];
    }

    // Use Median of Medians to select a good pivot
    int pivotIndex = medianOfMedians(arr, left, right, (right - left + 1) / 2);

    // Partition the array around the pivot
    pivotIndex = partition(arr, left, right, pivotIndex);

    // The pivot is in its final sorted position
    if (k == pivotIndex) {
        return arr[k];
    } else if (k < pivotIndex) {
        return quickselect(arr, left, pivotIndex - 1, k);
    } else {
        return quickselect(arr, pivotIndex + 1, right, k);
    }
}

// Median of Medians Algorithm to select a good pivot with partition size 2
int medianOfMedians(int arr[], int left, int right, int k) {
    if (right - left <= 1) {
        // If only 1 or 2 elements are left, sort and return the appropriate element
        if (right > left && arr[left] > arr[right]) {
            swap(arr[left], arr[right]);
        }
        return arr[left + k];
    }

    // Partition the array into groups of size 2 and find the "median" (smaller value)
    int numGroups = (right - left + 1) / 2;
    vector<int> medians(numGroups);

    for (int i = 0; i < numGroups; i++) {
        int groupLeft = left + i * 2;
        int groupRight = min(groupLeft + 1, right); // Ensure bounds
        medians[i] = min(arr[groupLeft], arr[groupRight]); // Take the smaller value as the "median"
    }

    // Recursively find the median of medians
    return medianOfMedians(medians.data(), 0, numGroups - 1, numGroups / 2);
}

// Function to find the k-th smallest element in the combined array of arr1 and arr2
int kthSmallest(int arr1[], int size1, int arr2[], int size2, int k) {
    // Combine the two arrays into one
    vector<int> combined(size1 + size2);
    for (int i = 0; i < size1; i++) {
        combined[i] = arr1[i];
    }
    for (int i = 0; i < size2; i++) {
        combined[size1 + i] = arr2[i];
    }

    // Use Quickselect to find the k-th smallest element
    return quickselect(combined.data(), 0, combined.size() - 1, k);
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
