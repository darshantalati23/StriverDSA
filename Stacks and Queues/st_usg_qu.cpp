#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Stack {
    public:
        queue<int> q;
        Stack() {

        }
        
        void push(int x) {
            int sz=q.size();
            q.push(x);
            for (int i=0; i<sz; i++) {
                int y=q.front();
                q.push(y);
                q.pop();
            }
        }
        
        int pop() {
            int x=q.front();
            q.pop();
            return x;
        }
        
        int top() {
            return q.front();
        }
        
        bool empty() {
            if (q.size()==0)
                return true;
            return false;
        }

        int getSize() {
            return q.size();
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
    cout << "Top element is: " << s.top() << endl;

    // Pop elements from the stack
    cout << "Popped: " << s.pop() << endl;
    cout << "Popped: " << s.pop() << endl;

    // Check if stack is empty
    cout << "Is the stack empty? " << (s.empty() ? "Yes" : "No") << endl;

    // Push another element
    s.push(50);
    cout << "Size of the stack: " << s.getSize() << endl;

    return 0;
}
