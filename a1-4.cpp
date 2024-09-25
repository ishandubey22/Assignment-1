
#include <iostream>
#include <vector>
#include <algorithm> 
#include <limits>    

using namespace std;

// fn to partition the array for Median of Medians
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

// Quickselect function to find the k-th smallest element in the array (median of medians improves quickselects worst case frrom n^2 to n)
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

// fn to find the median in two unsorted arrays using Median of Medians
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

    // Merge the two arrays
    vector<int> mergedArr = arr1;
    mergedArr.insert(mergedArr.end(), arr2.begin(), arr2.end());

   int totalSize = mergedArr.size();
    int medianPos = (totalSize - 1) / 2;

    // If the total number of elements is odd, we return the middle element
    if (totalSize % 2 != 0) {
        median = quickSelect(mergedArr, 0, totalSize, medianPos);
    } else {
        // If even, we need to find the average of the two middle elements
        int leftMedian = quickSelect(mergedArr, 0, totalSize - 1, medianPos);
        int rightMedian = quickSelect(mergedArr, 0, totalSize - 1, medianPos + 1);
        median = (leftMedian + rightMedian) / 2.0;
    }

    return true; // Indicate success in calculating median
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

    double median;
    if (findMedianTwoUnsortedArrays(arr1, arr2, median)) {
        cout << "Median = " << median << endl;
    }

    return 0;
}
