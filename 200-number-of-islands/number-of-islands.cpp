class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int numberOfIslands = 0;
        int r = grid.size();
        int c = grid[0].size();
        unordered_set<string> visited;

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == '1' &&
                    visited.find((to_string(i) + "," + to_string(j))) ==
                        visited.end()) {
                    numberOfIslands++;
                    bfs(grid, visited, i, j);
                }
            }
        }
        return numberOfIslands;
    }

private:
    vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    
    void bfs(vector<vector<char>>& grid, unordered_set<string>& visited, int r,
             int c) {
        string coor = to_string(r) + "," + to_string(c);
        visited.insert(coor);
        queue<pair<int, int>> q;
        q.push({r, c});

        while (!q.empty()) {
            auto [row, col] = q.front();
            q.pop();
            for (auto [l, r] : dir) {
                int rr = row + l;
                int cc = col + r;

                if (rr >= 0 && rr < grid.size() && cc >= 0 &&
                    cc < grid[0].size() && grid[rr][cc] == '1' &&
                    visited.find(to_string(rr) + "," + to_string(cc)) ==
                        visited.end()) {
                    q.push({rr, cc});
                    visited.insert(to_string(rr) + "," + to_string(cc));
                }
            }
        }
    }
};