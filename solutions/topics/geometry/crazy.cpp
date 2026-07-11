// https://codeforces.com/problemset/problem/498/A

#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    ll x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
    int n; cin >> n;
    vector<int> a(n), b(n), c(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i] >> c[i];
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] * x1 + b[i] * y1 + c[i] > 0 !=
            a[i] * x2 + b[i] * y2 + c[i] > 0) {
                ans++;
            }
    }

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // int t; cin >> t;
    // while (t--)
        solve();
    return 0;
}
