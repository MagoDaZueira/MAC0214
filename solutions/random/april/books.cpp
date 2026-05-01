// https://codeforces.com/problemset/problem/1374/E1

#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int n, k; cin >> n >> k;
    vector<tuple<int,int,int>> v(n);
    vector<int> times;
    vector<int> temp_a;
    vector<int> temp_b;
    for (int i = 0; i < n; i++) {
        int t, a, b; cin >> t >> a >> b;
        if (a && b) times.push_back(t);
        else if (a) temp_a.push_back(t);
        else if (b) temp_b.push_back(t);
    }

    sort(temp_a.begin(), temp_a.end());
    sort(temp_b.begin(), temp_b.end());
    for (int i = 0; i < min(temp_a.size(), temp_b.size()); i++) {
        times.push_back(temp_a[i] + temp_b[i]);
    }

    if (times.size() < k) {
        cout << -1 << endl;
        return;
    }

    sort(times.begin(), times.end());

    int ans = 0;
    for (int i = 0; i < k; i++) {
        ans += times[i];
    }

    cout << ans << endl;
}

int main() {
    // int t; cin >> t;
    // while (t--)
        solve();
    return 0;
}
