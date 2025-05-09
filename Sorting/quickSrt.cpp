#include <bits/stdc++.h>
using namespace std;
#define in(T, x) T x; cin >> x
#define outl(y) cout << y << endl
#define outsp(y) cout << y << " "
#define newl cout << endl

/**
 * Time Complexity : O(n^2)
 * Space Complexity : O(1)
 */
int part_f(vector<int> &v, int low, int high) {
    int pivot = low, i = low, j = high;

    while (i<j) {
        while (v[i]<=v[pivot] && i<=high) {
            i++;
        }
        while (v[j]>v[pivot] && j>=low) {
            j--;
        }
        if (i<j)
            swap(v[i], v[j]);
    }
    swap(v[low], v[j]);
    return j;
}

void quickSort(vector<int> &v, int low, int high) {
    if (low<high) {
        int partInd=part_f(v, low, high);
        quickSort(v, low, partInd-1);
        quickSort(v, partInd+1, high);
    }
}

int main() {
    in(int, n);
    vector<int> v(n);
    for (int i=0; i<n; i++) {
        cin >> v[i];
    }
    quickSort(v, 0, n-1);
    outsp("Sorted:");
    for (int i=0; i<n; i++) {
        outsp(v[i]);
    }
    return 0;
}