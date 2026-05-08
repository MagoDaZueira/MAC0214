// https://codeforces.com/contest/727/problem/A

// esse problema tava numa lista de questões de grafos,
// mas aparentemente era mentira.
// vou deixar aqui já que resolvi, e fazer outras.

#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int a, b; cin >> a >> b;
    
    stack<int> ans;
    ans.push(b);
    while (b > a) {
        if (b % 2 == 0) b /= 2;
        else {
            if (b % 10 != 1) {
                cout << "NO" << endl;
                return;
            }
            b = (b - 1) / 10;
        }
        ans.push(b);
    }

    if (b == a) {
        cout << "YES" << endl;
        cout << ans.size() << endl;
        while (!ans.empty()) {
            cout << ans.top() << " ";
            ans.pop();
        }
    }

    else {
        cout << "NO" << endl;
    }
}

int main() {
    // int t; cin >> t;
    // while (t--)
        solve();
    return 0;
}
