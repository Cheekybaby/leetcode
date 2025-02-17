class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(nums.begin(), nums.end());
        vector<bool> used(nums.size(), false);

        solve(nums, ans, temp, used, 0);

        return ans;
    }

    void solve(vector<int> &nums, vector<vector<int>> &ans, vector<int> &temp, vector<bool> &used, int index){
        if (index == nums.size()){
            ans.push_back(temp);
            return;
        }

        for(int i=0; i<nums.size(); i++){
            if (used[i] || (i > 0 && nums[i] == nums[i-1] && !used[i-1])) continue;

            temp.push_back(nums[i]);
            used[i] = true;
            solve(nums, ans, temp, used, index+1);
            used[i] = false;
            temp.pop_back();
        }
    }
};