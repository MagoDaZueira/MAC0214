// https://codeforces.com/problemset/problem/377/A

#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<pair<int, int>> dir = {{-1, 0},{1, 0},{0, 1},{0, -1}};
int visited_count = 0;
int n, m, k, s;

bool valid(int i, int j) {
    return i >= 0 && i < n && j >= 0 && j < m;
}

void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int i, int j) {

    if (visited[i][j] || grid[i][j] == '#') return;
    
    if (visited_count >= s - k) return;
    visited[i][j] = true;
    visited_count++;

    for (auto& [di, dj] : dir) {
        int newI = i + di;
        int newJ = j + dj;

        if (valid(newI, newJ)) {
            dfs(grid, visited, newI, newJ);
        }
    }
}

void solve() {
    cin >> n >> m >> k;
    s = 0;
    vector<vector<char>> grid(n, vector<char>(m));
    vector<vector<bool>> visited(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '.') s++;
        }
    }

    bool found = false;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '.') {
                dfs(grid, visited, i, j);
                found = true;
                break;
            }
        }
        if (found) break;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '.' && !visited[i][j]) {
                cout << "X";
            }
            else {
                cout << grid[i][j];
            }
        }
        cout << endl;
    }
}

int main() {
    // int t; cin >> t;
    // while (t--)
        solve();
    return 0;
}