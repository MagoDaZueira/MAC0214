// https://vjudge.net/problem/LightOJ-1022

#include <bits/stdc++.h>
using namespace std;
#define ll long long

const double PI = 2 * acos(0.0);

void solve(int t) {
    double r; cin >> r;
    double r2 = r * r;
    double ans = 4 * r2 - PI * r2;
    cout << "Case " << t << ": " << fixed << setprecision(2) << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    for (int i = 1; i <= t; i++)
        solve(i);
    return 0;
}
