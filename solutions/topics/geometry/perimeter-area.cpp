// https://eolymp.com/en/problems/925

#include <bits/stdc++.h>
using namespace std;
#define ll long long

double distance(pair<double,double>& a, pair<double,double>& b) {
    double dx = a.first - b.first;
    double dy = a.second - b.second;
    return sqrt(dx * dx + dy * dy);
}

double get_perimeter(vector<pair<double, double>> tri) {
    return distance(tri[0], tri[1]) +
           distance(tri[0], tri[2]) +
           distance(tri[1], tri[2]);
}

double get_area(vector<pair<double, double>> tri) {
    double sum = tri[0].first * (tri[1].second - tri[2].second) +
                 tri[1].first * (tri[2].second - tri[0].second) +
                 tri[2].first * (tri[0].second - tri[1].second);
    return abs(sum) / 2;
}

void solve() {
    vector<pair<double,double>> p(3);
    for (int i = 0; i < 3; i++) {
        cin >> p[i].first >> p[i].second;
    }
    double perimeter = get_perimeter(p);
    double area = get_area(p);
    cout << fixed << setprecision(4) << perimeter << " " << fixed << setprecision(4) << area << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // int t; cin >> t;
    // while (t--)
        solve();
    return 0;
}
