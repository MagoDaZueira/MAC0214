// https://codeforces.com/problemset/problem/2113/C

#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int n, m, k; cin >> n >> m >> k;
    vector<vector<char>> grid(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    vector<vector<int>> prefH(n, vector<int>(m));
    vector<vector<int>> prefV(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        prefH[i][0] = grid[i][0] == 'g';
    }
    for (int j = 0; j < m; j++) {
        prefV[0][j] = grid[0][j] == 'g';
    }

    for (int i = 0; i < n; i++) {
        for (int j = 1; j < m; j++) {
            prefH[i][j] = prefH[i][j-1] + (grid[i][j] == 'g');
        }
    }
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m; j++) {
            prefV[i][j] = prefV[i-1][j] + (grid[i][j] == 'g');
        }
    }

    int totalGold = 0;
    int loss = INT_MAX;

    int gold = 0;
    for (int i = 0; i < min(n, k); i++) {
        gold += prefH[i][min(k-1, m-1)];
    }

    for (int i = 0; i < n; i++) {
        int checkpoint = gold;
        for (int j = 0; j < m; j++) {
            totalGold += grid[i][j] == 'g';

            if (grid[i][j] == '.') {
                loss = min(loss, gold);
            }

            if (j == m-1) continue;
            
            int i_up = max(i-k+1, 0);
            int i_lo = min(i+k-1, n-1);
            int j_l =  max(j-k+1, 0);
            int j_r =  min(j+k, m-1);

            if (j-k+1 >= 0) gold -= prefV[i_lo][j_l] - prefV[i_up][j_l] + (grid[i_up][j_l] == 'g');
            if (j + k < m)  gold += prefV[i_lo][j_r] - prefV[i_up][j_r] + (grid[i_up][j_r] == 'g');
        }

        gold = checkpoint;
        if (i < n-1) {
            if (i-k+1 >= 0) gold -= prefH[max(i-k+1, 0)][min(k-1, m-1)];
            if (i + k < n)  gold += prefH[min(i+k, n-1)][min(k-1, m-1)];
        }
    }

    cout << totalGold - loss << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while (t--)
        solve();
    return 0;
}
