// https://codeforces.com/contest/2085/problem/C

#include <bits/stdc++.h>
#define ll long long int
using namespace std;

ll count_bin_places(ll n) {
    ll count = 0;
    while (n > 0) {
        count++;
        n >>= 1;
    }
    return count;
}

void solve() {
    ll x, y; cin >> x >> y;

    if (x == y) {
        cout << -1 << endl;
        return;
    }

    ll big = max(x, y);
    ll count = count_bin_places(big);

    ll dist = (1LL << count) - big;
    cout << dist << endl;
}

int main() {
    int t; cin >> t;
    while (t--)
        solve();
    return 0;
}
