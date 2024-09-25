#include <iostream>
#include <vector>
#include <algorithm> 
#include <limits>    

using namespace std;

// Function partition the array
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high]; // Choose the last element as pivot
    int i = low;           // Index for smaller element

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[high]);
    return i; // Return pivot index
}

// Quickselect function to find the k-th smallest element in the array
int quickSelect(vector<int>& arr, int low, int high, int k) {
    if (low == high) {
        return arr[low];
    }

    int pivotIndex = partition(arr, low, high);

    // Check if pivotIndex is the k-th element
    if (pivotIndex == k) {
        return arr[pivotIndex];
    } else if (pivotIndex > k) {
        return quickSelect(arr, low, pivotIndex - 1, k);
    } else {
        return quickSelect(arr, pivotIndex + 1, high, k);
    }
}

// find median in 2 unsorted arrays using Quickselect
double findMedianTwoUnsortedArrays(const vector<int>& arr1, const vector<int>& arr2) {
    int size1 = arr1.size();
    int size2 = arr2.size();

    // Handle case when both arrays are empty
    if (size1 == 0 && size2 == 0) {
        cout << "Empty Array" << endl;
        return; //for invalid input
    }

    // If one array is empty, simply find the median of the other array
    if (size1 == 0) {
        return size2 % 2 == 0 ? (arr2[size2 / 2 - 1] + arr2[size2 / 2]) / 2.0 : arr2[size2 / 2];
    }
    if (size2 == 0) {
        return size1 % 2 == 0 ? (arr1[size1 / 2 - 1] + arr1[size1 / 2]) / 2.0 : arr1[size1 / 2];
    }

    // Merge botj the two arrays
    vector<int> mergedArr = arr1;
    mergedArr.insert(mergedArr.end(), arr2.begin(), arr2.end());

    int totalSize = mergedArr.size();
    int medianPos = (totalSize - 1) / 2;

    // If total number of elements is odd, we return the middle element
    if (totalSize % 2 != 0) {
        return quickSelect(mergedArr, 0, totalSize - 1, medianPos);
    } else {
        // If even, we need to find the average of the two middle elements
        int leftMedian = quickSelect(mergedArr, 0, totalSize - 1, medianPos);
        int rightMedian = quickSelect(mergedArr, 0, totalSize - 1, medianPos + 1);
        return (leftMedian + rightMedian) / 2.0;
    }
}

int main() {
    int size1;
    cin >> size1;

    vector<int> arr1(size1);
    for (int i = 0; i < size1; ++i) {
        cin >> arr1[i];
    }

    int size2;
    cin >> size2;

    vector<int> arr2(size2);
    for (int i = 0; i < size2; ++i) {
        cin >> arr2[i];
    }

    double median = findMedianTwoUnsortedArrays(arr1, arr2);
    cout << "Median = " << median << endl;

    return 0;
}
