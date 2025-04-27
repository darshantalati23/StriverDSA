#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<pair<int, int>, int>> q;
        vector<vector<int>> vis(n, vector<int>(m, 0));

        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (grid[i][j]==2) {
                    vis[i][j] = 2;
                    q.push({{i,j},0});
                }
            }
        }

        int t=0;
        int drow[] = {-1,0,1,0}, dcol[] = {0,1,0,-1};
        while (!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int tm = q.front().second;
            t = max(t, tm);
            q.pop();

            for (int i=0; i<4; i++) {
                int nrow = r + drow[i];
                int ncol = c + dcol[i];
                if (nrow>=0 && ncol>=0 && nrow<n && ncol<m && 
                    vis[nrow][ncol]!=2 && grid[nrow][ncol]==1) {
                    q.push({{nrow, ncol}, tm+1});
                    vis[nrow][ncol] = 2;
                }
            }
        }

        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (grid[i][j] == 1 && vis[i][j] != 2) return -1;
            }
        }
        return t;
    }
};

vector<vector<int>> inputGrid() {
    int n, m;
    cin>>n>>m;

    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
    return grid;
}

int main() {
    vector<vector<int>> grid = inputGrid();

    Solution sol;
    int result = sol.orangesRotting(grid);
    cout << result << endl;

    return 0;
}
