func maxProfit(p []int) int {
    res,minv:=0,math.MaxInt32
    for i,_:=range(p){
        if minv>p[i]{
            minv=p[i]
        }else{
            res=max(res,p[i]-minv)
        }
    }
    return res
}
func max(i,j int)int{
    if(i<j){
        return j
    }
    return i
}



//dp
func maxProfit(p []int) int {
    res,n:=0,len(p)
    record:=make([]int,n)
    for i:=1;i<n;i+=1{
        record[i]=max(0,record[i-1]+p[i]-p[i-1])
        res=max(res,record[i])
    }
    return res
}
func max(i,j int)int{
    if(i<j){
        return j
    }
    return i
}