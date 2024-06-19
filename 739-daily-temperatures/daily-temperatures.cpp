class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans(temperatures.size());
        stack<pair<int,int>> st;
        for (int i=0; i<temperatures.size(); i+=1){
            int currD = i;
            int currT = temperatures[i];

            while (!st.empty() && st.top().second < currT){
                int prevD = st.top().first;
                int prevT = st.top().second;

                st.pop();

                ans[prevD] = currD - prevD;
            }

            st.push({currD, currT});
        }

        return ans;
    }
};