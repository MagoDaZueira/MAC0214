// https://codeforces.com/edu/course/2/lesson/4/1/practice/contest/273169/problem/B

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

const int MAXN = 200005;
vector<int> arr(MAXN);
vector<ll> seg(4 * MAXN);

void build(int node, int l, int r) {
    if (l == r) {
        seg[node] = arr[l];
        return;
    }
    int mid = (l + r) / 2;
    build(2 * node, l, mid);
    build(2 * node + 1, mid + 1, r);
    seg[node] = min(seg[2 * node], seg[2 * node + 1]);
}

void update(int node, int l, int r, int i, int val) {
    if (l == r) {
        seg[node] = val;
        return;
    }
    int mid = (l + r) / 2;
    if (i <= mid) update(2 * node, l, mid, i, val);
    else          update(2 * node + 1, mid + 1, r, i, val);
    seg[node] = min(seg[2 * node], seg[2 * node + 1]);
}

ll query(int node, int l, int r, int ql, int qr) {
    if (r < ql || l > qr) return LLONG_MAX;
    if (ql <= l && r <= qr) return seg[node];
    int mid = (l + r) / 2;
    return min(query(2 * node, l, mid, ql, qr), query(2 * node + 1, mid + 1, r, ql, qr));
}

int main() {
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    build(1, 0, n-1);
    while (m--) {
        int op, a, b; cin >> op >> a >> b;
        if (op == 1) {
            update(1, 0, n-1, a, b);
        }
        else {
            cout << query(1, 0, n-1, a, b-1) << endl;
        }
    }
    return 0;
}