// https://codeforces.com/problemset/problem/2240/A

#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int n, k; cin >> n >> k;
    int ans = 0;
    int curN = n;
    for (int bit = 0; (1 << bit) <= n; bit++) {
        int cost = 1 << bit;
        int amountOfThisBit = min(k, curN / cost);
        ans += amountOfThisBit;
        curN -= amountOfThisBit * cost;
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while (t--)
        solve();
    return 0;
}
