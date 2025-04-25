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
    vector<int> adj[n+1];
    for (int i=0; i<m; i++) {
        in(int, u);
        in(int, v);
        adj[u].push_back(v);
        adj[v].push_back(u); // not required if directed graph (u --> v)
    }
    return 0;
}