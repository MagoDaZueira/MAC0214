// https://codeforces.com/edu/course/2/lesson/4/1/practice/contest/273169/problem/C

#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct Node {
    int small;
    int count;
};

Node merge(Node a, Node b) {
    if (a.small < b.small) return a;
    if (b.small < a.small) return b;
    return {a.small, a.count + b.count};
}

const int MAXN = 100005;
int arr[MAXN];
Node seg[4 * MAXN];

void build(int node, int l, int r) {
    if (l == r) {
        seg[node] = {arr[l], 1};
        return;
    }
    int mid = (l + r) / 2;
    build(2 * node, l, mid);
    build(2 * node + 1, mid + 1, r);
    seg[node] = merge(seg[2 * node], seg[2 * node + 1]);
}

void update(int node, int l, int r, int i, int val) {
    if (l == r) {
        seg[node] = {val, 1};
        return;
    }
    int mid = (l + r) / 2;
    if (i <= mid) update(2 * node, l, mid, i, val);
    else          update(2 * node + 1, mid + 1, r, i, val);
    seg[node] = merge(seg[2 * node], seg[2 * node + 1]);
}

Node query(int node, int l, int r, int ql, int qr) {
    if (r < ql || l > qr) return {INT_MAX, 0};
    if (ql <= l && r <= qr) return seg[node];
    
    int mid = (l + r) / 2;
    Node left_res = query(2 * node, l, mid, ql, qr);
    Node right_res = query(2 * node + 1, mid + 1, r, ql, qr);
    
    return merge(left_res, right_res);
}

int main() {
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    build(1, 0, n - 1);
    
    while (m--) {
        int op, a, b;
        cin >> op >> a >> b;
        if (op == 1) {
            update(1, 0, n-1, a, b);
        }
        else {
            Node ans = query(1, 0, n - 1, a, b - 1);
            cout << ans.small << " " << ans.count << endl;
        }
    }
    return 0;
}