type MinStack struct {
    Minimum     int
    Stack       []int
}

func newMinStack(stack []int, minimum int) MinStack {
    return MinStack {
        Minimum :   minimum,
        Stack   :   stack,
    }
}

func Constructor() MinStack {
    var stack []int
    minimum := math.MaxInt

    return newMinStack(stack, minimum)
}


func (this *MinStack) Push(val int)  {
    this.Stack = append(this.Stack, val)
    this.Minimum = min(this.Minimum, val)
}


func (this *MinStack) Pop()  {
    this.Stack = this.Stack[:len(this.Stack)-1]

    this.Minimum = this.FindMin()
}


func (this *MinStack) Top() int {
    return this.Stack[len(this.Stack)-1]
}


func (this *MinStack) GetMin() int {
    return this.Minimum
}

func (this *MinStack) FindMin() int {
    mini := math.MaxInt

    for i := range this.Stack {
        mini = min(mini, this.Stack[i])
    }

    return mini
}

/**
 * Your MinStack object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Push(val);
 * obj.Pop();
 * param_3 := obj.Top();
 * param_4 := obj.GetMin();
 */