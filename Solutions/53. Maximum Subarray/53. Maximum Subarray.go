func maxSubArray(nums []int) int {
    curr,res:=math.MinInt32,math.MinInt32
    for _,n:=range(nums){
        curr=max(0,curr)+n
        res=max(res,curr)
    }
    return res
}
func max(i,j int)int{
    if(i>j){
        return i
    }
    return j
}