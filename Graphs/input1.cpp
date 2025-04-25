#include <bits/stdc++.h>
using namespace std;
#define in(T, x) T x; cin >> x
#define outl(y) cout << y << endl
#define outsp(y) cout << y << " "
#define newl cout << endl

int main() {
    // Only two inputs: nodes and edges
    in(int, n);
    in(int, m);
    int adj[n+1][n+1];
    for (int i=0; i<m; i++) {
        in(int, u);
        in(int, v);
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
    return 0;
}