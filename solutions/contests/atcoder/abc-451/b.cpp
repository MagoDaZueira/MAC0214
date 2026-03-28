// https://atcoder.jp/contests/abc451/tasks/abc451_b

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m; 
    cin >> n >> m;

    vector<int> diff(m + 1, 0);

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        diff[a]--;
        diff[b]++;
    }

    for (int i = 1; i <= m; i++) {
        cout << diff[i] << endl;
    }

    return 0;
}