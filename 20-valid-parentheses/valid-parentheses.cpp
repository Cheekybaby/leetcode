static const unordered_map<char, char> bracket_pairs{
    {')', '('}, {']', '['}, {'}', '{'}};
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (char& c : s) {
            if (bracket_pairs.count(c)) {
                if (st.empty() || bracket_pairs.at(c) != st.top())
                    return false;
                st.pop();
            } else {
                st.push(c);
            }
        }
        return st.empty();
    }
};