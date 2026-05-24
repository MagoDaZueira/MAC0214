// https://leetcode.com/problems/minimum-operations-to-sort-a-permutation/

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int zero;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) zero = i;
        }

        bool inc = true;
        bool dec = true;

        int expected = 1;
        for (int i = (zero+1) % n; i != zero; i = (i+1) % n) {
            if (nums[i] != expected++) {
                inc = false;
                break;
            }
        }

        if (inc) return min(zero, 2 + n - zero);
        
        expected = n-1;
        for (int i = (zero+1) % n; i != zero; i = (i+1) % n) {
            if (nums[i] != expected--) {
                dec = false;
                break;
            }
        }

        if (dec) return min(n - zero, zero + 2);

        return -1;
    }
};