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

/*
   25
 21  19
15 18 16
*/

class Heap {
public:
int arr[100];
int size=0;

    void insert(int val) {
        size++;
        int ind = size;
        arr[ind] = val;

        while (ind > 1) {
            int prt = ind/2;

            if (arr[prt] < arr[ind]) {
                swap(arr[prt], arr[ind]);
                ind=prt;
            } else {
                break;
            }
        }
        return;
    }

    void print() {
        for (int i=0; i<= size; i++) {
            cout << arr[i] << " ";
        }
        newl;
    }

    void del() {
        // Algo: replace root with last element, delete latter, and arrange
        if (!size) {
            outl("Nothing to delete");
            return;
        }
        arr[1]=arr[size];
        size--;

        int i = 1;
        while (i<size) {
            int lc = 2*i, rc = 2*i + 1;
            // Replace with Left child
            if (lc < size && arr[i] < arr[lc]) {
                swap(arr[i], arr[lc]);
                i=lc;
            }
            // Replace with Right child
            else if (rc < size && arr[i] < arr[rc]) {
                swap(arr[i], arr[rc]);
                i=rc;
            }
            // Correct position
            else {
                break;
            }
        }
    }
};

void heapify(int arr[], int n, int i) {
    int lrg = i, left = 2*i, right = 2*i + 1;
    if (left < n && arr[lrg] < arr[left]) {
        lrg = left;
    }
    if (right < n && arr[lrg] < arr[right]) {
        lrg = right;
    }

    if (lrg != i) {
        swap(arr[lrg], arr[i]);
        heapify(arr, n, lrg);
    }
}

int main() {
    Heap h;
    h.insert(25);
    h.insert(21);
    h.insert(19);
    h.insert(18);
    h.insert(15);
    h.insert(16);
    h.print();
    h.del();
    h.print();

    int ar[6] = {-1, 20, 84, 55, 51, 36};
    int n = 5;
    for (int i=n/2; i>0; i--) {
        heapify(ar, n, i);
    }

    for (int i=1; i<=n; i++) {
        cout << ar[i] << " ";
    }
    newl;

    return 0;
}