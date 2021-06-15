func largestAltitude(gain []int) int {
    res,curr:=0,0
    for _,g:=range(gain){
        curr+=g
        res=max(res,curr)
    }
    return res
}
func max(i,j int) int{
    if i>j{
        return i
    }
    return j
}