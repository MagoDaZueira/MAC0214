// https://atcoder.jp/contests/abc451/tasks/abc451_c

#include <bits/stdc++.h>
using namespace std;

int main() {
    int q; cin >> q;
    multiset<int> s;
    while (q--) {
        int a, b; cin >> a >> b;
        if (a == 1) {
            s.insert(b);
        }
        else {
        for (auto it = s.begin(); it != s.end(); ) {
            if (*it <= b) {
                it = s.erase(it);
            } else {
                break;
            }
        }
        }
        cout << s.size() << endl;
    }

    return 0;
}