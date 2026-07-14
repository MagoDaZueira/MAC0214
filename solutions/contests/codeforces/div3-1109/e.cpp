// https://codeforces.com/problemset/problem/2244/E

#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    ll n, q; cin >> n >> q;
    string s; cin >> s;

    vector<int> pref(n+1, 0);
    for (int i = 2; i <= n; i++) {
        pref[i] = pref[i-1] + (s[i-2] == s[i-1]);
    }

    while (q--) {
        int l, r, k; cin >> l >> r >> k;
        int errors = pref[r] - pref[l];
        if (k >= ceil(errors / 2.0)) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
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
