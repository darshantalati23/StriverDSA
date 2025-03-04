#include <iostream>
#include <stack>

class Queue {
public:
    std::stack<int> smn, ssb;

    void push(int x) {
        smn.push(x);
    }

    int pop() {
        if (ssb.empty()) {
            while (!smn.empty()) {
                ssb.push(smn.top());
                smn.pop();
            }
        }
        if (ssb.empty()) {
            return -1; // Or throw an exception, indicating an empty queue
        }
        int x = ssb.top();
        ssb.pop();
        return x;
    }

    int front() {
        if (ssb.empty()) {
            while (!smn.empty()) {
                ssb.push(smn.top());
                smn.pop();
            }
        }
        if (ssb.empty()) {
            return -1; // Or throw an exception, indicating an empty queue
        }
        return ssb.top();
    }

    bool empty() {
        return smn.empty() && ssb.empty();
    }

    int getSize() {
        return smn.size() + ssb.size();
    }
};

int main() {
    Queue s;
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        switch (n) {
            case 1: {
                int x;
                std::cin >> x;
                s.push(x);
                break;
            }
            case 2: {
                if (!s.empty()) {
                    s.pop();
                }
                break;
            }
            case 3: {
                if (!s.empty()) {
                    std::cout << s.front() << std::endl;
                }
                break;
            }
        }
    }
    return 0;
}