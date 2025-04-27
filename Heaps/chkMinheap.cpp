#include <bits/stdc++.h>
using namespace std;
#define in(T, x) T x; cin >> x
#define outl(y) cout << y << endl
#define outsp(y) cout << y << " "
#define newl cout << endl

bool chkMinHp(vector<int>& arr, int n, int i) {
    if (arr[i] <= arr[2*i + 1] && arr[i] <= arr[2*i + 2]) {
        return true;
    }
    return false;
}

pair<vector<int>, int> input() {
    vector<int> arr;
    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        int x;
        cin >> x;
        arr.push_back(x);
    }
    return make_pair(arr, n);
}

int main() {
    auto [arr, n] = input();

    for (int i = n/2 - 1; i>=0; i--) {
        if (!chkMinHp(arr, n, i)) {
            cout << "Not a min heap" << endl;
            return 0;
        }
    }
    cout << "Min Heap !!" << endl;
    return 0;
}