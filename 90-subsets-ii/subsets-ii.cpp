class Solution {
public:
    void solve(vector<int> &nums, vector<int> &temp, vector<vector<int>> &ans, int idx){
        if (idx == nums.size()){
            ans.push_back(temp);
            return ;
        }

        temp.push_back(nums[idx]);
        solve(nums, temp, ans, idx + 1);

        temp.pop_back();

        while (idx+1 < nums.size() && nums[idx] == nums[idx+1]){
            idx += 1;
        }

        solve(nums, temp, ans, idx + 1);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;

        sort(nums.begin(), nums.end());

        solve(nums, temp, ans, 0);

        return ans;
    }
};