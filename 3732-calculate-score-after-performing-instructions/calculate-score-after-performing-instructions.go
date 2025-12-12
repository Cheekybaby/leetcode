func calculateScore(instructions []string, values []int) int64 {
    score := int64(0)
    i := 0
    for i >=0 && i < len(instructions) {
        instr := instructions[i]
        val := values[i]

        j := i
        if instr == "jump" {
            i += val
        } else if instr == "add" {
            score += int64(val)
            i+=1
        } else {
            break
        }

        instructions[j] = "done"
    }
    return score
}