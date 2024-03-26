class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(int i=0; i<n; i+=1){
            int num = nums[i];

            while (num>=1 && num<=n && nums[num-1]!=num && num!=i+1){
                swap(nums[i], nums[num-1]);
                num = nums[i];
            }
        }

        for (int i=0; i<n; i+=1){
            if (nums[i] != i+1){
                return i+1;
            }
        }

        return n+1;
    }
};