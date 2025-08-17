class Solution {
private:
    int countLessOrEqual(vector<vector<int>> &matrix, int mid){
        int cnt = 0, c = matrix.size() - 1;
        for(int i=0; i<matrix.size(); i++){
            while(c >= 0 && matrix[i][c] > mid) c--;
            cnt += (c + 1);
        }
        return cnt;
    }
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int ans = -1;
        int l = matrix[0][0], r = matrix[n-1][n-1];
        while (l <= r){
            int mid = midpoint(l,r);

            if (countLessOrEqual(matrix, mid) >= k){
                ans = mid;
                r = mid - 1;
            } else l = mid + 1;
        }
        return ans;
    }
};