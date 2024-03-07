class Solution {
public:
    string removeStars(string s) {
        stack<char> st;
        int size = s.length(), i = 0;
        while (size--){
            char c = s[i];
            if (c == '*'){
                if (st.empty()){
                    i+=1;
                } else {
                    i+=1;
                    st.pop();
                }
                continue;
            }
            st.push(c);
            i+=1;
        }

        // Creating the final string
        string sn;
        while (st.size()){
            sn+=st.top();
            st.pop();
        }

        reverse(sn.begin(), sn.end());
        return sn;
    }
};