// https://codeforces.com/problemset/problem/1661/B

#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int MOD = 32768;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    queue<pair<int,int>> q;
    vector<int> dist(MOD, -1);

    q.push({0, 0});

    while (!q.empty()) {
        auto [i, d] = q.front();
        q.pop();
        if (dist[i] != -1) continue;
        dist[i] = d;
        q.push({(i - 1 + MOD) % MOD, d+1});
        if (i % 2 == 0) {
            q.push({i / 2, d+1});
            q.push({i / 2 + MOD / 2, d+1});
        }
    }

    for (int i = 0; i < n; i++) {
        cout << dist[a[i]] << " ";
    }
}

int main() {
    // int t; cin >> t;
    // while (t--)
        solve();
    return 0;
}
