#include <iostream>
#include <vector>
#include <algorithm> // For std::swap
#include <limits>    // For handling infinity values

using namespace std;

// Utility function to partition the array for Median of Medians
int partition(vector<int>& arr, int low, int high, int pivot) {
    while (low <= high) {
        while (arr[low] < pivot) low++;
        while (arr[high] > pivot) high--;
        if (low <= high) {
            swap(arr[low], arr[high]);
            low++;
            high--;
        }
    }
    return low;
}

// Function to find the median of an array
double findMedian(vector<int>& arr) {
    int n = arr.size();
    sort(arr.begin(), arr.end());
    return n % 2 == 0 ? (arr[n / 2 - 1] + arr[n / 2]) / 2.0 : arr[n / 2];
}

// Median of Medians algorithm to find the k-th smallest element
int medianOfMedians(vector<int>& arr, int low, int high, int k) {
    if (high - low < 5) {
        sort(arr.begin() + low, arr.begin() + high + 1);
        return arr[low + k];
    }

    for (int i = low; i <= high; i += 5) {
        int subHigh = i + 4 > high ? high : i + 4;
        sort(arr.begin() + i, arr.begin() + subHigh + 1);
        int median = arr[i + (subHigh - i) / 2];
        swap(arr[low + (i / 5)], median);
    }

    return medianOfMedians(arr, low, low + (high - low) / 5, (high - low) / 10);
}

// Quickselect function to find the k-th smallest element in the array
int quickSelect(vector<int>& arr, int low, int high, int k) {
    int pivot = medianOfMedians(arr, low, high, (high - low) / 2);
    int partitionIndex = partition(arr, low, high, pivot);

    if (k < partitionIndex) {
        return quickSelect(arr, low, partitionIndex - 1, k);
    } else if (k > partitionIndex) {
        return quickSelect(arr, partitionIndex, high, k);
    } else {
        return arr[partitionIndex - 1]; // Return the k-th smallest element
    }
}

// Function to find the median in two unsorted arrays using Median of Medians
bool findMedianTwoUnsortedArrays(const vector<int>& arr1, const vector<int>& arr2, double& median) {
    int size1 = arr1.size();
    int size2 = arr2.size();

    // Handle case when both arrays are empty
    if (size1 == 0 && size2 == 0) {
        cout << "Empty Array" << endl;
        return false; // Indicate failure to calculate median
    }

    // If one array is empty, simply find the median of the other array
    if (size1 == 0) {
        median = size2 % 2 == 0 ? (arr2[size2 / 2 - 1] + arr2[size2 / 2]) / 2.0 : arr2[size2 / 2];
        return true;
    }
    if (size2 == 0) {
        median = size1 % 2 == 0 ? (arr1[size1 / 2 - 1] + arr1[size1 / 2]) / 2.0 : arr1[size1 / 2];
        return true;
    }

    // Merge the two arra
