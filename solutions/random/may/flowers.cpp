// https://codeforces.com/problemset/problem/474/D

#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int MAXN = 1e5 + 1;
const int MOD = 1e9 + 7;

void solve() {
    int t, k; cin >> t >> k;

    vector<ll> dp(MAXN);
    dp[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        dp[i] = dp[i-1];
        if (i - k >= 0) dp[i] = (dp[i] + dp[i-k]) % MOD;
    }

    vector<int> pref(MAXN);
    pref[0] = dp[0];
    for (int i = 1; i < MAXN; i++) {
        pref[i] = (pref[i-1] + dp[i]) % MOD;
    }

    while (t--) {
        int a, b; cin >> a >> b;
        cout << (pref[b] - pref[a-1] + MOD) % MOD << endl;
    }
}

int main() {
    // int t; cin >> t;
    // while (t--)
        solve();
    return 0;
}
