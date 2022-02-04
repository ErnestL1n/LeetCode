func findMaxLength(nums []int) int {
    m:=make(map[int]int)
    res,cnt:=0,0
    m[0]=0
    for idx,n:=range(nums){
        if n==1{
            cnt+=1
        }else{
            cnt-=1
        }
        if i,ok:=m[cnt];ok{
            res=max(res,idx+1-i)
        }else{
            m[cnt]=idx+1
        }
    }
    return res
}
func max(a,b int)int{
    if a>b{
        return a
    }
    return b
}