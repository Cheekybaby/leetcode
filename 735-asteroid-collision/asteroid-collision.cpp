class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st;
        for (auto it:asteroids){
            while(!st.empty() && st.back() > 0 && it < 0){
                int diff = st.back() + it;

                if (diff > 0){
                    it = 0;
                } else if (diff == 0){
                    st.pop_back();
                    it = 0;
                } else {
                    st.pop_back();
                }
            }
            if (it != 0) {
                st.push_back(it);
            }
        }
        return st;
    }
};