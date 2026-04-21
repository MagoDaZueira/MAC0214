// https://cses.fi/problemset/task/2220

#include <bits/stdc++.h>
using namespace std;
#define ll long long

// dp[i][j][k][z] = amount of numbers <= upper number from this state
// i = current digit index
// j = last digit
// k = whether the number is already < upper (bool)
// z = whether we're in the leading 0s phase (bool)
ll dp[20][11][2][2];
vector<int> num;

ll rec(int i, int last, int less, int lead) {
    if (i == num.size()) return 1;

    if (dp[i][last][less][lead] != -1) return dp[i][last][less][lead];

    int limit = less ? 9 : num[i];
    
    ll ret = 0;
    for (int d = 0; d <= limit; d++) {
        if (d == last) continue;
        int newLess = less || (d < num[i]);
        int newLead = lead && (d == 0);
        ret += rec(i + 1, newLead ? 10 : d, newLess, newLead);
    }

    return dp[i][last][less][lead] = ret;
}

ll solve(ll n) {
    if (n < 0) return 0;
    num.clear();
    while (n > 0) {
        num.push_back(n % 10);
        n /= 10;
    }
    reverse(num.begin(), num.end());
    memset(dp, -1, sizeof(dp));
    return rec(0, 10, 0, 1);
}

int main() {
    ll a, b; cin >> a >> b;
    cout << solve(b) - solve(a-1) << endl;
    return 0;
}
