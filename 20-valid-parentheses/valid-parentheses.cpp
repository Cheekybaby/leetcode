class Solution {
private:
    bool isOpen(char c){
        if (c == '(' || c == '[' || c == '{') return true;
        return false;
    }
    bool isValidPair(char c, char t){
        if (c == '(' && t == ')') return true;
        if (c == '{' && t == '}') return true;
        if (c == '[' && t == ']') return true;
        return false;
    }
public:
    bool isValid(string s) {
        stack<char> st;
        for(char c:s){
            if (isOpen(c)){
                st.push(c);
            } else {
                if (st.empty()) return false;
                if (isValidPair(st.top(), c)){
                    st.pop();
                } else {
                    return false;
                }
            }
        }
        if (st.empty()) return true;
        return false;
    }
};