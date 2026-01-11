func minOperations(nums []int, k int) int {
    min_pq := &MinHeap{}
    heap.Init(min_pq)

    for _, num := range nums {
        heap.Push(min_pq, num)
    }
    ops := 0
    for min_pq.Len() >= 2 {
        x := heap.Pop(min_pq).(int)
        y := heap.Pop(min_pq).(int)

        if x >= k && y >= k {
            break
        }
        
        val := min(x, y) * 2 + max(x, y)
        ops++
        
        heap.Push(min_pq, val)
    }

    return ops
}

type MinHeap []int

func (pq MinHeap) Len() int {
    return len(pq)
}
func (pq MinHeap) Less(i, j int) bool {
    return pq[i] < pq[j]
}
func (pq MinHeap) Swap(i, j int) {
    pq[i], pq[j] = pq[j], pq[i]
}
func (pq *MinHeap) Push(x any) {
    *pq = append(*pq, x.(int))
}
func (pq *MinHeap) Pop() any {
    temp := *pq
    x := temp[len(temp)-1]
    *pq = temp[:len(temp)-1]

    return x
}