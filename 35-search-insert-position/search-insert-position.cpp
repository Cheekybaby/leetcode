class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = lower_bound(nums, target);
        return l;
    }

private:
    int lower_bound(vector<int> &nums, int target){
        int l = 0, r = nums.size()-1;
        while (l <= r){
            int mid = midpoint(l, r);
            if (nums[mid] == target){
                if(mid == 0) return mid;
                else{
                    if (nums[mid-1] != target) return mid;
                    else r = mid - 1;
                }
            } else if (nums[mid] > target){
                if (mid == 0) return mid;
                else {
                    if (nums[mid-1] < target) return mid;
                    else r = mid - 1;
                }
            } else {
                if (mid == nums.size()-1) return nums.size();
                else l = mid + 1;
            }
        }

        return -1;
    }
};