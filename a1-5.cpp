#include <iostream>

using namespace std;

// Stack class to represent the towers
class Stack {
    int* arr;
    int top;
    int capacity;

public:
    Stack(int size) {
        arr = new int[size];
        capacity = size;
        top = -1;
    }

    ~Stack() {
        delete[] arr;
    }

    // Function to add an element to the stack
    void push(int x) {
        if (isFull()) return;
        arr[++top] = x;
    }

    // Function to pop the top element
    int pop() {
        if (isEmpty()) return -1;
        return arr[top--];
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
    bool isFull() const {
        return top == capacity - 1;
    }

    bool isEmpty() const {
        return top == -1;
    }
};

// Global stacks for the towers
Stack* A;
Stack* B;
Stack* C;

// Function to display the state of the towers
void displayTowers() {
    cout << "Tower A: ";
    A->display();
    cout << "Tower B: ";
    B->display();
    cout << "Tower C: ";
    C->display();
    cout << endl;
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

// Recursive function to solve Tower of Hanoi
void rearrangeDisks(int n, Stack& A, Stack& C, Stack& B, char from, char to, char aux) {
    if (n == 0) return;

    rearrangeDisks(n - 1, A, B, C, from, aux, to);
    moveDisk(A, C, from, to);
    rearrangeDisks(n - 1, B, C, A, aux, to, from);
}

int main() {
    int n;
    cin >> n;

    // Input validation
    if (n <= 0) {
        cout << "Invalid Input" << endl;
        return 1;
    }

    A = new Stack(n);
    B = new Stack(n);
    C = new Stack(n);

    // Initialize tower A with disks
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
