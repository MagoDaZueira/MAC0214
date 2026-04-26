#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void solve() {
    int n, w; cin >> n >> w;
    vector<int> p(n);
    vector<int> t(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i] >> t[i];
    }

    double lo = 1, hi = 4e18;
    double ans = 4e18;
    for (int it = 0; it < 100; it++) {
        double mid = lo + (hi - lo) / 2.0;
        double processed = 0;
        for (int i = 0; i < n; i++) {
            processed += max(0.0, mid - 2 * t[i]) * p[i];
            if (processed >= w) break;
        }
        if (processed >= w) {
            ans = mid;
            hi = mid;
        }
        else {
            lo = mid;
        }
    }
    cout << fixed << setprecision(8) << ans << endl;
}

int main() {
    // int t; cin >> t;
    // while (t--)
        solve();
    return 0;
}
