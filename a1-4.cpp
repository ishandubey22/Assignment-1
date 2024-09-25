#include <iostream>
#include <vector>
#include <limits> // For handling infinity values

using namespace std;

// Function to find the median of two sorted arrays using binary search
double findMedianBinarySearch(const vector<int>& arr1, const vector<int>& arr2) {
    int size1 = arr1.size();
    int size2 = arr2.size();

    // Handle case when both arrays are empty
    if (size1 == 0 && size2 == 0) {
        cout << "Empty Array" << endl;
        return numeric_limits<double>::quiet_NaN(); // Return NaN for invalid input
    }

    // Ensure arr1 is the smaller array to minimize search space
    if (size1 > size2) {
        return findMedianBinarySearch(arr2, arr1);
    }

    int low = 0, high = size1;
    int halfLength = (size1 + size2 + 1) / 2;

    while (low <= high) {
        int partition1 = (low + high) / 2;
        int partition2 = halfLength - partition1;

        // Handle boundaries
        int maxLeft1 = (partition1 == 0) ? numeric_limits<int>::min() : arr1[partition1 - 1];
        int minRight1 = (partition1 == size1) ? numeric_limits<int>::max() : arr1[partition1];

        int maxLeft2 = (partition2 == 0) ? numeric_limits<int>::min() : arr2[partition2 - 1];
        int minRight2 = (partition2 == size2) ? numeric_limits<int>::max() : arr2[partition2];

        // Check for correct partition
        if (maxLeft1 <= minRight2 && maxLeft2 <= minRight1) {
            if ((size1 + size2) % 2 == 0) {
                return (max(maxLeft1, maxLeft2) + min(minRight1, minRight2)) / 2.0;
            } else {
                return max(maxLeft1, maxLeft2);
            }
        } else if (maxLeft1 > minRight2) {
            high = partition1 - 1;
        } else {
            low = partition1 + 1;
        }
    }

    throw invalid_argument("Input arrays are not sorted or not valid.");
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

    // Check if both arrays are empty
    if (size1 == 0 && size2 == 0) {
        cout << "Empty Array" << endl;
        return 0;
    }

    try {
        double median = findMedianBinarySearch(arr1, arr2);
        if (!isnan(median)) {
    cout << "Median = " << median << endl;
}
    } catch (const exception& e) {
        cout << e.what() << endl;
    }

    return 0;
}
