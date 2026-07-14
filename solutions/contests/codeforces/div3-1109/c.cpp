// https://codeforces.com/problemset/problem/2244/C

#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int MAXN = 200005;
vector<int> parent(MAXN);
vector<int> depth(MAXN, 0);
vector<int> sz(MAXN, 1);

int find(int a) {
    if (parent[a] == a) return a;
    return parent[a] = find(parent[a]);
}
 
void unite(int a, int b) {
    int root_a = find(a);
    int root_b = find(b);
 
    if (root_a == root_b) return;
 
    if (depth[root_a] < depth[root_b]) {
        parent[root_a] = root_b;
        sz[root_b] += sz[root_a];
    }
    else if (depth[root_a] > depth[root_b]) {
        parent[root_b] = root_a;
        sz[root_a] += sz[root_b];
    }
    else {
        parent[root_b] = root_a;
        sz[root_a] += sz[root_b];
        depth[root_a]++;
    }
}

void solve() {
    int n, x, y; cin >> n >> x >> y;
    vector<ll> p(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }

    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        depth[i] = 0;
        sz[i] = 1;
    }
    
    for (int i = 1; i <= n; i++) {
        if (i + x <= n) unite(i, i + x);
        if (i + y <= n) unite(i, i + y);
    }

    for (int i = 1; i <= n; i++) {
        if (find(p[i]) != find(i)) {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while (t--)
        solve();
    return 0;
}
