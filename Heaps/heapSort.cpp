/*
With God's Grace,

 DDD     K   K   TTTTT       EEEEE   K   K     A     N   N   TTTTT  III   K   K
 D  D    K  K      T         E       K  K     A A    NN  N     T     I    K  K
 D   D   KKK       T         EEEE    KKK     AAAAA   N N N     T     I    KKK
 D  D    K  K      T   ____  E       K  K    A   A   N  NN     T     I    K  K
 DDD     K   K     T   ____  EEEEE   K   K   A   A   N   N     T    III   K   K

*/

#include <bits/stdc++.h>
using namespace std;
#define in(T, x) T x; cin >> x
#define outl(y) cout << y << endl
#define outsp(y) cout << y << " "
#define newl cout << endl

/*
If a number is at index 'i':
parent = i/2
left child = 2*i
right child = 2*i + 1
*/

void heapify(int arr[], int n, int i) {
    int lrg = i, left = 2*i, right = 2*i + 1;
    if (left <= n && arr[lrg] < arr[left]) {
        lrg = left;
    }
    if (right <= n && arr[lrg] < arr[right]) {
        lrg = right;
    }

    if (lrg != i) {
        swap(arr[lrg], arr[i]);
        heapify(arr, n, lrg);
    }
}

void heapSort(int arr[], int n) {
    int size=n;
    while (size > 0) {
        // Step 1: Swap root and last last element
        swap(arr[1], arr[size]);
        size--;
        //Step 2: Heapify
        heapify(arr, size, 1);
    }
    for (int i=1; i<=n; i++) {
        outsp(arr[i]);
    }
    newl;
}

int main() {
    int ar[7] = {-1, 30, 84, 55, 51, 36, 25};
    heapSort(ar, 6);
    return 0;
}