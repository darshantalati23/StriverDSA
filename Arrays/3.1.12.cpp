/**
 * Question: Given an array and a sum k, we need to print 
   the length of the longest subarray that sums to k (ONLY positive numbers).

 * Brute: 
    

 * Better:
    

 * Optimal:
    
 */

#include <bits/stdc++.h>
using namespace std;

void solve(vector<int>& v, int sum) {
    int i=0, j=0, s=v[0], l=0, ml=0;
    while (i<=j && j<v.size()) {
        if (s==sum) {
            l=j-i+1;
            i++;
            if (v[i-1]!=0)
                j++;
        } else if (s<sum) {
            if (j>=v.size())
                break;
            j++;
            s+=v[j];
        } else {
            i++;
            s-=v[i];
        }

        ml=max(l, ml);
    }
    cout << ml << endl;
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i=0; i<n; i++) cin>>arr[i];

    int sum;
    cin >> sum;

    solve(arr, sum);
    
    return 0;
}