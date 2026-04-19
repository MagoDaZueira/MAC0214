// https://leetcode.com/contest/weekly-contest-498/problems/multi-source-flood-fill/

class Solution {
public:
    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources) {
        vector<vector<int>> grid(n, vector<int>(m, 0));
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));

        queue<pair<int, int>> q;
        for (auto& t : sources) {
            grid[t[0]][t[1]] = t[2];
            q.push({t[0], t[1]});
            dist[t[0]][t[1]] = 0;
        }

        vector<pair<int,int>> dir = {{-1, 0},{1, 0},{0, -1},{0, 1}};
        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();
            
            for (auto [di, dj] : dir) {
                if (i + di >= n || i + di < 0 || j + dj < 0 || j + dj >= m) continue;

                if (dist[i + di][j + dj] > dist[i][j] + 1) {
                    dist[i + di][j + dj] = dist[i][j] + 1;
                    grid[i + di][j + dj] = grid[i][j];
                    q.push({i + di, j + dj});
                }
                else if (dist[i + di][j + dj] == dist[i][j] + 1) {
                    grid[i + di][j + dj] = max(grid[i + di][j + dj], grid[i][j]);
                }
            }
        }

        return grid;
    }
};