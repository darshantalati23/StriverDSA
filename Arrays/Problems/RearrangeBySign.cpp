/**
 * Problem Statement: You are given an array of prices where prices[i]
 * is the price of a given stock on an ith day.
 * 
 * Brute: Traverse once for odd indices and once for even indices,
 * storing them in two diff arrays on n/2 size. +ve elements on 2*n
 * indices of main array and -ve elements on 2*n+1 indices of main.
 * Time Complexity: O(2N)
 * Space Complexity: O(N)
 * 
 * Optimal Approach: Traverse once, and keep putting +ve and -ve
 * directly to main array via two separate pointers
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

vector<int> maxProfit(vector<int> &arr, int n) {
    vector<int> ans(n, 0);
    int pos=0, neg=1;
    forl(i, 0, n) {
        if (arr[i]>=0) {
            ans[pos]=arr[i];
            pos+=2;
        } else {
            ans[neg]=arr[i];
            neg+=2;
        }
    }
    return ans;
}

int main() {
    in(int, n);
    vin(int, arr, n);

    vector<int> ans=maxProfit(arr, n);

    forl(i, 0, n) {
        outsp(ans[i]);
    }
}