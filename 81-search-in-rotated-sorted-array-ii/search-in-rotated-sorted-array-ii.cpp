class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int i = 0, j = nums.size()-1;
        while(i <= j){
            int mid = midpoint(i,j);
            if (nums[mid] == target) return true;

            if (nums[i] == nums[mid] && nums[j] == nums[mid]) {
                i++; j--;
                continue;
            }
            if (nums[mid] >= nums[i]){
                if (nums[mid] > target && nums[i] <= target) j = mid - 1;
                else i = mid + 1;
            } else {
                if (target > nums[mid] && target <= nums[j]) i = mid + 1;
                else j = mid - 1;
            }
        }

        return false;
    }
};