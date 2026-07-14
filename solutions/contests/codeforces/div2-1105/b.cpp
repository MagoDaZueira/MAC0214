// https://codeforces.com/problemset/problem/2240/B

#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int MOD = 998244353;
const int MOD1 = 998244353 - 1;

ll fastPow(ll base, ll exp) {
    if (exp == 0) return 1;
    base %= MOD;
    ll half = fastPow(base, exp / 2);
    ll half_sq = (half * half) % MOD;
    
    if (exp % 2 == 0) {
        return half_sq;
    } else {
        return (half_sq * base) % MOD;
    }
}

void solve() {
    ll n, m, r, c; 
    cin >> n >> m >> r >> c;
    
    ll cells = (n * m) % MOD1;
    ll windows = ((n - r + 1) * (m - c + 1)) % MOD1;
    ll exp = (cells - windows + MOD1) % MOD1;
    
    cout << fastPow(2, exp) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while (t--)
        solve();
    return 0;
}
