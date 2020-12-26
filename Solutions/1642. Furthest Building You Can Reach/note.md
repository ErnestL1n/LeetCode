## [Idea is from here](https://leetcode.com/problems/furthest-building-you-can-reach/discuss/918515/JavaC%2B%2BPython-Priority-Queue)

### reference:
  1. [Package heap(Go)](https://golang.org/pkg/container/heap/)
  2. [Priority Queue Using Heap](https://www.codesdope.com/blog/article/priority-queue-using-heap/#:~:text=Thus%2C%20a%20max%2Dpriority%20queue,with%20the%20smallest%20key%20first.&text=Heaps%20are%20great%20for%20implementing,and%20a%20min%2Dheap%20respectively.)
      * We use a max-heap for a max-priority queue and a min-heap for a min-priority queue

```go
//define priority_queue behavior
type MinHeap []int
func (h MinHeap) Len() int{return len(h)}
//min priority_queue,in the other hand ,change h[i]>h[j] to be a max priority_queue
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
```
