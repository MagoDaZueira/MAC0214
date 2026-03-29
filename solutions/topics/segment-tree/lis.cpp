// https://leetcode.com/problems/longest-increasing-subsequence/

class Solution {

private:
    const int MAXN = 2505;
    vector<int> seg = vector<int>(4 * MAXN);

    void build(int node, int l, int r) {
        if (l == r) {
            seg[node] = 0;
            return;
        }
        int mid = (l + r) / 2;
        build(2 * node, l, mid);
        build(2 * node + 1, mid + 1, r);
        seg[node] = max(seg[2 * node], seg[2 * node + 1]);
    }

    void update(int node, int l, int r, int i, int val) {
        if (l == r) {
            seg[node] = val;
            return;
        }
        int mid = (l + r) / 2;
        if (i <= mid) update(2 * node, l, mid, i, val);
        else          update(2 * node + 1, mid + 1, r, i, val);
        seg[node] = max(seg[2 * node], seg[2 * node + 1]);
    }

    int query(int node, int l, int r, int ql, int qr) {
        if (r < ql || l > qr) return 0;
        if (ql <= l && r <= qr) return seg[node];
        int mid = (l + r) / 2;
        return max(query(2 * node, l, mid, ql, qr), query(2 * node + 1, mid + 1, r, ql, qr));
    }

public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());
        sortedNums.erase(unique(sortedNums.begin(), sortedNums.end()), sortedNums.end());

        vector<int> coords(nums.size());

        for (int i = 0; i < n; i++) {
            coords[i] = lower_bound(sortedNums.begin(), sortedNums.end(), nums[i]) - sortedNums.begin();
        }

        build(1, 0, n-1);

        int ans = 1;
        for (auto coord : coords) {
            int longest = query(1, 0, n-1, 0, coord-1) + 1;
            ans = max(ans, longest);
            update(1, 0, n-1, coord, longest);
        }

        return ans;
    }
};