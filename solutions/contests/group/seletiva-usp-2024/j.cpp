// https://codeforces.com/gym/105297/problem/J

#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int n; cin >> n;
    vector<ll> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    sort(p.begin(), p.end());

    ll ans = 0;
    ll price = 0;
    for (int i = 0; i < n; i++) {
        ll rev = (n - i) * p[i];
        if (rev > ans) {
            ans = rev;
            price = p[i];
        }
    }

    cout << price << " " << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // int t; cin >> t;
    // while (t--)
        solve();
    return 0;
}
