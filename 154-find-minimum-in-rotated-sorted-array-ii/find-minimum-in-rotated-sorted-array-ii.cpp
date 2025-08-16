class Solution {
public:
    int findMin(vector<int>& nums) {
        int min_element = nums[0];
        int i=0, j=nums.size()-1;
        while(i <= j){
            int mid = midpoint(i, j);

            if (nums[i] < nums[j]){
                min_element = min(min_element, nums[i]);
                break;
            }

            min_element = min(min_element, nums[mid]);
            // We need to be more precise how to move

            // If left and right both are same
            if (nums[i] == nums[j]){
                i++; j--;
                continue;
            }
            if (nums[mid] < nums[i] && nums[mid] <= nums[j]) j = mid - 1;
            else i = mid + 1;
        }

        return min_element;
    }
};