// https://cses.fi/problemset/task/1745

#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int n; cin >> n;
    vector<int> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    const int MAX_SUM = 100001;

    vector<bool> dp(MAX_SUM, false);

    dp[0] = dp[x[0]] = true;
    for (int i = 1; i < n; i++) {
        for (int j = MAX_SUM; j >= x[i]; j--) {
            dp[j] = dp[j] || dp[j - x[i]];
        }
    }

    int k = 0;
    for (int j = 1; j < MAX_SUM; j++) {
        if (dp[j]) k++;
    }

    cout << k << endl;
    for (int j = 1; j < MAX_SUM; j++) {
        if (dp[j]) cout << j << " ";
    }
}

int main() {
    // int t; cin >> t;
    // while (t--)
        solve();
    return 0;
}
