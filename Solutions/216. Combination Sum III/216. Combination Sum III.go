func combinationSum3(k int, n int) [][]int {
    var res [][]int
    var tmp[]int
    combination(&res,tmp,k,1,n)
    return res
}

func combination(res *[][]int,tmp []int,k,st,n int) {
    if len(tmp)==k && n==0{
        x:=make([]int,len(tmp))
        copy(x,tmp)
        *res=append(*res,x)
        return;
    }
    for i:=st;i<=9;i+=1{
        tmp=append(tmp,i)
        combination(res,tmp,k,i+1,n-i)
        tmp=tmp[:len(tmp)-1]
    }
}