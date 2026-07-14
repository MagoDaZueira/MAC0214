// https://codeforces.com/problemset/problem/2240/C

// Não consegui essa durante o contest, embora seja simples.
// faltou olhar o problema sob o ângulo de quão poucos são os estados perdedores.
// O MOD inútil do enunciado me enganou também, não tem como negar.

#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int n; cin >> n;
    vector<ll> a(n);
    int totalXor = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        totalXor ^= a[i];
    }
    
    if (n == 1) {
        cout << 0 << "\n";
        return;
    }

    if (totalXor == 0) {
        cout << 1 << "\n";
        return;
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] >= (totalXor ^ a[i])) ans++;
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
