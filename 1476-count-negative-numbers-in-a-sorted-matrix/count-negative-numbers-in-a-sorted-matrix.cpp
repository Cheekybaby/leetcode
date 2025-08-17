class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int total_negatives = 0;
        for(int i=0; i<m; i++){
            int l = 0, r = n - 1;
            while (l <= r){
                int mid = midpoint(l, r);

                if (grid[i][mid] >= 0) l = mid + 1;
                else if (grid[i][mid] < 0) r = mid - 1;
            }
            total_negatives += (n - l);
        }

        return total_negatives;
    }
};