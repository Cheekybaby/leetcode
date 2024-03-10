class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for (auto ast:asteroids){
            while (!st.empty() && st.top()>0 && ast<0){
                int diff = st.top() + ast;
                if (diff > 0){
                    ast = 0;
                } else if (diff < 0){
                    st.pop();
                } else {
                    ast = 0;
                    st.pop();
                }
            }
            if (ast!=0){
                st.push(ast);
            }
        }

        vector<int> ans;
        while (!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};