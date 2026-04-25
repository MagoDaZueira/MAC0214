// https://leetcode.com/problems/compare-sums-of-bitonic-parts/description/

class Solution {
public:
    int compareBitonicSums(vector<int>& nums) {
        int n = nums.size();
        int idx = 0;
        vector<long long> sums(2, 0);
        for (int i = 0; i < n; i++) {
            sums[idx] += nums[i];
            if (i < n - 1 && nums[i+1] < nums[i] && idx == 0) {
                idx++;
                sums[idx] = nums[i];
            }
        }
        if (idx == 0) sums[1] = nums[n-1];
        if (sums[0] > sums[1]) return 0;
        if (sums[1] > sums[0]) return 1;
        return -1;
    }
};