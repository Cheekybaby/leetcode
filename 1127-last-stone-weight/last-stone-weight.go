func lastStoneWeight(stones []int) int {
    maxHeap := &MaxHeap{}
    heap.Init(maxHeap)

    for _, stone := range stones {
        heap.Push(maxHeap, stone)
    }

    for maxHeap.Len() > 1 {
        stone1 := heap.Pop(maxHeap).(int)
        stone2 := heap.Pop(maxHeap).(int)

        if stone1 != stone2 {
            newStone := stone1 - stone2
            heap.Push(maxHeap, newStone)
        }
    }

    if maxHeap.Len() == 0 {
        return 0
    }
    return heap.Pop(maxHeap).(int)
}

// Define a new type as a slice of int
type MaxHeap []int

// The heap interface needs to implement 5 different functions
// Len(), Less(), Push(), Pop(), Swap()

func (h MaxHeap) Len() int {
    return len(h)
}

func (h MaxHeap) Less(i, j int) bool {
    return h[i] > h[j]
}

func (h MaxHeap) Swap(i, j int) {
    h[i], h[j] = h[j], h[i]
}

func (h *MaxHeap) Push(x interface{}) {
    *h = append(*h, x.(int))
}

func (h *MaxHeap) Pop() interface{} {
    old := *h
    n := len(old)
    x := old[n-1]
    *h = old[0:n-1]
    return x
}