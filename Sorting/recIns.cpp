#include <bits/stdc++.h>
using namespace std;
#define in(T, x) T x; cin >> x
#define outl(y) cout << y << endl
#define outsp(y) cout << y << " "
#define newl cout << endl

// Time Complexity: O(n^2)
// Space Complexity: O(n)
void recInsertion(vector<int> &v, int i, int n) {
    // Base Case
    if (i==n)
        return;
    // General
    int j=i;
    while (j>0 && v[j-1]>v[j]) {
        swap(v[j-1], v[j]);
        j--;
    }
    recInsertion(v, i+1, n);
}
int main() {
    in(int, n);
    vector<int> v(n);
    for (int i=0; i<n; i++) {
        cin >> v[i];
    }
    recInsertion(v, 0, n);
    outsp("Sorted:");
    for (int i=0; i<n; i++) {
        outsp(v[i]);
    }
    return 0;
}