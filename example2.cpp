#include <iostream>
#include <vector>
using namespace std;

class MyCircularDeque {
private:
    vector<int> deque;  // Fixed-size array
    int front;          // Index before the first element
    int rear;           // Index of the last element
    int size;           // Current number of elements
    int capacity;       // Maximum size of deque

public:
    // Constructor to initialize deque of size k
    MyCircularDeque(int k) {
        capacity = k;
        deque.resize(k);
        front = 0;
        rear = k - 1;
        size = 0;
    }

    // Insert at the front
    bool insertFront(int value) {
        if (isFull()) return false;
        front = (front - 1 + capacity) % capacity;
        deque[front] = value;
        size++;
        return true;
    }

    // Insert at the rear
    bool insertLast(int value) {
        if (isFull()) return false;
        rear = (rear + 1) % capacity;
        deque[rear] = value;
        size++;
        return true;
    }

    // Delete from the front
    bool deleteFront() {
        if (isEmpty()) return false;
        front = (front + 1) % capacity;
        size--;
        return true;
    }

    // Delete from the rear
    bool deleteLast() {
        if (isEmpty()) return false;
        rear = (rear - 1 + capacity) % capacity;
        size--;
        return true;
    }

    // Get the front item
    int getFront() {
        if (isEmpty()) return -1;
        return deque[front];
    }

    // Get the rear item
    int getRear() {
        if (isEmpty()) return -1;
        return deque[rear];
    }

    // Check if the deque is empty
    bool isEmpty() {
        return size == 0;
    }

    // Check if the deque is full
    bool isFull() {
        return size == capacity;
    }
};

// Sample main function to test the deque
int main() {
    MyCircularDeque dq(3); // Create deque of capacity 3

    cout << dq.insertLast(1) << endl;   // returns true
    cout << dq.insertLast(2) << endl;   // returns true
    cout << dq.insertFront(3) << endl;  // returns true
    cout << dq.insertFront(4) << endl;  // returns false (deque is full)
    cout << dq.getRear() << endl;       // returns 2
    cout << dq.isFull() << endl;        // returns true
    cout << dq.deleteLast() << endl;    // returns true
    cout << dq.insertFront(4) << endl;  // returns true
    cout << dq.getFront() << endl;      // returns 4

    return 0;
}
