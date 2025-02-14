class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.length();
        stack<char> st;
        int open = 0;
        for(int i=0; i<n; i++){
            if (s[i] == '('){
                st.push('(');
                open++;
            } else if (s[i] == ')'){
                if (!st.empty() && open > 0){
                    st.push(')');
                    open--;
                }
            } else {
                st.push(s[i]);
            }
        }

        s.clear();

        while(!st.empty()){
            char c = st.top();
            st.pop();

            if (c == '('){
                if (open > 0){
                    open--;
                    continue;
                } else {
                    s += c;
                }
            } else {
                s += c;
            }
        }

        reverse(s);
        return s;
    }

private:
    void reverse(string &s){
        int i=0, j = s.length()-1;
        while(i < j){
            swap(s[i], s[j]);
            i++; j--;
        }
    }
};