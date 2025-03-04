#include <bits/stdc++.h>
using namespace std;
#define ll long long

int prio(char c) {
    switch (c) {
        case '^': return 4;
        case '*': 
        case '/': return 3;
        case '+': 
        case '-': return 2;
        default: return 1;
    }
}

void inf_postf(string s) {
    stack<char> st;
    string ans = "";
    for (int i = 0; i < s.length(); i++) {
        if (isalnum(s[i])) { // If operand
            ans += s[i];
        } else if (s[i] == '(') {
            st.push(s[i]);
        } else if (s[i] == ')') {
            while (!st.empty() && st.top() != '(') {
                ans += st.top();
                st.pop();
            }
            st.pop();
        } else { // Operator
            while (!st.empty() && prio(s[i]) <= prio(st.top())) {
                ans += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while (!st.empty()) {
        ans += st.top();
        st.pop();
    }
    cout << ans << endl;
}

char invBrc(char c) {
    if (c == '(') return ')';
    if (c == ')') return '(';
    return c;
}

string revStr(string s) {
    int n = s.length();
    for (int i = 0; i < n / 2; i++) {
        swap(s[i], s[n - i - 1]);
    }
    for (int i = 0; i < n; i++) {
        s[i] = invBrc(s[i]);
    }
    return s;
}

void inf_pref(string s) {
    stack<char> st;
    string ans = "";
    s = revStr(s);

    for (int i = 0; i < s.length(); i++) {
        if (isalnum(s[i])) { // If operand
            ans += s[i];
        } else if (s[i] == '(') {
            st.push(s[i]);
        } else if (s[i] == ')') {
            while (!st.empty() && st.top() != '(') {
                ans += st.top();
                st.pop();
            }
            st.pop();
        } else { // Operator
            while (!st.empty() && prio(s[i]) < prio(st.top())) {
                ans += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while (!st.empty()) {
        ans += st.top();
        st.pop();
    }
    ans = revStr(ans);
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        int conv;
        cin >> s >> conv;
        if (conv == 1)
            inf_postf(s);
        else if (conv == 2)
            inf_pref(s);
    }
}
