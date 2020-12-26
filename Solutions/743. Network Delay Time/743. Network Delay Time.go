//Dijkstra
//define priority_queue behavior
type MinHeap [][2]int  //as pair
func (h MinHeap) Len() int{return len(h)}
//min priority_queue sort by first element(which is distance)
//compare with second element is h[i][1]<h[j][1]
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

func networkDelayTime(times [][]int, N int, K int) int {
    vp:=make([][][2]int,N+1)
    for _,time:=range(times){
        vp[time[0]]=append(vp[time[0]],[2]int{time[1],time[2]})
    }
    visited:=make([]bool,N+1)
    d:=make([]int,N+1)
    for i:=0;i<=N;i+=1{
        d[i]=math.MaxInt32
    }
    d[0],d[K]=0,0
    pq:=&MinHeap{}
    heap.Init(pq) //can init or not 
    heap.Push(pq,[2]int{0,K})
    for pq.Len()>0{
        node:=heap.Pop(pq).([2]int)
        c,u:=node[0],node[1]
        if visited[u]{
            continue
        }
        for _,to:=range(vp[u]){
            v,w:=to[0],to[1]
            if c+w<d[v]{
                d[v]=c+w
                heap.Push(pq,[2]int{d[v],v})
            }
        }
        visited[u]=true
    }
    res:=math.MinInt32
    for i:=0;i<len(d);i+=1{
        if res<d[i]{
            res=d[i]
        }
    }
    if res==math.MaxInt32{
        return -1
    }
    return res
}




//Bellman Ford
func networkDelayTime(times [][]int, N int, K int) int {
    dist:=make([]int,N+1)
    for i:=0;i<=N;i+=1{
        dist[i]=math.MaxInt32
    }
    dist[0],dist[K]=0,0
    for i:=0;i<=N;i+=1{
        for _,t:=range(times){
            u,v,w:=t[0],t[1],t[2]
            if dist[u]!=math.MaxInt32 && dist[v]>dist[u]+w{
                dist[v]=dist[u]+w
            }
        }
    }
    res:=0
    for i:=1;i<=N;i+=1{
        res=Max(dist[i],res)
    }
    
    if(res==math.MaxInt32){
        return -1
    }
        
    return res
}

func Max(i,j int) int{
    if i<j {
        return j
    }
    return i
}