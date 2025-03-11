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

void postf_inf(string s) {
    stack<string> st;
    string ans = "";
    
    for (int i = 0; i < s.length(); i++) {
        if (isalnum(s[i])) {  // Operand
            ans = string(1, s[i]);  // Convert character to string
            st.push(ans);
        } else {  // Operator
            if (!st.empty()) {
                string b = st.top();  // Get the first operand
                st.pop();
                string a = st.top();  // Get the second operand
                st.pop();
                // Form a valid infix expression with parentheses
                ans = "(" + a + s[i] + b + ")";
                st.push(ans);  // Push the result back to stack
            }
        }
    }
    
    // The final answer will be at the top of the stack
    cout << st.top() << endl;
}

void pref_inf(string s) {
    stack<string> st;
    string ans = "";
    
    for (int i = s.length()-1; i >= 0; i--) {
        if (isalnum(s[i])) {  // Operand
            ans = string(1, s[i]);  // Convert character to string
            st.push(ans);
        } else {  // Operator
            if (!st.empty()) {
                string a = st.top();  // Get the first operand
                st.pop();
                string b = st.top();  // Get the second operand
                st.pop();
                // Form a valid infix expression with parentheses
                ans = "(" + a + s[i] + b + ")";
                st.push(ans);  // Push the result back to stack
            }
        }
    }
    
    // The final answer will be at the top of the stack
    cout << st.top() << endl;
}

void postf_pref(string s) {
    stack<string> st;
    string ans = "";
    
    for (int i = 0; i < s.length(); i++) {
        if (isalnum(s[i])) {  // Operand
            ans = string(1, s[i]);  // Convert character to string
            st.push(ans);
        } else {  // Operator
            if (!st.empty()) {
                string b = st.top();  // Get the first operand
                st.pop();
                string a = st.top();  // Get the second operand
                st.pop();
                // Form a valid infix expression with parentheses
                ans = s[i] + a + b;
                st.push(ans);  // Push the result back to stack
            }
        }
    }
    
    // The final answer will be at the top of the stack
    cout << st.top() << endl;
}

void pref_postf(string s) {
    stack<string> st;
    string ans = "";
    
    for (int i = s.length()-1; i >= 0; i--) {
        if (isalnum(s[i])) {  // Operand
            ans = string(1, s[i]);  // Convert character to string
            st.push(ans);
        } else {  // Operator
            if (!st.empty()) {
                string a = st.top();  // Get the first operand
                st.pop();
                string b = st.top();  // Get the second operand
                st.pop();
                // Form a valid infix expression with parentheses
                ans = a + b + s[i];
                st.push(ans);  // Push the result back to stack
            }
        }
    }
    
    // The final answer will be at the top of the stack
    cout << st.top() << endl;
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
        else if (conv==3)
            postf_inf(s);
        else if (conv==4)
            pref_inf(s);
        else if (conv==5)
            postf_pref(s);
        else
            pref_postf(s);
    }
}
