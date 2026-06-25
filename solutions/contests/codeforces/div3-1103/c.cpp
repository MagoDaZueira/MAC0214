// https://codeforces.com/problemset/problem/2236/C

#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int a, b, x; cin >> a >> b >> x;
    int ans = INT_MAX;
    int ops = 0;
    while (a != b) {
        ans = min(ans, abs(a - b) + ops);
        if (a > b) a /= x;
        else       b /= x;
        ops++;
    }
    ans = min(ans, ops);
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
