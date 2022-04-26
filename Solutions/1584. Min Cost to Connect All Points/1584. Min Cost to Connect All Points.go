// Prim's with priority queue (min heap implementation)
type MinHeap [][2]int
func (h MinHeap) Len() int{return len(h)}
func (h MinHeap) Less(i,j int) bool{return h[i][0]<h[j][0]}
func (h MinHeap) Swap(i,j int) {h[i],h[j]=h[j],h[i]}
func (h *MinHeap) Push(i interface{}) {
    *h=append(*h,i.([2]int))
}
func (h *MinHeap) Pop() interface{} {
    v:=(*h)[len(*h)-1]
    *h=(*h)[:len(*h)-1]
    return v
}
func (h MinHeap) Peek() interface{} {
    return h[0]
}

func minCostConnectPoints(points [][]int) int {
    res,n,from,connected:=0,len(points),0,1
    pq:=&MinHeap{}
    visited:=make([]bool,n)
    heap.Init(pq)
    for connected<n{
        visited[from]=true
        for i:=0;i<n;i+=1{
            if visited[i]==false{
                dist:=Abs(points[i][0]-points[from][0])+Abs(points[i][1]-points[from][1])
                heap.Push(pq,[2]int{dist,i})
            }
        }
        for visited[pq.Peek().([2]int)[1]]==true{
            heap.Pop(pq)
        }
        res+=pq.Peek().([2]int)[0]
        from=pq.Peek().([2]int)[1]
        connected+=1
    }
    return res
}

func Abs(x int) int {
    if x<0{
        return -x
    }
    return x
}










//Kruskal  ,min heap implementation
type MinHeap [][3]int
func (h MinHeap) Len() int{return len(h)}
func (h MinHeap) Less(i,j int) bool{return h[i][0]<h[j][0]}
func (h MinHeap) Swap(i,j int) {h[i],h[j]=h[j],h[i]}
func (h *MinHeap) Push(i interface{}) {
    *h=append(*h,i.([3]int))
}
func (h *MinHeap) Pop() interface{} {
    v:=(*h)[len(*h)-1]
    *h=(*h)[:len(*h)-1]
    return v
}
func (h MinHeap) Peek() interface{} {
    return h[0]
}

func minCostConnectPoints(p [][]int) int {
    n,res:=len(p),0
    ds:=make([]int,n)
    for i:=0;i<n;i+=1{
        ds[i]=-1
    }
    pq:=&MinHeap{}
    heap.Init(pq)
    for i:=0;i<n;i+=1{
        for j:=i+1;j<n;j+=1{
            dist:=Abs(p[i][0]-p[j][0])+Abs(p[i][1]-p[j][1])
            heap.Push(pq,[3]int{dist,i,j})
            //fmt.Println(dist)
        }
    }
    for pq.Len()>0{
        node:=heap.Pop(pq).([3]int)
        node[1]=find(&ds,node[1])
        node[2]=find(&ds,node[2])
        if node[1]!=node[2]{
            res+=node[0]
            //fmt.Print(" ",res)
            ds[node[1]]+=ds[node[2]]
            ds[node[2]]=node[1]
            if ds[node[1]]==-n{
                break
            }
        }
    }
    return res
}

func find(ds *[]int,i int)int{
    if (*ds)[i]<0{
        return i
    }
    (*ds)[i]=find(ds,(*ds)[i])
    return (*ds)[i]
}

func Abs(x int)int{
    if x<0{
        return -x
    }
    return x
}









//optimal Prim's for Complete Graph
func minCostConnectPoints(p [][]int) int {
    n,res,i,connected:=len(p),0,0,1
    min_d:=make([]int,n)
    for i:=0;i<n;i+=1{
        min_d[i]=4000000
    }
    for connected<n{
        min_d[i]=math.MaxInt32
        min_j:=i
        for j:=0;j<n;j+=1{
            if min_d[j]!=math.MaxInt32{
                dist:=Abs(p[i][0]-p[j][0])+Abs(p[i][1]-p[j][1])
                min_d[j]=min(dist,min_d[j])
                if min_d[j]<min_d[min_j]{
                    min_j=j
                }
            }
        }
        res+=min_d[min_j]
        i=min_j
        connected+=1
    }
    return res
}

func Abs(x int)int{
    if x<0{
        return -x
    }
    return x
}

func min(i,j int)int{
    if(i<j){
        return i
    }
    return j
}