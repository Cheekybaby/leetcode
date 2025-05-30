class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1;
        while(l <= r){
            int mid = midpoint(l, r);
            if (nums[mid] == target) return mid;
            else if (nums[mid] >= nums[l]){
                if (nums[l] <= target && target <= nums[mid]){
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            } else {
                if (nums[mid] <= target && target <= nums[r]){
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
        }

        return -1;
    }
};