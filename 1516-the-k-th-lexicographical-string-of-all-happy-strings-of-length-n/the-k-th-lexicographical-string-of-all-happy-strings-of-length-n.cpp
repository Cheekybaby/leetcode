class Solution {
public:
    string getHappyString(int n, int k) {
        vector<char> s = {'a', 'b', 'c'};

        vector<string> ans;
        string temp;
        solve(n, s, temp, ans);

        if (ans.size() < k)
            return "";
        return ans[k-1];
    }

private:
    void solve(int n, vector<char>& s, string& temp, vector<string>& ans) {
        if (temp.length() == n) {
            ans.push_back(temp);
            return;
        }

        for(auto c:s){
            if (temp.empty() || temp.back() != c){
                temp += c;
                solve(n, s, temp, ans);
                temp.pop_back();
            }
        }
    }
};