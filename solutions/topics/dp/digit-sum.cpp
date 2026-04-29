// https://atcoder.jp/contests/dp/tasks/dp_s

#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int MOD = 1e9 + 7;

int dp[10001][101][2];
vector<int> num;
int d;

int rec(int i, int rem, int less) {
    if (i == num.size()) return rem == 0;
    if (dp[i][rem][less] != -1) return dp[i][rem][less];

    int lim = less ? 9 : num[i];

    ll ret = 0;
    for (int digit = 0; digit <= lim; digit++) {
        ret = (ret + rec(i+1, (rem + digit) % d, less || digit < num[i])) % MOD;
    }

    return dp[i][rem][less] = ret;
}

void solve() {
    string k; cin >> k;
    cin >> d;
    num.resize(k.size());
    for (int i = 0; i < num.size(); i++) {
        num[i] = (k[i] - '0');
    }
    memset(dp, -1, sizeof(dp));
    cout << (rec(0, 0, 0) - 1 + MOD) % MOD << endl;
}

int main() {
    // int t; cin >> t;
    // while (t--)
        solve();
    return 0;
}
