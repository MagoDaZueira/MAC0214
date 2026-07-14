// https://codeforces.com/problemset/problem/2242/B

#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int ones = 0;
    int twos = 0;
    int threes = 0;
    vector<int> val(n);

    for (int i = 0; i < n; i++) {
        if      (a[i] == 1) ones++;
        else if (a[i] == 2) twos++;
        else if (a[i] == 3) threes++;
        val[i] = ones + twos - threes;
    }

    vector<int> bestFrom(n);
    bestFrom[n-2] = val[n-2];
    for (int i = n - 3; i >= 1; i--) {
        bestFrom[i] = max(val[i], bestFrom[i+1]);
    }
    
    ones = 0;
    twos = 0;
    threes = 0;
    bool can = false;
    for (int i = 0; i < n - 2; i++) {
        if      (a[i] == 1) ones++;
        else if (a[i] == 2) twos++;
        else if (a[i] == 3) threes++;
        if (ones >= twos + threes && bestFrom[i+1] - val[i] >= 0) {
            can = true;
            break;
        }
    }
    
    if (can) {
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
