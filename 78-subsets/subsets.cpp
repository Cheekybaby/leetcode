class Solution {
public:
    void solve(vector<int> &n, vector<vector<int>> &ans, vector<int> &subset, int i){
        if (i == n.size()){
            ans.push_back(subset);
            return ;
        }

        // We can either include
        subset.push_back(n[i]);
        solve(n, ans, subset, i+1);
        // or not
        subset.pop_back();
        solve(n, ans, subset, i+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> all_subset;
        vector<int> subset;
        solve(nums, all_subset, subset, 0);

        return all_subset;
    }
};

/*
    - We will recursively create all the subset
*/