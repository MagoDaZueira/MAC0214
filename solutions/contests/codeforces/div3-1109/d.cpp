// https://codeforces.com/problemset/problem/2244/D

#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    ll n, m; cin >> n >> m;
    vector<ll> a(n+1);
    vector<ll> b(m);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    
    sort(b.begin(), b.end());

    int i, j = 0;
    ll intervalSum = 0;
    ll ans = 0;
    for (i = 1; j < m; i++) {
        intervalSum += a[i];
        if (i == b[j]) {
            ans += abs(intervalSum);
            intervalSum = 0;
            j++;
        }
    }

    for (; i <= n; i++) {
        ans += a[i];
    }

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while (t--)
        solve();
    return 0;
}
