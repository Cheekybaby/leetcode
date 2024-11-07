class Solution {
public:
    void solve(vector<string> &ans, int n, string &temp, int i=0, int j=0){
        if (i == n && j == n){
            ans.push_back(temp);
            return ;
        }

        if (i <= n-1){
            temp.push_back('(');
            solve(ans, n, temp, i+1, j);
            temp.pop_back();
        }

        if (j <= n-1 && j < i){
            temp.push_back(')');
            solve(ans, n, temp, i, j+1);
            temp.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string temp;
        solve(ans, n, temp);

        return ans;
    }
};