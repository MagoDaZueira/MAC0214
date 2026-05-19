// https://codeforces.com/problemset/problem/2143/C

#include <bits/stdc++.h>
using namespace std;
#define ll long long

void dfs(int i, vector<vector<int>>& adj, vector<bool>& visited, vector<int>& order) {
    if (visited[i]) return;
    visited[i] = true;
    for (int j : adj[i]) {
        dfs(j, adj, visited, order);
    }
    order.push_back(i);
}

void solve() {
    int n; cin >> n;
    vector<bool> visited(n+1, false);
    vector<int> order;
    vector<vector<int>> adj(n+1);
    for (int i = 1; i < n; i++) {
        int u, v, x, y; cin >> u >> v >> x >> y;
        if (x > y) adj[v].push_back(u);
        else       adj[u].push_back(v);
    }

    for (int i = 1; i <= n; i++) {
        dfs(i, adj, visited, order);
    }

    vector<int> ans(n+1);

    int idx = 1;
    for (int i = n-1; i >= 0; i--) {
        ans[order[i]] = idx++;
    }

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while (t--)
        solve();
    return 0;
}
