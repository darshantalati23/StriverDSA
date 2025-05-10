/**
 * Problem Statement: Given an array of N integers,
 * write a program to return an element that occurs more than N/2 times in the
 * given array. You may consider that such an element always exists in the array.
 * 
 * Brute: traverse the array, and for every element, traverse the entire array again
 * to check if freq > n/2. (O(n^2))
 * 
 * Better: Use HashMap (TC: O(nlogn)+O(n) and SC: O(n))
 * After storing elements in map,
 * //searching for the majority element:
    for (auto it : mpp) {
        if (it.second > (n / 2)) {
            return it.first;
        }
    }
 * 
 * Optimal Approach: Moore's Voting Algorithm
 * We first take the initial element (ele), then we traverse array with a ptr.
 * If we find the same element again, then cnt++; if any other element, cnt--.
 * If cnt=0, ptr++ and ele = arr[ptr]. If at the end, cnt>0, then ele is the
 * majority element, ONLY IF SUCH A MAJORITY ELEMENT EXISTS.
 * So, run a loop once to check it's frequency.
 * 
 * Time Complexity: O(n) + O(n)
 * Space Complexity: O(1)
 */

#include <bits/stdc++.h>
using namespace std;
#define in(T, x) T x; cin >> x
#define outl(y) cout << y << endl
#define outsp(y) cout << y << " "
#define newl cout << endl
#define vin(T, v, n) vector<T> v(n); for (int i=0; i<n; i++) cin>>v[i]

int majEle(vector<int> &arr, int n) {
    int ele=arr[0], cnt=1;
    for (int i=0; i<n; i++) {
        if (arr[i]==ele) {
            cnt++;
        } else {
            cnt--;
            if (!cnt) {
                if (i != n-1)
                    ele=arr[i+1];
                else
                    break;
            }
        }
    }
    if (cnt > 0) {
        int ce=0;
        for (int i=0; i<n; i++) {
            if (arr[i]==ele)
                ce++;
        }
        if (ce > n/2)
            return ele;
        else
            return -1;
    }
    return -1;
}

int main() {
    in(int, n);
    vin(int, arr, n);

    int me = majEle(arr, n);

    if (me==-1)
        cout << "Majority Element does not exist." << endl;
    else
        cout << "Majority Element = " << me << endl;
}