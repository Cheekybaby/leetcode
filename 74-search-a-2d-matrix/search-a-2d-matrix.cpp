class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int i = 0, j = m-1;
        while (i <= j){
            int mid = midpoint(i, j);

            if (matrix[mid][n-1] == target) return true;
            else if (matrix[mid][n-1] > target) j = mid - 1;
            else i = mid + 1;
        }

        if (i > m-1) return false;

        int l = 0, r = n-1;
        while(l <= r){
            int mid = midpoint(l, r);
            
            if (matrix[i][mid] == target) return true;
            else if (matrix[i][mid] > target) r = mid - 1;
            else l = mid + 1;
        }

        return false;
    }
};