// https://codeforces.com/contest/2236/problem/D

// Fui ver o editorial depois e tinha uma solução bem mais simples que essa.
// Fiquei encucado de tentar esta durante o contest e não rolou, tive que
// ajustar depois, no upsolving. Mas realmente deu.

#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int MAXN = 200005;
vector<ll> seg(4 * MAXN);

void build(int node, int l, int r) {
    if (l == r) {
        seg[node] = 0;
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

void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    vector<int> vals, cnts;
    for (int x : a) {
        if (vals.empty() || vals.back() != x) {
            vals.push_back(x);
            cnts.push_back(1);
        } else {
            cnts.back()++;
        }
    }
    int m = vals.size();

    vector<int> farthest(m);
    int j = 0;
    for (int i = 0; i < m; i++) {
        if (j < i) j = i;
        while (j + 1 < m && vals[j + 1] - vals[i] <= k) {
            j++;
        }
        farthest[i] = j;
    }

    build(1, 0, m);
    
    bool canWin = false;
    
    for (int i = m - 1; i >= 0; i--) {
        if (farthest[i] == i) {
            if (cnts[i] % 2 != 0) {
                update(1, 0, m, i, 1);
            } else {
                canWin = true;
            }
            continue;
        }

        int losingReachable = query(1, 0, m, i + 1, farthest[i]);

        if (losingReachable > 0) {
            canWin = true; 
        } else {
            if (cnts[i] % 2 != 0) {
                update(1, 0, m, i, 1); 
            } else {
                canWin = true; 
            }
        }
    }

    if (canWin) cout << "YES" << "\n";
    else        cout << "NO" << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while (t--)
        solve();
    return 0;
}
