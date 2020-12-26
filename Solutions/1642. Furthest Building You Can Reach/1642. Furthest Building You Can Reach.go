//define priority_queue behavior
type MinHeap []int
func (h MinHeap) Len() int{return len(h)}
//min priority_queue
func (h MinHeap) Less(i,j int) bool{return h[i]<h[j]}
func (h MinHeap) Swap(i,j int){h[i],h[j]=h[j],h[i]}
func (h MinHeap) Peek() int{return h[0]}
//important behavior
func (h *MinHeap) Push(x interface{}){
    *h=append(*h,x.(int))
}
func (h *MinHeap) Pop() interface{}{
    old:=*h
    n:=len(old)
    x:=old[n-1]
    *h=old[:n-1]
    return x
}

//main
func furthestBuilding(a []int, bricks int, ladders int) int {
    h:=&MinHeap{}
    heap.Init(h)
    
    for i:=0;i<len(a)-1;i+=1{
        dis:=a[i+1]-a[i]
        if dis>0{
            heap.Push(h,dis)
        }
        if h.Len()>ladders{
            bricks-=heap.Pop(h).(int)
        }
        if bricks<0{
            return i
        }
    }
    return len(a)-1
}