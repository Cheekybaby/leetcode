type SmallestInfiniteSet struct {
    set []int
}


func Constructor() SmallestInfiniteSet {
    const size = 1100
    set := make([]int, size)
    for i := range set {
        set[i] = i + 1
    }

    return SmallestInfiniteSet {
        set : set,
    }
}


func (this *SmallestInfiniteSet) PopSmallest() int {
    var i int
    for i = 0; i < len(this.set); i++ {
        if this.set[i] != 0 {
            break
        }
    }
    x := this.set[i]
    this.set[i] = 0
    return x
}


func (this *SmallestInfiniteSet) AddBack(num int)  {
    this.set[num-1] = num
}


/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * obj := Constructor();
 * param_1 := obj.PopSmallest();
 * obj.AddBack(num);
 */