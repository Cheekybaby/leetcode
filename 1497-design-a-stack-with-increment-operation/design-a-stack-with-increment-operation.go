type CustomStack struct {
    stk []int
}


func Constructor(maxSize int) CustomStack {
    stack := make([]int, 0, maxSize)

    return CustomStack{
        stk : stack,
    }
}


func (this *CustomStack) Push(x int)  {
    if len(this.stk) < cap(this.stk) {
        this.stk = append(this.stk, x)
    }
}


func (this *CustomStack) Pop() int {
    x := -1
    if len(this.stk) > 0 {
        x = this.stk[len(this.stk)-1]
        this.stk = this.stk[:len(this.stk)-1]
    }
    return x
}


func (this *CustomStack) Increment(k int, val int)  {
    for i := 0; i < len(this.stk) && k > 0; i++ {
        this.stk[i] += val
        k--
    }
}


/**
 * Your CustomStack object will be instantiated and called as such:
 * obj := Constructor(maxSize);
 * obj.Push(x);
 * param_2 := obj.Pop();
 * obj.Increment(k,val);
 */