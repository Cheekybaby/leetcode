class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int i=0, j=0;
        while (i<nums.size() && j<nums.size()){
            if (nums[j]!=0){
                swap(nums[i], nums[j]);
                i+=1;
            }
            j+=1;
        }
    }
};