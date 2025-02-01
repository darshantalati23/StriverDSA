#include <bits/stdc++.h>
using namespace std;
#define ll long long

void merge(vector<ll>& v, int low, int mid, int high) {
    vector<ll> temp;
    int p1 = low, p2 = mid + 1;

    // Merge the two sorted halves into `temp`
    while (p1 <= mid && p2 <= high) {
        if (v[p1] <= v[p2]) {
            temp.push_back(v[p1]);
            p1++;
        } else {
            temp.push_back(v[p2]);
            p2++;
        }
    }

    // Add remaining elements from the first half
    while (p1 <= mid) {
        temp.push_back(v[p1]);
        p1++;
    }

    // Add remaining elements from the second half
    while (p2 <= high) {
        temp.push_back(v[p2]);
        p2++;
    }

    // Copy merged elements back into the original vector
    for (int i = low; i <= high; i++) {
        v[i] = temp[i - low];
    }
}

void mergeSort(vector<ll>& v, int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;

        // Recursively sort the first half and the second half
        mergeSort(v, low, mid);
        mergeSort(v, mid + 1, high);

        // Merge the sorted halves
        merge(v, low, mid, high);
    }
}

int main() {
    int n;
    cin >> n;
    vector<ll> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    mergeSort(v, 0, n - 1);

    for (int i = 0; i < n; i++) cout << v[i] << " ";
    return 0;
}
