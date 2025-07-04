#include <stack>
using namespace std;

class MyQueue {
private:
    stack<int> input;   // Stack used for enqueue (push)
    stack<int> output;  // Stack used for dequeue (pop/peek)

public:
    // Constructor to initialize your data structure
    MyQueue() {
        // No need to initialize anything, stacks are empty by default
    }

    // Push element x to the back of queue
    void push(int x) {
        input.push(x); // Just push into the input stack
    }

    // Removes the element from in front of queue and returns that element
    int pop() {
        // If output stack is empty, transfer all elements from input to output
        if (output.empty()) {
            while (!input.empty()) {
                output.push(input.top());
                input.pop();
            }
        }

        // Now the front of the queue is on top of the output stack
        int front = output.top();
        output.pop(); // Remove it
        return front;
    }

    // Get the front element without removing it
    int peek() {
        // Same logic as pop, but don’t remove the element
        if (output.empty()) {
            while (!input.empty()) {
                output.push(input.top());
                input.pop();
            }
        }

        return output.top(); // Return the front element
    }

    // Return whether the queue is empty
    bool empty() {
        // Queue is empty only if both stacks are empty
        return input.empty() && output.empty();
    }
};
