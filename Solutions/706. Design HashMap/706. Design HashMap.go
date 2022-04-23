type MyHashMap struct {
    Table []int
}


func Constructor() MyHashMap {
    table:=make([]int,1000001)
    for i:=0;i<1000001;i+=1{
        table[i]=-1
    }
    return MyHashMap{table}
}


func (this *MyHashMap) Put(key int, value int)  {
    this.Table[key]=value
}


func (this *MyHashMap) Get(key int) int {
    return this.Table[key]
}


func (this *MyHashMap) Remove(key int)  {
    this.Table[key]=-1
}


/**
 * Your MyHashMap object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Put(key,value);
 * param_2 := obj.Get(key);
 * obj.Remove(key);
 */