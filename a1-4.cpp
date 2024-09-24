#include <iostream>
#include <vector>
using namespace std;

// Function to find the median of two sorted arrays
double findMedian(const vector<int>& arr1, const vector<int>& arr2) {
    int size1 = arr1.size();
    int size2 = arr2.size();

    // Handle the case when both arrays are empty
    if (size1 == 0 && size2 == 0) {
        cout << "Empty Array" << endl;
        return std::nan(""); // Return NaN for clarity
    }

    // Handle the case when only one array is empty
    if (size1 == 0) {
        return (size2 % 2 == 0)
            ? (arr2[size2 / 2 - 1] + arr2[size2 / 2]) / 2.0
            : arr2[size2 / 2];
    }
    if (size2 == 0) {
        return (size1 % 2 == 0)
            ? (arr1[size1 / 2 - 1] + arr1[size1 / 2]) / 2.0
            : arr1[size1 / 2];
    }

    int totalSize = size1 + size2;
    int medianIndex = totalSize / 2;

    bool isEven = (totalSize % 2 == 0);

    // Use two pointers to traverse both arrays
    int i = 0, j = 0, count = 0;
    int curr = 0, prev = 0;

    while (count <= medianIndex) {
        prev = curr;
        if (i < size1 && (j >= size2 || arr1[i] <= arr2[j])) {
            curr = arr1[i++];
        } else {
            curr = arr2[j++];
        }
        count++;
    }

    // Return median based on whether the total size is even or odd
    if (isEven) {
        return (curr + prev) / 2.0;
    } else {
        return curr;
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

    double median = findMedian(arr1, arr2);
    if (!(size1 == 0 && size2 == 0)) {
        cout << "Median = " << median << endl;
    }

    return 0;
}
