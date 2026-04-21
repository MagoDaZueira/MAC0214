// https://codeforces.com/contest/2225/problem/D

#include <bits/stdc++.h>
#define ll long long int
using namespace std;

const int MOD = 998244353;

ll countRem(ll k, int r) {
    if (k < 0) return 0;
    ll res = (k / 4) + ((k % 4) >= r);
    return res;
}

void solve() {
    ll n, x; cin >> n >> x;
    
    ll left0 = 1 + countRem(x-1, 3);
    ll left1 = countRem(x-1, 1);
    ll right0 = countRem(n, 3) - countRem(x-1, 3);
    ll right1 = countRem(n, 1) - countRem(x-1, 1);

    ll ans = ((left0 % MOD) * (right0 % MOD)) % MOD;
    ans = (ans + ((left1 % MOD) * (right1 % MOD)) % MOD) % MOD;

    cout << ans << endl;
}

int main() {
    int t; cin >> t;
    while (t--)
        solve();
    return 0;
}
