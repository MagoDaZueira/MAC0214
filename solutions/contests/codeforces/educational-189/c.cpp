// https://codeforces.com/contest/2225/problem/C

#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int costHorizontal(vector<vector<char>>& grid, int i) {
    return (grid[i][0] != grid[i-1][0]) + (grid[i][1] != grid[i-1][1]);
}
int costVertical(vector<vector<char>>& grid, int i) {
    return grid[i][0] != grid[i][1];
}

void solve() {
    int n; cin >> n;
    vector<vector<char>> grid(n, vector<char>(2));
    for (int j = 0; j < 2; j++) {
        for (int i = 0; i < n; i++) {
            cin >> grid[i][j];
        }
    }

    
    vector<int> dp(n);
    
    dp[0] = grid[0][0] != grid[0][1];

    if (n == 1) {
        cout << dp[0] << endl;
        return;
    }

    dp[1] = min(costHorizontal(grid, 1), dp[0] + costVertical(grid, 1));
    for (int i = 2; i < n; i++) {
        dp[i] = min(dp[i-2] + costHorizontal(grid, i), dp[i-1] + costVertical(grid, i));
    }

    cout << dp[n-1] << endl;
}

int main() {
    int t; cin >> t;
    while (t--)
        solve();
    return 0;
}
