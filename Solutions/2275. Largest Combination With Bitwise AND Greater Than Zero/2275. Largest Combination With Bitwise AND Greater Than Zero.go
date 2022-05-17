func largestCombination(candidates []int) int {
    res:=0
    mx:=-1
    for _,c:=range candidates{mx=max(mx,c)}
    for b:=1;b<=mx;b*=2{
        cnt:=0
        for _,c:=range candidates{
            if c&b>0{
                cnt+=1   
            }
            res=max(res,cnt)
        }
    }
    return res
}

func max(i,j int) int{
    if i>j{
        return i
    }
    return j
}