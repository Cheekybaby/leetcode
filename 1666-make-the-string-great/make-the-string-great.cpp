class Solution {
public:
    string makeGood(string s) {
        stack<char> st;
        st.push(s[0]);
        int i=1;
        while (i<s.length()){
            char a, b;
            a = s[i];
            if (!st.empty()){
                b = st.top();
                if (abs(a - b) == 32){
                    st.pop();
                } else {
                    st.push(a);
                }
            } else {
                st.push(a);
            }

            i+=1;
        }

        string ans;
        while (!st.empty()){
            ans+=st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};