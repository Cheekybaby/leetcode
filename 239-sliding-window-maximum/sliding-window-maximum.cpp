class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset<int, greater<int>> st;
        vector<int> ans;

        int i=0, j=0;
        while (j < k) {
            st.insert(nums[j]);
            j+=1;
        }

        auto it = st.begin();
        ans.push_back(*it);

        while (j < nums.size()){
            st.insert(nums[j]);

            auto x = st.find(nums[i]);
            st.erase(x);

            it = st.begin();
            ans.push_back(*it);

            i+=1;
            j+=1;
        }
        return ans;
    }
};