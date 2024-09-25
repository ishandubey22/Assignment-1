#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to partition the array around a pivot
int partition(int arr[], int left, int right, int pivotIndex);

// Median of Medians algorithm to select a good pivot (Partition size = 5)
int medianOfMedians(int arr[], int left, int right, int k);

// Helper function to find the k-th smallest element using Quickselect
int quickselect(int arr[], int left, int right, int k);

// Function to find the k-th smallest element in the combined array of arr1 and arr2
int kthSmallest(int arr1[], int size1, int arr2[], int size2, int k);

// Function to find the combined median of two unsorted arrays
double findMedian(int arr1[], int size1, int arr2[], int size2) {
    int totalSize = size1 + size2;

    if (totalSize % 2 == 1) {
        return kthSmallest(arr1, size1, arr2, size2, totalSize / 2);
    } else {
        int leftMedian = kthSmallest(arr1, size1, arr2, size2, totalSize / 2 - 1);
        int rightMedian = kthSmallest(arr1, size1, arr2, size2, totalSize / 2);
        return (leftMedian + rightMedian) / 2.0;
    }
}

int main() {
    int size1;
    cin >> size1;

    vector<int> arr(size1);
    for (int i = 0; i < size1; ++i) {
        cin >> arr[i];
    }

    int size2;
    cin >> size2;

    vector<int> arr1(size2);
    for (int i = 0; i < size2; ++i) {
        cin >> arr1[i];
    }

    cout << "Median = " << findMedian(arr.data(), size1, arr1.data(), size2) << endl;

    return 0;
}
