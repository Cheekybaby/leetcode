func maxArea(height []int) int {
    i, j := 0, len(height)-1
    max_water := 0
    for i < j {
        l := min(height[i], height[j])
        b := j - i

        water := l * b
        max_water = max(max_water, water)

        if height[i] < height[j] {
            i++
        } else {
            j--
        }
    }
    return max_water
}