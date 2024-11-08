class Solution {
public:
    // Global
    vector<vector<int>> ans;
    vector<int> temp;

    void solve(vector<int> &candi, int target, int index, int sum){
        if (sum == target){
            ans.push_back(temp);
            return ;
        }

        if (sum > target || index == candi.size()) return ;

        temp.push_back(candi[index]);
        solve(candi, target, index + 1, sum+candi[index]);
        temp.pop_back();
        while(index+1 < candi.size() && candi[index] == candi[index+1]){
            index += 1;
        }
        solve(candi, target, index + 1, sum);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        solve(candidates, target, 0, 0);
        return ans;
    }
};