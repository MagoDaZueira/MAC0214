// https://cses.fi/problemset/task/1193

#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));
    int ai, aj;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c; cin >> c;
            if (c == 'A') {
                ai = i;
                aj = j;
            }
            grid[i][j] = c;
        }
    }

    queue<tuple<int,int,char>> q;
    vector<vector<char>> parent(n, vector<char>(m, 'X'));
    q.push({ai, aj, 'O'});

    while (!q.empty()) {
        auto [i, j, p] = q.front();
        q.pop();
        if (i < 0 || i >= n || j < 0 || j >= m) continue;
        if (grid[i][j] == '#') continue;
        if (parent[i][j] != 'X') continue;
        parent[i][j] = p;

        if (grid[i][j] == 'B') {
            stack<char> ans;
            while (parent[i][j] != 'O') {
                char cur = parent[i][j];
                ans.push(cur);
                if      (cur == 'L') j++;
                else if (cur == 'R') j--;
                else if (cur == 'U') i++;
                else if (cur == 'D') i--;
            }
            cout << "YES" << endl;
            cout << ans.size() << endl;
            while (!ans.empty()) {
                cout << ans.top();
                ans.pop();
            }
            cout << endl;
            return;
        }

        q.push({i-1, j, 'U'});
        q.push({i+1, j, 'D'});
        q.push({i, j-1, 'L'});
        q.push({i, j+1, 'R'});
    }

    cout << "NO" << endl;
}

int main() {
    // int t; cin >> t;
    // while (t--)
        solve();
    return 0;
}
