// https://cses.fi/problemset/task/1647

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int log2_floor(unsigned ll n) {
    return n ? __builtin_clzll(1) - __builtin_clzll(n) : -1;
}

const int MAXN = 2e5 + 2;
const int K = 25;

int st[K+1][MAXN];

void build(vector<int>& arr) {
    int n = arr.size();
    copy(arr.begin(), arr.end(), st[0]);
    for (int i = 1; i <= K; i++) {
        for (int j = 0; j + (1 << i) - 1 < n; j++) {
            st[i][j] = min(st[i-1][j], st[i-1][j + (1 << (i-1))]);
        }
    }
}

int query(int l, int r) {
    int i = log2_floor(r - l + 1);
    return min(st[i][l], st[i][r - (1 << i) + 1]);
}

void solve() {
    int n, q; cin >> n >> q;
    vector<int> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    build(x);

    while (q--) {
        int a, b; cin >> a >> b;
        cout << query(a-1, b-1) << endl;
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
