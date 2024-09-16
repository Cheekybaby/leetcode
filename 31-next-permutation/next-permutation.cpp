class Solution {
public:
    void reverse(vector<int> &nums, int left, int right){
        while (left <= right){
            swap(nums[left], nums[right]);
            left += 1;
            right -= 1;
        }
    }
    void nextPermutation(vector<int>& nums) {
        // Find the breaking index fron the back of the array
        int idx = nums.size()-2;
        while (idx >= 0){
            if (nums[idx] < nums[idx + 1]){
                break;
            }
            idx -= 1;
        }

        if (idx == -1){
            reverse(nums, 0, nums.size()-1);
        } else {
            // Find the next greater element in the right half
            int mini = INT_MAX, minidx = idx;
            for (int i=idx+1; i<nums.size(); i+=1){
                if (nums[i] > nums[idx]){
                    if (mini >= nums[i]){
                        mini = nums[i];
                        minidx = i;
                    }
                }
            }
            // Swap the new found element with the nums[idx] element
            swap(nums[idx], nums[minidx]);

            // Reverse the rest of the array
            reverse(nums, idx + 1, nums.size()-1);
        }
    }
};