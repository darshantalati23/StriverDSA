/**
 * Problem Statement: You are given an array of prices where prices[i]
 * is the price of a given stock on an ith day.
 * 
 * Brute: Try all combinations of buying and selling (O(n^2))
 * 
 * Optimal Approach:
 *  ---------
 * |8|1|2|7|4|
 *  ---------
 * mn-^   ^--cur
 * We need to find min element before the current one.
 * We can thus find the max. cost by updating min and maxProfit.
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
#define forl(i, s, e) for(int i=s; i<e; i++)

int maxProfit(vector<int> &arr, int n) {
    int mini = arr[0];
    int maxPro = 0;
    forl(i, 0, n) {
        int cost = arr[i] - mini;
        maxPro = max(cost, maxPro);
        mini = min(mini, arr[i]);
    }
    return maxPro;
}

int main() {
    in(int, n);
    vin(int, arr, n);

    int maxP=maxProfit(arr, n);

    cout << "Maximum Profit = " << maxP << endl;
}