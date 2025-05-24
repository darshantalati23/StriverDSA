/**
 * Problem Statement: Given a matrix if an element in the matrix is
 * 0 then you will have to set its entire column and row to 0 and then
 * return the matrix.
 * 
 * Brute: Traverse through the matrix, and for every element, check if
 * it is 0 or not. If 0, mark its entire row and column as -1 (diff so 
 * as to avoid mixing of original and new 0s). Finally, traverse the
 * matrix again, and for every element, if it is -1, make it 0.
 * 
 * Time Complexity: O(n^3); O((n*m)*(n+m) + (n*m))
 * Space Complexity: O(1)
 * 
 * Better: Create two matrices, one for rows and one for columns.
 * Traverse the matrix, and for every element if it is 0, mark that row
 * and column for 1. Finally, traverse the matrix again, and for every
 * elements, if row and column both are 0, make the element 1; else 0.
 * 
 * Time Complexity: O(n*m)
 * Space Complexity: O(n+m)
 *       - - - -
 *      |0|1|1|1|
 *       - - - -
 *  -    - - - -
 * |0|  |1|1|1|1|
 * |0|  |1|1|1|1|
 * |1|  |1|0|1|0|
 * |1|  |1|1|0|1|
 * |0|  |1|1|1|1|
 *  -    - - - -
 *       - - - -
 *      |0|1|1|1|
 *       - - - -
 *  -    - - - -
 * |0|  |1|0|0|0|
 * |0|  |1|0|0|0|
 * |1|  |0|0|0|0|
 * |1|  |0|0|0|0|
 * |0|  |1|0|0|0|
 *  -    - - - -
 * 
 * Optimal Approach: We can use the 1st row and 1st column to mark that
 * particular rwo and column resp., if any element is 0. Because 1st element
 * of the 1st row and 1st column is same, we use another variable to mark
 * the first element of column. BINGO!
 * 
 * Time Complexity: O(n*m)
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

void setMatrix(vector<vector<int>> &arr, int n, int m) {
    // int col[m] = {0} -> matrix[0][...]
    // int row[n] = {0} -> matrix[...][0]
    int col0 = 1;
    forl(i, 0, n) {
        forl(j, 0, m) {
            if (arr[i][j]==0) {
                // mark i-th row
                arr[i][0] = 0;
                // mark j-th col
                if (j!=0) {
                    arr[0][j]=0;
                } else {
                    col0 = 0;
                }
            }
        }
    }

    // We first do the changes for the remaining matrix starting from
    // second row and second col

    forl(i, 1, n) {
        forl(j, 1, m) {
            if (arr[i][j] != 0) {
                // check for row & col
                if (arr[i][0]==0 || arr[0][j]==0) {
                    arr[i][j]=0;
                }
            }
        }
    }

    if (arr[0][0] == 0) {
        forl(j, 0, m) {
            arr[0][j] = 0;
        }
    }

    if (col0==0) {
        forl(i, 0, n) {
            arr[i][0]=0;
        }
    }
}

int main() {
    in2(int, n, m);
    matrIn(int, arr, n, m);

    setMatrix(arr, n, m);

    matrOut(int, arr);
    return 0;
}