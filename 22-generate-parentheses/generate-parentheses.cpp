class Solution {
private:
    void possibleCombinations(int open, int close, int n, vector<string> &combos, string &st){
        if (open == n && close == n){
            combos.push_back(st);
            return;
        }

        if (open < n){
            st += "(";
            possibleCombinations(open+1, close, n, combos, st);
            st.pop_back();
        }
        if (close < open){
            st += ")";
            possibleCombinations(open, close+1, n, combos, st);
            st.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> combos;
        string st;
        possibleCombinations(0, 0, n, combos, st);
        return combos;
    }
};