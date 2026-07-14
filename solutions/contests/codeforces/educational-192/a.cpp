// https://codeforces.com/problemset/problem/2242/A

#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int k; cin >> k;
    vector<int> c(k);
    int twos = 0;
    int threes = 0;
    for (int i = 0; i < k; i++) {
        cin >> c[i];
        if (c[i] >= 2) twos++;
        if (c[i] >= 3) threes++;
    }

    if (threes || twos >= 2) {
        cout << "YES" << "\n";
    }
    else {
        cout << "NO" << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while (t--)
        solve();
    return 0;
}
