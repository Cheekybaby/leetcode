class Solution {
public:
    int numTilePossibilities(string tiles) {
        unordered_set<string> ans;
        string temp;
        vector<bool> used(tiles.length(), false);

        solve(tiles, temp, used, ans);

        for (auto& it : ans) {
            cout << it << endl;
        }

        return ans.size()-1;
    }

private:
    void solve(string& s, string& temp, vector<bool>& used,
               unordered_set<string>& ans) {
        ans.insert(temp);
        for (int i = 0; i < s.length(); i++) {
            if (!used[i]) {
                temp.push_back(s[i]);
                used[i] = true;
                solve(s, temp, used, ans);
                temp.pop_back();
                used[i] = false;
            }
        }
    }
};