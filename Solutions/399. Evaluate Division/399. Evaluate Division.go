func calcEquation(eqs [][]string, values []float64, queries [][]string) []float64 {
    graph:=make(map[string]map[string]float64)
    for i:=0;i<len(eqs);i+=1{
        st,ed:=eqs[i][0],eqs[i][1]
        ratio:=values[i]
        if _,ok:=graph[st];!ok{
            graph[st]=make(map[string]float64)
        }
        if _,ok:=graph[ed];!ok{
            graph[ed]=make(map[string]float64)
        }
        graph[st][ed]=ratio
        graph[ed][st]=1.0/ratio
    }
    res:=make([]float64,len(queries))
    for i:=0;i<len(queries);i+=1{
        st,ed:=queries[i][0],queries[i][1]
        if _,ok:=graph[st];!ok{
            res[i]=-1
            continue
        }
        if _,ok:=graph[ed];!ok{
            res[i]=-1
            continue
        }
        visited:=make(map[string]bool)
        res[i]=dfs(graph,st,ed,visited)
    }
    return res
}

func dfs(graph map[string]map[string]float64,st,ed string,visited map[string]bool) float64{
    if _,ok:=graph[st][ed];ok{
        return graph[st][ed]
    }
    visited[st]=true
    for k,v:=range graph[st]{
        if _,ok:=visited[k];ok{
            continue
        }
        res:=dfs(graph,k,ed,visited)
        if res==-1.0{
            continue
        }
        return res*v
    }
    return -1
}