func maxProduct(nums []int) int {
    res,l,r,n:=nums[0],0,0,len(nums)
    for i,_:=range(nums){
        if l==0{
            l=1
        }
        l*=nums[i]
        if r==0{
            r=1
        }
        r*=nums[n-i-1]
        res=max(res,max(l,r))
    }
    return res
}
func max(i,j int)int{
    if i>j{
        return i
    }
    return j
}