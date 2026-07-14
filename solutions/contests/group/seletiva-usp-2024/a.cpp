#include <bits/stdc++.h>
using namespace std;
#define ll long long;

void solve() {
    int n;
    cin >> n;

    vector<array<int, 4>> v;
    v.reserve(n);

    for (int i = 0; i < n; i++) {
        int t, m, c;
        cin >> t >> m >> c;
        v.push_back({t, m, c, i + 1});
    }

    sort(v.begin(), v.end());

    vector<int> ans;
    deque<array<int, 3>> q;

    for (auto [t, m, c, idx] : v) {
        if (c == 0) {
            q.push_back({t, m, idx});
            continue;
        }

        while (!q.empty()) {
            auto [start, dur, cur_idx] = q.front();
            q.pop_front();

            int end = start + dur;
            if (end > t) {
                ans.push_back(cur_idx);
                break;
            }

            if (!q.empty()) {
                q.front()[0] = max(q.front()[0], end);
            }
        }

        q.push_front({t, m, idx});
    }

    cout << ans.size() << '\n';
    for (int x : ans) cout << x << ' ';
    cout << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    // int t; cin >> t;
    // while(t--)
        solve();
    return 0;
}