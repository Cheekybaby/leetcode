class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> temp;

        solve(nums, ans, temp, 0);

        return ans;
    }

private:
    void solve(vector<int>& nums, vector<vector<int>>& ans, vector<int>& temp,
               int index) {
        if (index == nums.size()) {
            ans.push_back(temp);
            return;
        }

        temp.push_back(nums[index]);
        solve(nums, ans, temp, index + 1);
        temp.pop_back();

        while (index + 1 < nums.size() && nums[index] == nums[index + 1]) {
            index++;
        }

        solve(nums, ans, temp, index + 1);
    }
};