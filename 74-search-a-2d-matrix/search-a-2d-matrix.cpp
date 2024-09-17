class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // Binary Search to find the first element greater than target in the last col
        int m = matrix.size(); // Number of rows
        int n = matrix[0].size(); // Number of columns

        vector<int> lastCol;
        for (int i=0; i<m; i+=1){
            lastCol.push_back(matrix[i][n-1]);
        }
        int r = lower_bound(lastCol.begin(), lastCol.end(), target) - lastCol.begin();
        cout << r;
        if (r > m-1) return false;
        return binary_search(matrix[r].begin(), matrix[r].end(), target);
    }
};