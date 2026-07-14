// https://codeforces.com/problemset/problem/2244/F

#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct DfsRet {
    int small;
    int big;
    int count;
};

bool can;

vector<vector<int>> adj;
vector<int> a;

auto cmp = [](DfsRet& a, DfsRet& b) {
    return a.small < b.small;
};

DfsRet dfs(int u) {
    if (!can) return {0,0,0};
    if (adj[u].empty()) {
        return {a[u], a[u], 1};
    }
    int count = 0;
    int small = INT_MAX;
    int big = INT_MIN;

    vector<DfsRet> boundaries;
    
    for (int v : adj[u]) {
        DfsRet ret = dfs(v);
        count += ret.count;
        small = min(small, ret.small);
        big = max(big, ret.big);
        boundaries.push_back(ret);
    }

    if (!can || count != big - small + 1) {
        can = false;
        return {0,0,0};
    }

    vector<DfsRet> expected = boundaries;
    sort(expected.begin(), expected.end(), cmp);

    // Truque tosco que já tinha visto num leetcode pra ver se a ordem é a mesma
    vector<DfsRet> duplicated = expected;
    duplicated.insert(duplicated.end(), expected.begin(), expected.end());

    bool correct = false;
    for (int i = 0; i < boundaries.size(); i++) {
        bool found = true;
        for (int j = 0; j < boundaries.size(); j++) {
            if (duplicated[i+j].small != boundaries[j].small) {
                found = false;
                break;
            }
        }
        if (found) {
            correct = true;
            break;
        }
    }

    if (!correct) can = false;
    return {small, big, count};
}

void solve() {
    int n; cin >> n;
    adj.assign(n+1, vector<int>());
    a.assign(n+1, 0);
    for (int i = 2; i <= n; i++) {
        int p; cin >> p;
        adj[p].push_back(i);
    }
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (auto& v : adj) {
        sort(v.begin(), v.end());
    }

    can = true;

    dfs(1);

    if (can) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while (t--)
        solve();
    return 0;
}
