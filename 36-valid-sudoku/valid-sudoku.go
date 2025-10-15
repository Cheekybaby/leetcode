func isValidSudoku(board [][]byte) bool {
	// Rows
	for i := 0; i < 9; i++ {
		set := make(map[int]bool)
		for j := 0; j < 9; j++ {
			char := board[i][j]
			if char == '.' {
				continue
			}
			digit := int(char - '0')
			if _, ok := set[digit]; ok {
				return false
			}
			set[digit] = true
		}
	}
	// Columns
	for i := 0; i < 9; i++ {
		set := make(map[int]bool)
		for j := 0; j < 9; j++ {
			char := board[j][i]
			if char == '.' {
				continue
			}
			digit := int(char - '0')
			if _, ok := set[digit]; ok {
				return false
			}
			set[digit] = true
		}
	}
	// 3x3 grids
	for row := 0; row < 9; row += 3 {
		for col := 0; col < 9; col += 3 {
			set := make(map[int]bool)
			for i := row; i < row+3; i++ {
				for j := col; j < col+3; j++ {
					char := board[i][j]
					if char == '.' {
						continue
					}
					digit := int(char - '0')
					if _, ok := set[digit]; ok {
						return false
					}
					set[digit] = true
				}
			}
		}
	}

	return true
}