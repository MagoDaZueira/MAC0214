// https://cses.fi/problemset/task/1745

#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    string s, t; cin >> s >> t;
    int n = s.size(), m = t.size();

    vector<vector<int>> dp(n+1, vector<int>(m+1));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            if (s[i-1] == t[j-1]) {
                dp[i][j] = max(dp[i][j], dp[i-1][j-1] + 1);
            }
        }
    }

    int i = n, j = m;
    string ans = "";
    while (i > 0 && j > 0) {
        if (s[i-1] == t[j-1]) {
            ans += s[i-1];
            i--; j--;
        }
        else if (dp[i-1][j] > dp[i][j-1]) {
            i--;
        }
        else {
            j--;
        }
    }

    reverse(ans.begin(), ans.end());
    cout << ans << endl;
}

int main() {
    // int t; cin >> t;
    // while (t--)
        solve();
    return 0;
}
