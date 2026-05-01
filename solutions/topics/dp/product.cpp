// https://codeforces.com/gym/100886/problem/G

#include <bits/stdc++.h>
using namespace std;
#define ll long long

pair<ll, string> dp[25][2][2][2];
bool vis[25][2][2][2];
vector<int> A;
vector<int> B;

pair<ll, string> rec(int i, bool less, bool greater, bool lead) {
    if (i == B.size()) return {1, ""};
    if (vis[i][less][greater][lead]) return dp[i][less][greater][lead];

    int hi = less ? 9 : B[i];
    int lo = greater ? 0 : A[i];

    pair<ll, string> ret = {-1, ""};

    for (int digit = lo; digit <= hi; digit++) {
        bool newLead = lead && (digit == 0);
        pair<ll, string> result = rec(i+1, less || (digit < hi), greater || (digit > lo), newLead);
        
        ll newVal = !newLead ? (ll)digit * result.first : result.first;
        
        if (newVal > ret.first) {
            ret.first = newVal;
            if (!newLead) ret.second = to_string(digit) + result.second;
            else ret.second = result.second;
        }
    }

    vis[i][less][greater][lead] = true;
    return dp[i][less][greater][lead] = ret;
}

void solve() {
    ll a, b; 
    if(!(cin >> a >> b)) return;
    if (a == 0 && b == 0) { cout << 0 << endl; return; }

    string sa = to_string(a), sb = to_string(b);
    while(sa.size() < sb.size()) sa = "0" + sa;

    A.clear(); B.clear();
    for(char c : sa) A.push_back(c - '0');
    for(char c : sb) B.push_back(c - '0');

    memset(vis, false, sizeof(vis));
    auto res = rec(0, 0, 0, 1);
    cout << (res.second == "" ? "0" : res.second) << endl;
}

int main() {
    solve();
    return 0;
}