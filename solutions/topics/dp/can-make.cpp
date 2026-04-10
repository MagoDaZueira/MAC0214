// https://codeforces.com/contest/687/problem/C

#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int n, k; cin >> n >> k;
    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }

    vector<vector<vector<bool>>> dp(n, vector<vector<bool>>(k + 1, vector<bool>(k + 1, false)));
    for (int i = 0; i < n; i++) {
        dp[i][0][0] = true;
    }

    if (c[0] <= k) dp[0][c[0]][c[0]] = true;
    if (c[0] <= k) dp[0][c[0]][0] = true;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= k; j++) {
            for (int r = 0; r <= k; r++) {
                dp[i][j][r] = dp[i-1][j][r];
                if (j - c[i] >= 0) {
                    dp[i][j][r] = dp[i][j][r] || dp[i-1][j-c[i]][r];
                    if (r - c[i] >= 0) dp[i][j][r] = dp[i][j][r] || dp[i-1][j-c[i]][r-c[i]];
                }
            }
        }
    }

    int count = 0;
    for (int i = 0; i <= k; i++) {
        count += dp[n-1][k][i];
    }
    
    cout << count << endl;
    for (int i = 0; i <= k; i++) {
        if(dp[n-1][k][i]) cout << i << " ";
    }
}

int main() {
    // int t; cin >> t;
    // while (t--)
        solve();
    return 0;
}
