func getSmallestString(n int, k int) string {
    res:=make([]byte,n)
    for i:=0;i<n;i+=1{
        res[i]='a'
    }
    k-=n
    for k>0{
        n-=1
        res[n]+=byte(min(25,k))
        k-=min(25,k)
    }
    return string(res)
}

func min(i,j int) int{
    if i<j{
        return i
    }
    return j
}