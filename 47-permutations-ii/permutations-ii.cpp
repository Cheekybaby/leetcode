class Solution {
public:
    void solve(vector<int> &nums, set<vector<int>> &sol, unordered_map<int,int> &m, vector<int> &temp, int index){
        if (index == nums.size()) {
            sol.insert(temp);
            return ;
        }

        for(auto &it:nums){
            if (m[it] > 0){
                temp.push_back(it);
                m[it]--;
                solve(nums, sol, m, temp, index+1);
                temp.pop_back();
                m[it]++;
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> sol; // To store all the unique permutations
        unordered_map<int,int> m; // To keep count of each occurance
        for(auto &n:nums){
            m[n]++;
        }
        vector<int> temp;

        solve(nums, sol, m, temp, 0);

        vector<vector<int>> ans;
        for(auto &it:sol){
            ans.push_back(it);
        }

        return ans;
    }
};