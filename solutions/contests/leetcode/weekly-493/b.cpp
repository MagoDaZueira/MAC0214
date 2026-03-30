// https://leetcode.com/problems/count-commas-in-range-ii/

// esse aqui é absurdo

class Solution {
public:
    long long countCommas(long long n) {
        long long ans = 0;
        ans += max(0LL, n-999);
        ans += max(0LL, n-999999);
        ans += max(0LL, n-999999999);
        ans += max(0LL, n-999999999999);
        ans += max(0LL, n-999999999999999);

        return ans;
    }
};