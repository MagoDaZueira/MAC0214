// https://leetcode.com/problems/sum-of-sortable-integers/

// um dos códigos mais toscos que já escrevi
// deu certo só num submit faltando 1 minuto, absurdo

class Solution {
public:
    vector<int> get_divs(int n) {
        vector<int> ret;
        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                ret.push_back(i);
                if (i * i != n) {
                    ret.push_back(n / i);
                }
            }
        }
        return ret;
    }

    bool check(vector<int>& nums, int k) {
        int mult = 1;
        vector<int> bigs;
        vector<int> smalls;

        int nk = nums.size() / k;
        for (int mult = 1; mult <= nk; mult++) {
            
            int small = INT_MAX;
            int big = INT_MIN;
            vector<int> starts;

            int l = (mult-1) * k;
            int r = mult * k;
            
            for (int i = l; i < r; i++) {
                small = min(small, nums[i]);
                big = max(big, nums[i]);
            }
            
            smalls.push_back(small);
            bigs.push_back(big);
            
            for (int i = l; i < r; i++) {
                if (nums[i] == small) {
                    starts.push_back(i);
                }
            }

            bool started = false;
            int idx = -1;
            for (int i = l; i < r; i++) {
                if (nums[i] != nums[starts[0]]) {
                    started = true;
                }
                if (started == true && nums[starts[0]] == nums[i]) {
                    idx = i;
                    break;
                }
            }
            if (idx == -1) idx = starts[0];
            
            bool found = true;
            int last = nums[idx];
            for (int i = (idx + 1 < r) ? idx + 1 : l; i != idx; i = (i + 1 < r) ? i + 1 : l) {
                if (nums[i] < last) {
                    found = false;
                    break;
                }
                last = nums[i];
            }
            if (!found) return false;
        }

        for (int i = 1; i < smalls.size(); i++) {
            if (smalls[i] < bigs[i-1]) return false;
        }
        
        return true;
    }

    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        vector<int> divs = get_divs(n);
        int ans = 0;
        for (auto k : divs) {
            if (check(nums, k)) {
                ans += k;
            }
        }
        return ans;
    }
};