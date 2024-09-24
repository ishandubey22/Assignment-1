#include <iostream>

using namespace std;

// We have defined a Stack class with the required functions to be used in the problem
class Stack {
    
    int* arr;
    int top;
    int capacity;

public:
    Stack(int size) { // The constructor has been defined for you
        arr = new int[size];
        capacity = size;
        top = -1;
    }

    ~Stack() {
        delete[] arr;
    }

    // Function to add an element to the stack
    void push(int x) {
        if (isFull()) {
            // If the stack is full, do nothing or handle overflow
            cout << "Stack overflow! Cannot push " << x << " onto the stack." << endl;
            return;
        }
        arr[++top] = x; // Increment top and add the element to the stack
    }

    // Function to pop the top element
    int pop() {
        if (isEmpty()) {
            // If the stack is empty, return an error value or handle underflow
            cout << "Stack underflow! No elements to pop." << endl;
            return -1; // Return an error code (could be -1 or any value indicating an error)
        }
        return arr[top--]; // Return the top element and decrement the top pointer
    }

    // Function to display the elements of the stack
    void display() const {
        if (isEmpty()) {
            cout << "Empty";
        } else {
            for (int i = 0; i <= top; i++) {
                cout << arr[i] << " ";
            }
        }
        cout << endl;
    }

private:
    // Function to check if the stack is full
    bool isFull() const {
        return top == capacity - 1;  // The stack is full when the top index reaches capacity - 1
    }

    // Function to check if the stack is empty
    bool isEmpty() const {
        return top == -1;  // The stack is empty when the top index is -1 (no elements in the stack)
    }
};

// Stacks have been defined globally for the towers A, B, and C for printing the towers at each step
Stack* A;
Stack* B;
Stack* C;

// Function to display the contents of the towers
void displayTowers() {
    cout << "Tower A: ";
    A->display();
    cout << "Tower B: ";
    B->display();
    cout << "Tower C: ";
    C->display();
    cout << "\n";
}

// Function to move disks between towers
void moveDisk(Stack& from, Stack& to, char fromTower, char toTower) {
    int disk = from.pop();
    if (disk != -1) {
        to.push(disk);
        cout << "Move disk " << disk << " from " << fromTower << " to " << toTower << endl;
        displayTowers();
    }
}

// Recursive function to solve the Tower of Hanoi problem
void rearrangeDisks(int n, Stack& A, Stack& C, Stack& B, char from, char to, char aux) {
    if (n == 0) {
        return;
    }
    
    // Move n-1 disks from A to B, using C as auxiliary
    rearrangeDisks(n - 1, A, B, C, from, aux, to);

    // Move the nth disk from A to C
    moveDisk(A, C, from, to);

    // Move the n-1 disks from B to C, using A as auxiliary
    rearrangeDisks(n - 1, B, C, A, aux, to, from);
}

int main() { 
    int n;
    cout << "Enter the number of disks: ";
    cin >> n;

    // Input validation
    if (n <= 0) {
        cout << "Invalid Input" << endl;
        return 1;
    }

    A = new Stack(n);
    B = new Stack(n);
    C = new Stack(n);

    // Initialize tower A with disks (largest disk at the bottom, smallest at the top)
    for (int i = n; i >= 1; i--) {
        A->push(i);
    }

    // Display initial state of the towers
    displayTowers();

    // Solve the Tower of Hanoi problem
    rearrangeDisks(n, *A, *C, *B, 'A', 'C', 'B');

    // Clean up
    delete A;
    delete B;
    delete C;

    return 0;
}
