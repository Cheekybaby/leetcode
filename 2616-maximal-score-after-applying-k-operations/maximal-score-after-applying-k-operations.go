func maxKelements(nums []int, k int) int64 {
    pq := &MaxHeap{}
    heap.Init(pq)

    for _, num := range nums {
        heap.Push(pq, num)
    }
    
    var score int64
    for k > 0 {
        top := heap.Pop(pq).(int)

        score += int64(top)

        val := top / 3
        if top % 3 != 0 {
            val += 1
        }

        heap.Push(pq, val)

        k--
    }

    return score
}

type MaxHeap []int

// Length, Less, Swap
func (pq MaxHeap) Len() int {
    return len(pq)
}

func (pq MaxHeap) Less(i, j int) bool {
    return pq[i] > pq[j] // this is for MaxHeap, reverse it for MinHeap
}

func (pq MaxHeap) Swap(i, j int) {
    pq[i], pq[j] = pq[j], pq[i]
}

// Push, Pop
func (pq *MaxHeap) Push(x any) {
    *pq = append(*pq, x.(int))
}

func (pq *MaxHeap) Pop() any {
    old := *pq
    x := old[len(old)-1]
    *pq = old[:len(old)-1]
    return x
}