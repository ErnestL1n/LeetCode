type MyHashSet struct {
    h []bool;
}


/** Initialize your data structure here. */
func Constructor() MyHashSet {
    return MyHashSet{make([]bool, 1000001)}
}


func (this *MyHashSet) Add(key int)  {
    this.h[key]=true
}


func (this *MyHashSet) Remove(key int)  {
    this.h[key]=false
}


/** Returns true if this set contains the specified element */
func (this *MyHashSet) Contains(key int) bool {
    return this.h[key];
}


/**
 * Your MyHashSet object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Add(key);
 * obj.Remove(key);
 * param_3 := obj.Contains(key);
 */