//define priority_queue behavior
type MinHeap []int
func (h MinHeap) Len() int{return len(h)}
//min priority_queue
func (h MinHeap) Less(i,j int) bool{return h[i]<h[j]}
func (h MinHeap) Swap(i,j int){h[i],h[j]=h[j],h[i]}
func (h MinHeap) Peek() int{return h[0]}
//important behavior
func (h *MinHeap) Push(i interface{}){
    *h=append(*h,i.(int))
}
func (h *MinHeap) Pop() interface{}{
    v:=(*h)[len(*h)-1]
    *h=(*h)[:len(*h)-1]
    return v
}

//main
func furthestBuilding(a []int, bricks int, ladders int) int {
    h:=&MinHeap{}
    heap.Init(h) //can init or not 
    
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