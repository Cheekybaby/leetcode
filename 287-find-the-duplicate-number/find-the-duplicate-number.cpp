class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // Initialize the fast and slow pointer
        int slow = nums[0];
        int fast = nums[nums[0]];

        // Find the cycle
        while (slow != fast){
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        // Start slow from start and continue fast as it is.
        // The element at which they meet is the duplicate value.
        slow = 0;
        while (slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};