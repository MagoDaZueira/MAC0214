// https://codeforces.com/problemset/problem/559/B

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int countA[200005][26];
int countB[200005][26];

string a, b;

bool equiv(int la, int ra, int lb, int rb) {
    int lenA = ra - la + 1;
    int lenB = rb - lb + 1;

    if (lenA != lenB) return false;
    if (lenA <= 0) return false;
    if (a.compare(la, lenA, b, lb, lenB) == 0) return true;
    if (lenA % 2 != 0 || lenB % 2 != 0) return false;

    for (int c = 0; c < 26; c++) {
        int freqA = countA[ra][c] - countA[la][c] + (a[la] - 'a' == c);
        int freqB = countB[rb][c] - countB[lb][c] + (b[lb] - 'a' == c);
        if (freqA != freqB) return false;
    }

    int midA = la + lenA / 2 - 1;
    int midB = lb + lenB / 2 - 1;

    bool ret1 = equiv(la, midA, lb, midB) && equiv(midA + 1, ra, midB + 1, rb);
    if (ret1) return true;
    bool ret2 = equiv(la, midA, midB + 1, rb) && equiv(midA + 1, ra, lb, midB);
    return ret2;
}

void solve() {
    cin >> a >> b;
    int n = a.size();

    countA[0][a[0] - 'a'] = 1;
    countB[0][b[0] - 'a'] = 1;

    for (int i = 1; i < n; i++) {
        for (int c = 0; c < 26; c++) {
            countA[i][c] = countA[i-1][c];
        }
        countA[i][a[i] - 'a']++;
    }

    for (int i = 1; i < n; i++) {
        for (int c = 0; c < 26; c++) {
            countB[i][c] = countB[i-1][c];
        }
        countB[i][b[i] - 'a']++;
    }

    if (equiv(0, n-1, 0, n-1))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}

int main() {
    // int t; cin >> t;
    // while (t--)
        solve();
    return 0;
}
