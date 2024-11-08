class Solution {
public:
    // Global
    vector<vector<int>> ans;

    void solve(vector<int> &candi, int target, vector<int> &temp, int index, int sum){
        if (sum == target) {
            ans.push_back(temp);
            return ;
        }

        if (sum > target || index == candi.size()) return ;

        temp.push_back(candi[index]);
        solve(candi, target, temp, index, sum+candi[index]);
        temp.pop_back();
        solve(candi, target, temp, index+1, sum);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        sort(candidates.begin(), candidates.end());

        solve(candidates, target, temp, 0, 0);

        return ans;
    }
};