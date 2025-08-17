class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int ans = 0;
        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
        // put the first element of all of all the rows in this min-heap
        for(int i=0; i<n; i++){
            pq.push({matrix[i][0], i, 0});
        }
        for(int i=1; i <= k; i++){
            auto top = pq.top(); pq.pop();
            int row = top[1], col = top[2];
            ans = top[0];

            if ((col+1) < n) pq.push({matrix[row][col+1], row, col+1});
        }
        return ans;
    }
};