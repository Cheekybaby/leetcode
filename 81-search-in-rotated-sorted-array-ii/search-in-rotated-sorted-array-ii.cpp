class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1;
        while (l <= r){
            int mid = l + (r-l)/2;
            if (nums[mid] == target) return true;
            
            if (nums[mid] == nums[l] && nums[mid] == nums[r]){
                l++;
                r--;
                continue;
            }

            if (nums[mid] >= nums[l]){
                if (target >= nums[l] && target <= nums[mid]){
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            } else {
                if (target <= nums[r] && target >= nums[mid]){
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
        }

        return false;
    }
};