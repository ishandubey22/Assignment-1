#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    if (nums1.size() > nums2.size()) {
        return findMedianSortedArrays(nums2, nums1);
    }
    int x = nums1.size();
    int y = nums2.size();

    // Handle edge cases
    if (x == 0 && y == 0) {
        cout << "Empty Array" << endl;
        return std::nan("");
    }
    if (x == 0) {
        return (y % 2 == 0) ? (nums2[y/2 - 1] + nums2[y/2]) / 2.0 : nums2[y/2];
    }
    if (y == 0) {
        return (x % 2 == 0) ? (nums1[x/2 - 1] + nums1[x/2]) / 2.0 : nums1[x/2];
    }

    int low = 0;
    int high = x;

    while (low <= high) {
        int partitionX = (low + high) / 2;
        int partitionY = (x + y + 1) / 2 - partitionX;

        int maxLeftX = (partitionX == 0) ? INT_MIN : nums1[partitionX - 1];
        int minRightX = (partitionX == x) ? INT_MAX : nums1[partitionX];

        int maxLeftY = (partitionY == 0) ? INT_MIN : nums2[partitionY - 1];
        int minRightY = (partitionY == y) ? INT_MAX : nums2[partitionY];

        if (maxLeftX <= minRightY && maxLeftY <= minRightX) {
            if ((x + y) % 2 == 0) {
                return (max(maxLeftX, maxLeftY) + min(minRightX, minRightY)) / 2.0;
            } else {
                return max(maxLeftX, maxLeftY);
            }
        } else if (maxLeftX > minRightY) {
            high = partitionX - 1;
        } else {
            low = partitionX + 1;
        }
    }

    throw invalid_argument("Input arrays are not sorted.");
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

    // We assume the input arrays are already sorted

    double median = findMedianSortedArrays(arr1, arr2);
    if (!(size1 == 0 && size2 == 0)) {
        cout << "Median = " << median << endl;
    }

    return 0;
}
