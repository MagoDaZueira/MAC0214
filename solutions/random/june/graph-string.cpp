// https://codeforces.com/problemset/problem/623/A

#include <bits/stdc++.h>
using namespace std;
#define ll long long

char currentChar;
int vertexCount;
int edgeCount;

void dfs(int u, vector<vector<int>>& adj, vector<bool>& visited, string& s) {
    visited[u] = true;
    vertexCount++;
    s[u] = currentChar;
 
    for (int v : adj[u]) {
        if (s[v] != 'b') edgeCount++;
        if (!visited[v]) {
            dfs(v, adj, visited, s);
        }
    }
}

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n+1);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
 
    unsigned int bSize = n - 1;
    string s(n+1, 'd');
    vector<bool> visited(n+1, false);
 
    for (int i = 1; i <= n; i++) {
        if (adj[i].size() == bSize) {
            visited[i] = true;
            s[i] = 'b';
        }
    }
 
    int components = 0;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            components++;
            if (components > 2) {
                cout << "No" << "\n";
                return;
            }
 
            if (components == 1) currentChar = 'a';
            else                 currentChar = 'c';
 
            vertexCount = 0;
            edgeCount = 0;
            dfs(i, adj, visited, s);
 
            if (edgeCount != vertexCount * (vertexCount - 1)) {
                cout << "No" << "\n";
                return;
            }
        }
    }
 
    cout << "Yes" << "\n";
    for (int i = 1; i <= n; i++) {
        cout << s[i];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // int t; cin >> t;
    // while (t--)
        solve();
    return 0;
}
