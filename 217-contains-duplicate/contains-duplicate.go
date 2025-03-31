func containsDuplicate(nums []int) bool {
    seen := make(map[int]bool)

    for _, num := range nums {
        seen[num] = true;
    }

    return len(nums) != len(seen);
}