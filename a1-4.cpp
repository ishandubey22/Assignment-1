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
    int n, m;
    cout << "Enter the size of the first array: ";
    cin >> n;
    vector<int> nums1(n);
    cout << "Enter the elements of the first array: ";
    for (int i = 0; i < n; i++) {
        cin >> nums1[i];
    }

    cout << "Enter the size of the second array: ";
    cin >> m;
    vector<int> nums2(m);
    cout << "Enter the elements of the second array: ";
    for (int i = 0; i < m; i++) {
        cin >> nums2[i];
    }

    double median = findMedianSortedArrays(nums1, nums2);
    cout << "Median: " << median << endl;

    return 0;
}
