// https://atcoder.jp/contests/dp/tasks/dp_q

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

const int MAXN = 200005;
vector<ll> seg = vector<ll>(4 * MAXN);

void build(int node, int l, int r) {
    if (l == r) {
        seg[node] = 0;
        return;
    }
    int mid = (l + r) / 2;
    build(2 * node, l, mid);
    build(2 * node + 1, mid + 1, r);
    seg[node] = max(seg[2 * node], seg[2 * node + 1]);
}

void update(int node, int l, int r, int i, ll val) {
    if (l == r) {
        seg[node] = val;
        return;
    }
    int mid = (l + r) / 2;
    if (i <= mid) update(2 * node, l, mid, i, val);
    else          update(2 * node + 1, mid + 1, r, i, val);
    seg[node] = max(seg[2 * node], seg[2 * node + 1]);
}

ll query(int node, int l, int r, int ql, int qr) {
    if (r < ql || l > qr) return 0;
    if (ql <= l && r <= qr) return seg[node];
    int mid = (l + r) / 2;
    return max(query(2 * node, l, mid, ql, qr), query(2 * node + 1, mid + 1, r, ql, qr));
}

int main() {
    int n; cin >> n;

    vector<int> h(n);
    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    build(1, 0, n-1);

    ll ans = 1;
    for (int i = 0; i < n; i++) {
        int coord = h[i] - 1;
        ll longest = query(1, 0, n-1, 0, coord-1) + a[i];
        ans = max(ans, longest);
        update(1, 0, n-1, coord, longest);
    }

    cout << ans << endl;
}