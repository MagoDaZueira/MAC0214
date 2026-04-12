// https://codeforces.com/problemset/problem/1418/C

#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int n; cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	if (n == 1) {
		cout << a[0] << endl;
		return;
	}

	vector<vector<int>> dp(n, vector<int>(2, INT_MAX - 50));

	dp[0][1] = a[0];
	dp[1][1] = a[0] + a[1];
	dp[1][0] = dp[0][1];

	for (int i = 2; i < n; i++) {
		dp[i][0] = min(dp[i-2][1], dp[i-1][1]);
		dp[i][1] = min(dp[i-2][0] + a[i-1] + a[i], dp[i-1][0] + a[i]);
	}

	cout << min(dp[n-1][0], dp[n-1][1]) << endl;
}

int main() {
    int t; cin >> t;
    while (t--)
        solve();
    return 0;
}
