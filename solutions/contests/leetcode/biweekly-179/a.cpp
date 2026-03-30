// https://leetcode.com/problems/minimum-absolute-difference-between-two-values/

// fiz O(n^2) na correria do contest porque passava,
// mas é bem facil a O(n) (e mais simples, provavelmente)

class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums) {
        int small = 999999;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                for (int j = 0; j < nums.size(); j++) {
                    if (nums[j] == 2) {
                        small = min(abs(i - j), small);
                    }
                }
            }
        }

        if (small == 999999) return -1;
        return small;
    }
};