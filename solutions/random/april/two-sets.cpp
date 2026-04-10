// https://cses.fi/alon/task/1092

#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int n; cin >> n;
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += i;
    }

    if (sum % 2) {
        cout << "NO" << endl;
        return;
    }

    int shift = n % 4;
    if (shift == 1 || shift == 2) {
        cout << "NO" << endl;
        return;
    }

    vector<vector<int>> sets(2);
    if (shift == 3) {
        sets[0].push_back(1);
        sets[0].push_back(2);
        sets[1].push_back(3);
    }

    int i = shift + 1; int j = n;
    int round = 0;
    while (i < j) {
        sets[round].push_back(i);
        sets[round].push_back(j);
        round = !round;
        i++; j--;
    }

    cout << "YES" << endl;

    for (auto& s : sets) {
        cout << s.size() << endl;
        for (auto num : s) {
            cout << num << " ";
        }
        cout << endl;
    }
}

int main() {
    // int t; cin >> t;
    // while (t--)
        solve();
    return 0;
}
