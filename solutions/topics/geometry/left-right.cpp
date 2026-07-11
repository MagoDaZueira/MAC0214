// https://cses.fi/problemset/task/2189/

#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    ll x1, y1, x2, y2, x3, y3; cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    ll zCross = (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1);
    if      (zCross > 0) cout << "LEFT" << "\n";
    else if (zCross < 0) cout << "RIGHT" << "\n";
    else                 cout << "TOUCH" << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while (t--)
        solve();
    return 0;
}
