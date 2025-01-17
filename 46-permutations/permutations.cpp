class Solution {
public:
    void solve(vector<int> &nums, vector<vector<int>> &ans, int i, set<int> &temp, vector<int> &sol){
        if (i == nums.size()){
            ans.push_back(sol);
            return ;
        }

        for(auto &it:nums){
            if (temp.count(it) == 0){
                sol.push_back(it);
                temp.insert(it);
                solve(nums, ans, i+1, temp, sol);
                sol.pop_back();
                temp.erase(it);
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        set<int> temp;
        vector<int> sol;
        solve(nums, ans, 0, temp, sol);

        return ans;
    }
};