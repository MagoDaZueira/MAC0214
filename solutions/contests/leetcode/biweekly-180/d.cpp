// https://leetcode.com/contest/biweekly-contest-180/problems/maximum-value-of-concatenated-binary-segments/

class Solution {
public:
    int maxValue(vector<int>& nums1, vector<int>& nums0) {
        const int MOD = 1e9 + 7;
        int n = nums1.size();
        vector<pair<int, int>> segs;
        int len = 0;
        for (int i = 0; i < n; i++) {
            segs.push_back({nums1[i], nums0[i]});
            len += nums1[i] + nums0[i];
        }

        auto cmp = [](const pair<int,int>& a, const pair<int,int>& b) {
            if ((a.second == 0) != (b.second == 0)) {
                return a.second == 0;
            }

            if (a.first != b.first) return a.first > b.first;

            return a.second < b.second;
        };

        sort(segs.begin(), segs.end(), cmp);

        vector<long long> powers(len + 1);
        powers[0] = 1;
        for (int i = 1; i <= len; i++) {
            powers[i] = (powers[i-1] * 2) % MOD;
        }

        long long ans = 0;
        for (auto& s : segs) {
            if (s.first) {
                ans = (ans * powers[s.first]) % MOD;
                ans = (ans + powers[s.first] - 1 + MOD) % MOD;
            }
            if (s.second) {
                ans = (ans * powers[s.second]) % MOD;
            }
        }

        return ans;
    }
};