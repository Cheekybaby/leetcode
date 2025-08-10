class Solution {
private:
    void solve(vector<int> &nums, unordered_set<int> &st, vector<vector<int>> &ans, vector<int> &temp, int idx){
        if (idx == nums.size()){
            ans.push_back(temp);
            return;
        }

        for(auto &it:nums){
            if (st.count(it) == 0){
                st.insert(it);
                temp.push_back(it);
                solve(nums, st, ans, temp, idx+1);
                st.erase(it);
                temp.pop_back();
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        unordered_set<int> st;
        vector<int> temp;
        vector<vector<int>> ans;

        solve(nums, st, ans, temp, 0);

        return ans;
    }
};

/*
    - We need to find all the permutation of the given array nums
    - The length of nums is <= 8, so we can go for backtracking kind of solution. 
    - How do we use the backtracking?
        -
*/