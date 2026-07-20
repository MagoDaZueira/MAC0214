// https://codeforces.com/problemset/problem/2074/D

#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int n, m; cin >> n >> m;
    vector<ll> x(n), r(n);
    for (int i = 0; i < n; i++) cin >> x[i];
    for (int i = 0; i < n; i++) cin >> r[i];

    map<ll, ll> xToMaxY;
    for (int i = 0; i < n; i++) {
        for (ll curX = x[i]-r[i]; curX <= x[i]+r[i]; curX++) {
            xToMaxY[curX] = max(xToMaxY[curX], (ll)sqrt(r[i]*r[i] - (curX-x[i])*(curX-x[i])));
        }
    }

    ll ans = 0;
    for (auto& [_, maxY] : xToMaxY) {
        ans += 2 * maxY + 1;
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
