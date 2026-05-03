// https://codeforces.com/problemset/problem/580/C

#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<bool> visited;
vector<int> a;
int n, m;

int dfs(int u, int cats, vector<vector<int>>& adj) {
    if (visited[u]) return 0;
    visited[u] = true;

    cats += a[u];
    if (cats > m) return 0;
    if (a[u] == 0) cats = 0;
    
    if (adj[u].size() == 1 && u != 1) return 1;

    int ret = 0;
    for (int v : adj[u]) {
        ret += dfs(v, cats, adj);
    }

    return ret;
}

void solve() {
    cin >> n >> m;
    a.resize(n+1);
    visited.resize(n+1, false);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    vector<vector<int>> adj(n+1);
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout << dfs(1, 0, adj) << endl;
}

int main() {
    // int t; cin >> t;
    // while (t--)
        solve();
    return 0;
}
