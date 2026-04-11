// https://leetcode.com/contest/biweekly-contest-180/problems/minimum-operations-to-transform-array-into-alternating-prime/description/

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int MAX = 101005;
        vector<bool> is_prime(MAX, true);
        vector<int> primes;
        is_prime[0] = false;
        is_prime[1] = false;
        for (long long i = 2; i * i < MAX; i++) {
            if (is_prime[i]) {
                for (long long j = i*i; j < MAX; j += i) {
                    is_prime[j] = false;
                }
            }
        }

        for (int i = 2; i < MAX; i++) {
            if (is_prime[i]) primes.push_back(i);
        }

        long long ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i % 2 == 0) {
                if (is_prime[nums[i]]) continue;
                auto it = upper_bound(primes.begin(), primes.end(), nums[i]);
                ans += (*it) - nums[i];
            }
            else {
                if (is_prime[nums[i]]) {
                    if (nums[i] == 2) ans += 2;
                    else ans++;
                }
            }
        }

        return ans;
    }
};