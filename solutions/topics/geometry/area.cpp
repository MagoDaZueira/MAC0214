// https://cses.fi/problemset/task/2191

#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int n; cin >> n;
    vector<ll> x(n);
    vector<ll> y(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans += x[i] * y[(i+1)%n] - x[(i+1)%n] * y[i];
    }
    cout << abs(ans) << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // int t; cin >> t;
    // while (t--)
        solve();
    return 0;
}
