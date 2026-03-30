// https://codeforces.com/problemset/problem/1843/E

#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<pair<int, int>> segs;
vector<int> x;
int n, m;

bool check(int mid) {
    vector<int> a(n + 1, 0);
    for (int i = 0; i < mid; i++) {
        a[x[i]] = 1;
    }

    vector<int> pref(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        pref[i] = pref[i - 1] + a[i];
    }

    for (int i = 0; i < m; i++) {
        int l = segs[i].first;
        int r = segs[i].second;
        int ones = pref[r] - pref[l - 1];
        int len = r - l + 1;
        
        if (ones > len / 2) {
            return true;
        }
    }
    return false;
}

void solve() {
    cin >> n >> m;
    segs.resize(m);
    for (int i = 0; i < m; i++) {
        cin >> segs[i].first >> segs[i].second;
    }

    int q; cin >> q;
    x.resize(q);
    for (int i = 0; i < q; i++) {
        cin >> x[i];
    }

    int lo = 1, hi = q;
    int ans = -1;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (check(mid)) {
            ans = mid;
            hi = mid - 1;
        }
        else {
            lo = mid + 1;
        }
    }

    cout << ans << endl;
}

int main() {
    int t; cin >> t;
    while (t--)
        solve();
    return 0;
}
