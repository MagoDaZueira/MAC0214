// https://leetcode.com/contest/weekly-contest-498/problems/smallest-stable-index-i/

class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> bigs(n);
        vector<int> smalls(n);
        bigs[0] = nums[0];
        for (int i = 1; i < n; i++) {
            bigs[i] = max(bigs[i-1], nums[i]);
        }
        smalls[n-1] = nums[n-1];
        for (int i = n-2; i >= 0; i--) {
            smalls[i] = min(smalls[i+1], nums[i]);
        }

        for (int i = 0; i < n; i++) {
            if (bigs[i] - smalls[i] <= k) return i;
        }
        return -1;
    }
};