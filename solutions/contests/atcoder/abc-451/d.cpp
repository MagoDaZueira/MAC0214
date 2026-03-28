// https://atcoder.jp/contests/abc451/tasks/abc451_d

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int n; cin >> n;
    int limit = 1e9;
    set<ll> s;
    vector<ll> powers;
    
    for (ll num = 1; num <= limit; num *= 2) {
        powers.push_back(num);
    }

    queue<string> q;
    q.push("");

    while (!q.empty()) {
        for (auto p : powers) {
            string p_string = to_string(p);
            string new_string = q.front() + p_string;
            
            if (new_string.size() > 10) continue;
            
            ll new_num = stoll(new_string);

            if (new_num <= limit) {
                if (s.find(new_num) == s.end()) {
                    s.insert(new_num);
                    q.push(new_string);
                }
            }
        }

        q.pop();
    }

    auto it = s.begin();
    int count = 1;
    while (count < n) {
        it++;
        count++;
    }

    cout << *it << endl;

    return 0;
}