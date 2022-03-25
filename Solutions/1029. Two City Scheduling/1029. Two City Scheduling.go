func twoCitySchedCost(costs [][]int) int {
    var tmp []int
    n,res:=len(costs)/2,0
    for _,cost:=range(costs){
        res+=cost[0]
        tmp=append(tmp,cost[1]-cost[0])
    }
    sort.Ints(tmp)
    for i:=0;i<n;i+=1{
        res+=tmp[i]
    }
    return res
}