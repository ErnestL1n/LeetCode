
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
        fmt.Println(dist[i])
    }
        
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