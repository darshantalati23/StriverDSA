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
 / \  /
5  7-8
 \  /
  6-4
*/

void bfs(int b, vector<int> adj[]) {
    vector<bool> vis(b+1, false);
    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        for (int i=0; i<adj[q.front()].size(); i++) {
            if (adj[q.front()][i] && !vis[adj[q.front()][i]]) {
                q.push(adj[q.front()][i]);
                vis[adj[q.front()][i]] = true;
            }
        }
        outsp(q.front());
        q.pop();
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
    bfs(n, adj);
    return 0;
}