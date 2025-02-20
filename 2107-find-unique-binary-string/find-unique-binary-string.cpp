class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        string temp;
        unordered_set<string> num;
        vector<string> ans;
        for(auto &it:nums){
            num.insert(it);
        }

        solve(n, temp, num, ans);

        // for(auto &it:ans) cout << it << " ";

        return ans[0];
    }
private:
    void solve(int n, string &temp, unordered_set<string> &num, vector<string> &ans){
        if (temp.length() == n){
            if (num.count(temp) == 0) {
                ans.push_back(temp);
            }
            return ;
        }

        temp += "0";
        solve(n, temp, num, ans);
        temp.pop_back();
        temp += "1";
        solve(n, temp, num, ans);
        temp.pop_back();
    }
};