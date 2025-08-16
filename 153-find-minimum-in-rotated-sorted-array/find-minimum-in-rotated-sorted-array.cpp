class Solution {
public:
    int findMin(vector<int>& nums) {
        int min_element = nums[0];
        int i=0, j=nums.size()-1;
        while(i <= j){
            int mid = midpoint(i,j);

            if (nums[i] <= nums[j]){
                min_element = min(nums[i], min_element);
                break;
            }

            min_element = min(min_element, nums[mid]);

            if (nums[i] <= nums[mid]){
                i = mid + 1;
            } else {
                j = mid - 1;
            }
        }
        return min_element;
    }
};