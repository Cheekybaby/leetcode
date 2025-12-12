type MinHeap [][]int

func (h MinHeap) Len() int {
    return len(h)
}
func (h MinHeap) Less(i, j int) bool {
    return h[i][0] < h[j][0]
}
func (h MinHeap) Swap(i, j int) {
    h[i], h[j] = h[j], h[i]
}
func (h *MinHeap) Push(x any) {
    *h = append(*h, x.([]int))
}
func (h *MinHeap) Pop() any {
    old := *h
    n := len(old)
    x := old[n-1]
    *h = old[:n-1]
    return x
}


func kClosest(points [][]int, k int) [][]int {
    h := &MinHeap{}
    heap.Init(h)

    for _, point := range points {
        x := point[0]
        y := point[1]

        dist := (x * x) + (y * y)

        heap.Push(h, []int{dist, x, y})
    }
    closest := make([][]int, k)
    for i := 0; i < k; i++ {
       item := heap.Pop(h).([]int)
       closest[i] = []int{item[1], item[2]}
    }
    return closest
}