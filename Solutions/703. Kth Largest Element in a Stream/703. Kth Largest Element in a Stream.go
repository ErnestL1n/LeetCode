type MinHeap []int
func (h MinHeap) Len() int{return len(h)}
func (h MinHeap) Less(i,j int) bool{return h[i]<h[j]}
func (h MinHeap) Peek() int{return h[0]}
func (h MinHeap) Swap(i,j int){h[i],h[j]=h[j],h[i]}
func (h* MinHeap) Push(i interface{}){
    *h=append(*h,i.(int))
}
func (h* MinHeap) Pop() interface{}{
    v:=(*h)[len(*h)-1]
    *h=(*h)[:len(*h)-1]
    return v
}

type KthLargest struct {
    PQ *MinHeap 
    K int
}


func Constructor(k int, nums []int) KthLargest {
    pq:=&MinHeap{}
    heap.Init(pq)
    for _,n:=range nums{
        heap.Push(pq,n)
        if pq.Len()>k{
            heap.Pop(pq)
        }
    }
    return KthLargest{pq,k}
}


func (this *KthLargest) Add(val int) int {
    heap.Push(this.PQ,val)
    if this.PQ.Len()>this.K{
        heap.Pop(this.PQ)
    }
    return this.PQ.Peek()
}


/**
 * Your KthLargest object will be instantiated and called as such:
 * obj := Constructor(k, nums);
 * param_1 := obj.Add(val);
 */