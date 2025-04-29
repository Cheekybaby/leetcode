func maxArea(height []int) int {
	i, j := 0, len(height)-1

	ans := 0

	for i <= j {
		l := j - i
		h := min(height[i], height[j])

		ans = max(ans, l*h)

		if height[i] < height[j] {
			i++
		} else {
			j--
		}
	}

    return ans
}