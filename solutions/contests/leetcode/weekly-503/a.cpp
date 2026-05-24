// https://leetcode.com/problems/limit-occurrences-in-sorted-array/

class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        vector<int> ans;
        int cur = -1;
        int curCount = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (cur != nums[i]) {
                cur = nums[i];
                curCount = 0;
            }
            curCount++;
            if (curCount > k) continue;
            ans.push_back(nums[i]);
        }
        return ans;
    }
};