func trap(height []int) int {
    total_water := 0
    l, r := 1, len(height)-2
    l_max, r_max := height[l-1], height[r+1]

    for l <= r {
        water := 0

        if l_max > r_max {
            water = max(0, (r_max - height[r]))
            r_max = max(r_max, height[r])
            r--
        } else {
            water = max(0, (l_max - height[l]))
            l_max = max(l_max, height[l])
            l++
        }
        total_water += water
    }

    return total_water
}