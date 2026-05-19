// https://cses.fi/problemset/task/1679

#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool cycle = false;
vector<bool> visited;
vector<bool> onStack;
vector<int> order;

void dfs(int i, vector<vector<int>>& adj) {
    if (onStack[i]) {
        cycle = true;
        return;
    }
    if (visited[i]) return;

    visited[i] = true;
    onStack[i] = true;

    for (int j : adj[i]) {
        dfs(j, adj);
    }

    order.push_back(i);
    onStack[i] = false;
}

void solve() {
    int n, m; cin >> n >> m;
    visited.resize(n+1);
    onStack.resize(n+1);
    vector<vector<int>> adj(n+1);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
    }

    for (int i = 1; i <= n; i++) {
        dfs(i, adj);
    }

    if (cycle) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }

    for (int i = n-1; i >= 0; i--) {
        cout << order[i] << " ";
    }
    cout << endl;
}

int main() {
    // int t; cin >> t;
    // while (t--)
        solve();
    return 0;
}
