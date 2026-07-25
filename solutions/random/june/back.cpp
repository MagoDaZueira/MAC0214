// https://codeforces.com/problemset/problem/2047/D

#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int n; cin >> n;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        pq.push(make_pair(a[i], i));
    }

    vector<int> first;
    priority_queue<int, vector<int>, greater<int>> last;

    for (int i = 0; i < n; i++) {
        if (!pq.empty() && a[i] == pq.top().first) {
            pq.pop();
            if (!last.empty() && a[i] > last.top())
                last.push(a[i] + 1);
            else
                first.push_back(a[i]);
            while (!pq.empty() && pq.top().second < i) {
                pq.pop();
            }
        }
        else last.push(a[i] + 1);
    }

    for (int i = 0; i < first.size(); i++) {
        cout << first[i] << " ";
    }
    while (!last.empty()) {
        cout << last.top() << " ";
        last.pop();
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while (t--)
        solve();
    return 0;
}
