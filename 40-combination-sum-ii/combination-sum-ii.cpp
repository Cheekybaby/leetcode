class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> temp;
        int index = 0;
        solve(candidates, target, ans, temp, index);
        return ans;
    }
private:
    void solve(vector<int> &candidates, int target, vector<vector<int>> &ans, vector<int>& temp, int index){
        if (target == 0){
            ans.push_back(temp);
            return ;
        }
        if (index >= candidates.size() || target < 0){
            return ;
        }

        for (int i=index; i<candidates.size(); i+=1){
            if (i > index && candidates[i] == candidates[i-1]){
                // skip the element
                continue;
            }

            if (candidates[i] > target){
                break;
            }

            temp.push_back(candidates[i]);
            solve(candidates, target - candidates[i], ans, temp, i+1);
            temp.pop_back();
        }
    }
};