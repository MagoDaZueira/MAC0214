// https://codeforces.com/problemset/problem/2244/A

#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    int curSize = s[0] == '#';
    char last = s[0];
    int big = curSize;
    for (int i = 1; i < n; i++) {
        char c = s[i];
        if (c != last) {
            if (last == '#') big = max(big, curSize);
            last = c;
            curSize = 0;
        }
        curSize++;
    }
    if (last == '#') big = max(big, curSize);

    cout << ceil(big / 2.0) << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while (t--)
        solve();
    return 0;
}
