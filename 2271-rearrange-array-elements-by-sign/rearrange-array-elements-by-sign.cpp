class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> negative;
        vector<int> positive;

        for (int i=0; i<nums.size(); i++){
            if(nums[i]<0){
                negative.push_back(nums[i]);
            } else {
                positive.push_back(nums[i]);
            }
        }

        int j=0, i=0; 
        while(j<nums.size()/2){
            nums[i] = positive[j];
            nums[i+1] = negative[j];
            i+=2;
            j++;
        }

        return nums;
    }
};