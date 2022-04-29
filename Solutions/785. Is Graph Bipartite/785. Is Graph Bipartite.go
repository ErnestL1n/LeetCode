//bfs
func isBipartite(graph [][]int) bool {
    n:=len(graph)
    colors:=make([]int,n)
    for i:=0;i<n;i+=1{
        if colors[i]!=0{
            continue
        }
        colors[i]=1
        var q []int
        q=append(q,i)
        for len(q)>0{
            cur:=q[0];q=q[1:]
            for _,x:=range graph[cur]{
                if colors[x]==0{
                    colors[x]=-colors[cur]
                    q=append(q,x)
                }else if colors[x]!=-colors[cur]{
                    return false
                }
            }
        }
    }
    return true
}

//dfs
func isBipartite(graph [][]int) bool {
    n:=len(graph)
    colors:=make([]int,n)
    for i:=0;i<n;i+=1{
        if colors[i]==0 && !validcolor(&graph,&colors,1,i){
            return false
        }
    }
    return true
}

func validcolor(graph *[][]int,colors *[]int,color,node int) bool{
    if (*colors)[node]!=0{
        return (*colors)[node]==color
    }
    (*colors)[node]=color
    for _,x:=range((*graph)[node]){
        if !validcolor(graph,colors,-color,x){
            return false
        }
    }
    return true
}