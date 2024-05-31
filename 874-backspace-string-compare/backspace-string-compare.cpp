class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> ss;
        for (int i=0; i<s.length(); i+=1){
            if (s[i]!='#') ss.push(s[i]);
            else {
                if (ss.empty()) continue;
                ss.pop();
            }
        }
        stack<char> st;
        for (int i=0; i<t.length(); i+=1){
            if (t[i]!='#') st.push(t[i]);
            else {
                if (st.empty()) continue;
                st.pop();
            }
        }
        if (st.size() != ss.size()) return false;
        while (!st.empty() && !ss.empty()){
            if (st.top() != ss.top()) return false;
            st.pop();
            ss.pop();
        }

        return true;
    }
};