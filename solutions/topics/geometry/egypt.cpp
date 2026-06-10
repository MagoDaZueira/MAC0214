// https://vjudge.net/problem/UVA-11854

#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int s[3];
    cin >> s[0] >> s[1] >> s[2];
    while (s[0] != 0 || s[1] != 0 || s[2] != 0) {
        sort(s, s + 3);
        bool isRight = s[0]*s[0] + s[1]*s[1] == s[2]*s[2];
        cout << (isRight ? "right" : "wrong") << "\n";
        cin >> s[0] >> s[1] >> s[2];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // int t; cin >> t;
    // while (t--)
        solve();
    return 0;
}
