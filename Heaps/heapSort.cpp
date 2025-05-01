#include <bits/stdc++.h>
using namespace std;
#define in(T, x) T x; cin >> x
#define outl(y) cout << y << endl
#define outsp(y) cout << y << " "
#define newl cout << endl

void heapify(vector<int> &arr, int n, int i) {
    int largest = i;          // Initialize largest as root
    int left = 2*i + 1;        // left = 2*i + 1
    int right = 2*i + 2;       // right = 2*i + 2

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // If right child is larger than largest so far
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest); // Recursively heapify the affected subtree
    }
}

void heapSort(vector<int> &arr, int n) {
    // Step 1: Build a max heap
    for (int i = n/2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    for (int i=0; i<n; i++) {
        outsp(arr[i]);
    }
    newl;

    // Step 2: One by one extract elements
    for (int i = n-1; i >= 0; i--) {
        swap(arr[0], arr[i]); // Move current root to end
        heapify(arr, i, 0);   // call max heapify on the reduced heap
    }
}
pair<vector<int>, int> input() {
    vector<int> arr;
    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        int x;
        cin >> x;
        arr.push_back(x);
    }
    return make_pair(arr, n);
}

int main() {
    auto [arr, n] = input();

    heapSort(arr, arr.size());

    // Print sorted array
    for (int i=0; i<n; i++) {
        outsp(arr[i]);
    }
    newl;

    return 0;
}