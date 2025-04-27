#include <bits/stdc++.h>
using namespace std;
#define in(T, x) T x; cin >> x
#define outl(y) cout << y << endl
#define outsp(y) cout << y << " "
#define newl cout << endl

void minheapify(vector<int>& arr, int n, int i) {
    int smallest = i;
    int lc = 2*i + 1;
    int rc = 2*i + 2;

    if (lc < n && arr[lc] < arr[smallest])
        smallest = lc;
    if (rc < n && arr[rc] < arr[smallest])
        smallest = rc;
    if (smallest != i) {
        swap(arr[i], arr[smallest]);
        minheapify(arr, n, smallest);
    }    
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

    for (int i = n/2; i>=0; i++) {
        minheapify(arr, n, i);
    }

    // Print sorted array
    for (int i=0; i<n; i++) {
        outsp(arr[i]);
    }
    cout << endl;

    return 0;
}