func minCost(s string, cost []int) int {
    maxcost,res:=0,0
    for i,_:=range(s){
        if i>0 && s[i]!=s[i-1]{
            maxcost=0
        }
        res+=min(cost[i],maxcost)
        maxcost=max(cost[i],maxcost)
    }
    return res
}
func min (a,b int) int{
    if a<b{
        return a
    }
    return b
}
func max(a,b int) int{
    if a<b{
        return b
    }
    return a
}