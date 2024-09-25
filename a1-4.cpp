
#include <iostream>
#include <vector>
#include <algorithm> // For std::min
#include <limits>    // For handling infinity values

using namespace std;

// Function to find the median in O(m + n) time using a merging approach
double findMedianTwoUnsortedArrays(const vector<int>& arr1, const vector<int>& arr2) {
    int size1 = arr1.size();
    int size2 = arr2.size();

    // Handle case when both arrays are empty
    if (size1 == 0 && size2 == 0) {
        cout << "Empty Array" << endl;
        return numeric_limits<double>::quiet_NaN(); // Return NaN for invalid input
    }

    // If one array is empty, simply find the median of the other array
    if (size1 == 0) {
        return size2 % 2 == 0 ? (arr2[size2 / 2 - 1] + arr2[size2 / 2]) / 2.0 : arr2[size2 / 2];
    }
    if (size2 == 0) {
        return size1 % 2 == 0 ? (arr1[size1 / 2 - 1] + arr1[size1 / 2]) / 2.0 : arr1[size1 / 2];
    }

    int totalSize = size1 + size2;
    bool isEven = (totalSize % 2 == 0);
    int medianPos = (totalSize - 1) / 2;

    int i = 0, j = 0; // Pointers for both arrays
    int current = 0, previous = 0;

    // Traverse the arrays using merge logic
    for (int count = 0; count <= medianPos + 1; ++count) {
        previous = current;

        if (i < size1 && (j >= size2 || arr1[i] < arr2[j])) {
            current = arr1[i++];
        } else {
            current = arr2[j++];
        }

        // If we have found the middle element(s), compute the median
        if (count == medianPos) {
            if (isEven) {
                // If even, the median is the average of the two middle elements
                return (current + previous) / 2.0;
            } else {
                // If odd, the median is the middle element
                return current;
            }
        }
    }

    return numeric_limits<double>::quiet_NaN(); // Should never reach here
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

