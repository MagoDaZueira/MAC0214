// https://codeforces.com/problemset/problem/2205/D

#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<int> left(n);
    vector<int> right(n);
    stack<int> s;

    for (int i = 0; i < n; i++) {
        while (!s.empty() && s.top() < a[i]) s.pop();
        s.push(a[i]);
        left[i] = s.size();
    }

    while (!s.empty()) s.pop();

    for (int i = n-1; i >= 0; i--) {
        while (!s.empty() && s.top() < a[i]) s.pop();
        s.push(a[i]);
        right[i] = s.size();
    }

    int ans = 0;

    for (int i = 0; i < n; i++) {
        ans = max(ans, left[i] + right[i] - 1);
    }

    cout << n - ans << endl;
}

int main() {
    int t; cin >> t;
    while (t--)
        solve();
    return 0;
}
