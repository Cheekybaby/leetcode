type MyHashSet struct {
    set []int
}


func Constructor() MyHashSet {
    return MyHashSet{set : []int{}}
}


func (this *MyHashSet) Add(key int)  {
    if !this.Contains(key) {
        this.set = append(this.set, key)
    }
}


func (this *MyHashSet) Remove(key int)  {
    var temp []int
    for i := range this.set {
        if this.set[i] == key {
            continue
        }
        temp = append(temp, this.set[i])
    }
    this.set = temp
}


func (this *MyHashSet) Contains(key int) bool {
    for i := range this.set {
        if this.set[i] == key {
            return true
        }
    }
    return false
}


/**
 * Your MyHashSet object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Add(key);
 * obj.Remove(key);
 * param_3 := obj.Contains(key);
 */