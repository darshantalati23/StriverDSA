/**
 * Problem Statement: Given an array consisting of only 0s, 1s, and 2s.
 * Write a program to in-place sort the array without using inbuilt sort functions.
 * (Expected: Single pass-O(N) and constant space)
 * 
 * Brute: Manual Sorting (O(nlogn))
 * 
 * Better: Count number of 0's, 1's and 2's and then change the original array (O(2n))
 * 
 * Optimal Approach:
 *  ---------------
 * |   |   |   |   |
 *  ---------------
 *   I  II  III  IV
 * I: low - all 0's
 * II: mid - all 1's
 * III: mid <-> high - mixed bag ----> Target: sort these elements & shorten this segment
 * IV: high - all 2's
 * 
 * DUTCH NATIONAL FLAG ALGORITHM
 * 
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */

#include <bits/stdc++.h>
using namespace std;
#define in(T, x) T x; cin >> x
#define outl(y) cout << y << endl
#define outsp(y) cout << y << " "
#define newl cout << endl
#define vin(T, v, n) vector<T> v(n); for (int i=0; i<n; i++) cin>>v[i]

void sort012(vector<int> &arr, int n) {
    int low=0, mid=0, high=n-1;
    while(mid<=high) {
        if (arr[mid]==0) {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if (arr[mid]==1) {
            mid++;
        }
        else {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
    return;
}

int main() {
    in(int, n);
    vin(int, arr, n);

    sort012(arr, n);

    for (int i=0; i<n; i++) {
        outsp(arr[i]);
    }
}