// https://codeforces.com/problemset/problem/1554/B

#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    ll n, k; cin >> n >> k;
    vector<ll> a(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    
    ll ans = LLONG_MIN;
    for (ll i = max(1LL, n - 10 * k); i <= n; i++) {
        for (ll j = i + 1; j <= n; j++) {
            ans = max(ans, i * j - k * (a[i] | a[j]));
        }
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
