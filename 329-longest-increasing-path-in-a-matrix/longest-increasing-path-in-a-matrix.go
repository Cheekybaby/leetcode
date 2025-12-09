var dir = [][]int{{1, 0}, {-1, 0}, {0, 1}, {0, -1}}

func dfs(matrix [][]int, i, j int, memo [][]int) int {
	if i < 0 || i >= len(matrix) || j < 0 || j >= len(matrix[0]) {
		return 0
	}
	if memo[i][j] != -1 {
		return memo[i][j]
	}

	length := 1

	for _, d := range dir {
		dr := i + d[0]
		dc := j + d[1]

        if (dr < 0 || dr >= len(matrix)) || (dc < 0 || dc >= len(matrix[0])) || matrix[dr][dc] <= matrix[i][j] {
            continue
        }

		l := dfs(matrix, dr, dc, memo)

		length = max(length, 1+l)
	}

	memo[i][j] = length

	return memo[i][j]
}

func longestIncreasingPath(matrix [][]int) int {
	max_len := 1

	memo := make([][]int, len(matrix))
	for i := range memo {
		memo[i] = make([]int, len(matrix[0]))
		for j := range memo[i] {
			memo[i][j] = -1
		}
	}

	for i := range matrix {
		for j := range matrix[i] {
			length := dfs(matrix, i, j, memo)
			max_len = max(max_len, length)
		}
	}

	return max_len
}