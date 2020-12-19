func allPathsSourceTarget(g [][]int) [][]int {
    var res [][]int
    var path []int
    path=append(path,0)
    dfs(g,&res,path,0)
    return res
}

func dfs(g [][]int,res *[][]int,path []int,node int){
    if node==len(g)-1{
        tmp:=make([]int,len(path))
        copy(tmp,path)
        *res=append(*res,tmp)
    }
    for _,i:=range g[node]{
        path=append(path,i)
        dfs(g,res,path,i)
        path=path[:len(path)-1]   
    }
}