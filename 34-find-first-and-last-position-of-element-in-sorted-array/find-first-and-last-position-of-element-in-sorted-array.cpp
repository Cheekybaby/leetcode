class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = lower_bound(nums, target);
        int r = upper_bound(nums, target);
        return {l, r};
    }

private:
    int lower_bound(vector<int> &nums, int target){
        int l = 0, r = nums.size()-1;
        while(l <= r){
            int mid = midpoint(l, r);
            if (nums[mid] == target){
                if (mid == 0) return mid;
                else {
                    if (nums[mid-1] != target) return mid;
                    else r = mid - 1;
                }
            } else if (nums[mid] > target){
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return -1;
    }
    int upper_bound(vector<int> &nums, int target){
        int l = 0, r = nums.size()-1;
        while(l <= r){
            int mid = midpoint(l, r);
            if (nums[mid] == target){
                if (mid == nums.size()-1) return mid;
                else {
                    if (nums[mid+1] != target) return mid;
                    else l = mid + 1;
                }
            } else if (nums[mid] > target){
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return -1;
    }
};