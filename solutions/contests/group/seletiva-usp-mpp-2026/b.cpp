#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void solve() {
    vector<vector<char>> dice(16, vector<char>(6));
    for (int j = 0; j < 6; j++) {
        for (int i = 0; i < 16; i++) {
            cin >> dice[i][j];
        }
    }

    vector<int> cost = {0, 1, 1, 1, 1, 2};

    vector<vector<int>> dp(16, vector<int>(6, INT_MAX));
    for (int j = 0; j < 6; j++) {
        dp[0][j] = cost[j];
    }

    for (int i = 1; i < 16; i++) {
        for (int j = 0; j < 6; j++) {
            for (int k = 0; k < 6; k++) {
                if (dice[i][j] < dice[i-1][k]) continue;
                if (dp[i-1][k] == INT_MAX) continue;
                dp[i][j] = min(dp[i][j], dp[i-1][k] + cost[j]);
            }
            if (dice[i][j] == 'Q') dice[i][j] = 'U';
        }
    }

    int ans = INT_MAX;
    for (int j = 0; j < 6; j++) {
        ans = min(ans, dp[15][j]);
    }

    if (ans == INT_MAX) cout << "impossible" << endl;
    else                cout << ans << endl;
}

int main() {
    // int t; cin >> t;
    // while (t--)
        solve();
    return 0;
}
