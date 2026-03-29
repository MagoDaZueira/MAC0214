// https://codeforces.com/problemset/problem/75/C

#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<int> get_divs(int n) {
    vector<int> divs;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            divs.push_back(i);

            if (i * i != n) {
                divs.push_back(n / i);
            }
        }
    }
    return divs;
}

void solve() {
    int a, b; cin >> a >> b;
    vector<int> divsA = get_divs(a);
    vector<int> divsB = get_divs(b);
    sort(divsA.begin(), divsA.end());
    sort(divsB.begin(), divsB.end());

    int n; cin >> n;

    while (n--) {
        int l, h; cin >> l >> h;
        bool found = false;
        for (int i = divsA.size() - 1; i >= 0; i--) {
            if (divsA[i] >= l && divsA[i] <= h) {
                auto it = lower_bound(divsB.begin(), divsB.end(), divsA[i]);
                if (*it == divsA[i]) {
                    found = true;
                    cout << divsA[i] << endl;
                    break;
                }
            }
        }
        if (!found) cout << -1 << endl;
    }
}

int main() {
    // int t; cin >> t;
    // while (t--)
        solve();
    return 0;
}