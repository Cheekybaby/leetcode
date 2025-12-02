type MyHashMap struct {
	hmap []int
}

func Constructor() MyHashMap {
	temp := make([]int, 1000100)

	block := make([]int, 1024)
	for i := range block {
		block[i] = -1
	}

	for i := 0; i < len(temp); i += len(block) {
		copy(temp[i:], block)
	}

	return MyHashMap{
		hmap: temp,
	}
}

func (this *MyHashMap) Put(key int, value int) {
	this.hmap[key] = value
}

func (this *MyHashMap) Get(key int) int {
	return this.hmap[key]
}

func (this *MyHashMap) Remove(key int) {
	this.hmap[key] = -1
}

/**
 * Your MyHashMap object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Put(key,value);
 * param_2 := obj.Get(key);
 * obj.Remove(key);
 */