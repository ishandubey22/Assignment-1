#include <iostream>
#include <vector>
#include <cmath> // For std::nan

using namespace std;

// Function to find the median of two sorted arrays
double findMedian(const vector<int>& arr1, const vector<int>& arr2) {
    int size1 = arr1.size();
    int size2 = arr2.size();

    // Handle the case when both arrays are empty
    if (size1 == 0 && size2 == 0) {
        cout << "Both arrays are empty." << endl;
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

    // Merge arrays
    vector<int> merged(size1 + size2);
    int i = 0, j = 0, k = 0;

    while (i < size1 && j < size2) {
        if (arr1[i] <= arr2[j]) {
            merged[k++] = arr1[i++];
        } else {
            merged[k++] = arr2[j++];
        }
    }
    while (i < size1) {
        merged[k++] = arr1[i++];
    }
    while (j < size2) {
        merged[k++] = arr2[j++];
    }

    int totalSize = size1 + size2;
    if (totalSize % 2 == 0) {
        return (merged[totalSize / 2 - 1] + merged[totalSize / 2]) / 2.0;
    } else {
        return merged[totalSize / 2];
    }
}

int main() {
    int size1, size2;

    cout << "Enter size of first array: ";
    cin >> size1;
    vector<int> arr1(size1);
    cout << "Enter elements of first array: ";
    for (int i = 0; i < size1; ++i) {
        cin >> arr1[i];
    }

    cout << "Enter size of second array: ";
    cin >> size2;
    vector<int> arr2(size2);
    cout << "Enter elements of second array: ";
    for (int i = 0; i < size2; ++i) {
        cin >> arr2[i];
    }

    double median = findMedian(arr1, arr2);
    if (size1 != 0 || size2 != 0) {
        cout << "Median = " << median << endl;
    }

    return 0;
}
