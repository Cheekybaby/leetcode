class Solution {
public:
    void solve(vector<int> &candidates, int target, vector<int> &temp, vector<vector<int>> &ans, int sum, int index){
        if (sum == target){
            ans.push_back(temp);
            return ;
        }

        if (sum > target || index >= candidates.size()){
            return ;
        }


        temp.push_back(candidates[index]);
        solve(candidates, target, temp, ans, sum + candidates[index], index);
        temp.pop_back();
        solve(candidates, target, temp, ans, sum, index + 1);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        int sum = 0, index = 0;
        solve(candidates, target, temp, ans, sum, index);

        return ans;
    }
};