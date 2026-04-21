// https://codeforces.com/contest/2225/problem/A

#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void solve() {
    ll x, y; cin >> x >> y;
    cout << (2 * x == y ? "NO" : "YES") << endl;
}

int main() {
    int t; cin >> t;
    while (t--)
        solve();
    return 0;
}
