// https://leetcode.com/problems/number-of-pairs-after-increment/

#define ll long long
class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums1, vector<int>& nums2og, vector<vector<int>>& queries) {
        vector<ll> nums2(nums2og.begin(), nums2og.end());
        
        int n = nums2.size();
        int sz = sqrt(n) + 1;
        int m = (n + sz - 1) / sz;
        vector<ll> lazy(m);
        vector<unordered_map<ll, int>> freq(m);

        for (int i = 0; i < n; i++) {
            int idx = i / sz;
            freq[idx][nums2[i]]++;
        }

        vector<int> ans;

        for (auto& q : queries) {
            if (q[0] == 1) {
                int x = q[1];
                int y = q[2];
                int val = q[3];
                
                int blockL = x / sz;
                int blockR = y / sz;

                int lEnd = (blockL + 1) * sz - 1;
                int rStart = blockR * sz;

                if (blockL == blockR) {
                    for (int i = x; i <= y; i++) {
                        freq[blockL][nums2[i]]--;
                        nums2[i] += val;
                        freq[blockL][nums2[i]]++;
                    }
                }

                else {
                    for (int i = x; i <= lEnd; i++) {
                        freq[blockL][nums2[i]]--;
                        nums2[i] += val;
                        freq[blockL][nums2[i]]++;
                    }
    
                    for (int b = blockL + 1; b < blockR; b++) {
                        lazy[b] += val;
                    }
                    
                    for (int i = rStart; i <= y; i++) {
                        freq[blockR][nums2[i]]--;
                        nums2[i] += val;
                        freq[blockR][nums2[i]]++;
                    } 
                }
            }

            else if (q[0] == 2) {
                int pairs = 0;
                for (int num : nums1) {
                    ll target = q[1] - num;
                    for (int b = 0; b < m; b++) {
                        pairs += freq[b][target - lazy[b]];
                    }
                }
                ans.push_back(pairs);
            }
        }

        return ans;
    }
};