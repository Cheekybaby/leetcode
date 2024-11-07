class Solution {
public:
    // Global
    vector<string> keys = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> ans;

    void solve(string &digits, string &temp, int index){
        int n = digits.size();
        if (index == n){
            ans.push_back(temp);
            return ;
        }


        for(auto &it:keys[digits[index] - '0']){
            temp.push_back(it);
            solve(digits, temp, index + 1);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if (digits.length() == 0) return ans;
        string temp;
        solve(digits, temp, 0);
        return ans;
    }
};