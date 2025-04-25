#include <bits/stdc++.h>
using namespace std;
#define in(T, x) T x; cin >> x
#define outl(y) cout << y << endl
#define outsp(y) cout << y << " "
#define newl cout << endl

/*
    1
   / \
  2   3
 /\   /
 5-7 8
 \  /
  6 4
*/

void dfs(int b, vector<int> adj[]) {
    vector<bool> vis(b+1, false);
    stack<pair<int, vector<int>>> st;
    vis[1] = true;
    st.push({1, adj[1]});
    while (!st.empty()) {
        outsp(st.top().first);
        vector<int> v = st.top().second;
        st.pop();
        for (auto it : v) {
            if (!vis[it]) {
                st.push({it, adj[it]});
                vis[it] = true;
            }
        }
    }
    return;
}
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
    dfs(n, adj);
    return 0;
}