class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        unordered_set<int> st;
        for (int i=1; i<=nums.size(); i+=1){
            st.insert(i);
        }

        for (int i=0; i<nums.size(); i+=1){
            if (st.count(nums[i])!=0) st.erase(nums[i]);
        }

        for (auto it:st){
            ans.push_back(it);
        }

        return ans;
    }
};