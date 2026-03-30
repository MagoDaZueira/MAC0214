// https://leetcode.com/problems/minimum-cost-to-equalize-arrays-using-swaps/

class Solution {
public:
    int minCost(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> m;
        unordered_map<int,int> m1;
        unordered_map<int,int> m2;
        for (int i = 0; i < nums1.size(); i++) {
            m[nums1[i]]++;
            m1[nums1[i]]++;
            m[nums2[i]]++;
            m2[nums2[i]]++;
        }

        int ans = 0;
        for (auto& p : m) {
            if (p.second % 2 != 0) return -1;
            ans += abs(m1[p.first] - m2[p.first]) / 2;
        }

        ans /= 2;

        return ans;
    }
};