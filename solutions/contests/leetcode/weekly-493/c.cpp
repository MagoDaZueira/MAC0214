// https://leetcode.com/problems/longest-arithmetic-sequence-after-changing-at-most-one-element/

class Solution {
public:
    int longestArithmetic(vector<int>& nums) {
        vector<int> left(nums.size(), 2);
        vector<int> right(nums.size(), 2);

        left[0] = 1;
        right[nums.size()-1] = 1;
        for (int i = 2; i < nums.size(); i++) {
            if (nums[i] - nums[i-1] == nums[i-1] - nums[i-2]) left[i] = left[i-1] + 1;
        }
        for (int i = nums.size()-3; i >= 0; i--) {
            if (nums[i+1] - nums[i] == nums[i+2] - nums[i+1]) right[i] = right[i+1] + 1;
        }

        int ans = 0;

        for (int i = 0; i < nums.size(); i++) {
            ans = max(ans, left[i]);
            if (i < nums.size() - 1) ans = max(ans, left[i]+1);
            if (i > 0) ans = max(ans, right[i]+1);
        }

        for (int i = 1; i < nums.size()-1; i++) {
            if ((nums[i+1] - nums[i-1]) % 2 == 0) {
                int diff = (nums[i+1] - nums[i-1]) / 2;
                int thisBlock = 1;
                
                if (i >= 2 && nums[i-1] - nums[i-2] == diff) {
                    thisBlock += left[i-1];
                } else {
                    thisBlock++;
                }
                
                if (i < nums.size()-2 && nums[i+2] - nums[i+1] == diff) {
                    thisBlock += right[i+1];
                } else {
                    thisBlock++;
                }

                ans = max(ans, thisBlock);
            }
        }

        return ans;
    }
};