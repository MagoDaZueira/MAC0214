// https://atcoder.jp/contests/dp/tasks/dp_j

#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int n; cin >> n;
    int a1, a2, a3; a1 = a2 = a3 = 0;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        if (a == 1) a1++;
        if (a == 2) a2++;
        if (a == 3) a3++;
    }

    vector<vector<vector<double>>> dp(n+1, vector<vector<double>>(n+1, vector<double>(n+1)));
    dp[0][0][0] = 0.0;

    for (int k = 0; k <= n; k++) {
        for (int j = 0; j <= n; j++) {
            for (int i = 0; i <= n; i++) {
                int with_sushi = i + j + k;
                if (with_sushi == 0 || with_sushi > n) continue;
                dp[i][j][k] = (1.0*n) / with_sushi;
                if (i) dp[i][j][k] += dp[i-1][j][k] * i / with_sushi;
                if (j) dp[i][j][k] += dp[i+1][j-1][k] * j / with_sushi;
                if (k) dp[i][j][k] += dp[i][j+1][k-1] * k / with_sushi;
            }
        }
    }

    cout << fixed << setprecision(10) << dp[a1][a2][a3] << endl;
}

int main() {
    // int t; cin >> t;
    // while (t--)
        solve();
    return 0;
}
