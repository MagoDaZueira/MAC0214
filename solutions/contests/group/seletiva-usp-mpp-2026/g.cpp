#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void solve() {
    string s; cin >> s;
    int m = s.size();
    int n; cin >> n;
    vector<string> words(n);
    for (int i = 0; i < n; i++) {
        cin >> words[i];
    }
    
    set<string> found;
    for (auto& w : words) {
        found.insert(w);
    }
    
    vector<bool> dp(m+1, false);
    dp[0] = true;
    for (int i = 6; i <= m; i++) {
        for (int sub = 6; sub <= 10 && sub <= i; sub++) {
            dp[i] = dp[i] || (dp[i-sub] && found.count(s.substr(i-sub, sub)));
        }
    }

    cout << (dp[m] ? "yes" : "no") << endl;
}

int main() {
    // int t; cin >> t;
    // while (t--)
        solve();
    return 0;
}
