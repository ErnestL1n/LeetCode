func smallestRangeII(nums []int, k int) int {
    sort.Ints(nums)
    n:=len(nums)
    res,right,left:=nums[n-1]-nums[0],nums[n-1]-k,nums[0]+k
    for i:=0;i<n-1;i+=1{
        m_ax:=max(right,nums[i]+k)
        m_in:=min(left,nums[i+1]-k)
        res=min(res,m_ax-m_in)
    }
    return res
}
func max(i,j int)int{
    if(i>j){
        return i
    }
    return j
}
func min(i,j int)int{
    if(i<j){
        return i
    }
    return j
}