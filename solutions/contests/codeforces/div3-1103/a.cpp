// https://codeforces.com/problemset/problem/2236/A

#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    ll n; cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    int big = 0;
    int small = INT_MAX;
    for (int h : a) {
        big = max(big, h);
        small = min(small, h);
    }

    cout << big - small + 1 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while (t--)
        solve();
    return 0;
}
