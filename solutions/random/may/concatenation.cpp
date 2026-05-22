// https://codeforces.com/problemset/problem/632/C

#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int n; cin >> n;
    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    auto cmp = [](string& a, string& b) {
        return (a + b) < (b + a);
    };

    sort(s.begin(), s.end(), cmp);

    string ans = "";
    for (string& i : s) {
        ans += i;
    }

    cout << ans << endl;
}

int main() {
    // int t; cin >> t;
    // while (t--)
        solve();
    return 0;
}
