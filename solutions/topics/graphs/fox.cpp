// https://codeforces.com/problemset/problem/510/C

#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool cycle = false;
vector<bool> visited(26);
vector<bool> onStack(26);
vector<char> order;

void dfs(char i, vector<unordered_set<char>>& adj) {
    if (onStack[i-'a']) {
        cycle = true;
        return;
    }
    if (visited[i-'a']) return;

    visited[i-'a'] = true;
    onStack[i-'a'] = true;

    for (int j : adj[i-'a']) {
        dfs(j, adj);
    }

    order.push_back(i);
    onStack[i-'a'] = false;
}

void solve() {
    int n; cin >> n;
    vector<string> names(n);
    for (int i = 0; i < n; i++) {
        cin >> names[i];
    }
    
    vector<unordered_set<char>> adj(26);
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            int it1 = 0, it2 = 0;
            while (it1 < names[i].size() && it2 < names[j].size() && names[i][it1] == names[j][it2]) {
                it1++;
                it2++;
            }

            if (it1 == names[i].size()) continue;
            if (it2 == names[j].size()) {
                cout << "Impossible" << endl;
                return;
            }

            adj[names[i][it1]-'a'].insert(names[j][it2]);
        }
    }

    for (char c = 'a'; c <= 'z'; c++) {
        dfs(c, adj);
    }

    if (cycle) {
        cout << "Impossible" << endl;
        return;
    }

    reverse(order.begin(), order.end());
    for (int i = 0; i < 26; i++) {
        cout << order[i];
    }
    cout << endl;
}

int main() {
    // int t; cin >> t;
    // while (t--)
        solve();
    return 0;
}
