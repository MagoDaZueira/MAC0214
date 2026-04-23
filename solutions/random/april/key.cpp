// https://codeforces.com/problemset/problem/1703/G

#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    ll ans = 0;
    ll pref = 0;
    for (int i = 0; i < n; i++) {
        ll suf = 0;
        int div = 2;
        int lim = min(i + 31, n);
        for (int j = i; j < lim; j++) {
            suf += a[j] / div;
            div *= 2;
        }
        ans = max(ans, pref + suf);
        pref += a[i] - k;
    }
    ans = max(ans, pref);

    cout << ans << endl;
}

int main() {
    int t; cin >> t;
    while (t--)
        solve();
    return 0;
}
