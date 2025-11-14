func countCollisions(directions string) int {
    var stack []byte
    collisions := 0

    for i := range directions {
        curr_dir := directions[i]
        if curr_dir == 'L' {
            for len(stack) > 0 {
                last_dir := stack[len(stack)-1]
                
                if curr_dir == 'R' {
                    break
                } else if curr_dir == last_dir {
                    break
                } else if curr_dir == 'S' && last_dir == 'L' {
                    break
                }

                if curr_dir == 'L' && last_dir == 'R' {
                    collisions += 2
                } else if curr_dir == 'L' && last_dir == 'S' {
                    collisions += 1
                } else if curr_dir == 'S' && last_dir == 'R' {
                    collisions += 1
                }

                curr_dir = 'S'
                stack = stack[:len(stack)-1]
            }
        } else if curr_dir == 'S' {
            for len(stack) > 0 {
                last_dir := stack[len(stack)-1]
                if last_dir == curr_dir || last_dir == 'L' {
                    break
                }
                collisions += 1
                stack = stack[:len(stack)-1]
            }
        }
        stack = append(stack, curr_dir)
    }


    return collisions
}