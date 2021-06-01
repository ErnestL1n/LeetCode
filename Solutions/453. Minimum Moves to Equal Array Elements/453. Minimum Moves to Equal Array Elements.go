func minMoves(nums []int) int {
    s,m_in:=0,math.MaxInt32
    for i,_:=range(nums){
        s+=nums[i]
        m_in=min(m_in,nums[i])
    }
    return s-m_in*len(nums)
}
func min(i,j int) int{
    if i<j{
        return i
    }
    return j
}