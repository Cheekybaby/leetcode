func topKFrequent(nums []int, k int) []int {
    minHeap :=  &MinHeap{}
    heap.Init(minHeap)

    freq := make(map[int]int)

    for _, num := range nums {
        freq[num]++
    }

    for key, f := range freq {
        heap.Push(minHeap, Pair{key, f})
        if minHeap.Len() > k {
            heap.Pop(minHeap)
        }
    }

    var ans []int

    for minHeap.Len() > 0 {
        x := heap.Pop(minHeap).(Pair)
        ans = append(ans, x.num)
    }

    return ans
}

type Pair struct {
    num int
    fre int
}

type MinHeap []Pair

func (h MinHeap) Len() int {
    return len(h)
}

func (h MinHeap) Less(i, j int) bool {
    return h[i].fre < h[j].fre
}

func (h MinHeap) Swap(i, j int) {
    h[i], h[j] = h[j], h[i]
}

func (h *MinHeap) Push(x interface{}) {
    *h = append(*h, x.(Pair))
}

func (h *MinHeap) Pop() interface{} {
    old := *h
    n := len(old)
    x := old[n-1]
    *h = old[0:n-1]
    return x
}