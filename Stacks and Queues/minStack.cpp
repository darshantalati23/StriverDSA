/**
 * Method 1:
 * Make two stacks
 * One pushes values and other the minimums
 * 
 * Method 2:
 * stack<pair<int, int>> s
 *    value----^    ^----min
 * We keep on updating the min with each push
 * s.push(make_pair(n, min(s.top().second, n)))
 * 
 * Method 3: Apply Maths ;)
 * Ex:
 * > push 12
 * > push 15
 * > push 10
 * > getMin
 * > pop
 * > getMin
 * 
 * Implementation:
 * mini = 12, 10
 * ------------
 * | 12 15 8    -> Stack of newVal
 * ------------
 * if n < mini DO
 *  2*val - mini = newVal
 *  mini = n
 * endif
 * 
 * Now, to retrive previous min element during pop.
 * 
 * WHY??
 * If,
 *  val < mini
 *  val-mini < 0
 *  2*val-mini < val --> Main condition used for mini and val
*/

#include <bits/stdc++.h>
using namespace std;

class MinStack {
    stack<int> st;
    int mini;
public:
    void push(int val) {
        if(st.empty()) {
            mini=val;
            st.push(val);
        } else {
            if (val>mini)
                st.push(val);
            else {
                st.push(2*val-mini);
                mini=val;
            }
        }
    }

    void pop() {
        if (st.empty())
            return;
        int n=st.top();
        st.pop();
        if (n<mini)
            mini = 2*mini - n;
    }

    int top() {
        int n=st.top();
        if (mini<n) return n;
        else return mini;
    }

    int getMin() {
        return mini;
    }

    void print() {
        stack<int> cpy=st;
        while (!cpy.empty()) {
            cout << cpy.top() << " ";
            cpy.pop();
        }
    }
};

int main() {
    MinStack s;
    int t;
    cin>>t;
    while (t--) {
        int op;
        cin>>op;
        switch (op) {
            case 1:
                int val;
                cin>>val;
                s.push(val);
                break;
            case 2:
                s.pop();
                break;
            case 3:
                cout << s.top() << endl;
                break;
            case 4:
                cout << s.getMin() << endl;
                break;
            default:
                s.print();
                cout << endl;
                break;
        }
    }
}