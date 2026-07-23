// https://codeforces.com/problemset/problem/1276/B

#include <bits/stdc++.h>
using namespace std;
#define ll long long

void dfs(int u, int stop, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v] && v != stop) {
            dfs(v, stop, adj, visited);
        }
    }
}
 
void solve() {
    int n, m, a, b; cin >> n >> m >> a >> b;
    vector<vector<int>> adj(n+1);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
 
    vector<bool> foundA(n+1, false);
    dfs(a, b, adj, foundA);
 
    vector<bool> foundB(n+1, false);
    dfs(b, a, adj, foundB);
 
    ll exclusiveA = -1; ll exclusiveB = -1;
    for (int i = 1; i <= n; i++) {
        if      (foundA[i] && !foundB[i]) exclusiveA++;
        else if (!foundA[i] && foundB[i]) exclusiveB++;
    }
 
    cout << exclusiveA * exclusiveB << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while (t--)
        solve();
    return 0;
}
