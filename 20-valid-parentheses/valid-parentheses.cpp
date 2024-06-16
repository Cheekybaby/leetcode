class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int i = 0;
        while (i < s.length()) {
            char c = s[i];
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            } else {
                if (c == ')') {
                    if (!st.empty() && st.top() == '(')
                        st.pop();
                    else
                        return false;
                } else if (c == '}') {
                    if (!st.empty() && st.top() == '{')
                        st.pop();
                    else
                        return false;
                } else if (c == ']') {
                    if (!st.empty() && st.top() == '[')
                        st.pop();
                    else
                        return false;
                }
            }
            i += 1;
        }
        if (!st.empty()) return false;
        return true;
    }
};