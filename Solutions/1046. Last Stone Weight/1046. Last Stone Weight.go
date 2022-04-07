type MaxHeap []int
func (h MaxHeap) Len() int{return len(h)}
func (h MaxHeap) Less(i,j int) bool{return h[i]>h[j]}
func (h MaxHeap) Swap(i,j int){h[i],h[j]=h[j],h[i]}
func (h MaxHeap) Peek() int{return h[0]}
func (h *MaxHeap) Push(i interface{}){*h=append(*h,i.(int))}
func (h *MaxHeap) Pop() interface{}{
    v:=(*h)[len(*h)-1]
    *h=(*h)[:len(*h)-1]
    return v
}



func lastStoneWeight(stones []int) int {
    h:=&MaxHeap{}
    heap.Init(h)
    for _,s:=range stones{
        heap.Push(h,s)
    }
    for h.Len()>1{
        x:=heap.Pop(h).(int)
        y:=heap.Pop(h).(int)
        heap.Push(h,x-y)
    }
    return h.Peek()
}type MaxHeap []int
func (h MaxHeap) Len() int{return len(h)}
func (h MaxHeap) Less(i,j int) bool{return h[i]>h[j]}
func (h MaxHeap) Swap(i,j int){h[i],h[j]=h[j],h[i]}
func (h MaxHeap) Peek() int{return h[0]}
func (h *MaxHeap) Push(i interface{}){*h=append(*h,i.(int))}
func (h *MaxHeap) Pop() interface{}{
    v:=(*h)[len(*h)-1]
    *h=(*h)[:len(*h)-1]
    return v
}



func lastStoneWeight(stones []int) int {
    h:=&MaxHeap{}
    heap.Init(h)
    for _,s:=range stones{
        heap.Push(h,s)
    }
    for h.Len()>1{
        x:=heap.Pop(h).(int)
        y:=heap.Pop(h).(int)
        heap.Push(h,x-y)
    }
    return h.Peek()
}