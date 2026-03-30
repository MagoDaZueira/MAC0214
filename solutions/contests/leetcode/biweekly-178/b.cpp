// https://leetcode.com/problems/sum-of-gcd-of-formed-pairs/

class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int mx = 0;
        vector<int> pref(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            mx = max(mx, nums[i]);
            pref[i] = gcd(nums[i], mx);
        }

        sort(pref.begin(), pref.end());

        long long ans = 0;
        for (int i = 0; i < nums.size() / 2; i++) {
            ans += gcd(pref[i], pref[nums.size()-i-1]);
        }

        return ans;
    }
};