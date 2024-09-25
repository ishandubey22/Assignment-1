#include <iostream>
using namespace std;

// Class to represent a stack (or tower)
class Tower {
    int* disks;
    int maxSize;
    int topIndex;

public:
    Tower(int capacity) {
        disks = new int[capacity];
        maxSize = capacity;
        topIndex = -1;
    }

    ~Tower() {
        delete[] disks;
    }

    // Function to add a disk to the tower
    void addDisk(int disk) {
        if (topIndex < maxSize - 1) {
            disks[++topIndex] = disk;
        }
    }

    // Function to remove the top disk from the tower
    int removeDisk() {
        if (topIndex >= 0) {
            return disks[topIndex--];
        }
        return -1;
    }

    // Display the current stack of disks
    void show() const {
        if (topIndex == -1) {
            cout << "Empty";
        } else {
            for (int i = 0; i <= topIndex; i++) {
                cout << disks[i] << " ";
            }
        }
        cout << endl;
    }

    // Utility functions to check state
    bool isTowerEmpty() const {
        return topIndex == -1;
    }

    bool isTowerFull() const {
        return topIndex == maxSize - 1;
    }
};

// Global towers
Tower* towerA;
Tower* towerB;
Tower* towerC;

// Function to display the current state of all towers
void showTowers() {
    cout << "Tower A: ";
    towerA->show();
    cout << "Tower B: ";
    towerB->show();
    cout << "Tower C: ";
    towerC->show();
    cout << endl;
}

// Function to handle disk movement between two towers
void moveDiskBetweenTowers(Tower& from, Tower& to, char fromLabel, char toLabel) {
    int disk = from.removeDisk();
    if (disk >= 0) {
        to.addDisk(disk);
        cout << "Move disk " << disk << " from " << fromLabel << " to " << toLabel << endl;
        showTowers();
    }
}

// Recursive function to rearrange the disks following Tower of Hanoi rules
void solveHanoi(int diskCount, Tower& source, Tower& destination, Tower& auxiliary, char sourceLabel, char destinationLabel, char auxiliaryLabel) {
    if (diskCount == 0) return;

    // Move n-1 disks from source to auxiliary tower
    solveHanoi(diskCount - 1, source, auxiliary, destination, sourceLabel, auxiliaryLabel, destinationLabel);

    // Move the nth disk from source to destination
    moveDiskBetweenTowers(source, destination, sourceLabel, destinationLabel);

    // Move the n-1 disks from auxiliary to destination
    solveHanoi(diskCount - 1, auxiliary, destination, source, auxiliaryLabel, destinationLabel, sourceLabel);
}

int main() {
    int numDisks;
    cin >> numDisks;

    if (numDisks <= 0) {
        cout << "Invalid Input" << endl;
        return 1;
    }

    // Create towers with the given number of disks
    towerA = new Tower(numDisks);
    towerB = new Tower(numDisks);
    towerC = new Tower(numDisks);

    // Add disks to Tower A in descending order
    for (int i = numDisks; i >= 1; i--) {
        towerA->addDisk(i);
    }

    // Display initial setup
    showTowers();

    // Solve the Tower of Hanoi problem
    solveHanoi(numDisks, *towerA, *towerC, *towerB, 'A', 'C', 'B');

    // Clean up memory
    delete towerA;
    delete towerB;
    delete towerC;

    return 0;
}
