// https://codeforces.com/problemset/problem/2242/C

#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int n, k; cin >> n >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> count;
    int i = 0;
    while (i < n) {
        int sz = 0;
        while (i < n && a[i] == a[i-(sz>0)]) {
            sz++;
            i++;
        }
        count.push_back(sz);
    }
    int m = count.size();

    sort(count.begin(), count.end());

    vector<int> distinctCount;
    distinctCount.push_back(0);
    for (int c : count) {
        if (c != distinctCount.back()) distinctCount.push_back(c);
    }
    int r = distinctCount.size();

    vector<long long> suf(m + 1, 0);
    for (int i = m - 1; i >= 0; i--) {
        suf[i] = suf[i + 1] + count[i];
    }

    int ans = 0;
    for (int i = 0; i < r - 1; i++) {
        auto it = upper_bound(count.begin(), count.end(), distinctCount[i]);
        int j = distance(count.begin(), it);
        int survivors = m - j;
        int survivorSum = suf[j];
        int diff = k - survivorSum;
        if (diff % survivors == 0 && distinctCount[i+1] >= 1 - diff / survivors) {
            ans++;
        }
    }

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while (t--)
        solve();
    return 0;
}
