// https://cses.fi/problemset/task/1750

#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int MAXN = 200005;
const int LOG = 30;
int up[MAXN][LOG];

void preprocess(vector<int>& parent) {
    int n = parent.size();
    for (int i = 1; i <= n; i++) {
        up[i][0] = parent[i];
    }

    for (int j = 1; j < LOG; j++) {
        for (int i = 1; i <= n; i++) {
            up[i][j] = up[up[i][j-1]][j-1];
        }
    }
}

int getKth(int x, int k) {
    for (int j = 0; j < LOG; j++) {
        if ((1 << j) & k) {
            x = up[x][j];
        }
    }
    return x;
}

void solve() {
    int n, q; cin >> n >> q;
    vector<int> t(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> t[i];
    }

    preprocess(t);

    while (q--) {
        int x, k; cin >> x >> k;
        cout << getKth(x, k) << "\n";
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
