func memLeak(memory1 int, memory2 int) []int {
    time := 1
    used_mem := 0
    for memory1 >= time || memory2 >= time {
        if memory1 >= memory2 {
            used_mem += time
            memory1 -= time
        } else {
            used_mem += time
            memory2 -= time
        }
        time += 1
    }

    return []int{time, memory1, memory2}
}