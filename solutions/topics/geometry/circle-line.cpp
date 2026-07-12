// https://eolymp.com/en/problems/359

#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    ll r, cx, cy, x1, y1, x2, y2; cin >> r >> cx >> cy >> x1 >> y1 >> x2 >> y2;

    ll dx = x2 - x1, dy = y2 - y1;
    ll pcx = cx - x1, pcy = cy - y1;

    ll cross = abs(dx * pcy - dy * pcx);
    ll vSq = dx * dx + dy * dy;

    if (cross * cross > r * r * vSq) {
        cout << -1 << "\n";
    }
    else if (cross * cross == r * r * vSq) {
        cout << 0 << "\n";
    }
    else {
        double dist = cross / sqrt(vSq);
        cout << fixed << setprecision(5) << 2 * sqrt(r * r - dist * dist) << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // int t; cin >> t;
    // while (t--)
        solve();
    return 0;
}
