func combinationSum2(candidates []int, target int) [][]int {
    var res [][]int
    var path []int
    sort.Ints(candidates)
    foo(candidates,target,&res,path,0)
    return res
}
func foo(c []int,t int,res *[][]int,path []int,begin int){
    if t<=0{
        if t==0{
            tmp:=make([]int,len(path))
            copy(tmp,path)
            *res=append(*res,tmp)
            return
        }
        return
    }
    for i:=begin;i<len(c);i+=1{
        if i>begin && c[i]==c[i-1]{
            continue
        }
        path=append(path,c[i])
        foo(c,t-c[i],res,path,i+1)
        path=path[:len(path)-1]
    }
}