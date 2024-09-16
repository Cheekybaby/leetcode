class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> st;
        for (int i=0; i<nums.size(); i+=1){
            if (st.count(nums[i]) == 1){
                return nums[i];
            }
            st.insert(nums[i]);
        }

        return -1;
    }
};