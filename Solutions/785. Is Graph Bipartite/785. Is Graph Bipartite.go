

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