// https://codeforces.com/problemset/problem/1/B

#include <bits/stdc++.h>
using namespace std;
#define ll long long

void RCtoAA11(string& s) {
    string r_str = "";
    string c_str = "";
    int i;
    for (i = 1; s[i] != 'C'; i++) {
        r_str.push_back(s[i]);
    }
    for (i = i + 1; i < s.size(); i++) {
        c_str.push_back(s[i]);
    }

    int r = stoi(r_str);
    int c = stoi(c_str);

    string c_final = "";
    while (c > 0) {
        c--;
        c_final.push_back('A' + (c % 26));
        c /= 26;
    }
    reverse(c_final.begin(), c_final.end());
    cout << c_final << r << endl;
}

void AA11toRC(string& s) {
    string r_str = "R";
    string c_str = "";
    int i;
    for (i = 0; s[i] >= 'A' && s[i] <= 'Z'; i++) {
        c_str.push_back(s[i]);
    }
    for (; i < s.size(); i++) {
        r_str.push_back(s[i]);
    }

    int c = 0;
    int mult = 1;
    for (int i = c_str.size() - 1; i >= 0; i--) {
        c += mult * (c_str[i] - 'A' + 1);
        mult *= 26;
    }

    cout << r_str << "C" << c << endl;
}

bool isRC(string& s) {
    if (s[0] != 'R' || !isdigit(s[1])) return false;
    for (int i = 2; i < s.length(); i++) {
        if (s[i] == 'C') return true;
    }
    return false;
}

void solve() {
    string s; cin >> s;
    if (isRC(s)) {
        RCtoAA11(s);
    }
    else {
        AA11toRC(s);
    }
}

int main() {
    int t; cin >> t;
    while (t--)
        solve();
    return 0;
}