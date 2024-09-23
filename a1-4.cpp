#include <iostream>

using namespace std;

// Function to find the median of two sorted arrays
double findMedian(int arr1[], int size1, int arr2[], int size2) {
    // Handle edge cases
    if (size1 == 0) {
        return static_cast<double>(arr2[(size2 - 1) / 2]);
    }
    if (size2 == 0) {
        return static_cast<double>(arr1[(size1 - 1) / 2]);
    }

    // Find the middle index of the combined array
    int totalSize = size1 + size2;
    int middleIndex = (totalSize - 1) / 2;

    // Use binary search to find the median
    int i = 0, j = 0, count = 0;
    while (i < size1 && j < size2 && count <= middleIndex) {
        if (arr1[i] <= arr2[j]) {
            count++;
            if (count == middleIndex + 1) {
                return static_cast<double>(arr1[i]);
            }
            i++;
        } else {
            count++;
            if (count == middleIndex + 1) {
                return static_cast<double>(arr2[j]);
            }
            j++;
        }
    }

    // If the middle index is not reached, the median is the last element of the array with fewer elements
    if (i == size1) {
        return static_cast<double>(arr2[j + middleIndex - count]);
    } else {
        return static_cast<double>(arr1[i + middleIndex - count]);
    }
}

int main() {
    // You can use cout statements, but ensure that you submit after commenting them out, as the autograder will otherwise mistake it for your actual output
    // Everything else in the main function remains unchanged

    int size1;
    // cout << "Enter the size of the array1: ";
    cin >> size1;

    int arr[size1];
    // cout << "Enter " << size1 << " elements:" << endl;
    for (int i = 0; i < size1; ++i) {
        cin >> arr[i];
    }

    // cout << "The array elements are: ";
    // for (int i = 0; i < size1; ++i) {
    //     cout << arr[i] << " ";
    // }
    // cout << endl;

    int size2;
    // cout << "Enter the size of the array2: ";
    cin >> size2;

    int arr1[size2];
    // cout << "Enter " << size2 << " elements:" << endl;
    for (int i = 0; i < size2; ++i) {
        cin >> arr1[i];
    }

    // cout << "The array elements are: ";
    // for (int i = 0; i < size2; ++i) {
    //     cout << arr1[i] << " ";
    // }
    // cout << endl;

    cout << "Median = " << findMedian(arr, size1, arr1, size2) << endl; // do not comment this out

    return 0;
}
