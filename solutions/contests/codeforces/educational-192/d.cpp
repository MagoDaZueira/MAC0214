// https://codeforces.com/problemset/problem/2242/D

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int lcs(vector<int>& a, vector<int>& b) {
    int n = a.size();
    int m = b.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    a.insert(a.begin(), 0);
    b.insert(b.begin(), 0);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            if (a[i] == b[j]) dp[i][j] = max(dp[i][j], dp[i-1][j-1] + 1);
        }
    }

    return dp[n][m];
}

void solve() {
    string a, b; cin >> a >> b;
    int n = a.size();
    int m = b.size();
    vector<int> prefA(n);
    vector<int> prefB(m);
    prefA[0] = a[0] - '0';
    prefB[0] = b[0] - '0';
    for (int i = 1; i < n; i++) {
        prefA[i] = ((a[i] - '0') + prefA[i-1]) % 10;
    }
    for (int i = 1; i < m; i++) {
        prefB[i] = ((b[i] - '0') + prefB[i-1]) % 10;
    }

    if (prefA[n-1] != prefB[m-1]) {
        cout << -1 << "\n";
        return;
    }

    cout << lcs(prefA, prefB) << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while (t--)
        solve();
    return 0;
}
