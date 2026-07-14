// https://codeforces.com/problemset/problem/2244/B

#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    ll pref = 0;
    bool can = true;
    for (int i = 0; i < n; i++) {
        ll required = ((ll)(i+1) * (i+2)) / 2;
        pref += a[i];
        if (pref < required) {
            can = false;
            break;
        }
    }
    
    if (can) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while (t--)
        solve();
    return 0;
}
