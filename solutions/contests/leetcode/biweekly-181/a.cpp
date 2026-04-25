// https://leetcode.com/problems/valid-digit-number/description/

class Solution {
public:
    bool validDigit(int n, int x) {
        bool ans = false;
        while (n > 0) {
            int d = n % 10;
            if (n < 10 && d == x) return false;
            if (d == x) ans = true;
            n /= 10;
        }
        return ans;
    }
};