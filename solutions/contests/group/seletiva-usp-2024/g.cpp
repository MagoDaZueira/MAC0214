// https://codeforces.com/gym/105297/problem/G
 
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 200005;
const int mod = 1e9+7;
int a[maxn];

void solve(){
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    if (n == 1) { cout << 0 << "\n"; return; }

    int xoring = 0;
    for (int i = 0; i < n; i++) xoring ^= a[i];

    if (xoring == 0) { cout << 1 << "\n"; return; }

    int count = 0;
    int m = 0;
    while ((1 << (m + 1)) <= xoring) m++;

    for (int i = 0; i < n; i++) if ((a[i] >> m) & 1) count++;

    cout << count % mod << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // int t; cin >> t;
    // while (t--)
        solve();
    return 0;
}
