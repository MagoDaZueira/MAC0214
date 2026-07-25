// https://cses.fi/problemset/task/2191

#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct Point {
    ll x, y;
};

ll dist2(const Point& a, const Point& b) {
    ll dx = a.x - b.x;
    ll dy = a.y - b.y;
    return dx * dx + dy * dy;
}

void solve() {
    int n; cin >> n;
    vector<Point> points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
    }

    auto cmpX = [](const Point& a, const Point& b) {
        if (a.x != b.x) return a.x < b.x;
        return a.y < b.y;
    };
    auto cmpY = [](const Point& a, const Point& b) {
        if (a.y != b.y) return a.y < b.y;
        return a.x < b.x;
    };

    sort(points.begin(), points.end(), cmpX);

    set<Point, decltype(cmpY)> valid(cmpY);

    ll d2 = LLONG_MAX;
    ll leftIdx = 0;

    for (Point& p : points) {
        ll d = ceil(sqrt(d2));
        while (p.x - points[leftIdx].x >= d) {
            valid.erase(points[leftIdx++]);
        }
        
        auto itLo = valid.lower_bound({p.x - d, p.y - d});
        auto itHi = valid.lower_bound({p.x + d, p.y + d});

        for (auto it = itLo; it != itHi; it++) {
            d2 = min(d2, dist2(p, *it));
        }

        valid.insert(p);
    }

    cout << d2 << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // int t; cin >> t;
    // while (t--)
        solve();
    return 0;
}
