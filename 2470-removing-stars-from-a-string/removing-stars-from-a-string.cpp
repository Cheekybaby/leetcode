class Solution {
public:
    string removeStars(string s) {
        stack<char> st;
        int i=0; 
        while (i<s.length()){
            char c = s[i];

            if (c == '*'){
                if (!st.empty()){
                    st.pop();
                }
            } else {
                st.push(c);
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