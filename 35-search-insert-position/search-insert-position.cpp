class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = -1, right = nums.size();
        int mid;
        while (right-left>1){
            mid = midpoint(left, right);
            if (nums[mid] == target){
                return mid;
            } else if (nums[mid]>target){
                right = mid;
            } else {
                left = mid;
            }
        }

        return left+1;
    }
};