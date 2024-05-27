class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> st;
        int i=0, j=0;
        while (j<nums.size()){
            while (j-i <= k && j<nums.size()){
                if (st.find(nums[j]) != st.end()) return true;
                st.insert(nums[j]);
                j+=1;
            }
            st.erase(nums[i]);
            i+=1;
        }

        return false;
    }
};