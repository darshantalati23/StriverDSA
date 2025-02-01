#include <bits/stdc++.h>
using namespace std;
#define ll long long

void bbls(vector<ll> &v, int n) {
    for (int i=0; i<n-1; i++) {
        if (v[i] > v[i+1]) {
            ll temp=v[i];
            v[i]=v[i+1];
            v[i+1]=temp;
        }
    }

    if (n>1)
        bbls(v, n-1);
}

int main() {
    int n;
    cin >> n;
    vector<ll> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    bbls(v, n);

    for (int i = 0; i < n; i++) cout << v[i] << " ";
    return 0;
}
