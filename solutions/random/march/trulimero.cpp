// https://codeforces.com/problemset/problem/2094/F

#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int n, m, k; cin >> n >> m >> k;
    vector<vector<int>> mat(n, vector<int>(m));

    if (m % k != 0) {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                mat[i][j] = (i * m + j) % k + 1;
    } 
    else if (n % k != 0) {
        for (int j = 0; j < m; j++)
            for (int i = 0; i < n; i++)
                mat[i][j] = (j * n + i) % k + 1;
    } 
    else {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                mat[i][j] = (i + j) % k + 1;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}