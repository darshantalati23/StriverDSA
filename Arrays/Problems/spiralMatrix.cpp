/**
 * Problem Statement: Given a Matrix, print the given matrix in spiral order.
 * 
 * Time Complexity: O(n*m) -> no of elements
 * Space Complexity: O(1)
 */

#include <bits/stdc++.h>
using namespace std;
#define in(T, x) T x; cin >> x
#define in2(T, x, y) T x, y; cin >> x >> y
#define outl(y) cout << y << endl
#define outsp(y) cout << y << " "
#define newl cout << endl
#define forl(i, s, e) for(int i=s; i<e; i++)
#define vin(T, v, n) vector<T> v(n); for (int i=0; i<n; i++) cin>>v[i]
#define matrIn(T, mat, n, m) vector<vector<T>> mat(n, vector<T>(m)); for (int i=0; i<n; i++) for (int j=0; j<m; j++) cin >> mat[i][j]
#define vout(T, v) for (auto x: v) cout << x << " "; cout << endl
#define matrOut(T, mat) for (auto x: mat) { for (auto y: x) cout << y << " "; cout << endl; }


void spiralMat(vector<vector<int>>& arr, int n, int m) {
    int top = 0, bottom = n - 1;
    int left = 0, right = m - 1;

    while (top <= bottom && left <= right) {
        // Traverse from Left to Right
        for (int j = left; j <= right; j++) {
            cout << arr[top][j] << " ";
        }
        top++;

        // Traverse from Top to Bottom
        if (top <= bottom) {
            for (int i = top; i <= bottom; i++) {
                cout << arr[i][right] << " ";
            }
            right--;
        }

        // Traverse from Right to Left
        if (left <= right && top <= bottom) {
            for (int j = right; j >= left; j--) {
                cout << arr[bottom][j] << " ";
            }
            bottom--;
        }

        // Traverse from Bottom to Top
        if (top <= bottom && left <= right) {
            for (int i = bottom; i >= top; i--) {
                cout << arr[i][left] << " ";
            }
            left++;
        }
    }
    cout << endl;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> arr[i][j];

    spiralMat(arr, n, m);

    return 0;
}