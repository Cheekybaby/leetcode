class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int numRows = grid.size(), numCols = grid[0].size();

        vector<vector<int>> minChanges(numRows, vector<int>(numCols, INT_MAX));
        minChanges[0][0] = 0;

        while (true) {
            vector<vector<int>> prevState = minChanges;

            for (int i = 0; i < numRows; i += 1) {
                for (int j = 0; j < numCols; j += 1) {
                    if (i > 0) {
                        minChanges[i][j] =
                            min(minChanges[i][j],
                                minChanges[i - 1][j] +
                                    (grid[i - 1][j] == 3 ? 0 : 1));
                    }
                    if (j > 0) {
                        minChanges[i][j] =
                            min(minChanges[i][j],
                                minChanges[i][j - 1] +
                                    (grid[i][j - 1] == 1 ? 0 : 1));
                    }
                }
            }

            for (int i = numRows - 1; i >= 0; i--) {
                for (int j = numCols - 1; j >= 0; j--) {
                    if (i < numRows - 1) {
                        minChanges[i][j] = min(minChanges[i][j],
                                               minChanges[i + 1][j] +
                                                   (grid[i+1][j] == 4 ? 0 : 1));
                    }
                    if (j < numCols - 1) {
                        minChanges[i][j] = min(minChanges[i][j],
                                               minChanges[i][j + 1] +
                                                   (grid[i][j+1] == 2 ? 0 : 1));
                    }
                }
            }

            if (prevState == minChanges)
                break;
        }

        return minChanges[numRows - 1][numCols - 1];
    }
};