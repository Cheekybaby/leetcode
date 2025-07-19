class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size(); 
        int col = matrix[0].size();
        // do a binary search on the last column to find the correct row to look for
        int l = 0 , r = row-1;
        while (l <= r){
            int mid = l + (r - l)/2;
            if (matrix[mid][col-1] == target) return true;
            else if (matrix[mid][col-1] > target) r = mid-1;
            else l = mid+1;
        }
        if (l >= row) return false;
        // now do a binary search on that row to check for the value
        int i = 0, j = col-1;
        while (i <= j){
            int mid = i + (j - i) / 2;
            if (matrix[l][mid] == target) return true;
            else if (matrix[l][mid] > target) j = mid-1;
            else i = mid+1;
        }

        return false;
    }
};