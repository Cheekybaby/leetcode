class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for(int a:asteroids){
            if (st.empty()){
                st.push(a);
                continue;
            }
            bool flag = true;
            while(!st.empty() && (a < 0 && st.top() > 0)){
                int b = st.top();
                st.pop();
                if (abs(a) == abs(b)){
                    flag = false;
                    break;
                } else if (abs(a) < abs(b)){
                    a = b;
                }
            }
            if (flag) st.push(a);
        }

        vector<int> left_ast(st.size(), 0);
        while(!st.empty()){
            left_ast[st.size()-1] = st.top();
            st.pop();
        }
        return left_ast;
    }
};