class Solution {
public:
    void sortColors(vector<int>& nums) {
        int r = 0, w = 0, b = 0;

        for (int i=0; i<nums.size(); i+=1){
            if (nums[i] == 0) r+=1;
            else if (nums[i] == 1) w+=1;
            else b+=1;
        }

        for (int i=0; i<nums.size(); i+=1){
            if (r > 0){
                nums[i] = 0;
                r-=1;
            } else if (w > 0){
                nums[i] = 1;
                w-=1;
            } else {
                nums[i] = 2;
                b-=1;
            }
        }
    }
};