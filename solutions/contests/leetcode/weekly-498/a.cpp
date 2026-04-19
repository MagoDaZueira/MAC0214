// https://leetcode.com/contest/weekly-contest-498/problems/smallest-stable-index-i/

class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = -1;
        for (int i = 0; i < n; i++) {
            int small = INT_MAX;
            int big = INT_MIN;
            for (int j = 0; j <= i; j++) {
                big = max(big, nums[j]);
            }
            for (int j = i; j < n; j++) {
                small = min(small, nums[j]);
            }
            if (big - small <= k) return i;
        }
        return ans;
    }
};