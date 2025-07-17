class Solution {
private:
    unordered_map<char,char> bracket_pairs {
        {')', '('},
        {']', '['},
        {'}', '{'}
    };
public:
    bool isValid(string s) {
        stack<char> st;
        for(char &c:s){
            if (bracket_pairs.count(c)){
                if (st.empty() || bracket_pairs[c] != st.top()) return false;
                st.pop();
            } else {
                st.push(c);
            }
        }
        return st.empty();
    }
};