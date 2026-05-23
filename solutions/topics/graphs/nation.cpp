// https://codeforces.com/problemset/problem/744/A

#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int MAXN = 1005;
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
    int n, m, k; cin >> n >> m >> k;
    vector<int> govs(k);
    vector<bool> isGov(n+1);
    for (int i = 0; i < k; i++) {
        cin >> govs[i];
    }
    for (int i = 1; i <= n; i++) parent[i] = i;
    
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        unite(u, v);
    }
    for (int i = 0; i < k; i++) {
        isGov[find(govs[i])] = true;
    }
        

    int loose = 0;
    int maxGov = find(govs[0]);
    vector<bool> visitedComp(n+1);
    for (int i = 1; i <= n; i++) {
        int root = find(i);
        if (visitedComp[root]) continue;
        visitedComp[root] = true;
        if (isGov[root]) {
            if (sz[root] > sz[maxGov]) {
                maxGov = root;
            }
        }
        else {
            loose += sz[root];
        }
    }

    int ans = 0;
    for (int g : govs) {
        int root = find(g);
        int s = sz[root];
        if (root == maxGov) s += loose;
        ans += (s * (s - 1)) / 2;
    }

    cout << ans - m << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // int t; cin >> t;
    // while (t--)
        solve();
    return 0;
}
