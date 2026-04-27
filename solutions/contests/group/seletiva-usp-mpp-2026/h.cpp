// https://codeforces.com/gym/688480/problem/H

#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void solve() {
    int n; int m;
    cin >> n >> m;
    vector<int> dist(n+1, INT_MAX);
    vector<int> parent(n+1, INT_MAX);
    vector<vector<int>> adj(n+1, vector<int>());
    pair<int, int> p;
    
    for (int i=0;i<m;i++){
        int u; int v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    queue<int> s;
    vector<bool> visited(n+1, false);

    s.push(1);
    dist[1] = 1;
    parent[1] = 1;

    int minimum = INT_MAX;

    while (!s.empty()){
        int v = s.front();
        s.pop();

        if (visited[v]) continue;
        visited[v] = true;

        if (parent[v] != v) dist[v] = dist[parent[v]]+1;

        for (int u : adj[v]){
            if (u == parent[v]) continue;
            if (visited[u]){
                if (dist[v] + dist[u] < minimum) p = {u, v};
                minimum = min(minimum, dist[v] + dist[u]);
            } else {
                parent[u] = v;
                s.push(u);
            }
        }
    }

    if (minimum == INT_MAX) cout << "impossible";
    else {
        cout << minimum << endl;

        int u = p.first;
        int v = p.second;

        vector<int> a;

        while (parent[v] != v){
            a.push_back(v);
            v = parent[v];
        }
        a.push_back(1);

        vector<int> b;

        while (parent[u] != u){
            b.push_back(u);
            u = parent[u];
        }

        b.push_back(1);

        for (int i=a.size()-1;i>=0;i--){
            cout << a[i] << " ";
        }

        for (int i=0;i<b.size();i++){
            cout << b[i] << " ";
        }
    }
}

int main() {
    // int t; cin >> t;
    // while (t--)
        solve();
    return 0;
}