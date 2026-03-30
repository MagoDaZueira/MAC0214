// https://leetcode.com/problems/minimum-xor-path-in-a-grid/

class Solution {
public:
    int minCost(vector<vector<int>>& grid) {

        vector<vector<unordered_set<int>>> dp(grid.size(), vector<unordered_set<int>>(grid[0].size()));
        dp[0][0].insert(grid[0][0]);
        for (int i = 1; i < grid.size(); i++) {
            for (int num : dp[i-1][0]) {
                dp[i][0].insert(grid[i][0] ^ num);
            }
        }

        for (int j = 1; j < grid[0].size(); j++) {
            for (int num : dp[0][j-1]) {
                dp[0][j].insert(grid[0][j] ^ num);
            }
        }
        
        for (int i = 1; i < grid.size(); i++) {
            for (int j = 1; j < grid[0].size(); j++) {
                for (auto num : dp[i-1][j]) {
                    dp[i][j].insert(grid[i][j] ^ num);
                }
                for (auto num : dp[i][j-1]) {
                    dp[i][j].insert(grid[i][j] ^ num);
                }
            }
        }

        int small = INT_MAX;
        for (auto num : dp[grid.size()-1][grid[0].size()-1]) {
            small = min(small, num);
        }

        return small;
    }
};