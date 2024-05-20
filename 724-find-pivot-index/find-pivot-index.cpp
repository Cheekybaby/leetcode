class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = 0;
        for (int i=0; i<nums.size(); i+=1){
            sum+=nums[i];
        }

        int i=0;
        int lsum = 0;

        while(i<nums.size()){
            int pivot = nums[i];
            int rsum = sum - (lsum+pivot);
            if (lsum == rsum){
                return i;
            }
            lsum+=pivot;
            i+=1;
        }

        return -1;
    }
};