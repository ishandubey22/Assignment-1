#include <iostream>
#include <climits>

using namespace std;

double findMedian(int arr1[], int size1, int arr2[], int size2) {
    if (size1 > size2) return findMedian(arr2, size2, arr1, size1); // ensure size1 <= size2

    int low = 0, high = size1;
    int halfLen = (size1 + size2 + 1) / 2;
    
    while (low <= high) {
        int i = (low + high) / 2;
        int j = halfLen - i;

        int maxLeftA = (i == 0) ? INT_MIN : arr1[i - 1];
        int minRightA = (i == size1) ? INT_MAX : arr1[i];

        int maxLeftB = (j == 0) ? INT_MIN : arr2[j - 1];
        int minRightB = (j == size2) ? INT_MAX : arr2[j];

        if (maxLeftA <= minRightB && maxLeftB <= minRightA) {
            if ((size1 + size2) % 2 == 0)
                return (max(maxLeftA, maxLeftB) + min(minRightA, minRightB)) / 2.0;
            else
                return max(maxLeftA, maxLeftB);
        } else if (maxLeftA > minRightB) {
            high = i - 1;
        } else {
            low = i + 1;
        }
    }

    return 0.0; // should never reach here
}

int main() {
    int size1;
    cin >> size1;

    int arr[size1];
    for (int i = 0; i < size1; ++i) {
        cin >> arr[i];
    }

    int size2;
    cin >> size2;

    int arr1[size2];
    for (int i = 0; i < size2; ++i) {
        cin >> arr1[i];
    }
    
    cout << "Median = " << findMedian(arr, size1, arr1, size2) << endl;
    
    return 0;
}
