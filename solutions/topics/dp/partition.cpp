// https://leetcode.com/problems/partition-equal-subset-sum/

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2) return false;
        int W = sum / 2;

        vector<bool> dp(W + 1);

        dp[0] = true;
        if (nums[0] <= W) dp[nums[0]] = true;

        for (int i = 1; i < n; i++) {
            for (int j = W; j > 0; j--) {
                dp[j] = dp[j];
                if (j - nums[i] >= 0) dp[j] = dp[j] || dp[j - nums[i]];
            }
        }

        return dp[W];
    }
};