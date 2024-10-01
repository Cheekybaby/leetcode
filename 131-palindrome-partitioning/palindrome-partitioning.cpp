class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<string> temp;
        vector<vector<string>> ans;
        int index = 0;
        solve(s, ans, temp, index);
        return ans;
    }

private:
    void solve(string &s, vector<vector<string>> &ans, vector<string> &temp, int index){
        if (index >= s.size()){
            ans.push_back(temp);
            return ;
        }

        for (int i=index; i<s.size(); i+=1){
            if (isPalindrome(s, index, i)){
                temp.push_back(s.substr(index, i-index+1));
                solve(s, ans, temp, i+1);
                temp.pop_back();
            }
        }
    }

    bool isPalindrome(string &s, int start, int end){
        while (start <= end){
            if (s[start] != s[end]){
                return false;
            }
            start+=1;
            end-=1;
        }

        return true;
    }
};