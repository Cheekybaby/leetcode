class Solution {
public:
    void sortColors(vector<int>& nums) {
        int r = 0, w = 0, b = nums.size()-1;

        while (w <= b){
            if (nums[w] == 0){
                swap(nums[w], nums[r]);
                r+=1;
                w+=1;
            } else if (nums[w] == 1){
                w+=1;
            } else {
                swap(nums[w], nums[b]);
                b-=1;
            }
        }
    }
};