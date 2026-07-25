// https://codeforces.com/problemset/problem/466/C

#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int n; cin >> n;
    vector<ll> a(n);
    ll sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
    }

    if (sum % 3 != 0) {
        cout << 0 << "\n";
        return;
    }

    ll target = sum / 3;
    ll curPref = 0;
    ll firstSplitCount = 0;
    ll ans = 0;

    for (int i = 0; i < n - 1; ++i) {
        curPref += a[i];
        if (i >= 1 && curPref == 2 * target) {
            ans += firstSplitCount;
        }
        if (curPref == target) {
            firstSplitCount++;
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
