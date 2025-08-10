class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int i = x, j = x + k - 1;

        while(i < j){
            for(int l = y; l < y + k; l++){
                swap(grid[i][l], grid[j][l]);
            }

            i++; j--;
        }

        return grid;
    }
};

/*
    - x here is the starting row, y is the starting column
    - So (x, y) represents the starting index in the grid
    - k represents the size of the submatrix.

    - We need to reverse the rows of the given submatrix

*/