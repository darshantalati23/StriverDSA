/**
 * Question: Given an array and a sum k, we need to print 
   the length of the longest subarray that sums to k (ONLY positive numbers).

 * Brute: 
    Here, in this approach, we are going to generate all possible subarrays to solve this problem.

    We will select all possible starting indices(say i) and all possible ending 
    indices(say j) to generate all possible subarrays. The possible starting indices 
    i.e. i can vary from index 0 to index n-1(i.e. The last index). For every index i, 
    the possible ending index j can vary from i to n-1.
    Time Complexity: O(N3) approx., where N = size of the array.
    Reason: We are using three nested loops, each running approximately N times.

    Space Complexity: O(1) as we are not using any extra space.

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