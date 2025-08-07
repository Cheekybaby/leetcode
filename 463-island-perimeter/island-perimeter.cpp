class Solution {
public:
    int bfs(vector<vector<int>> &grid, int i, int j, vector<vector<bool>> &visited){
        int perimeter = 0;
        queue<pair<int,int>> q;
        q.push({i,j});

        while(!q.empty()){
            pair<int,int> p = q.front();
            q.pop();

            int i = p.first;
            int j = p.second;

            if (visited[i][j] == true){
                continue;
            }

            if (i-1 < 0 || grid[i-1][j] == 0){
                perimeter += 1;
            } else if(!visited[i-1][j]) {
                q.push({i-1, j});
            }
            if (i+1 >= grid.size() || grid[i+1][j] == 0){
                perimeter += 1;
            } else if(!visited[i+1][j]) {
                q.push({i+1, j});
            }
            if (j - 1 < 0 || grid[i][j-1] == 0){
                perimeter += 1;
            } else if(!visited[i][j-1]) {
                q.push({i, j-1});
            }
            if (j + 1 >= grid[0].size() || grid[i][j+1] == 0){
                perimeter += 1;
            } else if(!visited[i][j+1]) {
                q.push({i, j+1});
            }

            visited[i][j] = true;
        }

        return perimeter;
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool> (m, false));

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if (grid[i][j] == 1){
                    int perimeter = bfs(grid, i, j, visited);
                    return perimeter;
                }
            }
        }

        return 0;
    }
};