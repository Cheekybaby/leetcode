class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0, right = nums.size()-1;
        while (left <= right){
            int mid = midpoint(left, right);
            if (mid>0 && nums[mid]<nums[mid-1]) right = mid - 1;
            else if (mid<nums.size()-1 && nums[mid]<nums[mid+1]) left = mid + 1;
            else return mid;
        }
        return -1;
    }
};