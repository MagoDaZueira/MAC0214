// https://codeforces.com/gym/688480/problem/A

#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void solve() {
    string s;
    cin >> s;

    double ans = 0.0;
    double expected = 1.0;

    int n = s.size();

    for (int i = 0; i < n; ++i) {
        int digit = s[i] - '0';
        int remainingDigits = n - 1 - i;

        ans += digit * expected * (0.9 * remainingDigits + 1.0);
        expected *= 0.1;
    }

    cout << fixed << setprecision(8) << ans << endl;
}

int main() {
    // int t; cin >> t;
    // while (t--)
        solve();
    return 0;
}
