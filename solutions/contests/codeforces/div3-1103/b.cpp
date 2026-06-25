// https://codeforces.com/problemset/problem/2236/B

#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int n, k; cin >> n >> k;
    string s; cin >> s;

    for (int i = 0; i + k < n; i++) {
        if (s[i] == '1') {
            s[i] = '0';
            if (s[i+k] == '0') s[i+k] = '1';
            else               s[i+k] = '0';
        }
    }

    for (char c : s) {
        if (c == '1') {
            cout << "NO" << "\n";
            return;
        }
    }
    cout << "YES" << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while (t--)
        solve();
    return 0;
}
