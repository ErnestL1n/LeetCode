func numSubarrayBoundedMax(nums []int, L int, R int) int {
    res,prev,dp:=0,-1,0
    for i:=0;i<len(nums);i+=1{
        if nums[i]<L && i>0{
            res+=dp
        }
        if nums[i]>R{
            dp=0
            prev=i
        }
        if L<=nums[i] && nums[i]<=R{
            dp=i-prev
            res+=dp
        }
    }
    return res
}