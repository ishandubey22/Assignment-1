#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

//partitioning for quickselect
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

// finding the median, self-explanatory i believe
double findMedian(vector<int>& arr) {
    int n = arr.size();
    sort(arr.begin(), arr.end());
    return n % 2 == 0 ? (arr[n / 2 - 1] + arr[n / 2]) / 2.0 : arr[n / 2];
}

// Median of Medians (sounds way too grand ngl) algorithm to optimise da quickselect algorithm.
int medianOfMedians(vector<int>& arr, int low, int high, int k) {
    if (high - low < 5) {
        sort(arr.begin() + low, arr.begin() + high + 1);
        return arr[low + k];
    }

    for (int i = low; i <= high; i += 5) {
        int subHigh = i + 4 > high ? high : i + 4;
        sort(arr.begin() + i, arr.begin() + subHigh + 1);
        int median = arr[i + (subHigh - i) / 2];
        swap(arr[low + (i - low) / 5], arr[i + (subHigh - i) / 2]);
    }

    return medianOfMedians(arr, low, low + (high - low) / 5, (high - low) / 10);
}

//the good old quickselect algorithm (inspired from geeks for geeks). (median of medians improves quickselect's worst case from n^2 to n)
int quickSelect(vector<int>& arr, int low, int high, int k) {
    if (low == high)
        return arr[low];

    int pivot = medianOfMedians(arr, low, high, (high - low) / 2);
    int partitionIndex = partition(arr, low, high, pivot);

    if (k < partitionIndex) {
        return quickSelect(arr, low, partitionIndex - 1, k);
    } else {
        return quickSelect(arr, partitionIndex, high, k);
    }
}

// one more function for the heck of it at this point (not really, this is the magical one)
bool findMedianTwoUnsortedArrays(const vector<int>& arr1, const vector<int>& arr2, double& median) {
    int size1 = arr1.size();
    int size2 = arr2.size();

    // edge case when both arrays empty
    if (size1 == 0 && size2 == 0) {
        cout << "Empty Array" << endl;
        return false; // failure to calculate median
    }

    // If one array is empty, ze function will simply find the median of other array
    if (size1 == 0) {
        median = size2 % 2 == 0 ? (arr2[size2 / 2 - 1] + arr2[size2 / 2]) / 2.0 : arr2[size2 / 2];
        return true;
    }
    if (size2 == 0) {
        median = size1 % 2 == 0 ? (arr1[size1 / 2 - 1] + arr1[size1 / 2]) / 2.0 : arr1[size1 / 2];
        return true;
    }

    // merging da arrays
    vector<int> mergedArr = arr1;
    mergedArr.insert(mergedArr.end(), arr2.begin(), arr2.end());

    int totalSize = mergedArr.size();
    int medianPos = (totalSize - 1) / 2;

    // if total no. of elements = odd, return middle element
    if (totalSize % 2 != 0) {
        median = quickSelect(mergedArr, 0, totalSize - 1, medianPos);
    } else {
        // if even, find avg. of two middle elements
        int leftMedian = quickSelect(mergedArr, 0, totalSize - 1, medianPos);
        int rightMedian = quickSelect(mergedArr, 0, totalSize - 1, medianPos + 1);
        median = (leftMedian + rightMedian) / 2.0;
    }

    return true; // success in calculating median! 
    //Imagine my shock after a HUNDRED lines of code (im pretty sure we could do it a simpler way but im way too exhausted to try)! T T
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
