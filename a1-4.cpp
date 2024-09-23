#include <iostream>
#include <fstream>
using namespace std;

// Function to find the median of two sorted arrays
double findMedian(int arr1[], int size1, int arr2[], int size2) {
    // Handle cases where one of the arrays is empty
    if (size1 == 0 && size2 == 0) {
        return 0.0; // Undefined behavior; you might want to return a specific message.
    }
    if (size1 == 0) {
        if (size2 % 2 == 0) {
            return (arr2[size2 / 2] + arr2[size2 / 2 - 1]) / 2.0;
        } else {
            return arr2[size2 / 2];
        }
    }
    if (size2 == 0) {
        if (size1 % 2 == 0) {
            return (arr1[size1 / 2] + arr1[size1 / 2 - 1]) / 2.0;
        } else {
            return arr1[size1 / 2];
        }
    }

    int totalSize = size1 + size2;
    int medianPos = (totalSize - 1) / 2;

    int i = 0, j = 0, count = 0;
    int prev = -1, current = -1;

    // Merge both arrays until we find the median position
    while (i < size1 && j < size2) {
        if (arr1[i] <= arr2[j]) {
            prev = current;
            current = arr1[i];
            i++;
        } else {
            prev = current;
            current = arr2[j];
            j++;
        }

        if (count == medianPos) {
            if (totalSize % 2 == 0) {
                return (current + prev) / 2.0;
            } else {
                return current;
            }
        }
        count++;
    }

    // If elements remain in arr1
    while (i < size1) {
        prev = current;
        current = arr1[i];
        i++;

        if (count == medianPos) {
            if (totalSize % 2 == 0) {
                return (current + prev) / 2.0;
            } else {
                return current;
            }
        }
        count++;
    }

    // If elements remain in arr2
    while (j < size2) {
        prev = current;
        current = arr2[j];
        j++;

        if (count == medianPos) {
            if (totalSize % 2 == 0) {
                return (current + prev) / 2.0;
            } else {
                return current;
            }
        }
        count++;
    }

    return -1; // This line should never be reached
}

int main() {
    // Read input
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

    // Find the median
    double median = findMedian(arr, size1, arr1, size2);

    // Output the result to a file named "a1-4.out"
    ofstream outFile("a1-4.out");
    if (outFile.is_open()) {
        outFile << "Median = " << median << endl;
        outFile.close();
    } else {
        cerr << "Unable to open file" << endl;
    }

    return 0;
}
