class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxi = INT_MIN;
        for (auto it:nums){
            maxi = max(it, maxi);
        }

        int i=0, j=0;
        long long count = 0;
        while (j<nums.size()){
            if (nums[j] == maxi){
                k--;
            }
            j+=1;
            while (k == 0){
                if (nums[i] == maxi) k+=1;
                i+=1;
            }
            count+=i;
        }

        return count;
    }
};