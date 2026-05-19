// https://codeforces.com/problemset/problem/1661/C

#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool can(int target, vector<int>& h, ll mid) {
    ll even = mid / 2;
    ll odd = mid - even;

    ll hasToBeOdd = 0;
    ll remainingEvens = 0;

    for (int x : h) {
        ll d = target - x;
        hasToBeOdd += d % 2;
        remainingEvens += d / 2;
    }

    if (hasToBeOdd > odd) return false;

    odd -= hasToBeOdd;

    return even + odd / 2 >= remainingEvens;
}

ll bin_search(int target, vector<int>& h) {
    ll lo = 0, hi = 1e15;
    ll ans = hi;
    while (lo <= hi) {
        ll mid = lo + (hi - lo) / 2;
        if (can(target, h, mid)) {
            ans = mid;
            hi = mid - 1;
        }
        else {
            lo = mid + 1;
        }
    }
    return ans;
}

void solve() {
    int n; cin >> n;
    vector<int> h(n);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }

    int big = 0;
    for (int i = 0; i < n; i++) {
        big = max(big, h[i]);
    }

    ll ans = min(bin_search(big, h), bin_search(big + 1, h));
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while (t--)
        solve();
    return 0;
}
