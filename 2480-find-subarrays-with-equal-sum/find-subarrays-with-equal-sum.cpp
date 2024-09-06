class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        if (nums.size() == 2) return false;

        set<int> st;

        int i=0, j=0;
        int sum = 0;
        while (j < nums.size()){
            sum += nums[j];

            if (j-i+1 == 2){
                if (st.count(sum)){
                    return true;
                }
                st.insert(sum);
                sum-=nums[i];
                i+=1;
            }

            j+=1;
        }
        return false;
    }
};