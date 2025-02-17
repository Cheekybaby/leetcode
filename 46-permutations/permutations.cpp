class Solution {
public:
    void solve(vector<int> &nums, vector<vector<int>> &ans, unordered_set<int> &st, vector<int> &temp, int index){
        if (index == nums.size()){
            ans.push_back(temp);
            return ;
        }

        for(auto &it:nums){
            if (st.count(it) == 0){
                temp.push_back(it);
                st.insert(it);
                solve(nums, ans, st, temp, index+1);
                temp.pop_back();
                st.erase(it);
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        unordered_set<int> st;
        vector<int> temp;

        solve(nums, ans, st, temp, 0);

        return ans;
    }
};