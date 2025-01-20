class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        unordered_map<int, pair<int,int>> mpp;
        vector<int> row(n), col(m);
        for(int i=0; i<n; i+=1){
            for(int j=0; j<m; j+=1){
                mpp[mat[i][j]] = {i, j};
            }
        }

        for(int i=0; i<arr.size(); i+=1){
            int find = arr[i];

            // Coloring
            pair<int,int> coordinate = mpp[arr[i]];
            int r = coordinate.first;
            int c = coordinate.second;

            mat[r][c] = 0;

            row[r]++;
            col[c]++;

            if (row[r] == m || col[c] == n) return i;
        }
        return -1;
    }
};