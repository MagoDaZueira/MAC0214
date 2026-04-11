// https://leetcode.com/contest/biweekly-contest-180/problems/count-digit-appearances/

class Solution {
public:
    int countNum(int num, int digit) {
        int ans = 0;
        while (num > 0) {
            if (num % 10 == digit) ans++;
            num /= 10;
        }
        return ans;
    }
    int countDigitOccurrences(vector<int>& nums, int digit) {
        int ans = 0;
        for (auto num : nums) {
            ans += countNum(num, digit);
        }
        return ans;
    }
};