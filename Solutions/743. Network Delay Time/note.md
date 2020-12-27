## Build min heap in golang (pair):
  [Reference](https://leetcode.com/problems/network-delay-time/discuss/906884/Go-54ms-heap-solution-beat-95)
  ```go
//Dijkstra
//define priority_queue behavior
type MinHeap [][2]int  //as pair
func (h MinHeap) Len() int{return len(h)}
//min priority_queue sort by first element(which is distance)
//if compare with second element : h[i][1]<h[j][1]
func (h MinHeap) Less(i,j int) bool{return h[i][0]<h[j][0]}
func (h MinHeap) Swap(i,j int){h[i],h[j]=h[j],h[i]}
//important behavior
func (h* MinHeap) Push(i interface{}){
    *h=append(*h,i.([2]int))
}
func (h* MinHeap) Pop() interface{}{
    v:=(*h)[len(*h)-1]
    *h=(*h)[:len(*h)-1]
    return v
}
```
