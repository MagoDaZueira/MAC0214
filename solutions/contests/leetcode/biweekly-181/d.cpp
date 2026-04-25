// https://leetcode.com/problems/k-th-smallest-remaining-even-integer-in-subarray-queries/description/

#define ll long long int

class Solution {
public:
    vector<int> kthRemainingInteger(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> pref(n);
        pref[0] = (nums[0] % 2 == 0);
        for (int i = 1; i < n; i++) {
            pref[i] = pref[i-1] + (nums[i] % 2 == 0);
        }

        ll lim = 3e14;
        vector<int> anss;

        for (auto& q : queries) {
            int l, r, k; l = q[0]; r = q[1]; k = q[2];

            ll lo = 1, hi = lim;
            ll ans = hi;

            while (lo <= hi) {
                ll mid = (lo + hi) / 2;
                mid -= (mid % 2 != 0);

                ll evens = mid / 2;

                auto it = upper_bound(nums.begin() + l, nums.begin() + r + 1, mid);

                int i = distance(nums.begin(), it) - 1;

                ll removed = 0;
                if (i >= l) {
                    removed += pref[i] - (l == 0 ? 0 : pref[l - 1]);
                }

                if (evens - removed >= k) {
                    ans = mid;
                    hi = mid - 2;
                }
                else {
                    lo = mid + 2;
                }
            }

            anss.push_back(ans);
        }

        return anss;
    }
};