class Solution {
private:
    pair<int,int> operands(stack<int> &st){
        int a = st.top();
        st.pop();
        int b = st.top();
        st.pop();
        return {a, b};
    }
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(auto &s:tokens){
            if (s == "+"){
                if (st.size() >= 2){
                    auto [a, b] = operands(st);
                    st.push(b + a);
                }
            } else if (s == "-"){
                if (st.size() >= 2){
                    auto [a, b] = operands(st);
                    st.push(b - a);
                }
            } else if (s == "*"){
                if (st.size() >= 2){
                    auto [a, b] = operands(st);
                    st.push(b * a);
                }
            } else if (s == "/"){
                if (st.size() >= 2){
                    auto [a, b] = operands(st);
                    st.push(b / a);
                }
            } else {
                int x = stoi(s);
                st.push(x);
            }
        }
        return st.top();
    }
};