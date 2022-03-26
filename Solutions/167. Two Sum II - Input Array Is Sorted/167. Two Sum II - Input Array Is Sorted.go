func twoSum(nums []int, target int) []int {
    lo,hi:=0,len(nums)-1
    for lo<hi{
        tmp:=nums[lo]+nums[hi]
        if tmp==target{
            return []int{lo+1,hi+1}
        }
        if tmp<target{
            lo+=1
        }else{
            hi-=1
        }
    }
    return []int{-1,-1}
}