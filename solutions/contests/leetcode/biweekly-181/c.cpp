// https://leetcode.com/problems/count-connected-subgraphs-with-even-node-sum/description/

class Solution {
public:
    bool connected(int mask, int start, int expected, vector<vector<int>>& adj) {
        int visitedMask = 0;
        queue<int> q;
        q.push(start);
        visitedMask |= (1 << start);
        int visCount = 1;
        
        while (!q.empty()) {
            int v = q.front();
            q.pop();

            for (auto u : adj[v]) {
                if (mask & (1 << u) && !(visitedMask & (1 << u))) {
                    visitedMask |= (1 << u);
                    visCount++;
                    q.push(u);
                }
            }
        }

        return visCount == expected;
    }

    int evenSumSubgraphs(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        vector<vector<int>> adj(n);
        for (auto& p : edges) {
            adj[p[0]].push_back(p[1]);
            adj[p[1]].push_back(p[0]);
        }

        int ans = 0;

        for (int mask = 1; mask < (1 << n); mask++) {
            int sum = 0;
            int start = -1;
            int expected = 0;
            for (int i = 0; i < n; i++) {
                if ((1 << i) & mask) {
                    sum += nums[i];
                    start = i;
                    expected++;
                }
            }

            if (sum % 2 != 0) continue;

            ans += connected(mask, start, expected, adj);
        }

        return ans;
    }
};