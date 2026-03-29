// https://codeforces.com/problemset/problem/377/A

#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int n; cin >> n;
	vector<int> a(n, 0);

	auto cmp = [](pair<int,int>& p1, pair<int,int>& p2){
		if (p1.first != p2.first) {
			return p1.first < p2.first;
		}
		return p1.second > p2.second;
	};

	priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
	
	pq.push({n, 0});
	int i = 1;

	while (!pq.empty()) {
		auto [size, l] = pq.top();
		pq.pop();

		if (size == 0) continue;

		int r = l + size - 1;

		int mid = ((r - l + 1) % 2 == 1) ? (l + r) / 2 : (l + r - 1) / 2;

		a[mid] = i++;

		pq.push({mid - l, l});
		pq.push({r - mid, mid + 1});
	}

	for (auto num : a) {
		cout << num << " ";
	}
	cout << endl;
}

int main() {
    int t; cin >> t;
    while (t--)
        solve();
    return 0;
}