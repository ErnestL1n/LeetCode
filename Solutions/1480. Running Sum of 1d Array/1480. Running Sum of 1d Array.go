func runningSum(nums []int) []int {
    tmp:=0
    for i:=0;i<len(nums);i+=1{
        tmp+=nums[i]
        nums[i]=tmp
    }
    return nums
}