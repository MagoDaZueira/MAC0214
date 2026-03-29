// https://cses.fi/problemset/task/1144/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

const int MAXN = 200005;
map<int, int> salaryToCount;
vector<int> idToCount(3 * MAXN);
vector<int> seg(10 * MAXN);
vector<int> employeeToSalary(MAXN);

void build(int node, int l, int r) {
    if (l == r) {
        seg[node] = idToCount[l];
        return;
    }
    int mid = (l + r) / 2;
    build(2 * node, l, mid);
    build(2 * node + 1, mid + 1, r);
    seg[node] = seg[2 * node] + seg[2 * node + 1];
}

void update(int node, int l, int r, int i, int inc) {
    if (l == r) {
        seg[node] += inc;
        return;
    }
    int mid = (l + r) / 2;
    if (i <= mid) update(2 * node, l, mid, i, inc);
    else          update(2 * node + 1, mid + 1, r, i, inc);
    seg[node] = seg[2 * node] + seg[2 * node + 1];
}

ll query(int node, int l, int r, int ql, int qr) {
    if (r < ql || l > qr) return 0;
    if (ql <= l && r <= qr) return seg[node];
    int mid = (l + r) / 2;
    return query(2 * node, l, mid, ql, qr) + query(2 * node + 1, mid + 1, r, ql, qr);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> coords;

    int n, q; cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        int a; cin >> a;
        salaryToCount[a]++;
        employeeToSalary[i] = a;
        coords.push_back(a);
    }

    vector<tuple<char, int, int>> queries;

    for (int i = 0; i < q; i++) {
        char op; int a, b; cin >> op >> a >> b;
        if (op == '!') {
            salaryToCount[b] += 0;
            coords.push_back(b);
        }
        else {
            salaryToCount[a] += 0;
            salaryToCount[b] += 0;
            coords.push_back(a);
            coords.push_back(b);
        }
        queries.push_back({op, a, b});
    }

    int curId = 0;
    for (auto& [salary, count] : salaryToCount) {
        idToCount[curId++] = count;
    }

    sort(coords.begin(), coords.end());
    coords.erase(unique(coords.begin(), coords.end()), coords.end());

    auto getID = [&](int x) {
        return lower_bound(coords.begin(), coords.end(), x) - coords.begin();
    };

    int m = salaryToCount.size() - 1;
    build(1, 0, m);

    for (auto& [op, a, b] : queries) {
        if (op == '!') {
            int old = employeeToSalary[a];
            employeeToSalary[a] = b;
            update(1, 0, m, getID(old), -1);
            update(1, 0, m, getID(b), +1);
        }
        else {
            cout << query(1, 0, m, getID(a), getID(b)) << "\n";
        }
    }
    return 0;
}