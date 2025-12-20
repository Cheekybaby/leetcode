func wateringPlants(nums []int, capacity int) int {
    steps := 0
    water := capacity
    for i := 0; i < len(nums); i++ {
        if nums[i] <= water {
            water -= nums[i]
            steps++
        } else {
            water = (capacity - nums[i])
            steps += (i + i + 1)
        }
    }

    return steps
}