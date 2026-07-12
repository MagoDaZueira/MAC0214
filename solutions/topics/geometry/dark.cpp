// https://codeforces.com/problemset/problem/1886/B

#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int px, py, ax, ay, bx, by; cin >> px >> py >> ax >> ay >> bx >> by;

    double abTouch = hypot(ax - bx, ay - by) / 2.0;
    double aHas0P = max(hypot(px - ax, py - ay), hypot(0 - ax, 0 - ay));
    double bHas0P = max(hypot(px - bx, py - by), hypot(0 - bx, 0 - by));
    double aHas0bHasP = max(hypot(px - bx, py - by), max(abTouch, hypot(0 - ax, 0 - ay)));
    double aHasPbHas0 = max(hypot(px - ax, py - ay), max(abTouch, hypot(0 - bx, 0 - by)));

    double ans = min(min(min(aHas0P, bHas0P), aHas0bHasP), aHasPbHas0);
    cout << fixed << setprecision(8) << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while (t--)
        solve();
    return 0;
}
