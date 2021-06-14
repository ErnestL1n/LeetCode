func check(nums []int) bool {
    cnt,n:=0,len(nums)
    for i:=0;i<n;i+=1{
        if nums[i]>nums[(i+1)%n]{
            cnt+=1
        }
        if cnt>1{
            return false
        }
    }
    return true
}