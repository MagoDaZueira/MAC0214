// https://codeforces.com/edu/course/2/lesson/4/3/practice/contest/274545/problem/A

#include <bits/stdc++.h>

using namespace std;
#define ll long long

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
    seg[node] = seg[2 * node] + seg[2 * node + 1];
}

void update(int node, int l, int r, int i, int val) {
    if (l == r) {
        seg[node] = val;
        return;
    }
    int mid = (l + r) / 2;
    if (i <= mid) update(2 * node, l, mid, i, val);
    else          update(2 * node + 1, mid + 1, r, i, val);
    seg[node] = seg[2 * node] + seg[2 * node + 1];
}

ll query(int node, int l, int r, int ql, int qr) {
    if (r < ql || l > qr) return 0;
    if (ql <= l && r <= qr) return seg[node];
    int mid = (l + r) / 2;
    return query(2 * node, l, mid, ql, qr) + query(2 * node + 1, mid + 1, r, ql, qr);
}

int main() {
    int n; cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    for (int i = 0; i < n; i++) {
        arr[i] = 0;
    }
    build(1, 0, n);

    for (int i = 0; i < n; i++) {
        int inversions = query(1, 0, n, p[i], n);
        cout << inversions << " ";
        update(1, 0, n, p[i], 1);
    }

    return 0;
}