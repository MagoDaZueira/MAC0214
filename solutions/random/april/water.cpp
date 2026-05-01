// https://codeforces.com/problemset/problem/2207/C

#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    ll n, h; cin >> n >> h;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }

    stack<ll> s;
    vector<ll> pref(n);
    vector<ll> suf(n);
    for (ll i = 0; i < n; i++) {
        while (!s.empty() && a[s.top()] <= a[i]) s.pop();
        if (s.empty()) {
            pref[i] = (h - a[i]) * (i + 1);
        }
        else {
            ll j = s.top();
            pref[i] = (h - a[i]) * (i - j) + pref[j];
        }
        s.push(i);
    }

    while (!s.empty()) s.pop();

    for (ll i = n-1; i >= 0; i--) {
        while (!s.empty() && a[s.top()] <= a[i]) s.pop();
        if (s.empty()) {
            suf[i] = (h - a[i]) * (n - i);
        }
        else {
            ll j = s.top();
            suf[i] = (h - a[i]) * (j - i) + suf[j];
        }
        s.push(i);
    }

    vector<ll> water(n);
    for (ll i = 0; i < n; i++) {
        water[i] = pref[i] + suf[i] - (h - a[i]);
    }

    ll ans = 0;
    for (ll i = 0; i < n; i++) {
        ll tall = a[i];
        ll idx = i;
        for (ll j = i; j < n; j++) {
            if (a[j] > tall) {
                tall = a[j];
                idx = j;
            }
            ans = max(ans, water[i] + water[j] - water[idx]);
        }
    }

    cout << ans << endl;
}

int main() {
    int t; cin >> t;
    while (t--)
        solve();
    return 0;
}
