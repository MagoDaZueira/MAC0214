// https://codeforces.com/contest/1446/problem/A

// Tava numa lista de problemas de DP então achei que era,
// mas ao que parece é só o nome que remete a DP

#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    ll n, W; cin >> n >> W;
    vector<int> w(n);
    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }
    ll half = (W + 1) / 2;

    for (int i = n-1; i >= 0; i--) {
        if (w[i] <= W && w[i] >= half) {
            cout << 1 << endl << i + 1 << endl;
            return;
        }
    }

    vector<int> idx;
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        if (w[i] > W) continue;
        sum += w[i];
        idx.push_back(i);
        if (sum >= half) {
            cout << idx.size() << endl;
            for (auto j : idx) {
                cout << j + 1 << " ";
            }
            return;
        }
    }

    cout << -1 << endl;
}

int main() {
    int t; cin >> t;
    while (t--)
        solve();
    return 0;
}
