// https://codeforces.com/contest/2225/problem/B

#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void solve() {
    string s; cin >> s;
    int n = s.size();
    int count = 0;
    for (int i = 1; i < n; i++) {
        count += s[i] == s[i-1];
    }
    if (count >= 3) cout << "NO" << endl;
    else           cout << "YES" << endl;
}

int main() {
    int t; cin >> t;
    while (t--)
        solve();
    return 0;
}
