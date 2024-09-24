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
            //
