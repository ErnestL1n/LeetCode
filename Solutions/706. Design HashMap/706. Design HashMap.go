type MyHashMap struct {
    table []int
}


func Constructor() MyHashMap {
    m:=new(MyHashMap)
    m.table=make([]int,10000,1000001)
    for i,_:=range(m.table){
        m.table[i]=-1
    }
    return *m
}


func (this *MyHashMap) Put(key int, value int)  {
    l:=len(this.table)
    if key>=l{
        newlen:=2*key
        if newlen>1000001{
            newlen=1000001
        }
        this.table=this.table[:newlen]
        for i:=l;i<len(this.table);i+=1{
            this.table[i]=-1
        }
    }
    this.table[key]=value
}


func (this *MyHashMap) Get(key int) int {
    if key>=len(this.table){
        return -1
    }
    return this.table[key]
}


func (this *MyHashMap) Remove(key int)  {
    if key>=len(this.table){
        return
    }
    this.table[key]=-1
}


/**
 * Your MyHashMap object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Put(key,value);
 * param_2 := obj.Get(key);
 * obj.Remove(key);
 */