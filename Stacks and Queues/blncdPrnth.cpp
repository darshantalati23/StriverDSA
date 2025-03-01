#include <bits/stdc++.h>
using namespace std;
#define ll long long
bool isOpening(char ch) {
    if (ch == '('||ch == '['||ch == '{')
        return true;
    return false;
}
char cntrBkt(char ch) {
    if (ch == '(')
        return ')';
    else if (ch == '[')
        return ']';
    return '}';
}
void balPar() {
    string s;
    cin>>s;
    stack<char> st;
    for (auto it: s) {
        if (isOpening(it))
            st.push(cntrBkt(it));
        else {
            if (st.size()==0||st.top()!=it) { // IMP: always incl "st.size()==0"
                cout << "NO" << endl;
                return;
            } else
                st.pop();
        }
    }
    if (st.size()==0)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}
int main() {
    int t=1;
    cin>>t;
    while (t--) balPar();
}