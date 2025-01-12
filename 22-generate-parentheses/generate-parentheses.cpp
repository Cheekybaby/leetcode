class Solution {
public:
    void solve(string &temp, int open, int close, int n, vector<string> &ans){
        if (open == n && close == n){
            ans.push_back(temp);
            return ;
        }

        if (open < n) {
            temp.push_back('(');
            solve(temp, open+1, close, n, ans);
            temp.pop_back();
        }

        if (close < open){
            temp.push_back(')');
            solve(temp, open, close+1, n, ans);
            temp.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string temp;
        vector<string> ans;
        solve(temp, 0, 0, n, ans);

        return ans;
    }
};