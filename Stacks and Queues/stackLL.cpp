#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct Node {
    ll data;        // Changed to long long (ll)
    Node* next;
    Node(ll val) : data(val), next(nullptr) {}
};

class Stack {
    private:
        Node* top;     // Points to the top of the stack
        int size=0;      // Track the size of the stack
    public:
        // Constructor to initialize top pointer and size
        Stack() : top(nullptr), size(0) {}

        // Push a value onto the stack
        void push(ll x) {
            Node* temp = new Node(x);  // Create a new node
            temp->next = top;          // Point new node to the current top
            top = temp;                // Update the top to new node
            size++;                    // Increase the size
        }

        // Pop a value from the stack and return it
        ll pop() {
            if (top == nullptr) {
                cout << "Stack is empty!" << endl;
                return -1; // Indicating that the stack is empty
            }
            Node* temp = top;         // Store the current top node
            ll poppedData = top->data; // Get the data to be popped
            top = top->next;          // Move top pointer to the next node
            delete temp;              // Delete the old top node
            size--;                   // Decrease the size
            return poppedData;        // Return the popped data
        }

        // Peek the top value of the stack without popping
        ll peek() {
            if (top == nullptr) {
                cout << "Stack is empty!" << endl;
                return -1; // Indicating that the stack is empty
            }
            return top->data; // Return the top data
        }

        // Check if the stack is empty
        bool isEmpty() {
            return top == nullptr;
        }

        // Get the size of the stack
        int getSize() {
            return size;
        }
};

int main() {
    Stack s;

    // Pushing elements onto the stack
    int a, b, c;
    cin>>a>>b>>c;
    s.push(a);
    s.push(b);
    s.push(c);

    // Peek at the top element
    cout << "Top element is: " << s.peek() << endl;

    // Pop elements from the stack
    cout << "Popped: " << s.pop() << endl;
    cout << "Popped: " << s.pop() << endl;

    // Check if stack is empty
    cout << "Is the stack empty? " << (s.isEmpty() ? "Yes" : "No") << endl;

    // Push another element
    s.push(50);
    cout << "Size of the stack: " << s.getSize() << endl;

    return 0;
}
