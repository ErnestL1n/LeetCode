# Cpp:
## In Prim's implementation

```cpp
while(visited[pq.top().second])
    pq.pop();
//above part is to avoid cycle	
```


## heap and priority_queue 

### heap
```cpp
// typedef array<int,3> ar;
make_heap(arr.begin(),arr.end(),greater<ar>());
```
as well as

### priority_queue

```cpp
// typedef pair<int,int> pr;
priority_queue<pr,vector<pr>,greater<pr>> pq;
```

are both in ascending order


### heap_pop

```cpp
pop_heap(arr.begin(),arr.end(),greater<ar>());  // top go to back
auto [dist,i,j]=arr.back();                     // peek from back
arr.pop_back();                                 // pop back
```

# Go:
### [heap peek() reference : Go Playground](https://play.golang.org/p/IFbLvyF3wP)
### [Package heap](https://golang.org/pkg/container/heap/)
### example:
```go
func (h MinHeap) Peek() interface{} {
    return h[0]
}
//then
for visited[pq.Peek().([2]int)[1]]{
            heap.Pop(pq)
        }

```
