// https://codeforces.com/problemset/problem/1526/C2

#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int n; cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    priority_queue<ll, vector<ll>, greater<ll>> pq;
    ll health = 0;
    for (int p : a) {
        pq.push(p);
        health += p;
        while (health < 0) {
            health -= pq.top();
            pq.pop();
        }
    }

    cout << pq.size() << endl;
}

int main() {
    // int t; cin >> t;
    // while (t--)
        solve();
    return 0;
}
