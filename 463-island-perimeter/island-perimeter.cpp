class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int perimeter = 0;
        for (int i=0; i<grid.size(); i+=1){
            for (int j=0; j<grid[0].size(); j+=1){
                if (grid[i][j] == 1){
                    perimeter+=4;
                    if (j>0 && grid[i][j-1] == 1){
                        perimeter-=2;
                    }
                    if (i>0 && grid[i-1][j] == 1){
                        perimeter-=2;
                    }
                }
            }
        }

        return perimeter;
    }
};