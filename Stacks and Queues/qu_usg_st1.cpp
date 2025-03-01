#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Queue {
    public:
        stack<int> smn, ssb;
        Queue() {

        }
        
        void push(int x) {
            while (smn.size()) {
                ssb.push(smn.top());
                smn.pop();
            }
            smn.push(x);
            while (ssb.size()) {
                smn.push(ssb.top());
                ssb.pop();
            }
        }

        void print() {
            stack<int> s=smn;
            while (s.size()) {
                cout << s.top() << " ";
                s.pop();
            }
            cout << endl;
            return;
        }
        
        int pop() {
            int x=smn.top();
            smn.pop();
            return x;
        }
        
        int front() {
            return smn.top();
        }
        
        bool empty() {
            if (smn.size()==0)
                return true;
            return false;
        }

        int getSize() {
            return smn.size();
        }
    };

int main() {
    Queue s;

    // Pushing elements onto the stack
    int a, b, c;
    cin>>a>>b>>c;
    s.push(a);
    s.push(b);
    s.push(c);

    s.print();
    // Peek at the front element
    cout << "Front element is: " << s.front() << endl;

    // Pop elements from the stack
    cout << "Popped: " << s.pop() << endl;
    cout << "Popped: " << s.pop() << endl;
    s.print();
    // Check if stack is empty
    cout << "Is the stack empty? " << (s.empty() ? "Yes" : "No") << endl;
    s.print();
    // Push another element
    s.push(50);
    s.print();
    cout << "Size of the stack: " << s.getSize() << endl;

    return 0;
}
