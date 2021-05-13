func smallestRangeI(nums []int, k int) int {
    m_ax,m_in:=nums[0],nums[0]
    for i:=1;i<len(nums);i+=1{
        m_ax=max(m_ax,nums[i])
        m_in=min(m_in,nums[i])
    }
    if m_ax-m_in-2*k>0{
        return m_ax-m_in-2*k
    }else{
        return 0
    }
}
func max(i,j int) int{
    if(i>j){
        return i
    }
    return j
}
func min(i,j int) int{
    if(i<j){
        return i
    }
    return j
}