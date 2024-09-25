#include <iostream>
#include <vector>

using namespace std;

// Function to find the median
double findMedian(int arr1[], int size1, int arr2[], int size2) {
    // Step 1: Create a frequency array to count scores from 0 to 100
    int freq[101] = {0}; // Initialize all to 0

    // Step 2: Populate the frequency array using arr1 and arr2
    for (int i = 0; i < size1; ++i) {
        freq[arr1[i]]++;
    }

    for (int i = 0; i < size2; ++i) {
        freq[arr2[i]]++;
    }

    // Step 3: Find the median
    int totalStudents = size1 + size2;
    bool isEven = (totalStudents % 2 == 0);
    
    // Positions of the median(s)
    int medianPos1 = totalStudents / 2;
    int medianPos2 = medianPos1 + (isEven ? 1 : 0); // second median for even case
    
    // Step 4: Traverse the frequency array to locate the median values
    int count = 0;
    int median1 = -1, median2 = -1;

    for (int score = 0; score <= 100; ++score) {
        count += freq[score];
        
        if (median1 == -1 && count >= medianPos1) {
            median1 = score;
        }
        if (median2 == -1 && count >= medianPos2) {
            median2 = score;
        }
        
        if (median1 != -1 && median2 != -1) {
            break; // We found both medians
        }
    }

    // Step 5: Return the median
    if (isEven) {
        return (median1 + median2) / 2.0; // Average of two medians
    } else {
        return median1; // Odd case, just one median
    }
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
    
    cout << "Median = " << findMedian(arr, size1, arr1, size2) << endl; // do not comment this out
    
    return 0;
}
