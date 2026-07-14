// https://codeforces.com/gym/105297/problem/I

#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int n; cin >> n;
    vector<int> mountains(n);

    for (int i = 0; i < n; i++) {
        cin >> mountains[i];
    }

    int operations = 0;
    bool hasOddMoreThanOne = false;
    bool hasOdd = false;
    bool hasEven = false;

    for (int mountain : mountains) {
        if (mountain % 2 == 1 && mountain > 1) {
            hasOddMoreThanOne = true;
        } else if (mountain % 2 == 0 && mountain != 0) {
            hasEven = true;
        } else if (mountain % 2 == 1) {
            hasOdd = true;
        }
    }

    if (!hasOdd && !hasEven && !hasOddMoreThanOne) {
        operations = 0;
    } else if (hasOddMoreThanOne || (hasEven && hasOdd)) {
        operations = 2;
    } else {
        operations = 1;
    }

    cout << operations << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // int t; cin >> t;
    // while (t--)
        solve();
    return 0;
}
