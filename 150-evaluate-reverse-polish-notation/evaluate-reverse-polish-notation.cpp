class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int i=0;
        while (i<tokens.size()){
            string s = tokens[i];
            if (st.size() > 1){
                if (s == "+"){
                    int a = st.top();
                    st.pop();
                    int b = st.top();
                    st.pop();
                    st.push(a+b);
                } else if (s == "-"){
                    int a = st.top();
                    st.pop();
                    int b = st.top();
                    st.pop();
                    st.push(b-a);
                } else if (s == "*"){
                    int a = st.top();
                    st.pop();
                    int b = st.top();
                    st.pop();
                    st.push(b*a);
                } else if (s == "/"){
                    int a = st.top();
                    st.pop();
                    int b = st.top();
                    st.pop();
                    st.push(b/a);
                } else {
                    int x = stoi(s);
                    st.push(x);
                }
            } else {
                int x = stoi(s);
                st.push(x);
            }
            i+=1;
        }
        return st.top();
    }
};