// https://codeforces.com/problemset/problem/371/C

#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    string recipe; cin >> recipe;
    vector<ll> n(3);
    vector<ll> p(3);
    vector<ll> m(3);
    cin >> n[0] >> n[1] >> n[2];
    cin >> p[0] >> p[1] >> p[2];
    ll r; cin >> r;

    for (auto c : recipe) {
        if (c == 'B') m[0]++;
        if (c == 'S') m[1]++;
        if (c == 'C') m[2]++;
    }

    ll ans = 0;
    ll lo = 1, hi = 2e14;
    while (lo <= hi) {
        ll mid = lo + (hi - lo) / 2;
        ll money = r;
        for (int i = 0; i < 3; i++) {
            ll needs = m[i] * mid;
            needs -= n[i];
            money -= max(0LL, needs * p[i]);;
        }
        if (money >= 0) {
            ans = mid;
            lo = mid + 1;
        }
        else {
            hi = mid - 1;
        }
    }

    cout << ans << endl;
}

int main() {
    // int t; cin >> t;
    // while (t--)
        solve();
    return 0;
}
