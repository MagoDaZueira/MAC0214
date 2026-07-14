// https://codeforces.com/problemset/problem/2240/D

#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    ll n, d; cin >> n >> d;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll windowWeights = a[0];
    int i = 1, j = n-1;
    while (i <= d) {
        windowWeights += a[i++] + a[j--];
    }
    ll ans = 0;
    for (i = 0; i < n; i++) {
        ans += max(0LL, a[i] * 2 * d - (windowWeights - a[i]));
        windowWeights -= a[(i-d + n) % n];
        windowWeights += a[(i+d+1) % n];
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
