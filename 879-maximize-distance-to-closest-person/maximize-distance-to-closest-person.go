func maxDistToClosest(seats []int) int {
    occ := []int{}
    for i, val := range seats {
        if val == 1 {
            occ = append(occ, i)
        }
    }

    max_dist := (occ[0] - 0)
    for i := 1; i < len(occ); i++ {
        mid := (occ[i] + occ[i-1])/2
        dist := min(mid - occ[i-1], occ[i] - mid)
        
        max_dist = max(max_dist, dist)
    }
    
    max_dist = max(max_dist, len(seats)- occ[len(occ)-1] - 1)
    return max_dist
}