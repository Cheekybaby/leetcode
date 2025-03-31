func containsDuplicate(nums []int) bool {
    seen := make(map[int]bool)

    for i:=0; i<len(nums); i++ {
        seen[nums[i]] = true;
    }

    return len(nums) != len(seen);
}