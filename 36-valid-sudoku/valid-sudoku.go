func isValidSudoku(board [][]byte) bool {
	// Check all the rows
	for i := 0; i < 9; i++ {
		set := make(map[byte]int)
		for j := 0; j < 9; j++ {
			char := board[i][j]

			if char == '.' {
				continue
			}

			if _, ok := set[char]; ok {
				return false
			}
			set[char]++
		}
	}
	// Check all the columns
	for i := 0; i < 9; i++ {
		set := make(map[byte]int)
		for j := 0; j < 9; j++ {
			char := board[j][i]

			if char == '.' {
				continue
			}

			if _, ok := set[char]; ok {
				return false
			}
			set[char]++
		}
	}
	// Check all 9 3x3 submatrix
	for r := 0; r < 9; r += 3 {
		for c := 0; c < 9; c += 3 {
			set := make(map[byte]int)
			for i := r; i < r+3; i++ {
				for j := c; j < c+3; j++ {
					char := board[i][j]

					if char == '.' {
						continue
					}

					if _, ok := set[char]; ok {
						return false
					}
					set[char]++
				}
			}
		}
	}
	return true
}