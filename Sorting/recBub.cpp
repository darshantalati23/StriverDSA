#include <bits/stdc++.h>
using namespace std;
#define in(T, x) T x; cin >> x
#define outl(y) cout << y << endl
#define outsp(y) cout << y << " "
#define newl cout << endl

// Time Complexity: O(n^2)
// Space Complexity: O(n)
void recBubble(vector<int> &v, int n) {
    // Base Case
    if (n==1)
        return;
    for (int i=0; i<n-1; i++) {
        if (v[i]>v[i+1])
            swap(v[i], v[i+1]);
    }
    recBubble(v, n-1);
}
int main() {
    in(int, n);
    vector<int> v(n);
    for (int i=0; i<n; i++) {
        cin >> v[i];
    }
    recBubble(v, n);
    outsp("Sorted:");
    for (int i=0; i<n; i++) {
        outsp(v[i]);
    }
    return 0;
}