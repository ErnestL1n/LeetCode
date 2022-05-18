var no_rk int

func criticalConnections(n int, connections [][]int) [][]int {
    no_rk=-2
    graph:=make([][]int,n)
    for _,conn:=range connections{
        graph[conn[0]]=append(graph[conn[0]],conn[1])
        graph[conn[1]]=append(graph[conn[1]],conn[0])
    }
    rk:=make([]int,n)
    for i:=0;i<n;i+=1{rk[i]=no_rk}
    var res [][]int
    critical(graph,n,0,0,rk,&res)
    return res
}

func critical(graph [][]int,n,node,myrk int,ranks []int,res *[][]int) int{
    if ranks[node]!=no_rk{
        return ranks[node]
    }
    lowestrk:=myrk
    ranks[node]=myrk
    for _,neighbor:=range(graph[node]){
        if ranks[neighbor]==myrk-1 || ranks[neighbor]==n{
            continue
        }
        neighborrk:=critical(graph,n,neighbor,myrk+1,ranks,res)
        lowestrk=min(lowestrk,neighborrk)
        if neighborrk>myrk{
            *res=append(*res,[]int{min(node,neighbor),max(node,neighbor)})
        }
    }
    ranks[node]=n
    return lowestrk
}

func min(i,j int) int{
    if i<j{
        return i
    }
    return j
}

func max(i,j int) int{
    if i>j{
        return i
    }
    return j
}