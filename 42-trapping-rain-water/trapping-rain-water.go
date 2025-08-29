func trap(height []int) int {
    i, j := 1, len(height)-2
    lmax, rmax := height[0], height[len(height)-1]
    total_water := 0

    for i <= j {
        water := 0
        if lmax >= rmax {
            water = max(0, rmax - height[j])
            rmax = max(rmax, height[j])
            j--
        } else {
            water = max(0, lmax - height[i])
            lmax = max(lmax, height[i])
            i++
        }
        total_water += water
    }
    return total_water
}