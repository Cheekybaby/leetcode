class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if (numRows == 1) return {{1}};
        vector<vector<int>> ans;
        ans.push_back({1});
        ans.push_back({1,1});
        for(int i=2; i<numRows; i+=1){
            vector<int> above = ans.back();
            vector<int> curr;
            for(int j=0; j<=i; j+=1){
                if (j == 0 || j == i){
                    curr.push_back(1);
                    continue;
                }
                int n = above[j-1] + above[j];
                curr.push_back(n);
            }

            ans.push_back(curr);
        }

        return ans;
    }
};